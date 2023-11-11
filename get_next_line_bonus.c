/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:30:50 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/11 01:05:07 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_error	read_file(t_buff *buff, char *static_buff)
{
	buff->bytes_read = \
		read(buff->fd, &(buff->content)[buff->prev_len], BUFFER_SIZE);
	if (buff->bytes_read < 0)
	{
		ft_clear_str(static_buff, BUFFER_SIZE + 1);
		free(buff->content);
		return (ERROR);
	}
	(buff->content)[buff->prev_len + buff->bytes_read] = '\0';
	buff->line_len += \
		ft_findeol(&(buff->content)[buff->prev_len], &(buff->eol));
	return (OK);
}

static t_error	extract_line(t_buff *buff, char *static_buff, char **line)
{
	size_t	remain_len;

	if (buff->eol)
		buff->line_len++;
	*line = (char *)malloc((buff->line_len + 1) * sizeof(char));
	if (!(*line))
	{
		ft_clear_str(static_buff, BUFFER_SIZE + 1);
		free(buff->content);
		return (ERROR);
	}
	ft_strlcpy(*line, buff->content, buff->line_len + 1);
	remain_len = buff->prev_len + buff->bytes_read - buff->line_len;
	if (buff->bytes_read > 0)
		ft_strlcpy(static_buff, buff->eol + 1, remain_len + 1);
	static_buff[remain_len] = '\0';
	free(buff->content);
	return (OK);
}

static t_error	resize_buffer(t_buff *buff, char *static_buff)
{
	char	*aux;

	aux = (char *)malloc((buff->prev_len + BUFFER_SIZE + 1) * sizeof(char));
	if (!aux)
	{
		ft_clear_str(static_buff, BUFFER_SIZE + 1);
		free(buff->content);
		return (ERROR);
	}
	ft_strlcpy(aux, buff->content, buff->prev_len + 1);
	free(buff->content);
	buff->content = aux;
	return (OK);
}

static t_error	get_line(t_buff *buff, char *static_buff, char **line)
{
	while (buff->bytes_read)
	{
		if (!(buff->eol))
		{
			if (read_file(buff, static_buff) == ERROR)
				return (ERROR);
		}
		if (buff->line_len == 0 && buff->bytes_read == 0)
		{
			free(buff->content);
			return (ERROR);
		}
		if (buff->eol || buff->bytes_read == 0)
		{
			if (extract_line(buff, static_buff, line) == ERROR)
				return (ERROR);
			break ;
		}
		buff->prev_len += buff->bytes_read;
		if (resize_buffer(buff, static_buff) == ERROR)
			return (ERROR);
		*line = buff->content;
	}
	return (OK);
}

char	*get_next_line(int fd)
{
	static char	static_buff[FD_MAX + 1][BUFFER_SIZE + 1] = {"\0"};
	t_buff		buff;
	char		*line;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0 || FD_MAX <= 0)
		return (NULL);
	buff.fd = fd;
	buff.prev_len = ft_strlen(static_buff[fd]);
	buff.content = \
		(char *)malloc((BUFFER_SIZE + buff.prev_len + 1) * sizeof(char));
	if (!buff.content)
		return (NULL);
	buff.eol = NULL;
	buff.line_len = 0;
	buff.bytes_read = 1;
	ft_strlcpy(buff.content, static_buff[fd], buff.prev_len + 1);
	buff.line_len = ft_findeol(buff.content, &(buff.eol));
	if (get_line(&buff, static_buff[fd], &line) == ERROR)
		return (NULL);
	return (line);
}

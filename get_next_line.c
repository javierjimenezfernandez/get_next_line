/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:45:45 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/09 00:45:00 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"

static ssize_t	read_file(t_buff *buff, char *static_buff)
{
	ssize_t	bytes_read;

	bytes_read = read(buff->fd, &(buff->content)[buff->prev_len], BUFFER_SIZE);
	if (bytes_read < 0)
	{
		ft_clear_str(static_buff, BUFFER_SIZE + 1);
		free(buff->content);
		return (bytes_read);
	}
	(buff->content)[buff->prev_len + bytes_read] = '\0';
	return (bytes_read);
}

static char	*extract_line(t_buff *buff, char *static_buff, ssize_t bytes_read)
{
	char	*line;
	size_t	remain_len;

	if (buff->eol)
		buff->line_len++;
	line = (char *)malloc((buff->line_len + 1) * sizeof(char));
	if (!line)
	{
		ft_clear_str(static_buff, BUFFER_SIZE + 1);
		free(buff->content);
		return (NULL);
	}
	ft_strlcpy(line, buff->content, buff->line_len + 1);
	remain_len = buff->prev_len + bytes_read - buff->line_len;
	if (bytes_read != 0)
		ft_strlcpy(static_buff, buff->eol + 1, remain_len + 1);
	static_buff[remain_len] = '\0';
	free(buff->content);
	return (line);
}

static char	*resize_buffer(t_buff *buff, char *static_buff)
{
	char	*aux;

	aux = (char *)malloc((buff->prev_len + BUFFER_SIZE + 1) * sizeof(char));
	if (!aux)
	{
		ft_clear_str(static_buff, BUFFER_SIZE + 1);
		free(buff->content);
		return (NULL);
	}
	ft_strlcpy(aux, buff->content, buff->prev_len + 1);
	free(buff->content);
	buff->content = aux;
	return (buff->content);
}

static char	*get_line(t_buff *buff, char *static_buff)
{
	char	*line;
	ssize_t	bytes_read;

	bytes_read = 1;
	while (!buff->eol)
	{
		buff->line_len = ft_findeol(buff->content, &(buff->eol));
		if (!(buff->eol))
		{
			bytes_read = read_file(buff, static_buff);
			if (bytes_read < 0)
				return (NULL);
			buff->line_len += \
				ft_findeol(&(buff->content)[buff->prev_len], &(buff->eol));
		}
		if (buff->line_len == 0 && bytes_read == 0)
		{
			free(buff->content);
			return (NULL);
		}
		if (buff->eol || bytes_read == 0)
		{
			line = extract_line(buff, static_buff, bytes_read);
			if (!line)
				return (NULL);
			break ;
		}
		buff->prev_len += bytes_read;
		buff->content = resize_buffer(buff, static_buff);
		if (!buff->content)
			return (NULL);
		line = buff->content;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	static_buff[BUFFER_SIZE + 1] = "\0";
	t_buff		buff;
	char		*line;

	if (fd < 0)
		return (NULL);
	buff.fd = fd;
	buff.prev_len = ft_strlen(static_buff);
	buff.content = \
		(char *)malloc((BUFFER_SIZE + buff.prev_len + 1) * sizeof(char));
	if (!buff.content)
		return (NULL);
	buff.eol = NULL;
	buff.line_len = 0;
	ft_strlcpy(buff.content, static_buff, buff.prev_len + 1);
	//buff.line_len = ft_findeol(buff.content, &(buff.eol));
	line = get_line(&buff, static_buff);
	return (line);
}

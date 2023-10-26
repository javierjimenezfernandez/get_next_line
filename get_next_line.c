/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:45:45 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/26 20:58:53 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	old_buff[BUFFER_SIZE] = "\0";

char	*get_next_line(int fd)
{
	char	*buff;
	char	*aux;
	char	*eol = NULL;
	char	*line = NULL;
	int		line_len;
	int		old_len;
	size_t	n;
	size_t	i;
	//static char	old_buff[BUFFER_SIZE] = "\0";

	if (fd < 0)
		return (NULL);
	old_len = ft_strlen(old_buff);
	buff = (char *)malloc((BUFFER_SIZE + old_len) * sizeof(char));
	if (!buff)
		return (NULL);
	ft_strncpy(buff, old_buff, old_len);
	n = 1;
	i = old_len;
	while (n && !eol)
	{
		n = read(fd, &buff[i], BUFFER_SIZE);
		if (n < 0)
		{
			free(buff);
			return (NULL);
		}
		if (n < BUFFER_SIZE)
		{
			if (buff[i + n] != '\n')
				buff[i + n + 1] = '\0';
		}
		line_len = ft_findeol(buff, eol);
		if (eol)
		{
			line = (char *)malloc((line_len + 1) * sizeof(char));
			ft_strncpy(line, buff, line_len + 1);
			ft_strncpy(old_buff, eol + 1, BUFFER_SIZE - line_len - 1);
			old_buff[BUFFER_SIZE - line_len] = '\0';
			free(buff);
			break ;
		}
		i += BUFFER_SIZE;
		aux = (char *)malloc((i + BUFFER_SIZE) * sizeof(char));
		if (!aux)
		{
			free(buff);
			return (NULL);
		}
		ft_strncpy(aux, buff, i);
		free(buff);
		buff = aux;
		line = aux;
	}
	return (line);
}

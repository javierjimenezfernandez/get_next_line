/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:45:45 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/08 19:48:02 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buff;
	char	*aux;
	char	*eol = NULL;
	char	*line = NULL;
	int		line_len;
	int		remain_len;
	ssize_t	n;
	size_t	i;
	static char	static_buff[BUFFER_SIZE + 1] = "\0";

	if (fd < 0)
		return (NULL);
	i = ft_strlen(static_buff);
	buff = (char *)malloc((BUFFER_SIZE + i + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, static_buff, i + 1);
	n = 1;
	while (!eol)
	{
		line_len = ft_findeol(buff, &eol);
		if (!eol)
			{
			n = read(fd, &buff[i], BUFFER_SIZE);
			if (n < 0)
			{
				ft_clear_str(static_buff, BUFFER_SIZE + 1);
				free(buff);
				return (NULL);
			}
			buff[i + n] = '\0';
			line_len = ft_findeol(buff, &eol);
		}
		if (line_len == 0 && n == 0)
		{
			free(buff);
			return (NULL);
		}
		if (eol || n == 0)
		{
			if (!eol)
				line = (char *)malloc((line_len + 1) * sizeof(char));
			else
				line = (char *)malloc((line_len + 2) * sizeof(char));
			if (!line)
			{
				ft_clear_str(static_buff, BUFFER_SIZE + 1);
				free(buff);
				return (NULL);
			}
			if (!eol)
				ft_strlcpy(line, buff, line_len + 1);
			else
				ft_strlcpy(line, buff, line_len + 2);
			if (!eol)
				remain_len = i + n - line_len;
			else
				remain_len = i + n - line_len - 1;
			if (n != 0)
				ft_strlcpy(static_buff, eol + 1, remain_len + 1);
			static_buff[remain_len] = '\0';
			free(buff);
			break ;
		}
		i += n;
		aux = (char *)malloc((i + BUFFER_SIZE + 1) * sizeof(char));
		if (!aux)
		{
			ft_clear_str(static_buff, BUFFER_SIZE + 1);
			free(buff);
			return (NULL);
		}
		ft_strlcpy(aux, buff, line_len + 1);
		free(buff);
		buff = aux;
		line = buff;
	}
	return (line);
}

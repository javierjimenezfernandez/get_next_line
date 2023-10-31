/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:45:45 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/31 17:44:25 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"

static char	static_buff[BUFFER_SIZE] = "\0";

char	*get_next_line(int fd)
{
	char	*buff;
	char	*aux;
	char	*eol = NULL;
	char	*line = NULL;
	int		line_len;
	int		remain_len;
	int		old_len;
	size_t	n;
	size_t	i;
	//static char	static_buff[BUFFER_SIZE] = "\0";

	if (fd < 0)
		return (NULL);
	old_len = ft_strlen(static_buff);
	buff = (char *)malloc((BUFFER_SIZE + old_len) * sizeof(char));
	//buff = (char *)malloc((BUFFER_SIZE) * sizeof(char));
	if (!buff)
		return (NULL);
	ft_strncpy(buff, static_buff, old_len);
	n = 1;
	i = old_len;
	while (n && !eol)
	{
		n = read(fd, &buff[i], BUFFER_SIZE);
		//printf("n = \t\t%zu\n", n);
		if (n <= 0)
		{
			free(buff);
			return (NULL);
		}
		if (n < BUFFER_SIZE)
		{
			if (buff[i + n] != '\n')
				buff[i + n] = '\0';
		}
		line_len = ft_findeol(buff, &eol, i + n);
		//printf("line_len = \t\"%d\"\n", line_len);
		//printf("eol = \t\t\"%s\"\n", eol);
		if (eol)
		{
			line = (char *)malloc((line_len + 1) * sizeof(char));
			if (!line)
			{
				free(buff);
				return (NULL);
			}
			ft_strncpy(line, buff, line_len + 1);
			remain_len = i + n - line_len - 1;
			//printf("remain_len = \t%d\n", remain_len);
			if (remain_len < 0)
				remain_len = 0;
			ft_strncpy(static_buff, eol + 1, remain_len);
			static_buff[remain_len] = '\0';
			//printf("static_buff = \"%s\"\n", static_buff);
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

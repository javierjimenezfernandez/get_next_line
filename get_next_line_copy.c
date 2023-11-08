/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:45:45 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/08 19:47:07 by javjimen         ###   ########.fr       */
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
	printf("old_len = \t%lu\n", i);
	buff = (char *)malloc((BUFFER_SIZE + i + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, static_buff, i + 1);
	n = 1;
	while (n && !eol)
	{
		line_len = ft_findeol(buff, &eol);
		if (!eol)
			{
			n = read(fd, &buff[i], BUFFER_SIZE);
			printf("n = \t\t%zu\n", n);
			if (n < 0)
			{
				ft_clear_str(static_buff, BUFFER_SIZE + 1);
				free(buff);
				return (NULL);
			}
			buff[i + n] = '\0';
			printf("buff = \t\t\"%s\"\n", buff);
			printf("i + n = \t%ld\n", i + n);
			line_len = ft_findeol(buff, &eol);
			printf("line_len = \t%d\n", line_len);
			printf("eol = \t\t\"%s\"\n", eol);
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
			printf("i = \t\t%zu\n", i);
			printf("n = \t\t%ld\n", n);
			printf("line_len = \t%d\n", line_len);
			if (!eol)
				remain_len = i + n - line_len;
			else
				remain_len = i + n - line_len - 1;
			printf("remain_len = \t%d\n", remain_len);
			if (n != 0)
				ft_strlcpy(static_buff, eol + 1, remain_len + 1);
			static_buff[remain_len] = '\0';
			printf("static_buff = \t\"%s\"\n", static_buff);
			printf("buff = \t\t\"%s\"\n", buff);
			free(buff);
			break ;
		}
		i += n;
		printf("i = %zu\n", i);
		aux = (char *)malloc((i + BUFFER_SIZE + 1) * sizeof(char));
		//printf("aux malloc ok\n");
		if (!aux)
		{
			ft_clear_str(static_buff, BUFFER_SIZE + 1);
			free(buff);
			return (NULL);
		}
		//printf("aux = \"%s\"\n", aux);
		printf("i = %zu\n", i);
		printf("buff = \t\t\"%s\"\n", buff);
		printf("line_len = \t\"%d\"\n", line_len);
		ft_strlcpy(aux, buff, line_len + 1);
		free(buff);
		printf("aux = \t\t\"%s\"\n", aux);
		//printf("---------\n\n");
		buff = aux;
		printf("buff = \t\t\"%s\"\n", buff);
		line = buff;
	}
	return (line);
}

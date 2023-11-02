/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:46:05 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/02 17:43:35 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	ft_lentoeol(char *line, int *eol_flag)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n' && (i + 1) < BUFFER_SIZE)
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		*eol_flag = 1;
	else
		*eol_flag = 0;
	return (i);
}

int	ft_findeol(char *line, char **eol, int buff_len)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n' && (i + 1) < buff_len)
		i++;
	if (line[i] == '\n')
	{
		*eol = &line[i];
		//write(1, "found \\n\n", 9); 
	}
	else
		*eol = NULL;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	size_t			len;
	unsigned char	*aux;

	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	len = count * size;
	p = (void *)malloc(len);
	if (p)
	{
		aux = p;
		while (len > 0)
		{
			*aux = 0;
			aux++;
			len--;
		}
	}
	return (p);
}

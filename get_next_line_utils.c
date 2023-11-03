/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:46:05 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/03 16:41:59 by javjimen         ###   ########.fr       */
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

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && (i + 1) < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
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

int	ft_findeol(char *line, char **eol)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			*eol = &line[i];
			break ;
		}
		else
			*eol = NULL;
		i++;
	}
	return (i);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
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

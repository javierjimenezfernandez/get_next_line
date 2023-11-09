/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:46:05 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/08 19:34:24 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// delete include for macOS version:
#include <stdint.h>

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
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

void	ft_clear_str(char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}

size_t	ft_findeol(char *line, char **eol)
{
	size_t	i;

	i = 0;
	*eol = NULL;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			*eol = &line[i];
			break ;
		}
		i++;
	}
	return (i);
}

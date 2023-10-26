/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:46:05 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/26 20:43:33 by javjimen         ###   ########.fr       */
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

int	ft_findeol(char *line, char *eol)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n' && (i + 1) < BUFFER_SIZE)
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		eol = &line[i];
	else
		eol = NULL;
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

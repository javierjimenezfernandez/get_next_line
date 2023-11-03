/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:46:19 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/03 14:40:10 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//static char	*old_buff = NULL;

char	*get_next_line(int fd);

/* AUX FUNCTIONS */
char	*ft_strncpy(char *dest, char *src, unsigned int n);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		ft_lentoeol(char *line, int *eol_flag);
//int		ft_findeol(char *line, char **eol, int buff_len);
int		ft_findeol(char *line, char **eol);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t count, size_t size);

#endif

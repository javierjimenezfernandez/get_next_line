/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:46:19 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/09 00:12:54 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OK
#  define OK 0
# endif
# ifndef ERROR
#  define ERROR -1
# endif

typedef struct s_buff
{
	int		fd;
	char	*content;
	size_t	prev_len;
	ssize_t	bytes_read;
	char	*eol;
	size_t	line_len;
}				t_buff;

typedef int	t_error;

char	*get_next_line(int fd);
t_error	ft_read_file(t_buff *buff, char *static_buff);
t_error	ft_extract_line(t_buff *buff, char *static_buff, char **line);
t_error	ft_resize_buffer(t_buff *buff, char *static_buff);
t_error	ft_get_line(t_buff *buff, char *static_buff, char **line);
size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t	ft_findeol(char *line, char **eol);
void	ft_clear_str(char *str, size_t size);

#endif

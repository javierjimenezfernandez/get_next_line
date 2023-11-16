/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:32:00 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/11 01:03:36 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef FD_MAX
#  define FD_MAX 1000
# endif

# define OK 0
# define ERROR 1

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

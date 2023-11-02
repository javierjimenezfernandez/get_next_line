/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:03:59 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/02 16:29:01 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stddef.h>
#include <stdio.h>
#include <fcntl.h>

/*size_t	ft_linelen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != '\n')
		len++;
	return (len);
}*/

void	ft_putline(char *line)
{
	int	i;

	i = 0;
	write(1, "line read = \"", 13);
	while (line[i] != '\0' && line[i] != '\n')
	{
		write(1, &line[i], 1);
		i++;
	}
	write(1, "\"", 1);
	write(1, &line[i], 1);
}

int	main(void)
{
	int		fd;
	char	*new_line;
	int		i;

	fd = open("test_file.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	new_line = get_next_line(fd);
	i = 4;
	while (i)
	{
		ft_putline(new_line);
		printf("---------\n\n");
		free(new_line);
		new_line = get_next_line(fd);
		i--;
	}
	ft_putline(new_line);
	printf("---------\n\n");
	close(fd);
	//system("leaks a.out");
	return (0);
}

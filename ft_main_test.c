/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:03:59 by javjimen          #+#    #+#             */
/*   Updated: 2023/11/03 16:41:09 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stddef.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*new_line;
	int		i;

	printf("\nTEST 1: EMPTY FILE\n-_-_-_-_-_-_-_-_-_-\n\n");
	fd = open("empty_file.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	new_line = get_next_line(fd);
	while (new_line)
	{
		printf("line read = \"%s\"\n", new_line);
		printf("---------\n\n");
		free(new_line);
		new_line = get_next_line(fd);
	}
	printf("line read = \"%s\"\n", new_line);
	printf("---------\n\n");
	close(fd);


	printf("\nTEST 2: NORMAL FILE\n-_-_-_-_-_-_-_-_-_-_-\n\n");
	fd = open("test_file_1.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	new_line = get_next_line(fd);
	while (new_line)
	{
		printf("line read = \"%s\"\n", new_line);
		printf("---------\n\n");
		free(new_line);
		new_line = get_next_line(fd);
	}
	printf("line read = \"%s\"\n", new_line);
	printf("---------\n\n");
	close(fd);

	printf("\nTEST 3: FILE WITHOUT \'\\n\' AT EOF\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
	fd = open("test_file_2.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	new_line = get_next_line(fd);
	while (new_line)
	{
		printf("line read = \"%s\"\n", new_line);
		printf("---------\n\n");
		free(new_line);
		new_line = get_next_line(fd);
	}
	printf("line read = \"%s\"\n", new_line);
	printf("---------\n\n");
	close(fd);

	printf("\nTEST 4: EMPTY FILE BUT CONTAINS 1 EMPTY LINE\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
	fd = open("test_file_3.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	new_line = get_next_line(fd);
	while (new_line)
	{
		printf("line read = \"%s\"\n", new_line);
		printf("---------\n\n");
		free(new_line);
		new_line = get_next_line(fd);
	}
	printf("line read = \"%s\"\n", new_line);
	printf("---------\n\n");
	close(fd);

	i = 2;
	printf("\nTEST 5: READ %d LINES FORM SCREEN (fd = 0)\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n", i);
	fd = 0;
	new_line = get_next_line(fd);
	while (--i)
	{
		printf("line read = \"%s\"\n", new_line);
		printf("---------\n\n");
		free(new_line);
		new_line = get_next_line(fd);
	}
	printf("line read = \"%s\"\n", new_line);
	printf("---------\n\n");

	//system("leaks a.out");
	return (0);
}

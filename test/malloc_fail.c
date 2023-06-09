/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_fail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:21:07 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/09 15:37:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

#define ERRO_MESS	"Usage: ./program filename\n"
#define ERRO_OPEN	"Error: Could not open file\n"

void	*malloc(size_t size)
{
	(void)size;
	return (NULL);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	printf("BUFFER_SIZE:%d\n\n", BUFFER_SIZE);
	if (ac != 2)
	{
		write(STDERR_FILENO, ERRO_MESS, 26);
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		write(STDERR_FILENO, ERRO_OPEN, 27);
		exit(EXIT_FAILURE);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line != NULL)
		{
			// do something
			printf("%s", line);
			free(line);
		}
	}
	if (line == NULL)
		printf("fail retrun NULL");
	printf("\n");
	close(fd);
	return (0);
}

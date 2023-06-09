/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:32:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/09 14:00:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"
#define ERRO_MESS	"Usage: ./program file1 file2 file3 file4\n"
#define ERRO_OPEN	"Error: Could not open file\n"

void	close_file(int ac, int fd[4])
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		close(fd[i]);
		i++;
	}
}

void	open_file(int ac, char **av, int fd[4])
{
	int		i;

	i = 0;
	while (i < ac - 1)
	{
		fd[i] = open(av[i + 1], O_RDONLY);
		if (fd[i] < 0)
		{
			write(STDERR_FILENO, ERRO_OPEN, strlen(ERRO_OPEN));
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		fd[4];
	char	*line;

	printf("BUFFER_SIZE:%d\n", BUFFER_SIZE);
	if (ac > 5)
	{
		write(STDERR_FILENO, ERRO_MESS, strlen(ERRO_MESS));
		exit(EXIT_FAILURE);
	}
	open_file(ac, av, fd);
//	while ((line = get_next_line(fd)) != NULL)
//	{
//		if (line != NULL)
//		{
//			// do something
//			printf("%s", line);
//			free(line);
//		}
//	}
	line = get_next_line(fd[0]);
	printf("fd[0]=%d : %s", fd[0], line);
	free(line);
	line = get_next_line(fd[1]);
	printf("fd[1]=%d : %s", fd[1], line);
	free(line);
	line = get_next_line(fd[2]);
	printf("fd[2]=%d : %s", fd[2], line);
	free(line);
	line = get_next_line(fd[3]);
	printf("fd[3]=%d : %s", fd[3], line);
	free(line);
	close_file(ac, fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:51:54 by kamitsui          #+#    #+#             */
/*   Updated: 2023/04/05 11:12:21 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <libc.h>//for __attribute
#include "get_next_line.h"
#define ERRO_MESS	"Usage: ./program filename\n"
#define ERRO_OPEN	"Error: Could not open file\n"

__attribute__((destructor)) static void destructor()
{
	system("leaks -q a.out");
}

char	*ft_newline(char **saved, int fd, int bytes_read);

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

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
	
	char	*saved[256];
	ssize_t	bytes_read;
	char	buf[BUFFER_SIZE];

	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		saved[fd] = ft_strdup(buf);
		line = ft_newline(saved, fd, bytes_read);
		if (line != NULL)
		{
			// do something
			printf("%s\n", line);
			free(line);
		}
	}
	free(saved[fd]);
	close(fd);
	destructor();
	return (0);
}

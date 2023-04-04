/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:46:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/04/04 22:20:35 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>//for check

char	*ft_newline(char **saved, int fd, int bytes_read)
{
	char	*temp;
	char	*line;
	int		len;

	if ((saved[fd] == NULL) && (bytes_read == 0))
		return (NULL);
	temp = strchr(saved[fd], '\n');
	if (temp != NULL)
	{
		len = temp - saved[fd] + 1;
		line = strndup(saved[fd], len);
//		line = strndup(saved[fd], len);
		temp = ft_strdup(temp + 1);
		free(saved[fd]);
		saved[fd] = temp;
	}
	else
	{
		line = ft_strdup(saved[fd]);
//		free(saved[fd]);
		saved[fd] = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved[256];
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = strdup(buffer);
//			saved[fd] = ft_strdup(buffer);
		else
		{
			tmp = strdup(buffer);
//			tmp = ft_strdup(buffer);
			free(saved[fd]);
			saved[fd] = tmp;
		}
		if (strchr(buffer, '\n'))
//		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (bytes_read == -1)
		return (NULL);
	if (bytes_read == 0 && saved[fd] == NULL)
		return (NULL);
	return (NULL);
//	return (ft_new_line(saved, fd, bytes_read));
}

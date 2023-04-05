/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:46:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/04/05 22:28:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "get_next_line.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	if (!maxlen)
		return (len);
	while (*s)
	{
		if (len == maxlen)
			break ;
		len++;
		s++;
	}
	return (len);
}

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*result;

	len = ft_strnlen(s1, n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	return (ft_memmove(result, s1, len));
}

char	*ft_newline(char **saved, int fd)
{
	char	*temp;
	char	*line;
	int		len;

	if (saved[fd] == NULL)
		return (NULL);
	temp = ft_strchr(saved[fd], '\n');
	if (temp != NULL)
	{
		len = temp - saved[fd] + 1;
		line = ft_strndup(saved[fd], len);
		temp = ft_strdup(temp + 1);
		free(saved[fd]);
		saved[fd] = temp;
	}
	else
	{
		if (!(*saved[fd] == '\0'))
			line = ft_strdup(saved[fd]);
		else
			line = NULL;
		free(saved[fd]);
		saved[fd] = NULL;
	}
	return (line);
}

ssize_t	search_newline(char **saved, char *buffer, ssize_t bytes_read, int fd)
{
	char	*str_temp;
	ssize_t	bytes_temp;

	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = ft_strdup(buffer);
		else
		{
			str_temp = ft_strjoin(saved[fd], buffer);
			free(saved[fd]);
			saved[fd] = str_temp;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_temp = read(fd, buffer, BUFFER_SIZE);
		if (bytes_temp < 0)
			return (bytes_temp);
		bytes_read = bytes_temp;
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	static char	*saved[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	bytes_read = search_newline(saved, buffer, bytes_read, fd);
	if (bytes_read == -1)
		return (NULL);
	if (bytes_read == 0 && saved[fd] == NULL)
		return (NULL);
	return (ft_newline(saved, fd));
}

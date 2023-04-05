/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:46:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/04/05 13:42:04 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>//for check

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

//char	*ft_substrline(char *str, char *str_nl)
//{
//	char	*line;
//	size_t	len;
//
//	if (str == NULL)
//		return (NULL);
//	len = str_nl - str;
//	line = ft_strndup(str, len);
//	if (line == NULL)
//		return (NULL);
//	str_nl = ft_strdup(str_nl + 1);
//	saved[fd] = ;
//}

char	*ft_newline(char **saved, int fd, int bytes_read)
{
	char	*temp;
	char	*line;
	int		len;

	if ((saved[fd] == NULL) && (bytes_read == 0))
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
		line = ft_strdup(saved[fd]);
		free(saved[fd]);
		saved[fd] = NULL;
	}
	return (line);
}

ssize_t	seach_nl(char **saved, char *buffer, ssize_t bytes_read, int fd)
{
	char	*str_tmp;
	ssize_t	bytes_tmp;

	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = ft_strdup(buffer);
		else
		{
			str_tmp = ft_strjoin(*saved, buffer);
			free(saved[fd]);
			saved[fd] = str_tmp;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_tmp = read(fd, buffer, BUFFER_SIZE);
		if (bytes_tmp < 0)
			return (bytes_tmp);
		else
			bytes_read = bytes_tmp;
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	static char	*saved[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	bytes_read = seach_nl(saved, buffer, bytes_read, fd);
	if (bytes_read == -1)
		return (NULL);
	if (bytes_read == 0 && saved[fd] == NULL)
		return (NULL);
	return (ft_newline(saved, fd, bytes_read));
}
//void code
//	char		buffer[BUFFER_SIZE + 1];
//	char		*tmp;
//	bytes_read = read(fd, buffer, BUFFER_SIZE);
//	while (bytes_read > 0)
//	{
//		buffer[bytes_read] = '\0';
//		if (saved[fd] == NULL)
//			saved[fd] = ft_strdup(buffer);
//		else
//		{
//			tmp = ft_strdup(buffer);
//			free(saved[fd]);
//			saved[fd] = tmp;
//		}
//		if (ft_strchr(buffer, '\n'))
//			break ;
//		bytes_read = read(fd, buffer, BUFFER_SIZE);
//	}

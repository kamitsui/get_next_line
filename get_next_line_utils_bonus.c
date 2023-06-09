/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:31:14 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/09 11:55:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s++))
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (1)
	{
		if (*s == ch)
			return ((char *)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return ((char *)0);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	int				d;

	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	if (dst == src || n == 0)
		return (dst);
	if (to > from)
	{
		to += n - 1;
		from += n - 1;
		d = -1;
	}
	else
		d = +1;
	while (n-- > 0)
	{
		*(unsigned char *)to = *(unsigned char *)from;
		to += d;
		from += d;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	return (ft_memmove(str, s, len));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (joined == NULL)
		return (NULL);
	ft_memmove(joined, s1, len1);
	ft_memmove(joined + len1, s2, len2 + 1);
	return (joined);
}

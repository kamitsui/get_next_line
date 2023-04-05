/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_fail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:21:07 by kamitsui          #+#    #+#             */
/*   Updated: 2023/04/05 10:26:02 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*malloc(size_t size)
{
	(void)size;
	return (NULL);
}

int	main(void)
{
//	int	result = ft_printf("\n");
//	if (result == -1)
//		printf("%d: does not abort OK\n", result);
	return (0);
}

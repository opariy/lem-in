/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:20:59 by opariy            #+#    #+#             */
/*   Updated: 2016/11/30 15:21:00 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*p;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == ((unsigned char)c))
			return (&p[i]);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:51:35 by opariy            #+#    #+#             */
/*   Updated: 2016/12/01 17:28:05 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*t;

	t = dst;
	if (src < dst)
	{
		src = src + len;
		dst = dst + len;
		while (len--)
			*(unsigned char *)--dst = *(const char *)--src;
	}
	else
		while (len--)
			*(unsigned char *)dst++ = *(const char *)src++;
	return (t);
}

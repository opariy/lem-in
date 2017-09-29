/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:45:26 by opariy            #+#    #+#             */
/*   Updated: 2016/12/03 15:45:28 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t c;

	i = 0;
	c = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + c] == little[c] && i + c < len)
		{
			c++;
			if (little[c] == '\0')
			{
				return ((char *)(big + i));
			}
		}
		c = 0;
		i++;
	}
	return (NULL);
}

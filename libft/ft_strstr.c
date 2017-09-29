/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:45:32 by opariy            #+#    #+#             */
/*   Updated: 2016/12/03 14:45:50 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] != '\0')
	{
		while (big[i + c] == little[c])
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

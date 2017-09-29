/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:21:53 by opariy            #+#    #+#             */
/*   Updated: 2016/12/05 17:21:55 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	sub = NULL;
	if (s != NULL)
	{
		if ((sub = malloc(len + 1)))
		{
			while (s[start] != '\0' && i < len)
			{
				sub[i] = s[start];
				start++;
				i++;
			}
			sub[i] = '\0';
		}
	}
	return (sub);
}

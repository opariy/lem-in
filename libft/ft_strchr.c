/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:09:11 by opariy            #+#    #+#             */
/*   Updated: 2016/12/03 13:09:13 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ((unsigned char)c))
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == ((unsigned char)c))
		return (&((char *)s)[i]);
	return (NULL);
}

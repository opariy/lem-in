/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:13:58 by opariy            #+#    #+#             */
/*   Updated: 2016/12/03 14:14:01 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		*p;

	i = 0;
	p = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == ((unsigned char)c))
			p = &((char *)s)[i];
		i++;
	}
	if (s[i] == ((unsigned char)c))
		return (&((char *)s)[i]);
	return (p);
}

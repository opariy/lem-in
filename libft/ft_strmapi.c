/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:29:37 by opariy            #+#    #+#             */
/*   Updated: 2016/12/05 16:29:40 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	i = 0;
	new_str = NULL;
	if (s != NULL)
	{
		if ((new_str = (char *)malloc(ft_strlen(s) + 1)))
		{
			while (s[i] != '\0')
			{
				new_str[i] = f(i, s[i]);
				i++;
			}
			new_str[i] = '\0';
		}
	}
	return (new_str);
}

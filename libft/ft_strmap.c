/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:49:52 by opariy            #+#    #+#             */
/*   Updated: 2016/12/05 15:49:54 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = NULL;
	if (s != NULL)
	{
		if ((new_str = (char *)malloc(ft_strlen(s) + 1)))
		{
			while (s[i] != '\0')
			{
				new_str[i] = f(s[i]);
				i++;
			}
			new_str[i] = '\0';
		}
	}
	return (new_str);
}

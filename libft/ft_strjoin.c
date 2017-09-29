/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:11:35 by opariy            #+#    #+#             */
/*   Updated: 2017/06/12 12:52:20 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		if ((s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		{
			while (s1[i] != '\0')
			{
				s[i] = s1[i];
				i++;
			}
			while (s2[j] != '\0')
			{
				s[i + j] = s2[j];
				j++;
			}
			s[i + j] = '\0';
		}
		return (s);
	}
	return (0);
}

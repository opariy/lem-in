/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:36:32 by opariy            #+#    #+#             */
/*   Updated: 2016/12/05 18:36:34 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*assign(char *str, char const *s, int i, int start)
{
	int		len;

	len = i - start + 1;
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static	int		check_front_spaces(char const *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
	{
		count++;
		i++;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		count;
	int		start;
	int		i;

	str = NULL;
	if (s != NULL)
	{
		count = check_front_spaces(s);
		if (count == (int)ft_strlen(s))
		{
			str = ft_strnew(0);
			return (str);
		}
		start = count;
		i = ft_strlen(s) - 1;
		while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
		{
			count++;
			i--;
		}
		if ((str = malloc(ft_strlen(s) - count + 1)))
			assign(str, s, i, start);
	}
	return (str);
}

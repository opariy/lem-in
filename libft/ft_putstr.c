/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:14:24 by opariy            #+#    #+#             */
/*   Updated: 2016/12/09 13:14:40 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

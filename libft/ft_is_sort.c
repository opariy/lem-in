/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:54:31 by opariy            #+#    #+#             */
/*   Updated: 2016/11/07 20:54:33 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	pos;
	int	neg;

	i = 0;
	neg = 0;
	pos = 0;
	while (i < (length - 1))
	{
		if (f(tab[i], tab[i + 1]) < 0)
			neg++;
		if (f(tab[i], tab[i + 1]) > 0)
			pos++;
		i++;
	}
	if ((pos == 0) || (neg == 0))
		return (1);
	return (0);
}

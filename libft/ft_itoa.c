/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:21:43 by opariy            #+#    #+#             */
/*   Updated: 2016/12/08 13:21:44 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*conver_to_string(char *nb, int len, int n, int sign)
{
	nb[len--] = '\0';
	while (n / 10 > 0)
	{
		nb[len] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	nb[len] = n % 10 + '0';
	if (sign == -1)
		nb[0] = '-';
	return (nb);
}

static	char	*weird_min_int(void)
{
	int		i;
	char	*str;
	char	*nb;

	i = 0;
	str = "-2147483648";
	if ((nb = malloc(12)))
	{
		while (i++ < 12)
			nb[i - 1] = str[i - 1];
		nb[i - 1] = '\0';
		return (nb);
	}
	else
		return (0);
}

char			*ft_itoa(int n)
{
	char	*nb;
	int		len;
	int		sign;
	int		tmp;

	len = 1;
	sign = 1;
	if (n == -2147483648)
		return (weird_min_int());
	if (n < 0)
	{
		sign = -1;
		len++;
	}
	n = n * sign;
	tmp = n;
	while (tmp / 10 > 0)
	{
		len++;
		tmp = tmp / 10;
	}
	if ((nb = malloc((len + 1))))
		conver_to_string(nb, len, n, sign);
	return (nb);
}

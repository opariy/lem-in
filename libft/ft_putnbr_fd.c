/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:01:03 by opariy            #+#    #+#             */
/*   Updated: 2016/12/10 14:01:07 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	rev[11];
	int		tempn;

	tempn = n;
	if (n == -2147483648)
		n = -214748364;
	i = 0;
	if (tempn < 0)
		n = -n;
	while ((n / 10) > 0)
	{
		rev[i] = n % 10 + '0';
		i++;
		n = n / 10;
	}
	rev[i] = n % 10 + '0';
	if (tempn < 0)
		rev[++i] = '-';
	while (i >= 0)
		ft_putchar_fd(rev[i--], fd);
	if (tempn == -2147483648)
		ft_putchar_fd('8', fd);
}

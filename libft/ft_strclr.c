/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:22:51 by opariy            #+#    #+#             */
/*   Updated: 2016/12/05 15:22:55 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			s[i] = '\0';
			i++;
		}
	}
}

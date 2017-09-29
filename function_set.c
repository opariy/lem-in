/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:06:39 by opariy            #+#    #+#             */
/*   Updated: 2017/09/04 17:06:41 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_number(char *str)
{
	int		i;
	int		len;

	len = -1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			len++;
		i++;
	}
	if (len == (int)ft_strlen(str) - 1)
		return (1);
	else
		return (0);
}

void	stop_validation(void)
{
	ft_putstr("ERROR\n");
	exit(0);
}

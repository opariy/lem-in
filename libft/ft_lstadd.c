/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:28:44 by opariy            #+#    #+#             */
/*   Updated: 2016/12/10 17:28:46 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *head;

	if (*alst == NULL)
	{
		*alst = new;
		(*alst)->next = NULL;
	}
	else
	{
		head = *alst;
		*alst = new;
		new->next = head;
	}
}

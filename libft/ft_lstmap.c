/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:52:51 by opariy            #+#    #+#             */
/*   Updated: 2016/12/12 16:52:53 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*header;

	new_list = NULL;
	if (lst == NULL)
		return (NULL);
	header = f(lst);
	new_list = header;
	while (lst->next)
	{
		new_list->next = f(lst->next);
		lst = lst->next;
		new_list = new_list->next;
	}
	return (header);
}

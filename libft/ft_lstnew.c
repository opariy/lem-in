/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:26:34 by opariy            #+#    #+#             */
/*   Updated: 2016/12/09 14:26:36 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if ((lst = (t_list *)malloc(sizeof(t_list))) != NULL)
	{
		if (content == NULL)
		{
			lst->content = NULL;
			lst->content_size = 0;
			return (lst);
		}
		if ((lst->content = malloc(content_size)))
			ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
		lst->next = NULL;
	}
	return (lst);
}

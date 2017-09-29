/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:51:01 by opariy            #+#    #+#             */
/*   Updated: 2017/09/21 17:51:03 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_links(t_request *request)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y < request->room_amount)
	{
		if (ft_strchr(request->matrix[y], '1'))
			x++;
		y++;
	}
	if (x == 0)
		return (0);
	else
		return (1);
}

t_links		*create_link(char *name, t_request *request)
{
	t_links		*head;

	head = (t_links *)malloc(sizeof(t_links));
	if (head)
	{
		head->room_digit = get_coresp_digit(request, name);
		head->name = ft_strdup(name);
		head->ant = 0;
		head->next = NULL;
	}
	return (head);
}

void	add_link(char *c, t_links **links, t_request *request)
{
	t_links *current;

	current = *links;
	if (*links == NULL)
		*links = create_link(c, request);
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = create_link(c, request);
		current = current->next;
	}
}

t_links		*fing_link_by_digit(t_links *links, int a)
{
	t_links *l;

	l = links;
	while (l)
	{
		if (l->room_digit == a)
			return (l);
		l = l->next;
	}
	return (NULL);
}

t_links		*find_link_by_pos(t_links *links, int a, t_request *request)
{
	t_links *l;

	l = links;
	if (a == 0)
		return (links);
	else if (a == 2)
	{
		while (l)
		{
			if (find_room_by_digit(request->room_list, l->room_digit)->pos == a)
				return (l);
			l = l->next;
		}
	}
	return (NULL);
}

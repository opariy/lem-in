/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 10:36:21 by opariy            #+#    #+#             */
/*   Updated: 2017/09/22 10:36:23 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 			find_room_by_name(char *name, t_room_list *room_list)
{
	t_room_list		*begin;

	begin = room_list;
	while(begin->next)
	{
		if (ft_strcmp(begin->name, name) == 0)
			return (1);
		else
			begin = begin->next;
	}
	if (ft_strcmp(begin->name, name) == 0)
		return (1);
	else
		return (0);
}

int				find_end_start(t_room_list *room_list, int pos)
{
	t_room_list		*begin;
	int				result;

	result = 0;
	begin = room_list;
	while (begin->next)
	{
		if (begin->pos == pos)
			result++;
		begin = begin->next;
	}
	if (begin->pos == pos)
		result++;
	if (result == 0)
		return (0);
	else if (result == 1)
		return (1);
	else if (result == 2)
		return (2);
	return (0);
}

int				add_room(t_room_list **head, char *name, int x, int y, int pos)
{
	t_room_list	*current;
	int			room_amount;

	room_amount = 0;
	current = *head;
	if (!*head)
	{
		*head = create_el(name, x, y, pos);
		room_amount++;
	}
	else
	{
		while (current->next)
		{
			if (((current->x == x) && (current->y == y)) || (ft_strcmp(current->name, name) == 0))
				stop_validation();
			current = current->next;
		}
		if ((current->x == x) && (current->y == y))
			stop_validation();
		if (ft_strcmp(current->name, name) == 0)
			stop_validation();
		current->next = create_el(name, x, y, pos);
		room_amount++;
	}
	return (room_amount);
}

t_room_list		*find_room_by_digit(t_room_list *room_list, int digit_name)
{
	t_room_list		*begin;

	begin = room_list;
	while (begin)
	{
		if (begin->room_digit_name == digit_name)
			return (begin);
		begin = begin->next;
	}
	return (NULL);
}

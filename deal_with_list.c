/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 14:25:42 by opariy            #+#    #+#             */
/*   Updated: 2017/09/04 14:25:43 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_if_ends_connected(t_request *r, t_room_list *lst, int pos)
{
	t_room_list		*begin;
	int				room_digit_name;

	room_digit_name = -1;
	begin = lst;
	while (begin)
	{
		if (begin->pos == pos)
			room_digit_name = begin->room_digit_name;
		begin = begin->next;
	}
	if (room_digit_name == -1)
		stop_validation();
	if (ft_strstr(r->matrix[room_digit_name], "1"))
		return (1);
	else
		stop_validation();
	return (0);
}

int			get_coresp_digit(t_request *request, char *name)
{
	t_room_list		*begin;

	begin = request->room_list;
	while (begin->next)
	{
		if (ft_strcmp(begin->name, name) == 0)
			return (begin->room_digit_name);
		begin = begin->next;
	}
	if (ft_strcmp(begin->name, name) == 0)
		return (begin->room_digit_name);
	return (0);
}

void		set_vars(t_room_list *begin, int included, int comp, int digit)
{
	begin->included = included;
	begin->complexity = comp;
	begin->room_digit_name = digit;
}

void		set_digit_names(t_room_list *room_list, int amount)
{
	t_room_list		*begin;
	int				num;

	num = 1;
	begin = room_list;
	while (begin->next)
	{
		if (begin->pos == 0)
			set_vars(begin, 0, 0, 0);
		else if (begin->pos == 2)
			set_vars(begin, 1, -1, amount - 1);
		else
		{
			set_vars(begin, 0, -1, num);
			num++;
		}
		begin = begin->next;
	}
	if (begin->pos == 0)
		set_vars(begin, 0, 0, 0);
	else if (begin->pos == 2)
		set_vars(begin, 1, -1, amount - 1);
	else
		set_vars(begin, 0, -1, num);
}

t_room_list	*create_el(char *name, int x, int y, int pos)
{
	t_room_list		*head;

	head = (t_room_list *)malloc(sizeof(t_room_list));
	if (head)
	{
		head->name = name;
		head->x = x;
		head->y = y;
		head->pos = pos;
		head->next = NULL;
	}
	return (head);
}

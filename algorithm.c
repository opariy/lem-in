/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 12:01:17 by opariy            #+#    #+#             */
/*   Updated: 2017/09/13 12:01:19 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_path(int digit_of_room, t_request *request)
{
	int 	room_digit;
	int 	comp_1;
	int 	comp_2;
	char 	*tmp;

	if (find_room_by_digit(request->room_list, digit_of_room)->pos == 2 && request->current == NULL)
	{
		request->current = create_path();
		tmp = request->current->path;
		request->current->path = ft_strjoin(tmp, (find_room_by_digit(request->room_list, request->room_amount -1))->name);
		ft_memdel((void **)&tmp);
		tmp = request->current->path;
		request->current->path = ft_strjoin(tmp, " ");
		ft_memdel((void **)&tmp);
	}
	comp_1 = find_room_by_digit(request->room_list, digit_of_room)->complexity;
	room_digit = find_min(request->room_list, request->matrix[digit_of_room]);
	if (room_digit != -1)
	{
		comp_2 = find_room_by_digit(request->room_list, room_digit)->complexity;
		if ((comp_2 >= comp_1) && (comp_1 != -1))
		{
			ft_memdel((void **)&request->current->path);
			ft_memdel((void **)&(request->current));
			return (0);
		}

		if (find_room_by_digit(request->room_list, room_digit)->pos != 0)
		{
			find_room_by_digit(request->room_list, room_digit)->included = 1;
			tmp = request->current->path;
			request->current->path = ft_strjoin(tmp, find_room_by_digit(request->room_list, room_digit)->name);
			ft_memdel((void **)&tmp);
			tmp = request->current->path;
			request->current->path = ft_strjoin(tmp, " ");
			ft_memdel((void **)&tmp);
			if (!find_path(room_digit, request))
				return (0);
		}
		else
		{
			tmp = request->current->path;
			request->current->path = ft_strjoin(tmp, find_room_by_digit(request->room_list, room_digit)->name);
			ft_memdel((void **)&tmp);
			push_back(&(request->path), request->current->path, count_compl(request->current->path));
			ft_memdel((void **)&(request->current));
			if (request->room_amount != 2) {

				find_path(request->room_amount - 1, request);
			}
		}
	}
	else
	{
		ft_memdel((void **)&(request->current->path));
		ft_memdel((void **)&(request->current));
		request->current = NULL;
		return (0);
	}
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&(request->current));
	return (1);
}

void	recursion(t_path *path, t_links *prev, t_links *cur, int ant)
{
	if (cur)
	{
		recursion(path, cur, cur->next, ant);
		if (prev)
		{
			if (fing_link_by_digit(path->links, cur->room_digit)->ant && fing_link_by_digit(path->links, prev->room_digit)->ant)
				fing_link_by_digit(path->links, cur->room_digit)->ant = 0;
			if (!fing_link_by_digit(path->links, cur->room_digit)->ant && fing_link_by_digit(path->links, prev->room_digit)->ant)
			{
				fing_link_by_digit(path->links, cur->room_digit)->ant = fing_link_by_digit(path->links, prev->room_digit)->ant;
				fing_link_by_digit(path->links, prev->room_digit)->ant = 0;
				ft_putstr("L");
				ft_putnbr(fing_link_by_digit(path->links, cur->room_digit)->ant);
				ft_putstr("-");
				ft_putstr(cur->name);
				ft_putstr(" ");
			}
		}
		else
		{
			fing_link_by_digit(path->links, cur->room_digit)->ant = ant;
			if (ant != 0)
			{
				ft_putstr("L");
				ft_putnbr(fing_link_by_digit(path->links, cur->room_digit)->ant);
				ft_putstr("-");
				ft_putstr(cur->name);
			}
		}
	}
}

void 	alorithm(t_request *request)
{
	int 	i;

	i = 0;
	request->current = NULL;
	request->path = NULL;
	while (request->matrix[request->room_amount - 1][i] != '\0') {
		if (request->matrix[request->room_amount - 1][i] == '1') {
			find_path(request->room_amount - 1, request);
		}
		i++;

	}
	split_paths(request);
	if (request->path)
	{
		print_paths(request);
		if (request->room_amount == 2)
			printf("\n");
	}
	else
	{
		printf("HELo\n");
		stop_validation();
	}

}
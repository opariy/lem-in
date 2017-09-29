/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 18:04:29 by opariy            #+#    #+#             */
/*   Updated: 2017/09/03 18:04:31 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	count_chars(char *str, char c)
{
	int 	i;
	int 	s;

	s = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			s++;
		i++;
	}
	return (s);
}

int 	check_if_link(char *str, t_request *request)
{
	char 	**link_arr;
	int 	i;

	i = 0;
	if (request->ant_amount == 0)
		stop_validation();
	else if (request->room_amount == 0)
		stop_validation();
	if ((link_arr = ft_strsplit(str, '-')))
	{
		while (link_arr[i])
			i++;
		if (i == 2)
		{
			if (count_chars(str, '-') != 1)
				stop_validation();
			set_digit_names(request->room_list, request->room_amount);
			if (find_room_by_name(link_arr[0], request->room_list) && find_room_by_name(link_arr[1], request->room_list))
			{
				change_matrix(request, link_arr[0], link_arr[1]);
				ft_memdel((void **)&link_arr[0]);
				ft_memdel((void **)&link_arr[1]);
				free(link_arr);
			}
			else
			{
				ft_memdel((void **)&link_arr[0]);
				ft_memdel((void **)&link_arr[1]);
				free(link_arr);
				stop_validation();
			}
			return (1);
		}
	}
	return (0);
}

int		check_if_room(char *str, t_request *request, int pos)
{
	char 	**room_arr;
	int 	i;

	i = 0;
	room_arr = ft_strsplit(str, ' ');
	if (request->ant_amount == 0)
		stop_validation();
	if ((room_arr[1]))
	{
		if (count_chars(str, ' ') != 2)
			stop_validation();
		while (room_arr[i])
			i++;
		if ((i == 3) && (room_arr[0][0] != 'L'))
		{
			if (is_number(room_arr[1]) && is_number(room_arr[2]))
			{
				request->room_amount = request->room_amount + add_room(&(request->room_list), room_arr[0], ft_atoi(room_arr[1]), ft_atoi(room_arr[2]), pos);
				ft_memdel((void **) &room_arr[1]);
				ft_memdel((void **) &room_arr[2]);
				free(room_arr);
				return (1);
			}
			else
			{
				ft_memdel((void **) &room_arr[1]);
				ft_memdel((void **) &room_arr[2]);
				free(room_arr);
				stop_validation();
			}
		}
		else
		{
			ft_memdel((void **) &room_arr[1]);
			ft_memdel((void **) &room_arr[2]);
			free(room_arr);
			stop_validation();
		}
	}
	else
	{
		ft_memdel((void **) &room_arr[0]);
		free(room_arr);
		return (0);
	}
	return (0);
}

int 	check_comment(char *str, t_request *request, char **task, int y)
{
	if (ft_strcmp(str, "##start") == 0)
	{
		y++;
		if (!task[y])
			stop_validation();
		while (task[y])
		{
			if (ft_strcmp(task[y], "##start") && ft_strcmp(task[y], "##end") && (task[y][0] == '#'))
				y++;
			else if (check_if_room(task[y], request, 0) == 0)
				stop_validation();
			else
				return (y);
		}
	}
	else if (ft_strcmp(str, "##end") == 0)
	{
		y++;
		if (!task[y])
			stop_validation();
		while (task[y])
		{
			if (ft_strcmp(task[y], "##start") && ft_strcmp(task[y], "##end") && (task[y][0] == '#'))
				y++;
			else if (check_if_room(task[y], request, 2) == 0)
				stop_validation();
			else
				return (y);
		}
	}
	return (y);
}

void 	validation(char **task, t_request *request)
{
	int 			y;

	request->room_list = NULL;
	request->matrix_created = 0;
	request->ant_amount = 0;
	y = 0;
	while (task[y])
	{
		if ((ft_atoi(task[y]) >= 0) && (request->ant_amount == 0) && (ft_strchr(task[y], ' ') == 0) && (ft_strchr(task[y], '-') == 0) && is_number(task[y]))
			request->ant_amount = ft_atoi(task[y]);
		else if (task[y][0] == '#')
			y = check_comment(task[y], request, task, y);
		else if ((ft_strchr(task[y], ' ') == 0) && (ft_strchr(task[y], '-') == 0))
			stop_validation();
		else if (check_if_room(task[y], request, 1) == 0)
		{
			if (request->matrix_created == 0)
				request->matrix = create_matrix(request);
			if ((request->room_amount))
				check_if_link(task[y], request);
		}
		y++;
	}
	if (request->room_amount == 0)
		stop_validation();
	if (request->matrix_created)
	{
		check_if_ends_connected(request, request->room_list, 0);
		check_if_ends_connected(request, request->room_list, 2);
	}
	if (request->matrix_created == 0)
		stop_validation();
	if (find_end_start(request->room_list, 0) == 0)
		stop_validation();
	if (find_end_start(request->room_list, 2) == 0)
		stop_validation();
	if (find_end_start(request->room_list, 0) == 2)
		stop_validation();
	if (find_end_start(request->room_list, 2) == 2)
		stop_validation();
	if (request->matrix_created)
	{
		if ((request->room_amount == 0) || check_links(request) == 0)
			stop_validation();
	}
}

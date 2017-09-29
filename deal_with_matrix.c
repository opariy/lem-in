/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:30:26 by opariy            #+#    #+#             */
/*   Updated: 2017/09/06 16:30:27 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	find_min(t_room_list *room_list, char *str)
{
	int 	i;
	int 	min_com;
	int 	room_digit;

	min_com = -1;
	room_digit = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
		{
			if ((min_com == -1) && (find_room_by_digit(room_list, i)->included == 0) && ((find_room_by_digit(room_list, i)->pos != 2)))
			{
				room_digit = i;
				min_com = find_room_by_digit(room_list, i)->complexity;
			}
			else if ((find_room_by_digit(room_list, i)->complexity < min_com) && (find_room_by_digit(room_list, i)->included == 0))
			{
				min_com = find_room_by_digit(room_list, i)->complexity;
				room_digit = i;
			}
		}
		i++;
	}
	return (room_digit);
}

int 	count_compl(char *str)
{
	int 	i;
	int 	comp;

	i = 0;
	comp = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			comp++;
		i++;
	}
	return (comp);
}

char		**create_matrix(t_request *request)
{
	int		x;
	int		y;
	char	**matrix;

	y = 0;
	matrix = (char **)malloc(sizeof(char *) * request->room_amount + 1);
	while (y < request->room_amount)
	{
		matrix[y] = (char *)malloc(sizeof(char) * request->room_amount + 1);
		x = 0;
		while (x < request->room_amount)
		{
			matrix[y][x] = '0';
			x++;
		}
		matrix[y][x] = '\0';
		y++;
	}
	matrix[y] = NULL;
	request->matrix_created = 1;
	return (matrix);
}

void		change_matrix(t_request *request, char *name1, char *name2)
{
	int		x;
	int		y;
	int		a;
	int		b;

	y = 0;
	a = get_coresp_digit(request, name1);
	b = get_coresp_digit(request, name2);
	while (y < request->room_amount)
	{
		x = 0;
		while (x < request->room_amount)
		{
			if (((y == a) && (x == b)) || ((x == a) && (y == b)))
			{
				request->matrix[y][x] = '1';
				request->matrix[x][y] = '1';
			}
			x++;
		}
		y++;
	}
}

void		assign_complexity(char *str, t_request *request, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' &&
				(find_room_by_digit(request->room_list, i)->complexity == -1 ||
					find_room_by_digit(request->room_list, i)->complexity > c)
			&& (find_room_by_digit(request->room_list, i)->pos != 2))
		{
			find_room_by_digit(request->room_list, i)->complexity = c;
			assign_complexity(request->matrix[i], request, c + 1);
		}
		i++;
	}
}

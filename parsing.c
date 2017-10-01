/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:01:32 by opariy            #+#    #+#             */
/*   Updated: 2017/09/29 11:01:34 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_end(t_request *request)
{
	int		i;
	int		c;
	int		n;

	n = 0;
	i = 0;
	c = 0;
	while (request->matrix[request->room_amount - 1][i] != '\0')
	{
		if (request->matrix[request->room_amount - 1][i] == '1')
		{
			n++;
			if (find_room_by_digit(request->room_list, i)->complexity == -1)
				c++;
		}
		i++;
	}
	if (c == n)
		return (0);
	else
		return (1);
}

char	**read_from_output(void)
{
	char	*line;
	size_t	i;
	char	**map;

	map = (char**)malloc(sizeof(char*) * 10000000 + 1);
	line = ft_strnew(0);
	i = 0;
	while (get_next_line(0, &line, ft_strnew(0)) > 0)
	{
		map[i] = ft_strdup(line);
		ft_memdel((void **)&line);

	}
	ft_memdel((void **)&line);
	map[i] = NULL;
	if (ft_strcmp(input_str, "") == 0)
		stop_validation();
	return (map);
}

int		main(void)
{
	char		**map;
	t_request	*request;

	request = (t_request *)malloc(sizeof(t_request));
	map = read_from_output();
//	while (1);
	validation(map, request);
	find_room_by_digit(request->room_list, 0)->complexity = 0;
	assign_complexity(request->matrix[0], request, 1);
	if (check_end(request) == 0)
	{
		stop_validation();
	}
	//	while (map[i])
//	{
//		ft_putstr(map[i]);
//		ft_putstr("\n");
//		i++;
//	}
//	ft_putstr("\n");
//	while (1);
	alorithm(request);
//	while (1);
}

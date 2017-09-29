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
	char	*input_str;
	char	**map;
	char	*tmp;

	input_str = ft_strnew(0);
	line = ft_strnew(0);
	tmp = NULL;
	int fd = open("map1.txt", O_RDONLY);
	while (get_next_line(fd, &line, ft_strnew(0)) > 0)
//	while (get_next_line(0, &line, ft_strnew(0)) > 0)
	{
//		printf("now here\n");
		if (strcmp(line, "") == 0)
		{
//			ft_memdel((void **)&line);
//			while (1);
			stop_validation();
		}
		tmp = input_str;
		input_str = ft_strjoin(tmp, line);
		ft_memdel((void **)&tmp);
		tmp = input_str;
		input_str = ft_strjoin(tmp, "\n");
		ft_memdel((void **)&tmp);
		ft_memdel((void **)&line);

	}
//	while (1);
//	printf("here we go\n");
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&line);
	if (ft_strcmp(input_str, "") == 0)
	{
		while (1);
		stop_validation();
	}
	map = ft_strsplit(input_str, '\n');
	ft_memdel((void **)&input_str);
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

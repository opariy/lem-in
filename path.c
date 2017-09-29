/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:46:53 by opariy            #+#    #+#             */
/*   Updated: 2017/09/21 17:46:55 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_paths(t_request *request)
{
	int		i;
	t_path	*p;

	i = 1;
	while (i <= request->ant_amount)
	{
		p = request->path;
		while (p)
		{
			if (p == request->path || p->length < request->ant_amount - i + 1)
			{
				recursion(p, NULL, p->links, i);
				i++;
			}
			else
				recursion(p, NULL, p->links, 0);
			p = p->next;
		}
		printf("\n");
	}
	p = request->path;
	while (1)
	{
		if (find_link_by_pos(p->links, 2, request)->ant != request->ant_amount)
		{
			recursion(p, NULL, p->links, 0);
			ft_putstr("\n");
			i--;
		}
		else
			break ;
	}
}

char	**reverse_arr(char **arr)
{
	int		i;
	int		len;
	char	**rev;

	i = 0;
	while (arr[i])
		i++;
	len = i - 1;
	rev = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (arr[i])
	{
		rev[len] = ft_strdup(arr[i]);
		i++;
		len--;
	}
	rev[i] = NULL;
	return (rev);
}

void	split_paths(t_request *request)
{
	t_path	*p;
	char	**rooms_c;
	int		i;
	char	**arr;

	p = request->path;
	while (p)
	{
		i = 0;
		p->links = NULL;
		arr = ft_strsplit(p->path, ' ');
		rooms_c = reverse_arr(arr);
		ft_free_bidarr((void **)arr);
		while (rooms_c[i])
		{
			if (find_room_by_digit(request->room_list, get_coresp_digit(request,rooms_c[i]))->pos != 0)
				add_link(rooms_c[i], &p->links, request);
			i++;
		}
		ft_free_bidarr((void**)rooms_c);
		p = p->next;
	}
}

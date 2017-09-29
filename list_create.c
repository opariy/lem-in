/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:10:22 by opariy            #+#    #+#             */
/*   Updated: 2017/09/29 17:10:23 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		push_back(t_path **begin_list, char *path, int length)
{
	t_path *current;

	current = *begin_list;
	if (*begin_list == NULL)
		*begin_list = create_elem(path, length);
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = create_elem(path, length);
	}
}

t_path		*create_elem(char *path, int length)
{
	t_path *head;

	head = malloc(sizeof(t_path));
	if (head != NULL)
	{
		head->next = NULL;
		head->path = path;
		head->length = length;
	}
	return (head);
}

t_path		*create_path(void)
{
	t_path	*new;

	new = (t_path *)malloc(sizeof(t_path));
	new->path = ft_strnew(0);
	new->length = 0;
	new->next = NULL;
	return (new);
}

size_t		ft_bidlen(void **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void		ft_free_bidarr(void **arr)
{
	size_t		i;
	size_t		len;

	len = ft_bidlen(arr);
	i = 0;
	while (i < len)
	{
		ft_memdel(&arr[i]);
		i++;
	}
	free(arr);
}

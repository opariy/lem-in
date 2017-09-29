/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:33:29 by opariy            #+#    #+#             */
/*   Updated: 2017/06/23 14:34:12 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



int get_next_line(const int fd, char **line, char *str)
{
	static char		*tail = NULL;
	char 			buf[BUFF_SIZE + 1];
	int				n;
	int				i;

	i = 0;
	buf[BUFF_SIZE] = '\0';
	if (!tail)
		tail = ft_strnew(0);
	while ((n = read(fd, buf, BUFF_SIZE)) >= 0)
	{
		if (n < BUFF_SIZE)
		{
			while (i < BUFF_SIZE - n)
			{
				buf[n + i] = '\0';
				i++;
			}
		}
		i = 0;
		ft_memdel((void **) &str);
		str = tail;
		tail = ft_strjoin(tail, buf);
		if (ft_strchr(tail, '\n'))
		{
			ft_memdel((void **)line);
			*line = ft_strsub(tail, 0, ft_strchr(tail, '\n') - tail);
			ft_memdel((void **)&tail);
			ft_memdel((void **) &str);
			return 1;
		}
		if (!n && !tail[0])
		{
			ft_memdel((void **) &str);
			ft_memdel((void **)line);
			*line = ft_strnew(0);
			return (0);
		}
		if (n == 0)
		{
//			printf("OLAOALA!\n");
			ft_memdel((void **) &str);
			ft_memdel((void **)line);
			*line = ft_strdup(tail);
			tail[0] = 0;
			return (1);
		}
	}
	return (-1);
}

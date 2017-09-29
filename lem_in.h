/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 09:33:40 by opariy            #+#    #+#             */
/*   Updated: 2017/09/13 09:33:42 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <fcntl.h>
# include "libft/libft.h"
# include <unistd.h>
# define BUFF_SIZE 1

typedef	 struct		s_room_list
{
	int 				x;
	int 				y;
	char 				*name;
	int 				room_digit_name;
	int 				pos;
	int 				complexity;
	int 				included;
	struct s_room_list	*next;

}					t_room_list;

typedef struct 		s_links
{
	int 			room_digit;
	char 			*name;
	int 			ant;
	struct s_links	*next;
}					t_links;

typedef struct 		s_path
{
	char 			*path;
	int 			length;
	t_links			*links;
	struct 	s_path	*next;

}					t_path;

typedef struct 		s_request
{
	int 			room_amount;
	char 			**matrix;
	int 			matrix_created;
	t_room_list		*room_list;
	int 			ant_amount;
	t_path			*path;
	t_path			*current;
}					t_request;

int				find_min(t_room_list *room_list, char *str);
int 			count_compl(char *str);
void			ft_free_bidarr(void **arr);
void			recursion(t_path *path, t_links *prev, t_links *cur, int ant);
int 			get_next_line(const int fd, char **line, char *str);
void			print_paths(t_request *request);
void			split_paths(t_request *request);
void			push_back(t_path **begin_list, char *path, int length);
t_path			*create_elem(char *path, int length);
t_path			*create_path(void);
t_links			*create_link(char *name, t_request *request);
void			add_link(char *c, t_links **links, t_request *request);
t_links			*fing_link_by_digit(t_links *links, int a);
t_links			*find_link_by_pos(t_links *links, int a, t_request *request);
int 			is_number(char *str);
void			stop_validation(void);
void			change_matrix(t_request *request, char *name1, char *name2);
char			**create_matrix(t_request *request);
int 			check_links(t_request *request);
int				add_room(t_room_list **head, char *name, int x, int y, int pos);
void			set_digit_names(t_room_list *room_list, int amount);
int 			find_room_by_name(char *name, t_room_list *room_list);
int 			find_end_start(t_room_list *room_list, int pos);
void 			validation(char **task, t_request *request);
int 			get_coresp_digit(t_request *request, char *name);
int 			check_if_ends_connected(t_request *request, t_room_list *room_list, int pos);
void 			alorithm(t_request *request);
void			assign_complexity(char *str, t_request *request, int c);
t_room_list		*find_room_by_digit(t_room_list *room_list, int digit_name);
t_room_list		*create_el(char *name, int x, int y, int pos);
int 			check_end(t_request *request);


#endif

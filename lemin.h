#ifndef LEMIN_H
# define LEMIN_H
#define EXITMSG (exit(write(2, "ERROR\n", 6)))

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct  s_data 
{
	int					fd;
    int					ants;
    char				*line;
	int					roomtype;
	int					start;
	int					end;
	int					connect;
}               t_data;

typedef	struct			s_roomlist
{
	struct s_roomlist	**link;
	char				*name;
	int					type;
	int					x;
	int					y;
	int					step;
	int					use;
	char				*from;
	struct s_roomlist	*next;
}						t_roomlist;

typedef struct			s_road
{
	char				*nameroom;
	int					tg;
	int					ant_room;
	struct s_road		*next;
}						t_road;

void ft_room(t_data *data,  t_roomlist **head);
void ft_link(t_data *data, t_roomlist **head);
void ft_bfs(t_roomlist **head);

#endif
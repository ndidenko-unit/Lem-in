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
}               t_data;

#endif
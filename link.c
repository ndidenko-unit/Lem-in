#include "lemin.h"

int ft_findconnect(t_roomlist **tmp0, t_roomlist **tmp1, char **vertex, t_data *data)
{
    data->connect = 0;
    while (*tmp0)
    {
        if (ft_strcmp(vertex[0], (*tmp0)->name) == 0)
        {
            data->connect++;
            while(*tmp1)
            {
                if (ft_strcmp(vertex[1], (*tmp1)->name) == 0)
                {
                    data->connect++;
                    break;
                } 
                *tmp1 = (*tmp1)->next;
            }
            if (!(*tmp0) || !(*tmp1))
                EXITMSG;
            else
                return(1);
        }
        *tmp0 = (*tmp0)->next;
    }
    return(0);
}

void ft_savelink(t_roomlist *tmp0, t_roomlist *tmp1)
{
    t_roomlist **buffer;
    int i;

    i = 0;
    if(tmp0->link == 0)
        tmp0->link = (t_roomlist**)malloc(sizeof(t_roomlist*) * 2);
    else
    {
        while(tmp0->link[i])
            i++;
        buffer = (t_roomlist**)malloc(sizeof(t_roomlist*) * (i + 2));
        i = 0;
        while (tmp0->link[i])
	    {
		    buffer[i] = tmp0->link[i];
		    i++;
	    }
	    free(tmp0->link);
	    tmp0->link = buffer;
    }
	tmp0->link[i] = tmp1;
	tmp0->link[i + 1] = 0;
}

void ft_link(t_data *data, t_roomlist **head)
{
    char **vertex;
    t_roomlist *tmp0;
    t_roomlist *tmp1;
    // printf("--ggg---");
    tmp0 = *head;
	tmp1 = *head;
    vertex = ft_strsplit(data->line, '-');
    if(ft_findconnect(&tmp0, &tmp1, vertex, data))
    {
        ft_savelink(tmp0, tmp1);
        ft_savelink(tmp1, tmp0);
    }
    if (data->connect != 2)
        EXITMSG;
    ft_putstr(data->line);
	write(1, "\n", 1);
    
}
#include "lemin.h"

t_roomlist *ft_createroom(void)
{
    t_roomlist *newroom;
    newroom = (t_roomlist*)malloc(sizeof(t_roomlist));
    ft_memset(newroom, 0, sizeof(t_roomlist));
    newroom->next = NULL;
    return(newroom);
}

void ft_room(t_data *data, t_roomlist **head)
{
    t_roomlist *newroom;
    t_roomlist *tmproom;
    char **splitroom;
    
    newroom = ft_createroom();
    newroom->type = data->roomtype;
    data->roomtype = 0;
    splitroom = ft_strsplit(data->line, ' ');
    newroom->name = ft_strdup(splitroom[0]);
    newroom->x = atoi(splitroom[1]);
    newroom->y = atoi(splitroom[2]);
    if (!(*head)) // addback
    {
        *head = newroom;
        return;
    }
    tmproom = *head;
    while(tmproom->next != NULL)
        tmproom = tmproom->next;
    tmproom->next = newroom;  
}
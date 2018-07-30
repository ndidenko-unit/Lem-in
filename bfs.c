#include "lemin.h"

static t_road *ft_createroad(void)
{
    t_road *newroad;

    newroad = (t_road*)malloc(sizeof(t_road));
    ft_memset(newroad, 0, sizeof(t_road));
    newroad->next = NULL;
    return(newroad);
}

static void ft_start_queue(t_roomlist *tmp, t_road **start_queue)
{
    t_road *new_road;
    int i;
    
    i = 1;
    while(tmp->type != 1)
        tmp = tmp->next;
    tmp->use = 1;
    if (!tmp->link)
        EXITMSG;
    new_road = ft_createroad();
    *start_queue = new_road;
    new_road->nameroom = tmp->link[0]->name;
    tmp->link[0]->from = tmp->name;
    while(tmp->link[i])
    {
        new_road->next = ft_createroad();
        new_road = new_road->next;
		new_road->nameroom = tmp->link[i]->name;
        tmp->link[i]->from = tmp->name;
		i++;
    }
}

void ft_bfs(t_roomlist **head)
{
    t_roomlist *tmp;
    t_road *start_queue;

    tmp = *head;
    ft_start_queue(tmp, &start_queue);

}
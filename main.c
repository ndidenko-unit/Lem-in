#include "lemin.h"

static void ft_init(t_data *data)
{
    data->fd = 0;
    data->ants = 0;
    data->line = 0;
    data->roomtype = 0;
    data->start = 0;
    data->end = 0;
    data->connect = 0;
}

 static void ft_parsants(t_data *data)
{
    char *tmp;

    tmp = data->line;
    data->ants = ft_atoi(data->line);
    while(*(data->line))
    {
        if (ft_isdigit(*(data->line)))
            (data->line)++;
        else
            EXITMSG;
    }
    ft_putnbr(data->ants);
    write(1, "\n", 1);
    free(tmp);
}

static void ft_parscommand (t_data *data)
{
    int len;

    len = ft_strlen(data->line);
    if (len == 1 || (len > 1 && data->line[1] != '#'))
        ;
    else if (ft_strcmp(data->line, "##start") == 0)
    {
        if (data->start == 1)
            EXITMSG;
        data->start++;
        data->roomtype = 1;
    }
    else if (ft_strcmp(data->line, "##end") == 0)
    {
        if (data->end == 1)
            EXITMSG;
        data->end++;
        data->roomtype = 2;
    }
    else
        EXITMSG;
    ft_putstr(data->line);
    write(1, "\n", 1);
    free(data->line);
}

void ft_parsing(t_data *data, t_roomlist **head)
{
    while (get_next_line(data->fd, &data->line))
    {
        if (data->ants == 0 && data->line != 0 && ft_isdigit(data->line[0]))
            ft_parsants(data);
        else if (data->line != 0 && data->line[0] == '#')
            ft_parscommand(data);
        else if (data->line != 0 && data->line[0] != '#' && data->line[0] != 'L' 
                    && ft_validroom(data->line) && ft_cw(data->line) == 3)
            ft_room(data, head);
        else if (data->line != 0 && data->line[0] != 'L' && ft_validlink(data->line))
            ft_link(data, head);
        else
            EXITMSG;
    }
    ft_valid_start_end(head);

    // while((*head))
    // {
    //     printf ("head nema = %s | x = %d | y = %d\n", (*head)->name, (*head)->x, (*head)->y);
    //     (*head) = (*head)->next;
    // }
    
}

// int main (void)
// {
//     t_data data;
//     t_roomlist *head;
//     t_road			*rd;

//     rd = NULL;
//     head = NULL;
//     ft_init(&data);
//     if(data.fd == -1)
//         EXITMSG;
//     ft_parsing(&data, &head);
//     ft_bfs(&head);
//     ft_create_rd(&head, &rd);
//     ft_let_my_people_go(&rd, data.ants);
//     while (rd)
// 	{
// 		free(rd);
// 		rd = rd->next;
// 	}
//     return(0);
// }

int main (int argc, char **argv)
{
    t_data data;
    t_roomlist *head;
    t_road			*rd;

    rd = NULL;
    head = NULL;
    if (argc > 22)
        printf("ololo");
    ft_init(&data);
    data.fd = open(argv[1], O_RDONLY, 0);
    if(data.fd == -1)
        EXITMSG;
    ft_parsing(&data, &head);
    ft_bfs(&head);
    ft_create_rd(&head, &rd);
    ft_let_my_people_go(&rd, data.ants);
    while (rd)
	{
		free(rd);
		rd = rd->next;
	}
   
    // while(head)
    // {
    //     int i = 0;
    //     if (head->link)
    //     {
    //         while(head->link[i])
    //         {
    //             printf("name_this_room: %s[use = %d] name_link_room: %s\n", head->name, head->use, head->link[i]->name);
    //             i++;
    //         }
    //     }
    //     if (head->from)
    //         printf("name_this_room: %s[from = %s]\n", head->name, head->from);
    //     i = 0;
    //     head = head->next;
    // }
    system ("leaks -quiet lem-in");
    close(data.fd);
    return(0);
}
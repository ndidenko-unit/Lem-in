#include "lemin.h"

void ft_init(t_data *data)
{
    data->fd = 0;
    data->ants = 0;
    data->line = 0;
    data->roomtype = 0;
    data->start = 0;
    data->end = 0;
    data->connect = 0;
}

void ft_parsants(t_data *data)
{
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
}

void ft_parscommand (t_data *data)
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
    ft_putstr(data->line);
    write(1, "\n", 1);
}

int ft_validroom(char *data)
{
    int space;
    int len;

    space = 0;
    len = ft_strlen(data);
    while(*data != ' ' && *data != '\0')
        data++;
    while (*data)
    {
        if (!ft_isdigit(*data) && *data != ' ')
            return(0);
        else if (*data == ' ' && *data + 1 == ' ')
            return(0);
        else if (*data == ' ')
            space++;
        data++;
    }
    if (space != 2)
        return(0);
    data = data - len;
    ft_putstr(data);
    write (1, "\n", 1);
    return(1);
}

int ft_validlink(char *data)
{
    int hyphen;
    int len;

    hyphen = 0;
    len = ft_strlen(data);
    while(*data)
    {
       if(*data == ' ')
           return(0);
       else if(*data == '-')
            hyphen++;
        data++;
    }
    if (hyphen != 1)
        return(0);
    data = data - len;
    // ft_putstr(data);
    // write (1, "\n", 1);
    return(1);
}

void ft_parsing(t_data *data, t_roomlist **head)
{
    int i = 0;
    while (i < 13)
    {
        get_next_line(data->fd, &data->line);
        if (data->ants == 0 && data->line != 0 && ft_isdigit(data->line[0]))
            ft_parsants(data);
        else if (data->line != 0 && data->line[0] == '#')
            ft_parscommand(data);
        else if (data->line != 0 && data->line[0] != '#' && data->line[0] != 'L' 
                    && ft_validroom(data->line))
            ft_room(data, head);
        else if (data->line != 0 && data->line[0] != 'L' && ft_validlink(data->line))
            ft_link(data, head);
        else
            EXITMSG;
        i++;
    }
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

//     ft_init(&data);
//     if(data.fd == -1)
//         EXITMSG;
//     ft_parsing(&data, &head);
//     return(0);
// }

int main (int argc, char **argv)
{
    t_data data;
    t_roomlist *head;

    if (argc > 22)
        printf("ololo");
    ft_init(&data);
    data.fd = open(argv[1], O_RDONLY, 0);
    if(data.fd == -1)
        EXITMSG;
    ft_parsing(&data, &head);
    close(data.fd);
    return(0);
}
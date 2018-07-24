#include "lemin.h"

void ft_init(t_data *data)
{
    data->fd = 0;
    data->ants = 0;
    data->line = 0;
    data->roomtype = 0;
    data->start = 0;
    data->end = 0;
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
        ft_putstr(data->line);
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
}

int ft_validroom(t_data *data)
{
    int space;
    int len;

    space = 0;
    len = ft_strlen(data->line);
    while(*(data->line) != ' ')
        (data->line)++;
    while (*(data->line))
    {
        if (!ft_isdigit(*(data->line)) && *(data->line) != ' ')
            EXITMSG;
        else if (*(data->line) == ' ')
            space++;
        (data->line)++;
    }
    if (space != 2)
        EXITMSG;
    data->line = data->line - len;
    ft_putstr(data->line);
    return(1);
}

void ft_parsing(t_data *data, t_roomlist **head)
{
    int i = 0;
    while (i < 4)
    {
        get_next_line(data->fd, &data->line);
        if (data->ants == 0 && data->line != 0 && ft_isdigit(data->line[0]))
            ft_parsants(data);
        else if (data->line != 0 && data->line[0] == '#')
            ft_parscommand(data);
        else if (data->line != 0 && data->line[0] != '#' && data->line[0] != 'L'
                                    && ft_validroom(data))
            ft_room(data, head);
        i++;
    }
    
}

int main (void)
{
    t_data data;
    t_roomlist *head;

    ft_init(&data);
    if(data.fd == -1)
        EXITMSG;
    ft_parsing(&data, &head);
    return(0);
}
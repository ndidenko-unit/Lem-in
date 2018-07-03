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

void ft_parsing(t_data *data)
{
    get_next_line(data->fd, &data->line);
    if (data->ants == 0 && data->line != 0 && ft_isdigit(data->line[0]))
        ft_parsants(data);
    else if (data->line != 0 && data->line[0] == '#')
        ft_parscommand(data);
}

int main (void)
{
    t_data data;

    ft_init(&data);
    if(data.fd == -1)
        EXITMSG;
    ft_parsing(&data);
    return(0);
}
#include "lemin.h"

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

void ft_valid_start_end(t_roomlist **head)
{
    int type1;
    int type2;
    t_roomlist *tmp;

    type1 = 0;
    type2 = 0;
    tmp = *head; // доделать
    while(tmp)
    {
        if(tmp->type == 1)
            type1++;
        else if(tmp->type == 2)
            type2++;
        tmp = tmp->next;
    }
    if (type1 != 1 || type2 != 1)
        EXITMSG;
}

int ft_cw(char *str)
{
    int count;

    count = 0;
    while(*str)
    {
        if (ft_is_space(*str) == 0 && ft_is_space(*(str + 1)) == 1)
            count++;
        str++;
    }
    return (count);
}
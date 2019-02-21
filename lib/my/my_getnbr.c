/*
** EPITECH PROJECT, 2018
** get nbr
** File description:
** get nbgr
*/

int is_nbr(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int is_add(char c)
{
    if (c >= 48 && c <= 57)
        return (0);
    else
        return (1);
}

int my_getnbr(char *str)
{
    int nb = 0;
    int i = 0;
    int neg = 1;

    while (is_add(str[i]) == 1)
        i = i + 1;
    if (str[i - 1] == '-')
        neg = -1;
    while (is_nbr(str[i]) == 1) {
        if (nb < 0)
            return (0);
        nb = ((nb * 10) + (str[i] - '0'));
        i = i + 1;
    }
    if (nb < 0)
        return (0);
    return (nb * neg);
}

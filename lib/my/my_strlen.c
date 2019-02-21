/*
** EPITECH PROJECT, 2018
** strlen.c
** File description:
** strlen
*/

int my_strlen(char *str)
{
    int n = 0;

    while (str[n] != '\0')
        n++;
    return (n);
}

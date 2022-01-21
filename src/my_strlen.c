/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** my_strlen.c
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** my_getnbr.c
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int nbr = 0;
    int i = 0;
    int sign = 1;

    while (str[i] > '9' || str[i] < '0') {
        i += 1;
        if (str[i - 1] == '-') {
            sign = -1;
            i += 1;
        }
    }
    while (str[i] <= '9' && str[i] >= '0') {
        nbr = ((nbr * 10) + (str[i] - '0'));
        i += 1;
    }
    return (nbr * sign);
}

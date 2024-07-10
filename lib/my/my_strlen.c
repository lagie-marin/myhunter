/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday04-marin.lagie
** File description:
** my_strlen.c
*/
#include "../../include/my.h"

int my_strlen(char const *str)
{
    if (*str == 0)
        return 0;
    return my_strlen(str + 1) + 1;
}

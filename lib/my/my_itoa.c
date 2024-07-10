/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-alexis.drago-beltran
** File description:
** my_itoa.c
*/

#include "../../include/my.h"

void my_itoa(int value, char *buffer)
{
    char *str = buffer;
    int parser = 0;
    int tmp = value;
    int len = 0;

    while (tmp > 0) {
        tmp /= 10;
        len++;
    }
    if (value == 0)
        len = 1;
    str[len] = '\0';
    while (len >= 0) {
        len--;
        str[len] = value % 10 + '0';
        value /= 10;
    }
}

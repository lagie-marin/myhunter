/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-marin.lagie
** File description:
** shorten.c
*/

#include "../../include/my_hunter.h"

void sfsprite_st(sfSprite *sprite, const sfTexture *texture, sfBool resetRect)
{
    sfSprite_setTexture(sprite, texture, resetRect);
}

sfTexture *sftexture_cff(const char *filename, const sfIntRect *area)
{
    return sfTexture_createFromFile(filename, area);
}

sfTime sfclock_get(const sfClock *clock)
{
    return sfClock_getElapsedTime(clock);
}

void sftext_ss(sfText *text, const char *string)
{
    sfText_setString(text, string);
}

sfFont *sffont_cff(const char *filename)
{
    return sfFont_createFromFile(filename);
}

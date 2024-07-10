/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-marin.lagie
** File description:
** set_text.c
*/

#include "../../include/my_hunter.h"

void set_text(game_t *game, sfText *text, sfVector2f position)
{
    sfFont *font = sfFont_createFromFile(game->settings->font);

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

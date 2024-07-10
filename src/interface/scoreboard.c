/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-marin.lagie
** File description:
** set_scoreboard.c
*/

#include "../../include/my_hunter.h"

void get_scoreboard(game_t *game, sfText *text)
{
    interface_t board = game->interface;
    char scoreboard[100] = "Vie          :";
    char type[10] = "";

    my_itoa(board.heart, type);
    my_strcat(scoreboard, type);
    my_strcat(scoreboard, "\nscore    :");
    my_itoa(board.score, type);
    my_strcat(scoreboard, type);
    my_strcat(scoreboard, "\ncombos:");
    my_itoa(board.combo, type);
    my_strcat(scoreboard, type);
    my_strcat(scoreboard, "\nkill       :");
    my_itoa(board.kill, type);
    my_strcat(scoreboard, type);
    sftext_ss(text, scoreboard);
}

void set_scoreboard(game_t *game)
{
    sfText *text = sfText_create();
    sfFloatRect text_rect;
    sfVector2u windowSize = sfRenderWindow_getSize(game->window);
    interface_t board = game->interface;
    sfFont *font = sfFont_createFromFile(game->settings->font);

    get_scoreboard(game, text);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    text_rect = sfText_getLocalBounds(text);
    sfText_setPosition(text, (sfVector2f){windowSize.x / 20, windowSize.y / 1.25});
    sfRenderWindow_drawText(game->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void death_scoreboard(game_t *game)
{
    sfText *text = sfText_create();
    sfFloatRect text_rect;
    sfVector2u windowSize = sfRenderWindow_getSize(game->window);
    sfVector2f position;
    sfFont *font = sfFont_createFromFile(game->settings->font);

    get_scoreboard(game, text);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    text_rect = sfText_getLocalBounds(text);
    position.x = windowSize.x / 2 - text_rect.width / 2.0;
    position.y = windowSize.y / 2 - text_rect.height / 2.0;
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

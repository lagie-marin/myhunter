/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-marin.lagie
** File description:
** get.c
*/

#include "../../include/my_hunter.h"

float get_time_with_pts(game_t *game, int pos)
{
    int calculate_pts = 0;
    float times = 6.0;

    if (pos == 1)
        times = 10.0;
    calculate_pts += 1000;
    while (calculate_pts < game->interface.score) {
        times -= 1.0;
        calculate_pts += 1000;
    }
    return game->settings->width / times / game->settings->fps;
}

int get_nb_ennemie(game_t *game)
{
    int combot = game->interface.combo;
    int combot_new_ennemie = 20;
    int nb_ennemie = 1;

    while (combot_new_ennemie < combot) {
        combot_new_ennemie += 20;
        nb_ennemie++;
    }
    return nb_ennemie;
}

sprites_t *get_current_sprite(sprites_t *sprites)
{
    sprites_t *current = sprites;

    while (current->next != NULL)
        current = current->next;
    return current;
}

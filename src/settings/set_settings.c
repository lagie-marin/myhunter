/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-marin.lagie
** File description:
** set_settings.c
*/

#include "../../include/my_hunter.h"

static void set_btn_restart(game_t *game, sfVector2f pos, sfVector2f scale)
{
    object_t *restart_btn = malloc(sizeof(object_t));

    restart_btn->is_board = 0;
    restart_btn->info.len_x = 792 / 9;
    restart_btn->info.len_y = 214 / 2;
    restart_btn->info.current = 1;
    restart_btn->sprite = sfSprite_create();
    restart_btn->texture = game->texture->icons;
    restart_btn->pos = pos;
    restart_btn->scale = scale;
    restart_btn->x = 792;
    restart_btn->y = 214;
    restart_btn->next = NULL;
    set_object_animate(game, restart_btn);
}

static void set_btn_parameter(game_t *game, sfVector2f pos, sfVector2f scale)
{
    object_t *param = malloc(sizeof(object_t));

    param->is_board = 0;
    param->info.len_x = 792 / 9;
    param->info.len_y = 214 / 2;
    param->info.current = 2;
    param->sprite = sfSprite_create();
    param->texture = game->texture->icons;
    param->pos = pos;
    param->scale = scale;
    param->x = 792;
    param->y = 214;
    param->next = NULL;
    set_object_animate(game, param);
}

static void set_btn_info(game_t *game, sfVector2f pos, sfVector2f scale)
{
    object_t *info = malloc(sizeof(object_t));

    info->is_board = 0;
    info->info.len_x = 792 / 9;
    info->info.len_y = 214 / 2;
    info->info.current = 3;
    info->sprite = sfSprite_create();
    info->texture = game->texture->icons;
    info->pos = pos;
    info->scale = scale;
    info->x = 792;
    info->y = 214;
    info->next = NULL;
    set_object_animate(game, info);
}

static void set_btn_acceuil(game_t *game, sfVector2f pos, sfVector2f scale)
{
    object_t *acceuil = malloc(sizeof(object_t));

    acceuil->is_board = 0;
    acceuil->info.len_x = 792 / 9;
    acceuil->info.len_y = 214 / 2;
    acceuil->info.current = 4;
    acceuil->sprite = sfSprite_create();
    acceuil->texture = game->texture->icons;
    acceuil->pos = pos;
    acceuil->scale = scale;
    acceuil->x = 792;
    acceuil->y = 214;
    acceuil->next = NULL;
    set_object_animate(game, acceuil);
}

static void set_btn_song(game_t *game, sfVector2f pos, sfVector2f scale)
{
    object_t *song = malloc(sizeof(object_t));

    song->is_board = 0;
    song->info.len_x = 792 / 9;
    song->info.len_y = 214 / 2;
    song->info.current = 5;
    song->sprite = sfSprite_create();
    song->texture = game->texture->icons;
    song->pos = pos;
    song->scale = scale;
    song->x = 792;
    song->y = 214;
    song->next = NULL;
    set_object_animate(game, song);
}

static void set_btn_mute(game_t *game, sfVector2f pos, sfVector2f scale)
{
    object_t *mute = malloc(sizeof(object_t));

    mute->is_board = 0;
    mute->info.len_x = 792 / 9;
    mute->info.len_y = 214 / 2;
    mute->info.current = 5;
    mute->sprite = sfSprite_create();
    mute->texture = game->texture->icons;
    mute->pos = pos;
    mute->scale = scale;
    mute->x = 792;
    mute->y = 214;
    mute->next = NULL;
    set_object_animate(game, mute);
}

void set_board(game_t *game, sfVector2f pos, sfVector2f scale)
{
    object_t *board = malloc(sizeof(object_t));

    board->is_board = 1;
    board->info.len_x = -1;
    board->info.len_y = -1;
    board->info.current = -1;
    board->sprite = sfSprite_create();
    board->texture = game->texture->board;
    board->pos = pos;
    board->scale = scale;
    board->x = 800;
    board->y = 586;
    board->next = NULL;
    set_object_animate(game, board);
}

void set_settings(game_t *game)
{
    sfVector2u windowSize = sfRenderWindow_getSize(game->window);
    sfVector2f pos;
    sfVector2f scale;
    sprites_t *current;

    game->sprites->texture = game->texture->settings;
    sfsprite_st(game->sprites->sprite, game->sprites->texture, sfFalse);
    pos = (sfVector2f) {windowSize.x / 4, windowSize.y / 1.5};
    scale = (sfVector2f) {1, 1};
    set_board(game, pos, scale);
}

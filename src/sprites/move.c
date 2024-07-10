/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-marin.lagie
** File description:
** move.c
*/

#include "../../include/my_hunter.h"

static int get_y_multiplier(void)
{
    int val = 0;
    int multi = 0;

    srand(time(NULL));
    val = rand() % 8;
    if (val == 1 || val == 4)
        multi = 1;
    else if (val == 2 || val == 7)
        multi = -1;
    else
        multi = 0;
    return multi;
}

static void check_pos_y(sprites_t *current, game_t *game, float new_pos_y)
{
    if (new_pos_y <= 100)
        current->disp_y = current->disp_y * -1;
    if (new_pos_y >= game->settings->height - 200)
        current->disp_y = current->disp_y * -1;
}

static void check_pos_x(sprites_t *current, game_t *game, float new_pos_x)
{
    info_texture_t *info = current->info_t_s;
    settings_t *settings = game->settings;

    if (current->disp_x < 0 && new_pos_x + info->size <= 0) {
        game->interface.heart--;
        game->interface.combo = 0;
        set_place_sprite(current, game);
    }
    if (current->disp_x > 0 && new_pos_x - info->size >= settings->width) {
        game->interface.heart--;
        game->interface.combo = 0;
        set_place_sprite(current, game);
    }
    if (game->interface.heart == 0)
        game->is_death = 1;
}

static void move_sprite(sprites_t *current, game_t *game)
{
    sfVector2f pos_sprites;
    sfVector2f new_pos;
    float new_pos_y = 0.0;
    float new_pos_x = 0.0;

    pos_sprites = sfSprite_getPosition(current->sprite);
    new_pos.x = current->disp_x;
    new_pos.y = current->disp_y * get_y_multiplier();
    new_pos_y = pos_sprites.y + new_pos.y;
    new_pos_x = pos_sprites.x + new_pos.x;
    check_pos_y(current, game, new_pos_y);
    check_pos_x(current, game, new_pos_x);
    if (game->is_death == 0)
        sfSprite_move(current->sprite, new_pos);
    else {
        del_all_sprites(game->sprites->next);
        game->sprites->next = NULL;
        change_map_towards(game);
    }
}

void move(sprites_t *sprites, game_t *game)
{
    sprites_t *current = sprites;

    while (current != NULL) {
        if (current->is_kill == 1) {
            current->is_kill = 0;
            set_place_sprite(current, game);
        }
        move_sprite(current, game);
        current = current->next;
    }
}

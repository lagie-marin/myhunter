/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-marin.lagie
** File description:
** delete.c
*/

#include "../../include/my_hunter.h"

static int is_outside(sprites_t *sprite, info_texture_t *info, game_t *game)
{
    int get_x = sfSprite_getPosition(sprite->sprite).x;

    if (sprite->disp_x < 0 && get_x + info->size <= 0)
        return 1;
    if (sprite->disp_x > 0 && get_x - info->size >= game->settings->width)
        return 1;
    return 0;
}

void del_overflow_sprite(sprites_t *current, game_t *game, int nb_ennemie)
{
    sprites_t *prev = current;
    sprites_t *next = current->next;
    sprites_t *tmp;
    info_texture_t *info;

    while (nb_ennemie < game->nb_ennemie && next != NULL) {
        info = next->info_t_s;
        if (is_outside(next, info, game)) {
            prev->next = next->next == NULL ? NULL : next->next;
            sfClock_destroy(next->info_t_s->clock);
            sfSprite_destroy(next->sprite);
            free(next->info_t_s);
            free(next);
            game->nb_ennemie--;
        }
        prev = next;
        next = next->next;
    }
}

void del_all_sprites(sprites_t *sprites)
{
    sprites_t *tmp;

    while (sprites != NULL) {
        tmp = sprites->next;
        free(sprites->info_t_s);
        free(sprites);
        sprites = tmp;
    }
}

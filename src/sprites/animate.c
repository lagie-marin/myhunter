/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-marin.lagie
** File description:
** animate.c
*/

#include "../../include/my_hunter.h"

static void animate_sprite(sprites_t *sprite)
{
    int x = 0;
    int y = 0;
    info_texture_t *info = sprite->info_t_s;
    sfIntRect rect;

    info->current = (info->current + 1) % (info->count * info->count);
    rect.left = (info->current % info->count) * info->size;
    rect.top = (info->current / info->count) * info->size;
    rect.width = info->size;
    rect.height = info->size;
    sfSprite_setTextureRect(sprite->sprite, rect);
}

void animate_sprites(sprites_t *sprites)
{
    sprites_t *current = sprites;
    info_texture_t *info;
    int milli = 0;

    while (current != NULL) {
        info = current->info_t_s;
        milli = sfclock_get(current->info_t_s->clock).microseconds / 1000;
        if (milli >= info->max_clock) {
            animate_sprite(current);
            sfClock_restart(info->clock);
        }
        current = current->next;
    }
}

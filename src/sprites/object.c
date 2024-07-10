/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-marin.lagie
** File description:
** object.c
*/

#include "../../include/my_hunter.h"

object_t *get_object_current(object_t *object)
{
    object_t *current = object;

    while (current != NULL)
        current = current->next;
    return current;
}

void set_object_animate(game_t *game, object_t *object)
{
    object_t *current = get_object_current(game->object);
    int len_x = object->info.len_x;
    int len_y = object->info.len_y;
    sfIntRect rect;
    sfSprite *sprite = object->sprite;

    if (object->info.current != -1)
        rect = (sfIntRect) {object->info.current * len_x, 0, len_x, len_y};
    if (current == NULL)
        game->object = object;
    else
        current->next = object;
    sfsprite_st(sprite, object->texture, sfFalse);
    sfSprite_setScale(sprite, object->scale);
    sfSprite_setPosition(sprite, object->pos);
    sfSprite_setOrigin(sprite, (sfVector2f) {object->x / 2, object->y / 2});
    if (object->info.current != -1)
        sfSprite_setTextureRect(sprite, rect);
}

void set_object(game_t *game, object_t *object, sprites_t *current)
{
    sprites_t *new_sprite = malloc(sizeof(sprites_t));
    sfSprite *sprite = sfSprite_create();

    new_sprite->sprite = sprite;
    new_sprite->info_t_s = NULL;
    new_sprite->texture = object->texture;
    new_sprite->score = 0;
    new_sprite->is_kill = 0;
    new_sprite->next = NULL;
    new_sprite->pos = object->pos;
    new_sprite->scale = object->scale;
    current->next = new_sprite;
    sfsprite_st(sprite, new_sprite->texture, sfFalse);
    sfSprite_setScale(sprite, new_sprite->scale);
    sfSprite_setPosition(sprite, new_sprite->pos);
    sfSprite_setOrigin(sprite, (sfVector2f) {object->x / 2, object->y / 2});
}

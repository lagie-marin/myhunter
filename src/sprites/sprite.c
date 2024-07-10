/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-marin.lagie
** File description:
** sprite.c
*/

#include "../../include/my_hunter.h"

static int set_x_alea(game_t *game)
{
    int pos = rand() % 2;

    if (pos == 0)
        return 0;
    return game->settings->width;
}

static int set_y_sprite(game_t *game)
{
    int y = rand() % game->settings->height;

    if (y < 300)
        y = 300;
    if (y > game->settings->height - 300)
        y = game->settings->height - 300;
    return y;
}

static float extend_rand(game_t *game)
{
    int combo = game->interface.combo;
    int new_combo = 10;
    float result = 0.0;

    while (new_combo < combo) {
        result += 0.1;
        new_combo += 10;
    }
    if (result > 0.7)
        result = 0.7;
    return result;
}

void set_place_sprite(sprites_t *sprite, game_t *game)
{
    float scale_y = 1;
    float scale_x = 0;
    float calc_x = get_time_with_pts(game, 1);
    float calc_y = get_time_with_pts(game, 0);

    sprite->pos.x = set_x_alea(game);
    sprite->pos.y = set_y_sprite(game);
    if (game->interface.combo >= 10)
        scale_y = ((float)rand() / RAND_MAX) * 1.0 + 0.4;
    if (scale_y < 0.3)
        scale_y = 0.3;
    scale_x = sprite->pos.x > 0 ? -scale_y : scale_y;
    sprite->scale.x = scale_x;
    sprite->scale.y = scale_y;
    sprite->disp_x = scale_x < 0 ? -calc_x : calc_x;
    sprite->disp_y = calc_y / 3;
    sfSprite_setScale(sprite->sprite, sprite->scale);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
}

static void set_info_sprite(sprites_t *new_sprite)
{
    new_sprite->info_t_s = malloc(sizeof(info_texture_t));
    new_sprite->info_t_s->clock = sfClock_create();
    new_sprite->info_t_s->max_clock = 60;
    new_sprite->info_t_s->size = 240;
    new_sprite->info_t_s->count = 3;
    new_sprite->info_t_s->current = 0;
}

void set_sprite(sprites_t *new_sprite, game_t *game, sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    srand(time(NULL));
    set_info_sprite(new_sprite);
    new_sprite->sprite = sprite;
    new_sprite->texture = texture;
    new_sprite->score = 100;
    new_sprite->is_kill = 0;
    new_sprite->next = NULL;
    set_place_sprite(new_sprite, game);
    sfsprite_st(sprite, new_sprite->texture, sfFalse);
    sfSprite_setOrigin(sprite, (sfVector2f) {720 / 3, 720 / 3});
}

void *set_sprites(game_t *game)
{
    sprites_t *new_sprite;
    sprites_t *current = get_current_sprite(game->sprites);
    int nb_ennemie = get_nb_ennemie(game);

    while (game->nb_ennemie < nb_ennemie) {
        new_sprite = malloc(sizeof(sprites_t));
        set_sprite(new_sprite, game, game->texture->parrot);
        current->next = new_sprite;
        current = new_sprite;
        game->nb_ennemie++;
    }
    if (nb_ennemie < game->nb_ennemie) {
        del_overflow_sprite(game->sprites, game, nb_ennemie);
    }
    animate_sprites(game->sprites->next);
}

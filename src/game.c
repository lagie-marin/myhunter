/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-marin.lagie
** File description:
** game.c
*/

#include "../include/my_hunter.h"


static game_t *init_interface(game_t *game)
{
    game->interface.heart = 3;
    game->interface.score = 0;
    game->interface.combo = 0;
    game->interface.kill = 0;
    return game;
}

static void init_sprites(game_t *game)
{
    sfSprite *sprite_bg = sfSprite_create();

    game->sprites = malloc(sizeof(sprites_t));
    game->sprites->sprite = sprite_bg;
    game->sprites->texture = game->texture->settings;
    game->sprites->pos.x = 0;
    game->sprites->pos.y = 0;
    game->sprites->scale.x = 1920;
    game->sprites->scale.y = 1080;
    game->sprites->disp_x = 0;
    game->sprites->disp_y = 0;
    game->sprites->start = 0;
    game->sprites->next = NULL;
    game->sprites->score = 0;
}

static void init_settings(game_t *game)
{
    game->settings = malloc(sizeof(settings_t));
    game->settings->height = 1080;
    game->settings->width = 1920;
    game->settings->fps = 60;
    game->settings->font = "src/font/BungeeSpice-Regular.ttf";
}

static game_t *init_texture(game_t *game)
{
    game->texture = malloc(sizeof(texture_t));
    game->texture->bg = sftexture_cff("img/bg.jpg", NULL);
    game->texture->death = sftexture_cff("img/death.jpg", NULL);
    game->texture->settings = sftexture_cff("img/settings.jpg", NULL);
    game->texture->cible = sftexture_cff("img/cible.png", NULL);
    game->texture->parrot = sftexture_cff("img/parrot.png", NULL);
    game->texture->grave = sftexture_cff("img/grave.png", NULL);
    game->texture->btn_pressed = sftexture_cff("img/btn_press.png", NULL);
    game->texture->btn = sftexture_cff("img/btn.png", NULL);
    game->texture->board = sftexture_cff("img/board.png", NULL);
    game->texture->icons = sftexture_cff("img/icons.png", NULL);
    return game;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game = init_texture(game);
    init_sprites(game);
    game = init_interface(game);
    init_settings(game);
    game->object = NULL;
    game->window = NULL;
    game->nb_ennemie = 0;
    game->is_death = 0;
    sfsprite_st(game->sprites->sprite, game->sprites->texture, sfFalse);
    return game;
}

void change_map_towards(game_t *game)
{
    object_t *grave = malloc(sizeof(object_t));
    sfVector2u windowSize = sfRenderWindow_getSize(game->window);

    game->sprites->texture = game->texture->death;
    sfsprite_st(game->sprites->sprite, game->sprites->texture, sfFalse);
    grave->pos = (sfVector2f) {windowSize.x / 2, windowSize.y / 1.15};
    grave->scale = (sfVector2f) {1.25, 1.25};
    grave->texture = game->texture->grave;
    grave->x = 180;
    grave->y = 252;
    set_object(game, grave, game->sprites);
    free(grave);
}

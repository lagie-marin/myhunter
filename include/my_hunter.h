/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-marin.lagie
** File description:
** my_hunter.h
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

#ifndef MY_HUNTER
    #define MY_HUNTER
void sfsprite_st(sfSprite *sprite, const sfTexture *texture, sfBool resetRect);
void sftext_ss(sfText *text, const char *string);
sfTexture *sftexture_cff(const char *filename, const sfIntRect *area);
sfTime sfclock_get(const sfClock *clock);
sfFont *sffont_cff(const char *filename);

typedef unsigned int ui;
typedef struct sprites_s sprites_t;
typedef struct interface_s interface_t;
typedef struct game_s game_t;
typedef struct info_texture_s info_texture_t;
typedef struct settings_s settings_t;
typedef struct object_s object_t;
typedef struct texture_s texture_t;
typedef struct info_object_s info_object_t;

struct texture_s {
    sfTexture *bg;
    sfTexture *cible;
    sfTexture *death;
    sfTexture *grave;
    sfTexture *parrot;
    sfTexture *settings;
    sfTexture *board;
    sfTexture *btn_pressed;
    sfTexture *btn;
    sfTexture *icons;
};
struct interface_s {
    int heart;
    int score;
    int combo;
    int kill;

};
struct info_texture_s {
    int size;
    int count;
    int current;
    sfClock *clock;
    int max_clock;
};
struct info_object_s {
    int len_x;
    int len_y;
    int current;
};
struct sprites_s {
    sfSprite *sprite;
    info_texture_t *info_t_s;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    float disp_x;
    float disp_y;
    int start;
    sprites_t *next;
    int is_kill;
    int score;
};
struct object_s {
    int is_board;
    info_object_t info;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    float rotate;
    int x;
    int y;
    object_t *next;
};
struct settings_s {
    ui height;
    ui width;
    ui fps;
    ui mute;
    char *font;
};
struct game_s {
    texture_t *texture;
    interface_t interface;
    sprites_t *sprites;
    settings_t *settings;
    object_t *object;
    sfRenderWindow *window;
    ui nb_ennemie;
    ui is_death;
};
game_t *init_game(void);
void *set_sprites(game_t *game);
void move(sprites_t *sprites, game_t *game);
float get_time_with_pts(game_t *game, int pos);
int get_nb_ennemie(game_t *game);
sprites_t *get_current_sprite(sprites_t *sprites);
void del_overflow_sprite(sprites_t *current, game_t *game, int nb_ennemie);
void del_all_sprites(sprites_t *sprites);
void set_place_sprite(sprites_t *new_sprite, game_t *game);
void animate_sprites(sprites_t *sprites);
void event_manager(sfEvent event, game_t *game);
void set_scoreboard(game_t *game);
void change_map_towards(game_t *game);
void set_sprite(sprites_t *new_sprite, game_t *game, sfTexture *texture);
void set_object(game_t *game, object_t *object, sprites_t *current);
void set_text(game_t *game, sfText *text, sfVector2f position);
void death_scoreboard(game_t *game);
void set_settings(game_t *game);
void get_scoreboard(game_t *game, sfText *text);
void set_object_animate(game_t *game, object_t *object);
void set_board(game_t *game, sfVector2f pos, sfVector2f scale);
#endif

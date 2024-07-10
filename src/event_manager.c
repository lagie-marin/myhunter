/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-marin.lagie
** File description:
** event_manager.c
*/

#include "../include/my_hunter.h"

static sfBool is_click_in_sprite(sfEvent e, sfSprite* sprite)
{
    sfFloatRect box = sfSprite_getGlobalBounds(sprite);

    return sfFloatRect_contains(&box, e.mouseButton.x, e.mouseButton.y);
}

static void run_pos_all_sprite(sfEvent event, game_t *game)
{
    sprites_t *current = game->sprites->next;
    int kill_ennemie = 0;

    while (current != NULL) {
        if (is_click_in_sprite(event, current->sprite) == sfTrue) {
            game->interface.combo++;
            game->interface.kill++;
            game->interface.score += current->score;
            current->is_kill = 1;
            kill_ennemie++;
        }
        current = current->next;
    }
    if (kill_ennemie == 0)
        game->interface.combo = 0;
}

void event_manager(sfEvent event, game_t *game)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (event.type == sfEvtMouseButtonPressed) {
        run_pos_all_sprite(event, game);
    }
}

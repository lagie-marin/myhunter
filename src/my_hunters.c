/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-marin.lagie
** File description:
** my_hunters.c
*/

#include "../include/my_hunter.h"

static sfRenderWindow *create_window(game_t *game, ui bpp, char *title)
{
    ui width = game->settings->width;
    ui height = game->settings->height;
    sfVideoMode video_mode = {width, height, bpp};

    return sfRenderWindow_create(video_mode, title, sfClose | sfResize, NULL);
}

static void draw_sprites(game_t *game)
{
    sprites_t *current = game->sprites;

    while (current != NULL) {
        sfRenderWindow_drawSprite(game->window, current->sprite, NULL);
        current = current->next;
    }
}

static int help(void)
{
    write(1, "Epitech project 2023: My_hunter\nSubject: We must create a", 57);
    write(1, " 2d video game based on GAMES. When a bird appears you ", 55);
    write(1, "have to shoot it and when the player shoots, the bird is", 56);
    write(1, " killed.\nUsage:\n./my_hunter [-h]\n", 33);
    return 0;
}

static void update_window(game_t *game)
{
    sfVector2u windowSize = sfRenderWindow_getSize(game->window);
    sfVector2f pos;
    sfVector2f scale;

    sfRenderWindow_clear(game->window, sfBlack);
    if (game->is_death == 0) {
        set_sprites(game);
        move(game->sprites->next, game);
    }
    draw_sprites(game);
    if (game->is_death == 0)
        set_scoreboard(game);
    if (game->is_death == 1)
        death_scoreboard(game);
    sfRenderWindow_display(game->window);
}

static void free_sprites(sprites_t *sprites)
{
    sprites_t *tmp = sprites;

    while (sprites) {
        tmp = sprites->next;
        free(sprites->info_t_s);
        free(sprites);
        sprites = tmp;
    }
}

static void free_objects(object_t *objects)
{
    object_t *tmp = objects;

    while (objects) {
        tmp = objects->next;
        free(objects);
        objects = tmp;
    }
}

int main(int ac, char **av)
{
    game_t *game;
    sfEvent event;

    if (ac > 2)
        return 84;
    if (ac == 2 && av[1] && av[1][0] == '-' && av[1][1] == 'h')
        return help();
    game = init_game();
    game->window = create_window(game, 32, "My_Hunter");
    sfRenderWindow_setFramerateLimit(game->window, game->settings->fps);
    while (sfRenderWindow_isOpen(game->window)) {
        update_window(game);
        while (sfRenderWindow_pollEvent(game->window, &event))
            event_manager(event, game);
    }
    sfRenderWindow_destroy(game->window);
    free_sprites(game->sprites);
    // free_objects(game->object);
    free(game);
}

//bing image
/*
Ecran de chargement
    Nom du projet
    Epitech anné
    Nom du créateur
Ecran de menu
    Bouton play
    Bouton option
    Bouton quitter
    Credits
Ecran de jeu
    Fond d'écran
    Interface
        Vie
        Points
        Combot
        Tuer
    Armes
Ennemi
    Voleur
    Brigant
    Oiseau
    Ours
    Loup
    Chien
    Chauve-souris
    Araignée
    Serpent
    Scorpion
    Araignée géante (bosse)
    Bombe
    Bombe nucléaire
    Grenade
    Avion de chasse
    Gros verre
    Boss
    Boss final
    Boss secret
Map:
    Centre de la Terre
    Grotte
    Volcan
    Désert
    Jungle
    Forêt
    Plaine
    Montagne
    Ville
    Village
    Ciel
    Espace
    Planète
    Lune
    Soleil
    Etoile
    Galaxie
    Univers
Ennemie:
    déplacement ennemie:
        déplacement de base: 10s
        nombre de base: 1;
        quand ennemie tuer attendre 2s avant de régénerer ennemie
    tout les 5000 pts augmenter de 1 le nb d'ennemie
    tout les 10000 pts 1 nouveau type de mob
    tout les 10000 pts -0.1s
    taille aleatoire
*/

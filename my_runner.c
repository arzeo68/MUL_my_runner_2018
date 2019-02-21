/*
** EPITECH PROJECT, 2018
** repository
** File description:
** my_runner part 1
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "include/my.h"
#include "include/struct.h"

sfRenderWindow *create_the_window(void)
{
    sfVideoMode mode = {800, 600, 8};
    sfRenderWindow* window;
    window = sfRenderWindow_create(mode, "my_runner", sfResize |
    sfClose, NULL);
    if (!window) {
        return (window);
    }
    return (window);
}

int map_open_read_file(char *filepath, runner_t *runner)
{
    char *map;
    int fd;
    int sto;
    char **map_tab;
    struct stat size;

    stat(filepath, &size);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    map = malloc(sizeof(char) * (size.st_size + 1));
    if (!map)
        return (84);
    sto = read(fd, map, size.st_size);
    if (sto < 0)
        return (84);
    map [size.st_size] = '\0';
    runner->map_string = map;
    return (0);
}

int display_sprite(runner_t *runner, sprite_t *sprite)
{
    for (int i = 0; i <= 15; i++) {
        sfRenderWindow_drawSprite(runner->window, sprite->back[i], NULL);
    }
    for (int i = 0; i < runner->ennemy.number; i++) {
        sfRenderWindow_drawSprite(runner->window,
        runner->ennemy.ennemy_sprite[i], NULL);
    }
    sfRenderWindow_drawSprite(runner->window, sprite->player, NULL);
    return (0);
}

int game_loop(runner_t *runner, sprite_t *sprite, offset_t *offset)
{
    sfClock *clock_fly = sfClock_create();
    sfEvent evenement;
    count_ennemy(runner->map_string, runner);
    sprite_factory(runner, sprite);
    display_score(runner);
    while (sfRenderWindow_isOpen(runner->window)) {
        setup_text(runner);
        sfRenderWindow_clear(runner->window, sfCyan);
        if (runner->player.player_pos.y > 360)
            player_move(&runner->rect_player, runner, sprite);
        event_loop(evenement, runner, sprite, offset);
        if (hitbox(runner, sprite)) {
            end_game(runner, sprite, offset);
        }
        game_loop_2(runner, sprite, offset);
    }
    destroy(runner, sprite, offset);
}

int main(int argc, char **argv)
{
    sfEvent evenement;
    runner_t *runner = malloc(sizeof(*runner));
    sprite_t *sprite = malloc(sizeof(*sprite));
    offset_t *offset = malloc(sizeof(*offset));

    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            help();
            return (0);
        }
    }
    if (map_open_read_file(argv[1], runner) == 84)
        return (84);
    runner->window = create_the_window();
    sfRenderWindow_setFramerateLimit(runner->window, 60);
    setup(sprite, runner, offset);
    play_music(runner);
    start(runner, sprite, offset, evenement);
    if (game_loop(runner, sprite, offset))
        return (0);
}

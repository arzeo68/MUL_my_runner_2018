/*
** EPITECH PROJECT, 2019
** repository
** File description:
** runner
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"

void generate_sprite(runner_t *runner)
{
    sfSprite *start_screen_sprite = start_screen();
    runner->menu.sprite_player = malloc(sizeof(sfSprite *) * 9);
    runner->menu.sprite_player[0] = create_sprite(3,
    "sprite/player_pink.png", 270, 350);
    runner->menu.sprite_player[1] = create_sprite(3,
    "sprite/player_red.png", 270, 350);
    runner->menu.sprite_player[2] = create_sprite(3,
    "sprite/player_blue.png", 270, 350);
    runner->menu.sprite_player[3] = create_sprite(3,
    "sprite/player_cyan.png", 270, 350);
    runner->menu.sprite_player[4] = create_sprite(3,
    "sprite/player_green.png", 270, 350);
    runner->menu.sprite_player[5] = create_sprite(3,
    "sprite/player_yellow.png", 270, 350);
    runner->menu.sprite_player[6] = create_sprite(3,
    "sprite/player_multi.png", 270, 350);
    runner->menu.sprite_player[7] = create_sprite(2.5, "sprite/left.png",
    200, 350);
    runner->menu.sprite_player[8] = create_sprite(2.5, "sprite/right.png",
    500, 350);
}

sfSprite *create_sprite(float size, char *str, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile(str,
    NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){size, size});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

void display_start(runner_t *runner)
{
    for (int i = 7; i <= 8; i++) {
        sfRenderWindow_drawSprite(runner->window,
        runner->menu.sprite_player[i], NULL);
    }
}

void choose_color(runner_t *runner)
{
    if (runner->menu.pick > 6)
        runner->menu.pick = 0;
    if (runner->menu.pick < 0)
        runner->menu.pick = 6;
    sfRenderWindow_drawSprite(runner->window,
    runner->menu.sprite_player[runner->menu.pick], NULL);
    select_color(runner);
}

void select_color(runner_t *runner)
{
    sfTime time1;
    float sec = 0;
    time1 = sfClock_getElapsedTime(runner->clock);
    sec = time1.microseconds / 50000;
    sfFloatRect bounds_left = sfSprite_getGlobalBounds
    (runner->menu.sprite_player[3]);
    sfFloatRect bounds_right = sfSprite_getGlobalBounds
    (runner->menu.sprite_player[4]);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(runner->window);
    if (sec >= 1.5) {
        if ((sfFloatRect_contains(&bounds_left, mouse.x, mouse.y) &&
        (sfMouse_isButtonPressed(sfMouseLeft))) ||
        sfKeyboard_isKeyPressed(sfKeyRight))
            runner->menu.pick--;
        if (sfFloatRect_contains(&bounds_right, mouse.x, mouse.y) &&
        (sfMouse_isButtonPressed(sfMouseLeft)) ||
        sfKeyboard_isKeyPressed(sfKeyLeft))
            runner->menu.pick++;
        sfClock_restart(runner->clock);
    }
}

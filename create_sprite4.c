/*
** EPITECH PROJECT, 2018
** repository
** File description:
** runner
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "include/my.h"
#include "include/struct.h"

sfSprite *create_sprite_player(runner_t *runner,
sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile("sprite/player_pink.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){0, 390});
    sfSprite_setScale(sprites, (sfVector2f){3, 3});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

sfSprite *create_sprite_ennemy_ground(runner_t *runner,
sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile("ground_ennemy.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){900, 385});
    sfSprite_setScale(sprites, (sfVector2f){0.05, 0.05});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

sfSprite *create_sprite_ennemy_fly(runner_t *runner,
sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile("fly_ennemy.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){1400, 300});
    sfSprite_setScale(sprites, (sfVector2f){0.07, 0.07});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

void move_rect_player(sfIntRect *rect)
{
    int max_value = 80;
    int offset = 20;
    if (rect->left < max_value - offset) {
        rect->left += offset;
    }
    else {
        rect->left = 0;
    }
}

void player_move(sfIntRect *rect, runner_t *runner, sprite_t *sprite)
{
    sfSprite_setTextureRect(sprite->player, runner->rect_player);
    sfTime time1;
    float sec = 0;
    time1 = sfClock_getElapsedTime(runner->clock);
    sec = time1.microseconds / 50000;

    if (sec / runner->clock_counter >= 3) {
        runner->clock_counter++;
        move_rect_player(rect);
    }
}

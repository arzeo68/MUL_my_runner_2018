/*
** EPITECH PROJECT, 2019
** repository
** File description:
** map_runner
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"
#include "include/struct.h"
#include <stdio.h>

int count_ennemy(char *map, runner_t *runner)
{
    int ennemy = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'G')
            ennemy++;
    }
    runner->ennemy.number = ennemy;
    runner->ennemy.ennemy_sprite = malloc(sizeof(char *) * ennemy + 1);
    runner->ennemy.ennemy_pos = malloc(sizeof(int) * ennemy + 1);
    runner->ennemy.hitbox_pike = malloc(sizeof(sfFloatRect) * ennemy);
    mob_pos(runner);
    stock_ennemy(runner);
    return (ennemy);
}

sfSprite *ennemy_sprite_ground(int x)
{
    sfTexture *back = sfTexture_createFromFile("sprite/pike.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){x, 437});
    sfSprite_setScale(sprites, (sfVector2f){1, 1});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

void stock_ennemy(runner_t *runner)
{
    int j = 0;

    for (int i = 0; runner->ennemy.ennemy_pos[i]; i++) {
        runner->ennemy.ennemy_sprite[j] = ennemy_sprite_ground
        (runner->ennemy.ennemy_pos[i] * 200);
        j++;
    }
}

int mob_pos(runner_t *runner)
{
    int j = 0;

    for (int i = 0; runner->map_string[i] != '\0'; i++) {
        if (runner->map_string[i] == 'G') {
            runner->ennemy.ennemy_pos[j] = i;
            j++;
        }
    }
}

int score(runner_t *runner)
{
    sfTime time1;
    float sec = 0;
    time1 = sfClock_getElapsedTime(runner->clock);
    sec = time1.microseconds / 50000;
    if (sec >= 4) {
        runner->clock_counter = 0;
        runner->player.score++;
        sfClock_restart(runner->clock);
    }
}

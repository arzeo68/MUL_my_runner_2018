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
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"

void setup_offset(offset_t *offset)
{
    offset->offset[0] = (sfVector2f){-3, 0};
    offset->offset[1] = (sfVector2f){-2, 0};
    offset->offset[2] = (sfVector2f){-1.5, 0};
    offset->offset[3] = (sfVector2f){-1.3, 0};
    offset->offset[4] = (sfVector2f){-1, 0};
    offset->offset[5] = (sfVector2f){-0.8, 0};
    offset->offset[6] = (sfVector2f){-0.50, 0};
    offset->offset[7] = (sfVector2f){-0.25, 0};
}

void move_back(sprite_t *sprite, offset_t *offset, runner_t *runner)
{
    move_ennemy(runner, sprite, offset);
    sfSprite_move(sprite->ground_ennemy, offset->offset[0]);
    sfSprite_move(sprite->back[15], offset->offset[0]);
    sfSprite_move(sprite->back[14], offset->offset[0]);
    sfSprite_move(sprite->back[13], offset->offset[1]);
    sfSprite_move(sprite->back[12], offset->offset[1]);
    sfSprite_move(sprite->back[11], offset->offset[2]);
    sfSprite_move(sprite->back[10], offset->offset[2]);
    sfSprite_move(sprite->back[9], offset->offset[3]);
    sfSprite_move(sprite->back[8], offset->offset[3]);
    sfSprite_move(sprite->back[7], offset->offset[4]);
    sfSprite_move(sprite->back[6], offset->offset[4]);
    sfSprite_move(sprite->back[5], offset->offset[5]);
    sfSprite_move(sprite->back[4], offset->offset[5]);
    sfSprite_move(sprite->back[3], offset->offset[6]);
    sfSprite_move(sprite->back[2], offset->offset[6]);
    sfSprite_move(sprite->back[1], offset->offset[7]);
    sfSprite_move(sprite->back[0], offset->offset[7]);
    reset_back_pos(sprite, runner);
}

void reset_back_pos(sprite_t *sprite, runner_t *runner)
{
    int i = 0;
    sfVector2f pike_pos = sfSprite_getPosition(runner->ennemy.ennemy_sprite[i]);
    sfVector2f back_pos = sfSprite_getPosition(sprite->back[i]);
    for (i; i <= 15; i++) {
        back_pos = sfSprite_getPosition(sprite->back[i]);
        if (back_pos.x <= -780) {
            sfSprite_setPosition(sprite->back[i], (sfVector2f){780, 0});
        }
    }
    for (int i = 0; i < runner->ennemy.number; i++) {
        pike_pos = sfSprite_getPosition(runner->ennemy.ennemy_sprite[i]);
        if (pike_pos.x <= (-(runner->ennemy.number) * 150)) {
            sfSprite_setPosition(runner->ennemy.ennemy_sprite[i], (sfVector2f)
            {(runner->ennemy.number) * 170, 435});
        }
    }
}

void movement_jump(sprite_t *sprite, runner_t *runner)
{
    if (runner->player.status > 0 && runner->player.status < 4) {
        sfSprite_move(sprite->player, runner->player.velocity);

        runner->player.velocity.y += 0.2;
    }
    if (runner->player.player_pos.y > 390) {
        sfSprite_setPosition(sprite->player, (sfVector2f){0, 390});
        runner->player.status = 0;
    }
}

int setup(sprite_t *sprite, runner_t *runner, offset_t *offset)
{
    setup_offset(offset);
    runner->text.font = sfFont_createFromFile("arial.ttf");
    runner->text.text = sfText_create();
    runner->text.text2 = sfText_create();
    runner->text.text_end = sfText_create();
    runner->player.score = 0;
    runner->player.gravity = 100;
    runner->sound_status = 1;
    runner->clock = sfClock_create();
    runner->player.rect_player_jump = (sfIntRect){0, 0, 20, 28};
    runner->rect_player = (sfIntRect){0, 0, 20, 28};
    runner->rect_ground_ennemy = (sfIntRect){0, 0, 2200, 1963};
    runner->player.status = 0;
    runner->end.score = 0;
    runner->clock_counter = 0;
}

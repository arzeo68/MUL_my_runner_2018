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
#include "include/my.h"
#include "include/struct.h"
#include <stdio.h>

void move_rect_ground_ennemy(sfIntRect *rect)
{

    int max_value = 7200;
    int offset = 2400;
    if (rect->left < max_value - offset) {
        rect->left += offset;
    }
    else {
        rect->left = 0;
    }
}

int game_loop_2(runner_t *runner, sprite_t *sprite, offset_t *offset)
{
    runner->player.player_pos = sfSprite_getPosition(sprite->player);
    score(runner);
    movement_jump(sprite, runner);
    display_sprite(runner, sprite);
    move_back(sprite, offset, runner);
    sfRenderWindow_drawText(runner->window, runner->text.text, NULL);
    sfRenderWindow_drawText(runner->window, runner->text.text2, NULL);
    sfRenderWindow_display(runner->window);
}

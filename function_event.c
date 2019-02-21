/*
** EPITECH PROJECT, 2018
** repository
** File description:
** runner part 2
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"
#include "include/struct.h"
#include <stdio.h>

sfEvent event_loop(sfEvent ev, runner_t *runner, sprite_t *sprite,
offset_t *offset)
{
    while (sfRenderWindow_pollEvent(runner->window, &ev)) {
        player_jump(sprite, runner, offset);
        mute(runner);
        if (ev.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            close_window(runner, &ev, sprite, offset);
        }
    }
    return (ev);
}

int close_window(runner_t *runner, sfEvent *event, sprite_t *sprite,
offset_t *offset)
{
    sfRenderWindow_close(runner->window);
    return (0);
}

int mute(runner_t *runner)
{
    if (sfKeyboard_isKeyPressed(sfKeyM) && runner->sound_status == 1) {
        sfMusic_pause(runner->game_music);
        sfMusic_pause(runner->jump_sound);
        runner->sound_status = 0;
        return (0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyP) && runner->sound_status == 0) {
        sfMusic_play(runner->game_music);
        sfMusic_play(runner->jump_sound);
        runner->sound_status = 1;
        return (0);
    }
}

int player_jump(sprite_t *sprite, runner_t *runner, offset_t *offset)
{
    float difficulty = runner->text.difficulty;

    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (runner->player.status < 3) {
            runner->player.velocity.y = -5.2;
            runner->player.velocity.x = 0;
            runner->player.status++;
            sfMusic_play(runner->jump_sound);
            offset->offset[0].x -= (difficulty / 10);
        }
    }
}

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
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

void move_ennemy(runner_t *runner, sprite_t *sprite, offset_t *offset)
{
    for (int i = 0; i < runner->ennemy.number; i++)
        sfSprite_move(runner->ennemy.ennemy_sprite[i], offset->offset[0]);
}

void setup_text(runner_t *runner)
{
    char *str = my_itoa(runner->player.score);
    sfText_setString(runner->text.text2, str);
    sfText_setFont(runner->text.text2, runner->text.font);
    sfText_setCharacterSize(runner->text.text2, 30);
    sfText_setPosition(runner->text.text2, (sfVector2f){105, 550});
    sfText_setColor(runner->text.text2, (sfColor){1, 1, 1, 255});
}

void display_score(runner_t *runner)
{
    sfText_setString(runner->text.text, "score :");
    sfText_setFont(runner->text.text, runner->text.font);
    sfText_setCharacterSize(runner->text.text, 30);
    sfText_setPosition(runner->text.text, (sfVector2f){0, 550});
    sfText_setColor(runner->text.text, (sfColor){1, 1, 1, 255});
}

void help(void)
{
    write(1, "       Welcome to My_runner\n", 28);
    write(1, "   to start the game execute 'my_runner'\n", 41);
    write(1, " with a map in txt with '#' for void and 'G' for pike\n", 54);
    write(1, " after that pick a character and try your best to survive\n", 58);
}

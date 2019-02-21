/*
** EPITECH PROJECT, 2018
** repository
** File description:
** int to str
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"
#include <stdio.h>

int hitbox(runner_t *runner, sprite_t *sprite)
{
    sfFloatRect player = sfSprite_getGlobalBounds(sprite->player);

    for (int i = 0; i < runner->ennemy.number; i++) {
        runner->ennemy.hitbox_pike[i] = sfSprite_getGlobalBounds
        (runner->ennemy.ennemy_sprite[i]);
        runner->ennemy.hitbox_pike[i].left += 20;
        runner->ennemy.hitbox_pike[i].width -= 38;
        runner->ennemy.hitbox_pike[i].top += 3;
    }
    for (int i = 0; i < runner->ennemy.number; i++) {
        if (sfFloatRect_intersects(&player, &runner->ennemy.hitbox_pike[i],
        NULL)) {
            return (1);
        }
    }
    return (0);
}

void itoa_isnegative(int *n, int *negative)
{
    if (*n < 0) {
        *n *= -1;
        *negative = 1;
    }
}

char *my_itoa(int n)
{
    int tmpn;
    int len;
    int negative;
    char *str;

    tmpn = n;
    len = 2;
    negative = 0;
    itoa_isnegative(&n, &negative);
    while (tmpn /= 10)
        len++;
    len += negative;
    if ((str = malloc(sizeof(char) * len)) == NULL)
        return (NULL);
    str[--len] = '\0';
    while (len--) {
        str[len] = n % 10 + '0';
        n = n / 10;
    }
    return (str);
}

void destroy(runner_t *runner, sprite_t *sprite, offset_t *offset)
{
    sfMusic_stop(runner->jump_sound);
    sfMusic_stop(runner->game_music);
    sfMusic_destroy(runner->game_music);
    sfMusic_destroy(runner->jump_sound);
    sfText_destroy(runner->text.text2);
    sfText_destroy(runner->text.text);
    for (int i = 0; i <= 15; i++)
        sfSprite_destroy(sprite->back[i]);
    for (int i = 0; i < runner->ennemy.number; i++) {
        sfSprite_destroy(runner->ennemy.ennemy_sprite[i]);
    }
    for (int i = 0; i < 9; i++)
        sfSprite_destroy(runner->menu.sprite_player[i]);
    sfClock_destroy(runner->clock);
    sfSprite_destroy(create_sprite_restart(runner));
    sfFont_destroy(runner->text.font);
}

int restart(runner_t *runner, sprite_t *sprite, offset_t *offset)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(runner->end.restart);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(runner->window);
    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y) ||
    sfKeyboard_isKeyPressed(sfKeyR)) {
        if (sfMouse_isButtonPressed(sfMouseLeft) ||
        sfKeyboard_isKeyPressed(sfKeyR)) {
            count_ennemy(runner->map_string, runner);
            setup(sprite, runner, offset);
            reset_ground(runner, sprite);
            sfSprite_setPosition(sprite->player, (sfVector2f) {0, 390});
            display_score(runner);
            return (1);
        }
    }
    return (0);
}

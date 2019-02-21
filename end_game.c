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

int end_game(runner_t *runner, sprite_t *sprite, offset_t *offset)
{
    sfEvent evenement;
    sfClock_destroy(runner->clock);
    create_sprite_end(runner, sprite, 0, 0);
    create_sprite_restart(runner);
    end_text(runner);
    sfText_setPosition(runner->text.text2, (sfVector2f){458, 100});
    while (sfRenderWindow_isOpen(runner->window)) {
        sfRenderWindow_clear(runner->window, sfCyan);
        dispay_end(runner);
        event_loop(evenement, runner, sprite, offset);
        if (restart(runner, sprite, offset) == 1)
            return (0);
        sfRenderWindow_display(runner->window);
    }
}

sfSprite *create_sprite_end(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile
    ("sprite/end.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){0, 0});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    runner->end.end_back = sprites;
    return (sprites);
}

void end_text(runner_t *runner)
{
    sfText_setString(runner->text.text_end, "your score : ");
    sfText_setFont(runner->text.text_end, runner->text.font);
    sfText_setCharacterSize(runner->text.text_end, 30);
    sfText_setPosition(runner->text.text_end, (sfVector2f){280, 100});
    sfText_setColor(runner->text.text_end, (sfColor){1, 1, 1, 255});
}

void dispay_end(runner_t *runner)
{
    sfRenderWindow_drawSprite(runner->window, runner->end.end_back, NULL);
    sfRenderWindow_drawSprite(runner->window, runner->end.restart, NULL);
    sfRenderWindow_drawText(runner->window, runner->text.text_end, NULL);
    sfRenderWindow_drawText(runner->window, runner->text.text2, NULL);
}

sfSprite *create_sprite_restart(runner_t *runner)
{
    sfTexture *back = sfTexture_createFromFile
    ("sprite/restart.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){340, 300});
    sfSprite_setScale(sprites, (sfVector2f){0.35, 0.35});
    sfSprite_setTexture(sprites, back, sfTrue);
    runner->end.restart = sprites;
    return (sprites);
}

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

int start(runner_t *runner, sprite_t *sprite, offset_t *offset, sfEvent ev)
{
    runner->text.difficulty = 1;
    runner->menu.pick = 0;
    sfSprite *space = create_sprite(0.34, "sprite/space.png", 32, 507);
    sfSprite *start_screen_sprite = start_screen();
    generate_sprite(runner);
    while (sfRenderWindow_isOpen(runner->window)) {
        sfRenderWindow_clear(runner->window, sfCyan);
        event_loop(ev, runner, sprite, offset);
        sfRenderWindow_drawSprite(runner->window, start_screen_sprite, NULL);
        display_start(runner);
        choose_color(runner);
        sfRenderWindow_drawSprite(runner->window, space, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
            sfRenderWindow_clear(runner->window, sfCyan);
            return (0);
        }
        sfRenderWindow_display(runner->window);
    }
}

sfSprite *start_screen(void)
{
    sfTexture *back = sfTexture_createFromFile("sprite/start.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){0, 0});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

void setup_text_difficulty(runner_t *runner)
{
    char *str = malloc(sizeof(char) * 3);
    str = my_itoa(runner->text.difficulty);
    sfText_setString(runner->text.text_difficulty, str);
    sfText_setFont(runner->text.text_difficulty, runner->text.font);
    sfText_setCharacterSize(runner->text.text_difficulty, 90);
    sfText_setPosition(runner->text.text_difficulty, (sfVector2f){110, 350});
    sfText_setColor(runner->text.text_difficulty, (sfColor){1, 1, 1, 255});
}

void choose_difficulty(runner_t *runner)
{
    int condition = 0;
    sfTime time1;
    float sec = 0;
    time1 = sfClock_getElapsedTime(runner->clock);
    sec = time1.microseconds / 50000;

    if (sec >= 1.5) {
        if (sfKeyboard_isKeyPressed(sfKeyUp) && runner->text.difficulty < 10) {
            condition = 1;
            runner->text.difficulty++;
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown) && runner->text.difficulty > 0) {
            condition = 2;
            runner->text.difficulty--;
        }
        sfClock_restart(runner->clock);
    }
}

void reset_ground(runner_t *runner, sprite_t *sprite)
{
    sfSprite_destroy(sprite->back[15]);
    sfSprite_destroy(sprite->back[14]);
    sprite->back[14] = create_sprite08(runner, sprite, 0, 0);
    sprite->back[15] = create_sprite08(runner, sprite, 790, 0);

}

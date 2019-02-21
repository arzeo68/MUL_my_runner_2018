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

sfSprite *create_sprite05(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile
    ("sprite/_05_hill1.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

sfSprite *create_sprite06(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile
    ("sprite/_04_bushes.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

sfSprite *create_sprite07(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile
    ("sprite/_02_trees and bushes.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

sfSprite *create_sprite08(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile("sprite/_01_ground.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

void play_music(runner_t *runner)
{
    runner->jump_sound = (sfMusic_createFromFile("jump_sound.ogg"));
    runner->game_music = (sfMusic_createFromFile("game_music.ogg"));
    sfMusic_setVolume(runner->game_music, 30.0);
    sfMusic_setLoop(runner->game_music, sfTrue);
    sfMusic_play(runner->game_music);
}

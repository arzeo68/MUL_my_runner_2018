/*
** EPITECH PROJECT, 2018
** repository
** File description:
** runner part 3
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"
#include "include/struct.h"

sfSprite *create_sprite01(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile
    ("sprite/_11_background.png", NULL);
    sfSprite *sprites = sfSprite_create();

    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

sfSprite *create_sprite02(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile
    ("sprite/_10_distant_clouds.png", NULL);
    sfSprite *sprites = sfSprite_create();

    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

sfSprite *create_sprite03(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile("sprite/_08_clouds.png", NULL);
    sfSprite *sprites = sfSprite_create();

    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

sfSprite *create_sprite04(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile
    ("sprite/_07_huge_clouds.png", NULL);
    sfSprite *sprites = sfSprite_create();

    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

void sprite_factory(runner_t *runner, sprite_t *sprite)
{
    sprite->back = malloc(sizeof(sfSprite *) * 16);
    sprite->back[0] = create_sprite01(runner, sprite, 0, 0);
    sprite->back[1] = create_sprite01(runner, sprite, 790, 0);
    sprite->back[2] = create_sprite02(runner, sprite, 0, 0);
    sprite->back[3] = create_sprite02(runner, sprite, 790, 0);
    sprite->back[4] = create_sprite03(runner, sprite, 0, 0);
    sprite->back[5] = create_sprite03(runner, sprite, 790, 0);
    sprite->back[6] = create_sprite04(runner, sprite, 0, 0);
    sprite->back[7] = create_sprite04(runner, sprite, 790, 0);
    sprite->back[8] = create_sprite05(runner, sprite, 0, 0);
    sprite->back[9] = create_sprite05(runner, sprite, 790, 0);
    sprite->back[10] = create_sprite06(runner, sprite, 0, 0);
    sprite->back[11] = create_sprite06(runner, sprite, 790, 0);
    sprite->back[12] = create_sprite07(runner, sprite, 0, 0);
    sprite->back[13] = create_sprite07(runner, sprite, 790, 0);
    sprite->back[14] = create_sprite08(runner, sprite, 0, 0);
    sprite->back[15] = create_sprite08(runner, sprite, 790, 0);
    sprite->player = runner->menu.sprite_player[runner->menu.pick];
    sfSprite_setPosition(sprite->player, (sfVector2f){0, 390});
    sprite->ground_ennemy = create_sprite_ennemy_ground(runner, sprite, 0, 0);
}

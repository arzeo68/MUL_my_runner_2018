/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** __DESCRIPTION__
*/

#ifndef MY_PRINTF_F_
#define MY_PRINTF_F_

typedef struct offset_s {

    sfVector2f offset[7];

} offset_t;

typedef struct wolf_s {

    sfSprite *wolf_sprite[5];

} wolf_t;

typedef struct text_s {

    sfFont *font;
    sfText *text;
    sfText *text_difficulty;
    sfText *text2;
    sfVector2f pos_score;
    sfText *text_end;
    int difficulty;

} text_t;

typedef struct sprite_s {

    sfSprite *ground_ennemy;
    sfSprite *fly_ennemy;
    sfSprite **back;
    sfSprite *player;
    wolf_t wolf;

} sprite_t;


typedef struct player_s {

    sfVector2f player_pos;
    sfVector2f velocity;
    int gravity;
    int status;
    int score;
    int high_score;
    char *score_displayed;
    sfIntRect rect_player_jump;

} player_t;

typedef struct ennemy_s {

    int number;
    sfSprite **ennemy_sprite;
    int *ennemy_pos;
    sfFloatRect *hitbox_pike;

} ennemy_t;

typedef struct end_s {

    int score;
    sfSprite *end_back;
    sfSprite *restart;

} end_t;

typedef struct menu_s {

    int pick;
    sfSprite **sprite_player;

} menu_t;

typedef struct runner_s {

    sfRenderWindow *window;
    char *map_string;
    sfIntRect rect_ground_ennemy;
    sfIntRect rect_player;
    sfClock *clock;
    int clock_counter;
    sfMusic *game_music;
    sfMusic *jump_sound;
    int sound_status;
    player_t player;
    ennemy_t ennemy;
    text_t text;
    end_t end;
    menu_t menu;

} runner_t;

#endif

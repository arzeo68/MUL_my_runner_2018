/*
** EPITECH PROJECT, 2018
** include
** File description:
** create an include
*/
#include <stdarg.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "struct.h"

#ifndef MY_H_
#define MY_H_

int my_getnbr(char *str);
int my_strlen(char *str);
void my_putchar(char c);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const s2, int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char dest, char const *src, int nb);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
int map_open_read_file(char *filepath, runner_t *runner);
char **my_str_to_word_array(char const *str);
char* my_strdup(char* str);
int my_strlen(char *str);
char *my_strcpy(char *dest, char const *src);
int game_loop(runner_t *runner, sprite_t *sprite, offset_t *offset);
sfRenderWindow *create_the_window(void);
sfEvent event_loop(sfEvent ev, runner_t *runner, sprite_t *sprite,
offset_t *offset);
int close_window(runner_t *runner, sfEvent *event, sprite_t *sprite,
offset_t *offset);
int display_sprite(runner_t *runner, sprite_t *sprite);
void sprite_factory(runner_t *runner, sprite_t *sprite);
sfSprite *create_sprite01(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *create_sprite02(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *create_sprite03(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *create_sprite04(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *create_sprite05(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *create_sprite06(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *create_sprite07(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *create_sprite08(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *create_sprite_ennemy_ground(runner_t *runner,
sprite_t *sprite, int x, int y);
void key_press(sprite_t *sprite, runner_t *runner);
void sprite_move(runner_t *runner, sprite_t *sprite);
sfSprite *create_sprite_player(runner_t *runner,
sprite_t *sprite, int x, int y);
void move_rect_player(sfIntRect *rect);
void player_move(sfIntRect *rect, runner_t *runner, sprite_t *sprite);
int player_jump(sprite_t *sprite, runner_t *runner, offset_t *offset);
void play_music(runner_t *runner);
void move_back(sprite_t *sprite, offset_t *offset, runner_t *runner);
void setup_offset(offset_t *offset);
void reset_back_pos(sprite_t *sprite, runner_t *runner);
char *int_to_str(int nb);
char *my_revstrb(char *str);
int int_test(int nb);
char *patch_first_char(char *str);
int mute(runner_t *runner);
void movement_jump(sprite_t *sprite, runner_t *runner);
void ground_ennemy_move(sfIntRect *rect, runner_t *runner, sprite_t *sprite);
void move_rect_ground_ennemy(sfIntRect *rect);
sfSprite *create_sprite_ennemy_fly(runner_t *runner,
sprite_t *sprite, int x, int y);
void fly_ennemy_move(sfIntRect *rect, runner_t *runner,
sprite_t *sprite, sfClock *clock);
void display_txt(char *txt);
int setup(sprite_t *sprite, runner_t *runner, offset_t *offset);
int hitbox(runner_t *runner, sprite_t *sprite);
int count_ennemy(char *map, runner_t *runner);
sfSprite *ennemy_sprite_ground(int x);
int mob_pos(runner_t *runner);
void stock_ennemy(runner_t *runner);
void setup_wolf(sprite_t *sprite);
sfSprite *wolf_sprite(int x);
void move_ennemy(runner_t *runner, sprite_t *sprite, offset_t *offset);
int score(runner_t *runner);
void display_score(runner_t *runner);
void setup_text(runner_t *runner);
int game_loop_2(runner_t *runner, sprite_t *sprite, offset_t *offset);
char *my_itoa(int n);
void itoa_isnegative(int *n, int *negative);
void destroy(runner_t *runner, sprite_t *sprite, offset_t *offset);
int end_game(runner_t *runner, sprite_t *sprite, offset_t *offset);
sfSprite *create_sprite_end(runner_t *runner, sprite_t *sprite, int x, int y);
void dispay_end(runner_t *runner);
void end_text(runner_t *runner);
sfSprite *create_sprite_restart(runner_t *runner);
int restart(runner_t *runner, sprite_t *sprite, offset_t *offset);
sfSprite *start_screen(void);
int start(runner_t *runner, sprite_t *sprite, offset_t *offset, sfEvent ev);
void setup_text_difficulty(runner_t *runner);
void choose_difficulty(runner_t *runner);
void player_move_jump(sfIntRect *rect, runner_t *runner, sprite_t *sprite);
void move_rect_player_jump(sfIntRect *rect);
void create_sprite_jump(runner_t *runner);
void reset_ground(runner_t *runner, sprite_t *sprite);
void generate_sprite(runner_t *runner);
sfSprite *create_sprite(float size, char *str, int x, int y);
void display_start(runner_t *runner);
void choose_color(runner_t *runner);
void select_color(runner_t *runner);
void help(void);
#endif

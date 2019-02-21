##
## EPITECH PROJECT, 2018
## makefile
## File description:
## Makefile
##

SRC	=	lib/my/my_getnbr.c			\
		lib/my/my_putchar.c			\
		lib/my/my_strlen.c			\
		my_runner.c					\
		create_sprite.c				\
		create_sprite2.c			\
		move_back.c					\
		create_sprite4.c			\
		function_event.c			\
		int_to_str.c				\
		move_ground_ennemy.c		\
		map.c						\
		wolf.c						\
		end_game.c					\
		high_score.c				\
		choose_player.c

OBJ =   $(SRC:.c=.o)

CFLAGS  += -g -I./../../include -pedantic -O2

NAME    =   my_runner

RED =   \033[1m\033[38;2;164;0;0m

GREEN   =   \033[1m\033[38;2;100;245;0m

WHITE = \033[0m

BLUE = \033[1m\033[38;2;0;0;170m

$(NAME):    $(OBJ)
		gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
		rm -f *.o

all:    $(NAME)
		@printf " ----------------------------------\n"
		@printf " |$(BLUE)Compilation du Makefile réussie.$(WHITE)|\n"
		@printf " |$(BLUE)-> BINAIRE:$(WHITE) ./%s    |\n" $(NAME)
		@printf " ----------------------------------\n"

clean:
		@rm -f $(OBJ)
		@printf "Les .o ont bien été supprimés.\n"

fclean: clean
		@rm -f $(NAME)
		@printf "La/Le %s a été supprimé.\n" $(NAME)

re:     fclean all

%.o:    %.c
		@echo -en "${BLUE}$@${WHITE} "; $(CC) -c -o $@ $< ${CFLAGS}; if [ $$? -eq 0 ]; then echo -e "${GREEN}[OK]${WHITE}"; else echo -e "${RED}[ERROR]${WHITE}"; fi; echo;

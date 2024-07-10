##
## EPITECH PROJECT, 2023
## B-CPE-101-LYN-1-1-myprintf-alexis.drago-beltran
## File description:
## Makefile
##

SRC = my_itoa.c \
	my_swap_char.c \
	my_strcat.c \
	my_strlen.c \
	my_intlen.c \
	my_strcmp.c \
	../../src/event_manager.c \
	../../src/game.c \
	../../src/fct/shorten.c \
	../../src/get/get.c \
	../../src/sprites/delete.c \
	../../src/sprites/sprite.c \
	../../src/sprites/animate.c \
	../../src/sprites/move.c \
	../../src/sprites/object.c \
	../../src/interface/scoreboard.c \
	../../src/interface/set_text.c \
	../../src/settings/set_settings.c \

OBJ = ${SRC:.c=.o}
CFLAGS = -g3
NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME}
re: fclean all

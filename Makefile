##
## EPITECH PROJECT, 2023
## B-MUL-100-LYN-1-1-myhunter-marin.lagie
## File description:
## Makefile
##

SRC = src/my_hunters.c
NAME = my_hunter
CFLAGS += -g3
OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME} : ${OBJ}
	make -C lib/my all
	gcc ${OBJ} -o ${NAME} -L./lib/my -lmy -lcsfml-graphics -lcsfml-system

clean:
		make -C lib/my clean
		rm -f ${OBJ}
fclean: clean
	make -C lib/my fclean
	rm -f ${NAME}
re: fclean all

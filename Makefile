##
## EPITECH PROJECT, 2022
## my_lib makefile
## File description:
## task01
##

NAME	=	push_swap

SRC		=	stacking_sort.c \
			stack_a.c \
			stack_b.c \
			tools.c \
			stack_mem.c \
			main.c

all:
	make -C lib/my
	gcc -no-pie -o $(NAME) $(SRC) -L lib -lmy

clean:
	make -C lib/my clean

fclean:
	make -C lib/my fclean
	rm -f $(NAME)

re:
	make fclean
	make all

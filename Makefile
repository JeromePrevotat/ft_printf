CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = -L. -lft
NAME = print

DIR_SRC = ./src/
DIR_OBJ = ./obj/

SRCS += ./src/main.c
SRCS += ./src/ft_printf.c
SRCS += ./src/parsing.c
SRCS += ./src/select_type.c
SRCS += ./src/cat.c
SRCS += ./src/utils.c
SRCS += ./src/itoa_base.c

INC += ./inc/ft_printf.h
INC += ./inc/libft.h

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(LIB) $(MLXFLAGS) $(SRCS) -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

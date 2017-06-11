CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = -L. -lft
NAME = print

DIR_SRC = ./src/

SRCS += ./src/main.c
SRCS += ./src/ft_printf.c
SRCS += ./src/parsing.c
SRCS += ./src/conversion.c
SRCS += ./src/argument.c
SRCS += ./src/utils.c
SRCS += ./src/itoa_base.c

INC += ./inc/ft_printf.h
INC += ./inc/libft.h

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(LIB) $(SRCS) -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

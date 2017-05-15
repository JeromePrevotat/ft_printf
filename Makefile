CC = gcc
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I inc
CLIB = -L. -lft
NAME = print

DIR_SRC = ./src/
DIR_OBJ = ./obj/

SRCS += main.c
SRCS += ft_printf.c
SRCS += parsing.c
SRCS += utils.c

INC += ./inc/ft_printf.h
INC += ./inc/libft.h

SRC = $(addprefix $(DIR_SRC),$(SRCS))
OBJ = $(subst $(DIR_SRC),$(DIR_OBJ),$(subst .c,.o,$(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(IFLAGS) $(CLIB) $(OBJ)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(DIR_OBJ) $(INC)
	$(CC) -o $@ $(CFLAGS) $(IFLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

$(DIR_OBJ):
	mkdir -p $@
	mkdir -p $@/libft

.PHONY: clean

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = -L. -lft
NAME = print

DIR_SRC = ./src/


SRCS += ./src/main.c

SRCS += ./src/ft_printf.c
SRCS += ./src/parsing_utils.c

SRCS += ./src/init_arg.c
SRCS += ./src/convert.c

SRCS += ./src/special_flags.c
SRCS += ./src/set_size_flags.c
SRCS += ./src/apply_size_flags.c
SRCS += ./src/set_form_flags.c
SRCS += ./src/apply_form_flags.c

SRCS += ./src/nbr_conv.c
SRCS += ./src/char_conv.c

SRCS += ./src/itoa_base.c
SRCS += ./src/utils.c

SRCS += ./src/wchar_functions.c

INC += ./inc/ft_printf.h
INC += ./inc/libft.h

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(LIB) $(SRCS) -o $@
	$(MAKE) clean

.PHONY: clean
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

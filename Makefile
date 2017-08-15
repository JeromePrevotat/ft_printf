CC = gcc
CFLAGS = -Wall -Werror -Wextra
#NAME = print
NAME = libftprintf.a

#SRCS += ./src/main.c
SRCS += ./src/ft_putendl.c
SRCS += ./src/ft_putchar.c

SRCS += ./src/ft_printf.c
SRCS += ./src/cat_functions.c
SRCS += ./src/parsing_utils.c

SRCS += ./src/flags_parsing.c

SRCS += ./src/undefined_behaviour.c

SRCS += ./src/init_arg.c
SRCS += ./src/fill_arg.c
SRCS += ./src/convert.c

SRCS += ./src/special_flags.c
SRCS += ./src/set_size_flags.c
SRCS += ./src/apply_size_flags.c
SRCS += ./src/set_form_flags.c
SRCS += ./src/apply_form_flags.c
SRCS += ./src/zero_flag.c

SRCS += ./src/precision.c
SRCS += ./src/width.c

SRCS += ./src/nbr_conv.c
SRCS += ./src/char_conv.c

SRCS += ./src/r_value.c

SRCS += ./src/itoa_base.c
SRCS += ./src/itoa.c
SRCS += ./src/utils.c

SRCS += ./src/wchar_functions.c

SRCS += ./src/ft_atoi.c
SRCS += ./src/ft_isdigit.c
SRCS += ./src/ft_memset.c
SRCS += ./src/ft_strlen.c
SRCS += ./src/ft_memcpy.c
SRCS += ./src/ft_putstr.c


INC += ./inc/ft_printf.h
INC += ./inc/libft.h

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	#$(CC) $(CFLAGS) $(SRCS) -o $@
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

.PHONY: clean
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

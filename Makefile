CC = gcc
#CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

TEST = print

SRCS_T +=./src/main.c

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
SRCS += ./src/apply_flags.c
SRCS += ./src/special_flags.c
SRCS += ./src/set_size_flags.c
SRCS += ./src/apply_size_flags.c
SRCS += ./src/set_form_flags.c
SRCS += ./src/apply_form_flags.c
SRCS += ./src/zero_flag.c
SRCS += ./src/apply_zero.c
SRCS += ./src/precision.c
SRCS += ./src/apply_nbr_pre.c
SRCS += ./src/apply_ptr_pre.c
SRCS += ./src/width.c
SRCS += ./src/nbr_conv.c
SRCS += ./src/signed_nbr_conv.c
SRCS += ./src/unsigned_nbr_conv.c
SRCS += ./src/char_conv.c
SRCS += ./src/itoa.c
SRCS += ./src/utils.c
SRCS += ./src/wchar_functions.c
SRCS += ./src/buff.c
SRCS += ./src/ft_atoi.c
SRCS += ./src/ft_isdigit.c
SRCS += ./src/ft_memset.c
SRCS += ./src/ft_strlen.c
SRCS += ./src/ft_memcpy.c
SRCS += ./src/ft_putstr.c
SRCS += ./src/ft_strcmp.c
SRCS += ./src/ft_strdup.c

SRCS += ./src/bonus.c
SRCS += ./src/binary_conv.c
SRCS += ./src/bonus_alt_form.c

INC += ./inc/ft_printf.h
INC += ./inc/libft.h

OBJ = $(SRCS:.c=.o)
OBJ_T = $(SRCS_T:.c=.o)

all: $(NAME) $(TEST)

$(NAME): $(OBJ) $(INC)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(TEST): $(OBJ) $(OBJ_T) $(INC)
	$(CC) -g $(CFLAGS) $(SRCS) $(SRCS_T) -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ) $(OBJ_T)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

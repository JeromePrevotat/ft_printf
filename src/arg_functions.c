/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:59:53 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/24 18:02:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/ft_printf.h"

int	init_flags_arg(t_arg *arg)
{
	arg->flags.alt_form = FALSE;
	arg->flags.zero = FALSE;
	arg->flags.minus = FALSE;
	arg->flags.plus = FALSE;
	arg->flags.space = FALSE;
	arg->flags.h = FALSE;
	arg->flags.hh = FALSE;
	arg->flags.l = FALSE;
	arg->flags.ll = FALSE;
	arg->flags.j = FALSE;
	arg->flags.z = FALSE;
	return (1);
}

int	init_type_arg(t_arg *arg)
{
	char	c;

	c = arg->str_form[ft_strlen(arg->str_form) - 1];
	if (c == 'd' || c == 'i' || c == 'D' || c == 'o' || c == 'O' || c == 'u'
		|| c == 'U' || c == 'x' || c == 'X' || c == 'p')
		arg->type = T_INT;
	if (c == 'c')
		arg->type = T_CHAR;
	if (c == 'C')
		arg->type = T_WCHAR;
	if (c == 's')
		arg->type = T_STR;
	if (c == 'S')
		arg->type = T_WSTR;
	if (c == '%')
		arg->type = T_CHAR;
	if (c == 'p')
		arg->type = T_PTR;
	return (1);
}

int	init_conv_arg(t_arg *arg)
{
	char	c;

	c = arg->str_form[ft_strlen(arg->str_form) - 1];
	if (c == 'd' || c == 'i')
		arg->conv = -10;
	if (c == 'D')
		arg->conv = -100;
	if (c == 'o')
		arg->conv = 8;
	if (c == 'O')
		arg->conv = 80;
	if (c == 'u')
		arg->conv = 10;
	if (c == 'U')
		arg->conv = 100;
	if (c == 'x')
		arg->conv = 16;
	if (c == 'X')
		arg->conv = 160;
	if (c == 'c')
		arg->conv = 2;
	if (c == 'C')
		arg->conv = 20;
	if (c == 's')
		arg->conv = 3;
	if (c == 'S')
		arg->conv = 30;
	if (c == 'p')
		arg->conv = 4;
	if (c == '%')
		arg->conv = '%';
	return (1);
}

int		parse_flags(t_arg *arg)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(arg->str_form))
	{
		if (is_flag(arg, i) == FALSE)
			return (FALSE);
		if (is_flag(arg, i) == 2)
			i++;
		i++;
	}
	return (TRUE);
}

int		convert_argv(t_arg *arg, va_list ap)
{
	if (arg->type == T_INT)
		int_conv(arg, ap);
	if (arg->type == T_LONG)
		long_conv(arg, ap);
	if (arg->type == T_LLONG)
		llong_conv(arg, ap);
	if (arg->type == T_CHAR)
		char_conv(arg, ap);
	if (arg->type == T_STR)
		str_conv(arg, ap);
	if (arg->type == T_WCHAR)
		wchar_conv(arg, ap);
	if (arg->type == T_WSTR)
		wstr_conv(arg, ap);
	if (arg->type == T_PTR)
		ptr_conv(arg, ap);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c  	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"


int	init_arg(t_arg *arg)
{
	if (arg->str_form == NULL)
	{
		if (!(arg->str_form = (char *)malloc(1 * sizeof(char))))
			return (-1);
		ft_memset(arg->str_form, '\0', 1);
	}
	if (arg->converted_form == NULL)
	{
		if (!(arg->converted_form = (char *)malloc(1 * sizeof(char))))
			return (-1);
		ft_memset(arg->converted_form, '\0', 1);
	}
	if (arg->wconverted_form == NULL)
	{
		if (!(arg->wconverted_form = (wchar_t *)malloc(1 * sizeof(wchar_t))))
			return (-1);
		ft_memset(arg->wconverted_form, '\0', 1);
	}
	else
	{
		ft_memset(arg->str_form, '\0', ft_strlen(arg->str_form));
		ft_memset(arg->converted_form, '\0', ft_strlen(arg->converted_form));
		ft_memset(arg->wconverted_form, '\0', 1);
	}
	return (1);
}

int	fill_arg(t_arg *arg, va_list ap)
{
	arg->wchar_form = 0;
	init_flags_arg(arg);
	init_type_arg(arg);
	init_conv_arg(arg);
	parse_flags(arg);
	apply_size_flag(arg);
	convert_argv(arg, ap);
	apply_form_flag(arg);
	return (1);
}

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

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
		if (!(arg->str_form = (wchar_t *)malloc(2 * sizeof(wchar_t))))
			return (ERROR);
		ft_memset(arg->str_form, '\0', 2);
	}
	else
		ft_memset(arg->str_form, '\0', ft_wstrlen(arg->str_form));
	if (arg->converted_form == NULL)
	{
		if (!(arg->converted_form = (char *)malloc(2 * sizeof(char))))
			return (ERROR);
		ft_memset(arg->converted_form, '\0', 2);
	}
	else
		ft_memset(arg->converted_form, '\0', ft_strlen(arg->converted_form));
	if (arg->wconverted_form != NULL)
	{
		ft_memset(arg->wconverted_form, '\0', ft_wstrlen(arg->wconverted_form));
		arg->wconverted_form = NULL;
	}
	ft_memset(&arg->argv, '\0', 1 * sizeof(t_argv));
	return (TRUE);
}

int	fill_arg(t_arg *arg, va_list ap)
{
	arg->width = 0;
	arg->precision = 0;
	arg->wchar_form = FALSE;
	init_flags_arg(arg);
	init_type_arg(arg);
	init_conv_arg(arg);
	/*if (parse_flags(arg) == FALSE)
	{
		arg->wconverted_form = get_undefined_behaviour(arg);
		return (1);
	}*/
	parse_flags(arg);
	apply_size_flag(arg);
	convert_argv(arg, ap);
	apply_flags(arg);
	return (1);
}

void	init_flags_arg(t_arg *arg)
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
	arg->flags.precision = FALSE;
	arg->flags.width = FALSE;
}

void	init_type_arg(t_arg *arg)
{
	wchar_t	c;

	c = arg->str_form[ft_wstrlen(arg->str_form) - 1];
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
}

void	init_conv_arg(t_arg *arg)
{
	wchar_t	c;

	c = arg->str_form[ft_wstrlen(arg->str_form) - 1];
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
}

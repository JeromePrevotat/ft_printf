/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conv.c  	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		uchar_conv(t_arg *arg, va_list ap)
{
	if (arg->conv == '%')
		arg->converted_form = str_memcat(arg->converted_form, "%", 1, 1);
	else
	{
		arg->argv.c_arg = (unsigned char)va_arg(ap, int);
		if (arg->argv.c_arg == 0)
			return (1);
		arg->converted_form = str_memcat(arg->converted_form, &arg->argv.c_arg, 1, 1);
	}
	return (TRUE);
}

int		char_conv(t_arg *arg, va_list ap)
{
	if (arg->conv == '%')
		arg->converted_form = str_memcat(arg->converted_form, "%", 1, 1);
	else
	{
		arg->argv.c_arg = (char)va_arg(ap, int);
		if (arg->argv.c_arg == 0)
			return (1);
		if (arg->flags.hh == TRUE)
		{
			arg->conv = -10;
			arg->type = T_INT;
			arg->argv.i_arg = arg->argv.c_arg;
			arg->converted_form = str_memcat(arg->converted_form, convert(arg), ft_strlen(convert(arg)), 1);
		}
		else
			arg->converted_form = str_memcat(arg->converted_form, &arg->argv.c_arg, 1, 1);
	}
	return (TRUE);
}

void	str_conv(t_arg *arg, va_list ap)
{
	arg->argv.str_arg = va_arg(ap, char *);
	if (arg->argv.str_arg == NULL)
		arg->converted_form = str_memcat(arg->converted_form, "(null)", 6, 1);
	else
		arg->converted_form = str_memcat(arg->converted_form, arg->argv.str_arg, ft_strlen(arg->argv.str_arg), 1);
}

void	wchar_conv(t_arg *arg, va_list ap)
{
	arg->argv.wchar_arg = va_arg(ap, wchar_t);
	arg->wchar_form = TRUE;
	arg->wconverted_form = wstr_memcat(arg->wconverted_form, &arg->argv.wchar_arg, 1, 1);
}

void	wstr_conv(t_arg *arg, va_list ap)
{
	arg->argv.wstr_arg = va_arg(ap, wchar_t *);
	arg->wchar_form = TRUE;
	arg->wconverted_form = wstr_memcat(arg->wconverted_form, arg->argv.wstr_arg, ft_wstrlen(arg->argv.wstr_arg), 1);
}

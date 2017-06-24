/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c   		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		convert_argv(t_arg *arg, va_list ap)
{
	if (arg->type == T_SIZET)
		st_conv(arg, ap);
	if (arg->type == T_SHORT)
		short_conv(arg, ap);
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

char	*convert(t_arg *arg)
{
	//Size_t
	if ((arg->conv == 8 || arg->conv == 10 || arg->conv == 16 || arg->conv == 160)
		&& (arg->type == T_SIZET))
		return (itoa_base_unsigned(arg->argv.st_arg, arg->conv));
	//Signed Decimal
	if (arg->conv == -10 && (arg->type == T_INT))
		return (itoa_base(arg->argv.i_arg, 10));
	//LONG SIGNED DECIMAL
	if (arg->conv == -10 && ((arg->type == T_LONG) || (arg->type == T_LLONG)))
		return (itoa_base_long(arg->argv.l_arg, 10));
	//Unsigned Octal
	if (arg->conv == 8)
		return (itoa_base_unsigned(arg->argv.i_arg, 8));
	//Long Unsigned Octal
	if (arg->conv == 80)
		return (itoa_base_unsigned(arg->argv.i_arg, 8));
	//Unsigned Decimal
	if (arg->conv == 10)
		return (itoa_base_unsigned(arg->argv.i_arg, 10));
	//Long Unsigned Decimal
	if (arg->conv == 100)
		return (itoa_base_unsigned(arg->argv.i_arg, 10));
	//Unsigned Hex
	if (arg->conv == 16)
		return (itoa_base_unsigned(arg->argv.i_arg, 16));
	if (arg->conv == 160)
		return (itoa_base_unsigned(arg->argv.i_arg, 160));
	return (NULL);
}

int		apply_form_flag(t_arg *arg)
{
	if (arg->flags.alt_form == TRUE)
		apply_alt_form(arg);
	if (arg->flags.zero == TRUE)
		apply_zero(arg);
	if (arg->flags.minus == TRUE)
		apply_minus(arg);
	if (arg->flags.plus == TRUE)
		apply_plus(arg);
	if (arg->flags.space == TRUE)
		apply_space(arg);
	return (0);
}

int		apply_size_flag(t_arg *arg)
{
	if (arg->flags.h == TRUE)
		apply_h(arg);
	if (arg->flags.hh == TRUE)
		apply_hh(arg);
	if (arg->flags.l == TRUE)
		apply_l(arg);
	if (arg->flags.ll == TRUE)
		apply_ll(arg);
	if (arg->flags.j == TRUE)
		apply_j(arg);
	if (arg->flags.z == TRUE)
		apply_z(arg);
	return (0);
}

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
	if (arg->type == T_IMAX)
		imax_conv(arg, ap);
	if (arg->type == T_UIMAX)
		uimax_conv(arg, ap);
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
	int base;

	base = arg->conv;
	if (base < 0)
		base = -base;
	if (base > 16 && base != 160)
		base = base / 10;
	//SIGNED CONV
	if (arg->conv < 0)
	{
		if (arg->type == T_SHORT)
			return (itoa_base(arg->argv.sh_arg, base));
		if (arg->type == T_INT)
			return (itoa_base(arg->argv.i_arg, base));
		if (arg->type == T_SIZET)
			return (itoa_base_st(arg->argv.st_arg, base));
		if (arg->type == T_LONG)
			return (itoa_base_long(arg->argv.l_arg, base));
		if (arg->type == T_LLONG)
			return (itoa_base_llong(arg->argv.ll_arg, base));
		if (arg->type == T_IMAX)
			return (itoa_base_imax(arg->argv.imax_arg, base));
	}
	//UNSIGNED CONV
	else
	{
		if (arg->type == T_SHORT)
			return (itoa_base_unsigned(arg->argv.sh_arg, base));
		if (arg->type == T_INT)
			return (itoa_base_unsigned(arg->argv.i_arg, base));
		if (arg->type == T_SIZET)
			return (itoa_base_st(arg->argv.st_arg, base));
		if (arg->type == T_LONG)
			return (itoa_base_unsigned_long(arg->argv.l_arg, base));
		if (arg->type == T_LLONG)
			return (itoa_base_unsigned_llong(arg->argv.ll_arg, base));
		if (arg->type == T_UIMAX)
			return (itoa_base_uimax(arg->argv.uimax_arg, base));
	}
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
	return (FALSE);
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
	return (FALSE);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_conv.c  	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		st_conv(t_arg *arg, va_list ap)
{
	arg->argv.st_arg = va_arg(ap, size_t);
	if (arg->conv == 8 || arg->conv == 10 || arg->conv == 16 || arg->conv == 160)
		arg->converted_form = str_memcat(arg->converted_form,
			convert(arg), ft_strlen(convert(arg)));
	return (1);
}

int		short_conv(t_arg *arg, va_list ap)
{
	arg->argv.sh_arg = va_arg(ap, int);
	if (arg->conv == 8 || arg->conv == 10 || arg->conv == 16 || arg->conv == 160)
		arg->converted_form = str_memcat(arg->converted_form,
			convert(arg), ft_strlen(convert(arg)));
	return (1);
}

int		int_conv(t_arg *arg, va_list ap)
{
	arg->argv.i_arg = va_arg(ap, int);
	if (arg->conv == -10 || arg->conv == -100 || arg->conv == 8 || arg->conv == 80 || arg->conv == 10
		|| arg->conv == 100 || arg->conv == 16 || arg->conv == 160)
		arg->converted_form = str_memcat(arg->converted_form,
			convert(arg), ft_strlen(convert(arg)));
	return (1);
}

int		long_conv(t_arg *arg, va_list ap)
{
	arg->argv.l_arg = va_arg(ap, long);
	if (arg->conv == -10 || arg->conv == -100 || arg->conv == 8 || arg->conv == 80 || arg->conv == 10
		|| arg->conv == 100 || arg->conv == 16 || arg->conv == 160)
		arg->converted_form = str_memcat(arg->converted_form,
			convert(arg), ft_strlen(convert(arg)));
	return (1);
}

int		llong_conv(t_arg *arg, va_list ap)
{
	arg->argv.ll_arg = va_arg(ap, long long);
	if (arg->conv == -10 || arg->conv == -100 || arg->conv == 8 || arg->conv == 80 || arg->conv == 10
		|| arg->conv == 100 || arg->conv == 16 || arg->conv == 160)
		arg->converted_form = str_memcat(arg->converted_form,
			convert(arg), ft_strlen(convert(arg)));
	return (1);
}

int		ptr_conv(t_arg *arg, va_list ap)
{
	void	*p;

	p = va_arg(ap, void *);
	arg->converted_form = str_memcat(arg->converted_form, "0x", 2);
	arg->converted_form = str_memcat(arg->converted_form, itoa_base_long((long)p, 16),
		ft_strlen(itoa_base_long((long)p, 16)));
	return (1);
}

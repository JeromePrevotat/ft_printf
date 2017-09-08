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

void	st_conv(t_arg *arg, va_list ap)
{
	arg->argv.imax_arg = (size_t)va_arg(ap, size_t);
	if (arg->conv == -10 || arg->conv == 8 || arg->conv == 10
		|| arg->conv == 16 || arg->conv == 160)
		//arg->converted_form = convert(arg);
		convert(arg);
}

void	ushort_conv(t_arg *arg, va_list ap)
{
	arg->argv.uimax_arg = (unsigned short)va_arg(ap, int);
	if (arg->conv == 8 || arg->conv == 10 || arg->conv == 16 || arg->conv == 160)
		//arg->converted_form = convert(arg);
		convert(arg);
}

void	short_conv(t_arg *arg, va_list ap)
{
	arg->argv.imax_arg = (short)va_arg(ap, int);
	if (arg->conv == -10)
		//arg->converted_form = convert(arg);
		convert(arg);
}

void	uint_conv(t_arg *arg, va_list ap)
{
	arg->argv.uimax_arg = (unsigned int)va_arg(ap, int);
	if (arg->conv == 8 || arg->conv == 10 || arg->conv == 16 || arg->conv == 160)
		//arg->converted_form = convert(arg);
		convert(arg);
}

void	int_conv(t_arg *arg, va_list ap)
{
	arg->argv.imax_arg = (int)va_arg(ap, int);
	if (arg->conv == -10 || arg->conv == 8 || arg->conv == 10 || arg->conv == 16 || arg->conv == 160)
		//arg->converted_form = convert(arg);
		convert(arg);
}

void	ulong_conv(t_arg *arg, va_list ap)
{
	arg->argv.uimax_arg = (unsigned long)va_arg(ap, long);
	if (arg->conv == 8 || arg->conv == 10 || arg->conv == 16 || arg->conv == 160
		|| arg->conv == 80 || arg->conv == 100)
		//arg->converted_form = convert(arg);
		convert(arg);
}

void	long_conv(t_arg *arg, va_list ap)
{
	arg->argv.imax_arg = (long)va_arg(ap, long);
	if (arg->conv == -10 || arg->conv == -100 || arg->conv == 100)
		//arg->converted_form = convert(arg);
		convert(arg);
}

void	ullong_conv(t_arg *arg, va_list ap)
{
	arg->argv.uimax_arg = (unsigned long long)va_arg(ap, long long);
	if (arg->conv == 8 || arg->conv == 10 || arg->conv == 16 || arg->conv == 160)
		//arg->converted_form = convert(arg);
		convert(arg);
}

void	llong_conv(t_arg *arg, va_list ap)
{
	arg->argv.imax_arg = (long long)va_arg(ap, long long);
	if (arg->conv == -10)
		//arg->converted_form = convert(arg);
		convert(arg);
}

void	uimax_conv(t_arg *arg, va_list ap)
{
	arg->argv.uimax_arg = (uintmax_t)va_arg(ap, uintmax_t);
	if (arg->conv == 8 || arg->conv == 10 || arg->conv == 16 || arg->conv == 160)
		//arg->converted_form = convert(arg);
		convert(arg);
}

void	imax_conv(t_arg *arg, va_list ap)
{
	arg->argv.imax_arg = (intmax_t)va_arg(ap, intmax_t);
	if (arg->conv == -10)
		//arg->converted_form = convert(arg);
		convert(arg);
}

void	ptr_conv(t_arg *arg, va_list ap)
{
	void	*p;

	p = (void *)va_arg(ap, void *);
	//arg->converted_form = str_memcat(arg->converted_form, "0x", 2, 1);
	arg->flags.alt_form = TRUE;
	//arg->converted_form = str_memcat(arg->converted_form, itoa_base_imax((long)p, 16), ft_strlen(itoa_base_imax((long)p, 16)), 1);
	cat_str_buffer(arg->converted_form, itoa_base_imax((long)p, 16), ft_strlen(itoa_base_imax((long)p, 16)));
}

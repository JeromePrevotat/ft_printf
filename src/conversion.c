/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:59:53 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/24 18:02:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/ft_printf.h"

int		is_conversion(char c)
{
	char	*conv_tab;
	int		i;

	conv_tab = init_conv_tab();
	i = 0;
	while (i < 15)
	{
		if (c == conv_tab[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*init_conv_tab(void)
{
	char *conv_tab;

	if (!(conv_tab = (char *)malloc(15 * sizeof(char))))
		return (NULL);
	conv_tab[0] = '%';
	conv_tab[1] = 's';
	conv_tab[2] = 'S';
	conv_tab[3] = 'p';
	conv_tab[4] = 'd';
	conv_tab[5] = 'D';
	conv_tab[6] = 'i';
	conv_tab[7] = 'o';
	conv_tab[8] = 'O';
	conv_tab[9] = 'u';
	conv_tab[10] = 'U';
	conv_tab[11] = 'x';
	conv_tab[12] = 'X';
	conv_tab[13] = 'c';
	conv_tab[14] = 'C';
	return (conv_tab);
}

int		int_conv(t_arg *arg, va_list ap)
{
	arg->argv.i_arg = va_arg(ap, int);
	if (arg->conv == -10 || arg->conv == -100 || arg->conv == 8 || arg->conv == 80 || arg->conv == 10
		|| arg->conv == 100 || arg->conv == 16 || arg->conv == 160)
		arg->converted_form = str_memcat(arg->converted_form,
			convert(arg->argv.i_arg, arg->conv), ft_strlen(convert(arg->argv.i_arg, arg->conv)));
	return (1);
}

int		long_conv(t_arg *arg, va_list ap)
{
	arg->argv.l_arg = va_arg(ap, long);
	if (arg->conv == -10 || arg->conv == -100 || arg->conv == 8 || arg->conv == 80 || arg->conv == 10
		|| arg->conv == 100 || arg->conv == 16 || arg->conv == 160)
		arg->converted_form = str_memcat(arg->converted_form,
			convert(arg->argv.l_arg, arg->conv), ft_strlen(convert(arg->argv.l_arg, arg->conv)));
	return (1);
}

int		llong_conv(t_arg *arg, va_list ap)
{
	arg->argv.ll_arg = va_arg(ap, long long);
	if (arg->conv == -10 || arg->conv == -100 || arg->conv == 8 || arg->conv == 80 || arg->conv == 10
		|| arg->conv == 100 || arg->conv == 16 || arg->conv == 160)
		arg->converted_form = str_memcat(arg->converted_form,
			convert(arg->argv.ll_arg, arg->conv), ft_strlen(convert(arg->argv.ll_arg, arg->conv)));
	return (1);
}

int		char_conv(t_arg *arg, va_list ap)
{
	arg->argv.c_arg = va_arg(ap, int);
	arg->converted_form = str_memcat(arg->converted_form, &arg->argv.c_arg, 1);
	return (1);
}

int		str_conv(t_arg *arg, va_list ap)
{
	arg->argv.str_arg = va_arg(ap, char *);
	arg->converted_form = str_memcat(arg->converted_form, arg->argv.str_arg, ft_strlen(arg->argv.str_arg));
	return (1);
}

int		wchar_conv(t_arg *arg, va_list ap)
{
	arg->argv.wchar_arg = va_arg(ap, wchar_t);
	return (1);
}

int		wstr_conv(t_arg *arg, va_list ap)
{
	arg->argv.wstr_arg = va_arg(ap, wchar_t *);
	return (1);
}

char	*convert(int x, int type)
{
	//Signed Decimal
	if (type == -10)
		return (itoa_base(x, 10));
	//Long Signed Decimal
	if (type == -100)
		return (itoa_base(x, 10));
	//Unsigned Octal
	if (type == 8)
		return (itoa_base_unsigned(x, 8));
	//Long Unsigned Octal
	if (type == 80)
		return (itoa_base_unsigned(x, 8));
	//Unsigned Decimal
	if (type == 10)
		return (itoa_base_unsigned(x, 10));
	//Long Unsigned Decimal
	if (type == 100)
		return (itoa_base_unsigned(x, 10));
	//Unsigned Hex
	if (type == 16)
		return (itoa_base_unsigned(x, 16));
	if (type == 160)
		return (itoa_base_unsigned(x, 160));
	return (NULL);
}

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
		//arg->converted_form = str_memcat(arg->converted_form, "%\0", 2, 1);
		cat_str_buffer(arg->converted_form, "%", 1);
	else
	{
		arg->argv.uc_arg = (unsigned char)va_arg(ap, unsigned int);
		if (arg->flags.hh == TRUE)
		{
			arg->type = T_UINT;
			arg->argv.uimax_arg = arg->argv.uc_arg;
			//arg->converted_form = convert(arg);
			convert(arg);
		}
		else if (arg->argv.c_arg == 0)
			//arg->converted_form = str_memcat(arg->converted_form, "0\0", 2, 1);
			cat_str_buffer(arg->converted_form, "0", 1);
		else
			//arg->converted_form = &arg->argv.c_arg;
			cat_str_buffer(arg->converted_form, &arg->argv.c_arg, 1);
	}
	return (TRUE);
}

int		char_conv(t_arg *arg, va_list ap)
{
	if (arg->conv == '%')
		//arg->converted_form = str_memcat(arg->converted_form, "%\0", 2, 1);
		cat_str_buffer(arg->converted_form, "%", 1);
	else
	{
		arg->argv.c_arg = (char)va_arg(ap, int);
		if (arg->flags.hh == TRUE && (arg->str_form[ft_strlen(arg->str_form) - 1] == 'd'
			|| arg->str_form[ft_strlen(arg->str_form) - 1] == 'i'))
		{
			arg->conv = -10;
			arg->type = T_INT;
			arg->argv.imax_arg = arg->argv.c_arg;
			//arg->converted_form = convert(arg);
			convert(arg);
		}
		else
			//arg->converted_form = str_memcat(arg->converted_form, &arg->argv.c_arg, 1, 1);
			cat_str_buffer(arg->converted_form, &arg->argv.c_arg, 1);
	}
	return (TRUE);
}

void	str_conv(t_arg *arg, va_list ap)
{
	char	*null;

	null = NULL;
	arg->argv.str_arg = (char *)va_arg(ap, char *);
	if (arg->argv.str_arg == NULL)
	{
		if (!((null) = (char *)malloc(7 * sizeof(char))))
			return ;
		ft_memset(null, '\0', 7);
		null[0] = '(';
		null[1] = 'n';
		null[2] = 'u';
		null[3] = 'l';
		null[4] = 'l';
		null[5] = ')';
		null[6] = '\0';
		//arg->converted_form = null;
		cat_str_buffer(arg->converted_form, null, ft_strlen(null));
	}
	else
		//arg->converted_form = str_memcat(arg->converted_form, arg->argv.str_arg, ft_strlen(arg->argv.str_arg), 1);
		cat_str_buffer(arg->converted_form, arg->argv.str_arg, ft_strlen(arg->argv.str_arg));
}

void	wchar_conv(t_arg *arg, va_list ap)
{
	arg->argv.wchar_arg = (wchar_t)va_arg(ap, wchar_t);
	arg->wchar_form = TRUE;
	//arg->converted_form = wstr_to_str(arg, &arg->argv.wchar_arg);
	cat_str_buffer(arg->converted_form, wstr_to_str(arg, &arg->argv.wchar_arg), ft_strlen(wstr_to_str(arg, &arg->argv.wchar_arg)));
	if (arg->argv.wchar_arg == 0)
		arg->converted_form->len = 1;
}

void	wstr_conv(t_arg *arg, va_list ap)
{
	char	*null;
	wchar_t	*tmp;

	null = NULL;
	tmp = NULL;
	arg->argv.wstr_arg = (wchar_t *)va_arg(ap, wchar_t *);
	arg->wchar_form = TRUE;
	if (arg->argv.wstr_arg == NULL)
	{
		if (!((null) = (char *)malloc(7 * sizeof(char))))
			return ;
		ft_memset(null, '\0', 7);
		null[0] = '(';
		null[1] = 'n';
		null[2] = 'u';
		null[3] = 'l';
		null[4] = 'l';
		null[5] = ')';
		null[6] = '\0';
		//arg->converted_form = null;
		cat_str_buffer(arg->converted_form, null, ft_strlen(null));
	}
	else
		//arg->converted_form = wstr_to_str(arg, arg->argv.wstr_arg);
		//cat_str_buffer(arg->converted_form, wstr_to_str(arg, arg->argv.wstr_arg), ft_wstr_blen(arg->argv.wstr_arg));
		cat_str_buffer(arg->converted_form, wstr_to_str(arg, arg->argv.wstr_arg), ft_strlen(wstr_to_str(arg, arg->argv.wstr_arg)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_functions.c   	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		cat_format(wchar_t *format, va_list ap)
{
	wchar_t	*wstr;
	t_arg	*arg;
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	wstr = NULL;
	arg = NULL;
	if (init_cat_format_var(&wstr, &arg) == ERROR)
		return (ERROR);
	while (i < ft_wstrlen(format))
	{
		if (init_arg(arg) == ERROR)
			return (ERROR);
		if (format[i] == '%' && (i + 1) < ft_wstrlen(format))
		{
			ret = ret + get_arg((format + i + 1), arg, ap);
			i = i + ft_wstrlen(arg->str_form);
			cat_arg(arg, &wstr);
		}
		else if (format[i] != '%')
			ret = ret + cat_char(&wstr, (&format[i]));
		i++;
	}
	return (print_result(wstr, ret, &arg));
}

void	cat_arg(t_arg *arg, wchar_t **wstr)
{
	if (arg->wconverted_form == NULL)
		*wstr = wstr_memcat(*wstr, str_to_wstr(arg->converted_form), ft_strlen(arg->converted_form), 1);
	else
		*wstr = wstr_memcat(*wstr, arg->wconverted_form, ft_wstrlen(arg->wconverted_form), 1);
}

int		cat_char(wchar_t **wstr, wchar_t *c)
{
	*wstr = wstr_memcat(*wstr, c, 1, 1);
	return (1);
}

int		init_cat_format_var(wchar_t **wstr, t_arg **arg)
{
	if(!(*wstr = (wchar_t *)malloc(1 * sizeof(wchar_t))))
		return (ERROR);
	ft_memset(*wstr, '\0', 1);
	if (!(*arg = (t_arg *)malloc(1 * sizeof(t_arg))))
		return (ERROR);
	ft_memset(*arg, '\0', 1);
	return (TRUE);
}

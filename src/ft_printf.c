/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c   		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = parsing(format, ap);
	va_end(ap);
	return (ret);
}

int	parsing(const char *format, va_list ap)
{
	char	*str;
	wchar_t	*wstr;
	t_arg	*arg;
	size_t	i;

	if(!(str = (char *)malloc(2 * sizeof(char))))
		return (-1);
	ft_memset(str, '\0', 2);
	if(!(wstr = (wchar_t *)malloc(1 * sizeof(wchar_t))))
		return (-1);
	ft_memset(wstr, '\0', 1);
	if (!(arg = (t_arg *)malloc(1 * sizeof(t_arg))))
		return (-1);
	i = 0;
	while (i < ft_strlen(format))
	{
		init_arg(arg);
		if (format[i] == '%')
		{
			parse_format_arg(format + i + 1, arg, ap);
			i = i + ft_strlen(arg->str_form) + 1;
			if (arg->wchar_form == 0 && ft_wstrlen(wstr) == 0)
				str = str_memcat(str, arg->converted_form, ft_strlen(arg->converted_form));
			else
			{
				if (ft_wstrlen(wstr) == 0)
					wstr = str_to_wstr(str);
				if (arg->wchar_form == 1)
					wstr = wstr_memcat(wstr, arg->wconverted_form, ft_wstrlen(arg->wconverted_form));
				if (arg->wchar_form == 0)
					wstr = wstr_memcat(wstr, str_to_wstr(arg->converted_form), ft_wstrlen(str_to_wstr(arg->converted_form)));
			}
		}
		else
		{
			if (ft_wstrlen(wstr) != 0)
				wstr = wstr_memcat(wstr, str_to_wstr(&format[i]), 1);
			else
				str = str_memcat(str, &format[i], 1);
			i++;
		}
	}
	if (ft_wstrlen(wstr) != 0)
	{
		ft_putwstr(wstr);
		ft_putchar('\n');
	}
	else
		ft_putendl(str);
	return (ft_strlen(str));
}

int		parse_format_arg(const char *format, t_arg *arg, va_list ap)
{
	char	*str;
	size_t	i;

	if(!(str = (char *)malloc(2 * sizeof(char))))
		return (-1);
	ft_memset(str, '\0', 2);
	i = 0;
	while (i < ft_strlen(format) && is_conversion(format[i]) == FALSE)
	{
		str = str_memcat(str, &format[i], 1);
		i++;
	}
	str = str_memcat(str, &format[i], 1);
	arg->str_form = str_memcat(arg->str_form, str, ft_strlen(str));
	if (fill_arg(arg, ap) == FALSE)
		return (-1);
	return (1);
}

int		parse_flags(t_arg *arg)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(arg->str_form))
	{
		if (is_flag(arg, i) == FALSE)
			return (FALSE);
		if (is_flag(arg, i) == -1)
			i++;
		if (is_flag(arg, i) > 0)
			i = i + is_flag(arg, i);
		i++;
	}
	return (TRUE);
}

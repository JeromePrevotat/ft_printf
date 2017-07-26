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
	char	*f;
	size_t	i;

	i = 0;
	if (!(f = (char *)malloc((ft_strlen(format) + 1 ) * sizeof(char))))
		return (ERROR);
	ft_memset(f, '\0', ft_strlen(format) + 1);
	while (i < ft_strlen(format))
	{
		f[i] = format[i];
		i++;
	}
	va_start(ap, format);
	ret = parsing(f, ap);
	va_end(ap);
	return (ret);
}

int	parsing(const char *format, va_list ap)
{
	wchar_t	*wstr;
	t_arg	*arg;
	size_t	i;
	wchar_t	*f;

	i = 0;
	wstr = NULL;
	arg = NULL;
	f = str_to_wstr(format);
	if (init_parsing_var(&wstr, &arg) == ERROR)
		return (ERROR);
	while (i < ft_strlen(format))
	{
		init_arg(arg);
		if (format[i] == '%')
		{
			parse_format_arg(format + i + 1, arg, ap);
			i = i + ft_strlen(arg->str_form);
			if (arg->wconverted_form == NULL)
				wstr = wstr_memcat(wstr, str_to_wstr(arg->converted_form), ft_strlen(arg->converted_form), 1);
			else
				wstr = wstr_memcat(wstr, arg->wconverted_form, ft_wstrlen(arg->wconverted_form), 1);
		}
		else
			wstr = wstr_memcat(wstr, (&f[i]), 1, 1);
		i++;
	}
	ft_putwstr(wstr);
	return (ft_wstrlen(wstr));
}

int		parse_format_arg(const char *format, t_arg *arg, va_list ap)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(format) && is_conversion(format[i]) == FALSE)
	{
		arg->str_form = str_memcat(arg->str_form, &format[i], 1);
		i++;
	}
	arg->str_form = str_memcat(arg->str_form, &format[i], 1);
	if (fill_arg(arg, ap) == FALSE)
		return (ERROR);
	return (TRUE);
}

int		parse_flags(t_arg *arg)
{
	size_t	i;
	int		next_i;

	i = 0;
	next_i = 0;
	while (i < ft_strlen(arg->str_form))
	{
		next_i = is_flag(arg, i);
		if (i < ft_strlen(arg->str_form) && next_i > 0)
			i = i + next_i;
		else
			return (FALSE);
	}
	return (TRUE);
}

int		init_parsing_var(wchar_t **wstr, t_arg **arg)
{
	if(!(*wstr = (wchar_t *)malloc(1 * sizeof(wchar_t))))
		return (ERROR);
	ft_memset(*wstr, '\0', 1);
	if (!(*arg = (t_arg *)malloc(1 * sizeof(t_arg))))
		return (ERROR);
	return (TRUE);
}

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

int		cat_format(char *format, va_list ap)
{
	t_arg	*arg;
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	arg = NULL;
	while (i < ft_strlen(format))
	{
		if (format[i] == '%' && (i + 1) < ft_strlen(format))
		{
			if (new_init_arg(&arg) == ERROR)
				return (ERROR);
			ret = ret + get_arg((format + i + 1), arg, ap);
			i = i + ft_strlen(arg->str_form);
			if (arg->wchar_form == TRUE)
				ft_putwstr(arg->wconverted_form);
			else
				ft_putstr(arg->converted_form);
			free(arg->str_form);
			//free(arg->converted_form);
			//free(arg->wconverted_form);
			free(arg);
		}
		else if (format[i] != '%')
		{
			ret++;
			write(1, &format[i], 1);
		}
		i++;
	}
	return (ret);
}

void	cat_arg(t_arg *arg, wchar_t **wstr)
{
	if (arg->wconverted_form == NULL)
		*wstr = wstr_memcat(*wstr, str_to_wstr(arg->converted_form),
		ft_strlen(arg->converted_form), 1);
	else
		*wstr = wstr_memcat(*wstr, arg->wconverted_form,
		ft_wstrlen(arg->wconverted_form), 1);
}

//FREE FONCTION FOR ALL ARG COMPONENTS

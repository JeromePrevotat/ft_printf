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
			/*if (arg->str_form != arg->converted_form && arg->converted_form != NULL)
				free(arg->converted_form);
			if (arg->str_form != NULL)
				free(arg->str_form);
			if (arg->wconverted_form != NULL)
				free(arg->wconverted_form);*/
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

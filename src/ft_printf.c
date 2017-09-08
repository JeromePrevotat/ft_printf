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

int		ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;
	char	*f;
	size_t	i;

	MB_CUR_MAX = 4;
	i = 0;
	if (!(f = (char *)malloc((ft_strlen(format) + 1 ) * sizeof(char))))
		return (ERROR);
	ft_memset(f, '\0', ft_strlen(format) + 1);
	while (i < ft_strlen(format))
	{
		f[i] = format[i];
		i++;
	}
	f[i] = '\0';
	va_start(ap, format);
	ret = cat_format(f, ap);
	va_end(ap);
	free(f);
	return (ret);
}

int		get_arg(char *format, t_arg *arg, va_list ap)
{
	get_arg_str_form(format, arg, ap);
	//return (check_ret(arg));
	return (1);
}

void	get_arg_str_form(char *format, t_arg *arg, va_list ap)
{
	size_t	i;
	int		next_i;

	next_i = 1;
	i = 0;
	while (i < ft_strlen(format) - 1 && next_i > 0)
	{
		next_i = new_flag_parsing(arg, format, i);
		if (next_i > 0)
			i = i + next_i;
	}
	if (i < ft_strlen(format) && new_is_conversion(format[i]) == TRUE)
	{
		arg->str_form = str_memcat(arg->str_form, format, i + 1, 1);
		fill_arg(arg, ap);
		return ;
	}
	else if (i < ft_strlen(format) && new_is_conversion(format[i]) == FALSE)
		arg->str_form = str_memcat(arg->str_form, format, i + 1, 1);
	else
		arg->str_form = str_memcat(arg->str_form, format, ft_strlen(format), 1);
	arg->converted_form->str = get_undefined_behaviour(arg);
}

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
	ret = cat_format(str_to_wstr(f), ap);
	va_end(ap);
	return (ret);
}

int		get_arg(wchar_t *format, t_arg *arg, va_list ap)
{
	get_arg_str_form(format, arg, ap);
	return (check_ret(arg));
}

void	get_arg_str_form(wchar_t *format, t_arg *arg, va_list ap)
{
	size_t	i;
	int		next_i;

	next_i = 1;
	i = 0;
	/*while (i < ft_wstrlen(format) && is_conversion(format[i]) == FALSE)
	{
		arg->str_form = wstr_memcat(arg->str_form, &format[i], 1, 1);
		i++;
	}
	arg->str_form = wstr_memcat(arg->str_form, &format[i], 1, 1);
	if (is_conversion(arg->str_form[ft_wstrlen(arg->str_form) - 1]) == FALSE)
		arg->wconverted_form = get_undefined_behaviour(arg);
	else
		fill_arg(arg, ap);*/

	//NEW FUNCTION
	while (i < ft_wstrlen(format) - 1 && next_i > 0)
	{
		//printf("I : %zu // TESTED CHAR : %C\n", i , format[i]);
		next_i = new_flag_parsing(arg, format, i);
		if (next_i > 0)
			i = i + next_i;
		//printf("NEXT I : %d\n", next_i);
		//printf("ARG FLAG WIDTH : %d // WIDTH : %d\n", arg->flags.width, arg->width);
	}
	if (i < ft_wstrlen(format) && new_is_conversion(format[i]) == TRUE)
	{
		arg->str_form = wstr_memcat(arg->str_form, format, i + 1, 1);
		fill_arg(arg, ap);
		return ;
	}
	else if (i < ft_wstrlen(format) && is_conversion(format[i]) == FALSE)
		arg->str_form = wstr_memcat(arg->str_form, format, i + 1, 1);
	else
		arg->str_form = wstr_memcat(arg->str_form, format, ft_wstrlen(format), 1);
	arg->wconverted_form = get_undefined_behaviour(arg);
}

int		print_result(wchar_t *wstr, int ret, t_arg **arg)
{
	ft_putwstr(wstr);
	if (*arg != NULL)
	free(*arg);
	return (ret);
}

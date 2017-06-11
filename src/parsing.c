/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:59:53 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/24 18:02:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/ft_printf.h"

int	parsing(const char *format, va_list ap)
{
	char	*str;
	t_arg	*arg;
	size_t	i;

	(void)ap;
	if(!(str = (char *)malloc(2 * sizeof(char))))
		return (-1);
	ft_memset(str, '\0', 2);
	if (!(arg = (t_arg *)malloc(1 * sizeof(t_arg))))
		return (-1);
	i = 0;
	while (i < ft_strlen(format))
	{
		init_arg(arg);
		if (format[i] == '%')
		{
			parse_format_arg(format + i + 1, arg);
			i = i + ft_strlen(arg->str_form) + 1;
			str = str_memcat(str, arg->str_form, ft_strlen(arg->str_form));
		}
		else
		{
			str = str_memcat(str, &format[i], 1);
			i++;
		}
	}
	ft_putendl(str);
	return (ft_strlen(str));
}

int		parse_format_arg(const char *format, t_arg *arg)
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
	arg->str_form = str_memcat(arg->str_form, str, ft_strlen(str));
	if (fill_arg(arg) == FALSE)
		return (-1);
	return (1);
}

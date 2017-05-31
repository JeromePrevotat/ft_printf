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

#include <stdarg.h>
#include "../inc/libft.h"
#include <stdio.h>
#include "../inc/ft_printf.h"

int	parsing(const char *format, va_list ap)
{
	char      conv_list[16];
	size_t    i;
	int       type;
	char      *str;

	init_list(conv_list);
	i = 0;
	if (!(str = (char *)malloc(1 * sizeof(char))))
		return (-1);
	ft_memset(str, '\0', 1);
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			if (!(type = check_existing_conv(format[i + 1], conv_list)))
			{
				ft_putendl("Incomplete format specifier");
				exit (-1);
			}
			else
			{
				if (type == '%')
					str = str_memcat(str, "%", 1);
				else
					str = assign_va_arg(type, ap, str);
				i++;
			}
		}
		else
			str = str_memcat(str, &format[i], 1);
		i++;
	}
	ft_putendl(str);
	return (ft_strlen(str));
}

int		check_existing_conv(char c, char *conv_list)
{
	int  i;
	int type;

	type = 0;
	i = 0;
	while (conv_list[i] != '\0')
	{
		if (c == conv_list[i])
			type = select_type(c);
			i++;
	}
	return (type);
}

char	*assign_va_arg(int type, va_list ap, char *str)
{
	if (type == -10 || type == -100 || type == 8 || type == 80 || type == 10
		|| type == 100 || type == 16)
		str = cat_int(str, ap, type);
	else if (type == 2)
		str = cat_char(str, ap);
	else if (type == 20)
		str = cat_wchar(str, ap);
	else if (type == 3)
		str = cat_str(str, ap);
	else if (type == 30)
		str = cat_wstr(str, ap);
	else if (type == 4)
		str = cat_ptr(str, ap);
	return (str);
}

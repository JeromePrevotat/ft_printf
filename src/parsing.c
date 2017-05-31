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
	size_t	i;
	char	*str;
	char	*conv;
	char	*s_conv;

	i = 0;
	if (!(str = (char *)malloc(1 * sizeof(char))))
		return (-1);
	ft_memset(str, '\0', 1);
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			conv = parse_conv(format, i);
			s_conv = parse_arg(conv, ap);
			str = str_memcat(str, s_conv, ft_strlen(s_conv));
			i++;
		}
		else
			str = str_memcat(str, &format[i], 1);
		i++;
	}
	/*while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			flag = check_flag(format[i + 1]);
			if (flag == 'h' && format[i + 2] == 'h')
				flag = 'H';
			else if (flag == 'l' && format[i + 2] == 'l')
				flag = 'L';
			if (flag != 0)
				i++;
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
					str = assign_va_arg(type, ap, str, flag);
				i++;
			}
		}
		else
			str = str_memcat(str, &format[i], 1);
		i++;
	}*/
	ft_putendl(str);
	return (ft_strlen(str));
}

char	*parse_conv(const char *format, int start)
{
	char	*conv;
	size_t	i;

	if (!(conv = (char *)malloc(1 * sizeof(char))))
		return (NULL);
	ft_memset(conv, '\0', 1);
	i = 1;
	while ((i + start < ft_strlen(format)) && (check_flag(*(format + start + i)) != 0))
	{
		conv = str_memcat(conv, &format[start + i], 1);
		i++;
	}
	if ((i + start < ft_strlen(format)) && (check_conv((char)format[start + i]) != 0))
	{
		if (check_conv((char)format[start + i]) == '%')
		{
			conv = str_memcat(conv, format + start + i, 1);
			i++;
			return (conv);
		}
		conv = str_memcat(conv, format + start + i, 1);
		i++;
		return (conv);
	}
	ft_putendl("Incomplete format specifier");
	exit (-1);
	return (NULL);
}

int		check_conv(char c)
{
	int		i;
	char	conv_list[16];

	init_list(conv_list);
	i = 0;
	while (conv_list[i] != '\0')
	{
		if (c == conv_list[i])
			return (c);
		i++;
	}
	return (0);
}

char	*parse_arg(char *conv, va_list ap)
{
	char	*s_conv;
	int		type;

	if (!(s_conv = (char *)malloc(1 * sizeof(char))))
		return (NULL);
	type = select_type(conv[ft_strlen(conv) - 1]);
	s_conv = assign_va_arg(type, ap, s_conv);
	return (s_conv);
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

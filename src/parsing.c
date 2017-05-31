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

<<<<<<< HEAD
int	parsing(const char *format, va_list ap)
{
	char      conv_list[16];
	size_t    i;
	int       type;
	char      *str;
=======
void	parsing(const char *format, va_list ap)
{
	char	conv_list[15];
	size_t	i;
	int		type;
	char	*str;
>>>>>>> 7d1059df80994d3b0bd1e3352e5f04b26ae17231

	init_list(conv_list);
	i = 0;
	if (!(str = (char *)malloc(1 * sizeof(char))))
<<<<<<< HEAD
		return (-1);
=======
		return ;
>>>>>>> 7d1059df80994d3b0bd1e3352e5f04b26ae17231
	ft_memset(str, '\0', 1);
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
<<<<<<< HEAD
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
=======
			type = check_existing_conv(format[i + 1], conv_list);
			if (type == 0)
				exit(-1);
			else
			{
				str = assign_va_arg(type, ap, str);
>>>>>>> 7d1059df80994d3b0bd1e3352e5f04b26ae17231
				i++;
			}
		}
		else
			str = str_memcat(str, &format[i], 1);
		i++;
	}
	ft_putendl(str);
<<<<<<< HEAD
	return (ft_strlen(str));
=======
	free(str);
	return ;
>>>>>>> 7d1059df80994d3b0bd1e3352e5f04b26ae17231
}

int		check_existing_conv(char c, char *conv_list)
{
<<<<<<< HEAD
	int  i;
	int type;
=======
	int	i;
	int	type;
>>>>>>> 7d1059df80994d3b0bd1e3352e5f04b26ae17231

	type = 0;
	i = 0;
	while (conv_list[i] != '\0')
	{
		if (c == conv_list[i])
			type = select_type(c);
<<<<<<< HEAD
			i++;
=======
		i++;
>>>>>>> 7d1059df80994d3b0bd1e3352e5f04b26ae17231
	}
	return (type);
}

char	*assign_va_arg(int type, va_list ap, char *str)
{
<<<<<<< HEAD
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
=======
	int		x;
	char	c;
	char	*s;
	void	*p;

	x = 0;
	c = 0;
	s = NULL;
	p = NULL;
	if (type == -10 || type == -100 || type == 8 || type == 80 || type == 10
		|| type == 100 || type == 16 || type == 160)
	{
		x = va_arg(ap, int);
		s = convert(x, type);
		str = str_memcat(str, s, ft_strlen(s));
		ft_putendl(str);
	}
	else if (type == 2)
	{
		c = va_arg(ap, int);
		str = str_memcat(str, &c, 1);
		ft_putendl(str);
	}
	else if (type == 3)
	{
		str = str_memcat(str, s, ft_strlen(s));
		ft_putendl(str);

	}
	else if (type == 4)
	{
		p = va_arg(ap, void *);
		str = str_memcat(str, "0x", 2);
		str = str_memcat(str, itoa_base_unsigned((unsigned int)p, 16),
			ft_strlen(itoa_base_unsigned((unsigned int)p, 16)));
		ft_putendl(str);
	}
>>>>>>> 7d1059df80994d3b0bd1e3352e5f04b26ae17231
	return (str);
}

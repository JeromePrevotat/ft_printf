/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c	                                            :+:      :+:    :+:   */
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
#include <wchar.h>

char	*cat_int(char *str, va_list ap, int type)
{
	int		x;
	char	*s;

	x = va_arg(ap, int);
	s = convert(x, type);
	str = str_memcat(str, s, ft_strlen(s));
	return (str);
}

char	*cat_char(char *str, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	str = str_memcat(str, &c, 1);
	return (str);
}

char	*cat_wchar(char *str, va_list ap)
{
	wchar_t c;

	c = va_arg(ap, wchar_t);
	str = str_wmemcat(str, &c, 1 * sizeof(wchar_t));
	return (str);
}

char	*cat_str(char *str, va_list ap)
{
	char *s;

	s = va_arg(ap, char *);
	if (s == NULL)
		str = str_memcat(str, "(null)", 6);
	else
		str = str_memcat(str, s, ft_strlen(s));
	return (str);
}

char	*cat_wstr(char *str, va_list ap)
{
	wchar_t *s;

	s = va_arg(ap, wchar_t *);
	if (s == NULL)
		str = str_memcat(str, "(null)", 6);
	else
		str = str_wmemcat(str, s, wcslen(s));
	return (str);
}

char	*cat_ptr(char *str, va_list ap)
{
	void *p;

	p = va_arg(ap, void *);
	str = str_memcat(str, "0x", 2);
	str = str_memcat(str, itoa_base_unsigned((long)p, 16),
		ft_strlen(itoa_base_unsigned((long)p, 16)));
	return (str);
}

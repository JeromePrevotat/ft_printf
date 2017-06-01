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

char	*cat_int(char *str, va_list ap, int type, char *conv)
{
	int		x;
	char	*s;
	char	*f;

	if (!(f = (char *)malloc(1 * sizeof(char))))
		return (NULL);
	x = va_arg(ap, int);
	f = cat_flag(conv, type, f, x);
	s = convert(x, type);
	f = str_memcat(f, s, ft_strlen(s));
	str = str_memcat(str, f, ft_strlen(f));
	return (str);
}

char	*cat_char(char *str, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	ft_memset(str, '\0', ft_strlen(str));
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
	ft_memset(str, '\0', ft_strlen(str));
	if (s == NULL)
		str = str_memcat(str, "(null)", 6);
	else
		str = s;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t	ft_wstr_blen(const wchar_t *wstr)
{
	size_t	len;

	if (!wstr)
		return (ERROR);
	len = 0;
	while (*wstr)
	{
		if (*wstr <= 0x7F)
			len++;
		else if (*wstr <= 0x7FF)
			len = len + 2;
		else if (*wstr <= 0xFFFF)
			len = len + 3;
		else if (*wstr <= 0x10FFFF)
			len = len + 4;
		wstr++;
	}
	return (len);
}

size_t	ft_wstr_clen(const wchar_t *wstr)
{
	size_t	len;

	if (!wstr)
		return (ERROR);
	len = 0;
	while (*wstr)
	{
		len++;
		wstr++;
	}
	return (len);
}

int		ft_putwstr(wchar_t *wstr)
{
	if (!wstr)
		return (0);
	while (*wstr)
	{
		ft_putwchar(*wstr);
		wstr++;
	}
	return (1);
}

int		ft_putwchar(wchar_t wchar)
{
	//EXCLUSION DEMI CODETS
	//if (wchar >= 0xD800 && wchar <= 0xDFFF)
		//return (-1);
	if (wchar <= 0x7F)
		ft_putchar(wchar);
	else if (wchar <= 0x7FF)
	{
		ft_putchar((wchar >> 6) + 0xC0);
		ft_putchar((wchar & 0x3F) + 0x80);
	}
	else if (wchar <= 0xFFFF)
	{
		ft_putchar((wchar >> 12) + 0xE0);
		ft_putchar(((wchar >> 6) & 0x3F) + 0x80);
		ft_putchar((wchar & 0x3F) + 0x80);
	}
	else if (wchar <= 0x10FFFF)
	{
		ft_putchar((wchar >> 18) + 0xF0);
		ft_putchar(((wchar >> 12) & 0x3F) + 0x80);
		ft_putchar(((wchar >> 6) & 0x3F) + 0x80);
		ft_putchar((wchar & 0x3F) + 0x80);
	}
	return (1);
}

char	*wstr_to_str(t_arg *arg, wchar_t *wstr)
{
	char	*str;
	int		i;
	int		c_len;

	i = 0;
	c_len = 0;
	if (!(str = (char *)malloc(ft_wstr_blen(wstr) + 1 * sizeof(char))))
		return (NULL);
	ft_memset(str, '\0', ft_wstr_blen(wstr) + 1);
	while (*wstr)
	{
		c_len = wchar_to_char(*wstr, str + i);
		i = i + c_len;
		if (arg->flags.precision == TRUE && i >= arg->precision)
		{
			str[i - c_len] = '\0';
			return (str);
		}
		wstr++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		wchar_to_char(wchar_t wchar, char *str)
{
	int	i;

	i = 0;
	if (wchar <= 0x7F)
		str[i] = (wchar);
	else if (wchar <= 0x7FF)
	{
		str[i] = ((wchar >> 6) + 0xC0);
		str[i + 1] = ((wchar & 0x3F) + 0x80);
		return (1);
	}
	else if (wchar <= 0xFFFF)
	{
		str[i] = ((wchar >> 12) + 0xE0);
		str[i + 1] = (((wchar >> 6) & 0x3F) + 0x80);
		str[i + 2] = ((wchar & 0x3F) + 0x80);
		return (2);
	}
	else if (wchar <= 0x10FFFF)
	{
		str[i] = ((wchar >> 18) + 0xF0);
		str[i + 1] = (((wchar >> 12) & 0x3F) + 0x80);
		str[i + 2] = (((wchar >> 6) & 0x3F) + 0x80);
		str[i + 3] = ((wchar & 0x3F) + 0x80);
		return (3);
	}
	return (0);
}

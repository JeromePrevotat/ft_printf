/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c	                                            :+:      :+:    :+:   */
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

char *init_flag_list(void)
{
	char	*flag_list;

	if (!(flag_list = (char *)malloc(10 * sizeof(char))))
		return (NULL);
	flag_list[0] = '#';
	flag_list[1] = '0';
	flag_list[2] = '-';
	flag_list[3] = '+';
	flag_list[4] = ' ';
	flag_list[5] = 'h';
	flag_list[6] = 'l';
	flag_list[7] = 'j';
	flag_list[8] = 'z';
	flag_list[9] = '\0';
	return (flag_list);
}

int	check_flag(const char c)
{
	char	*flag_list;
	size_t	i;

	flag_list = init_flag_list();
	i = 0;
	while (i < ft_strlen(flag_list))
	{
		if (c == flag_list[i])
			return (c);
		i++;
	}
	return (0);
}

char	*cat_flag(char *conv, int type, char *s_conv, int x)
{
	int	i;

	i = 0;
	while (conv[i] != '\0')
	{
		if (conv[i] == '#')
			s_conv = alt_form(s_conv, type);
		if (conv[i] == '+')
			s_conv = plus_flag(s_conv, type, x);
		i++;
	}
	return (s_conv);
}

char	*alt_form(char *s_conv, int type)
{
	if (type == 16)
		s_conv = str_memcat(s_conv, "0x", 2);
	if (type == 160)
		s_conv = str_memcat(s_conv, "0X", 2);
	if (type == 8 || type == 80)
		s_conv = str_memcat(s_conv, "0", 1);
	return (s_conv);
}

char	*plus_flag(char *s_conv, int type, int x)
{
	if (type == -10 && x > 0)
		s_conv = str_memcat(s_conv, "+", 1);
	return (s_conv);
}

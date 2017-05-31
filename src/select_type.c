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

void	init_list(char *conv_list)
{
	conv_list[0] = 's';
	conv_list[1] = 'S';
	conv_list[2] = 'p';
	conv_list[3] = 'd';
	conv_list[4] = 'D';
	conv_list[5] = 'i';
	conv_list[6] = 'o';
	conv_list[7] = 'O';
	conv_list[8] = 'u';
	conv_list[9] = 'U';
	conv_list[10] = 'x';
	conv_list[11] = 'X';
	conv_list[12] = 'c';
	conv_list[13] = 'C';
	conv_list[14] = '%';
	conv_list[15] = '\0';
	return ;
}

int		select_type(char c)
{
     if (c == 'd' || c == 'i')
          return (-10);
     if (c == 'D')
          return (-100);
     if (c == 'o')
          return (8);
     if (c == 'O')
          return (80);
     if (c == 'u')
          return (10);
     if (c == 'U')
          return (100);
     if (c == 'x')
          return (16);
     if (c == 'X')
          return (160);
     if (c == 'c')
          return (2);
     if (c == 'C')
          return (20);
     if (c == 's')
          return (3);
     if (c == 'S')
          return (30);
     if (c == 'p')
          return (4);
	if (c == '%')
		return ('%');
     return (0);
}

char *convert(int x, int type)
{
     //Signed Decimal
     if (type == -10)
          return (itoa_base(x, 10));
     //Long Signed Decimal
     if (type == -100)
          return (itoa_base(x, 10));
     //Unsigned Octal
     if (type == 8)
          return (itoa_base_unsigned(x, 8));
     //Long Unsigned Octal
     if (type == 80)
          return (itoa_base_unsigned(x, 8));
     //Unsigned Decimal
     if (type == 10)
          return (itoa_base_unsigned(x, 10));
     //Long Unsigned Decimal
     if (type == 100)
          return (itoa_base_unsigned(x, 10));
     //Unsigned Hex
     if (type == 16)
          return (itoa_base_unsigned(x, 16));
     if (type == 160)
          return (itoa_base_unsigned(x, 160));
     return (NULL);
}

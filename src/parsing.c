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
#include "libft.h"
#include <stdio.h>
#include "ft_printf.h"

void parsing(const char *format, va_list ap)
{
     char      conv_list[15];
     size_t    i;
     void      *type;

     type = NULL;
     init_list(conv_list);
     i = 0;
     while (i < ft_strlen(format))
     {
          if (format[i] == '%')
          {
               check_existing_conv(format[i + 1], conv_list, type);
               type = va_arg(ap, typeof(type));
               ft_putstr(type);
          }
          i++;
     }
     return ;
}

void init_list(char *conv_list)
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
     conv_list[14] = '\0';
     return ;
}

void  check_existing_conv(char c, char *conv_list, void *type)
{
     int  i;

     i = 0;
     while (conv_list[i] != '\0')
     {
          if (c == conv_list[i])
               select_type(c, type);
          i++;
     }
     return ;
}

void  select_type(char c, void *type)
{
     if (c == 'D' || c == 'd' || c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
          type = (int *)type;
     else if (c == 's' || c == 'S')
          type = (char *)type;
     else if (c == 'c' || c == 'C')
          type = (char *)type;
     else if (c == 'p')
          type = (void *)type;
     return ;
}

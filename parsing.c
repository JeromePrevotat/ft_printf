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
     int       type;
     char      *str;

     init_list(conv_list);
     i = 0;
     if (!(str = (char *)malloc(1 * sizeof(char))))
          return ;
     ft_memset(str, '\0', 1);
     while (i < ft_strlen(format))
     {
          if (format[i] == '%')
          {
               type = check_existing_conv(format[i + 1], conv_list);
               if (type == 0)
                str = str_memcat(str, &format[i], 1);
              else
              {
                str = assign_va_arg(type, ap, str);
                i++;
             }
          }
          else
          {
            str = str_memcat(str, &format[i], 1);
          }
          i++;
     }
     ft_putendl(str);
     free(str);
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

int  check_existing_conv(char c, char *conv_list)
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

int  select_type(char c)
{
     if (c == 'D' || c == 'd' || c == 'i' || c == 'o' || c == 'O'
     || c == 'u' || c == 'U' || c == 'x' || c == 'X')
          return (1);
     else if (c == 's' || c == 'S')
          return (3);
     else if (c == 'c' || c == 'C')
          return (2);
     else if (c == 'p')
          return (4);
     return (0);
}

char  *assign_va_arg(int type, va_list ap, char *str)
{
    int x;
    char c;
    char *s;
    void *p;

    x = 0;
    c = 0;
    s = NULL;
    p = NULL;
    if (type == 1)
    {
      x = va_arg(ap, int);
      str = str_memcat(str, itoa_base(x, 10), ft_strlen(itoa_base(x, 10)));
    }
    else if (type == 2)
    {
      c = va_arg(ap, int);
      str = str_memcat(str, &c, 1);
    }
    else if (type == 3)
    {
      s = va_arg(ap, char *);
      str = str_memcat(str, s, ft_strlen(s));
    }
    else if (type == 4)
    {
      p = va_arg(ap, void *);
      str = str_memcat(str, itoa_base((int)p, 16), ft_strlen(itoa_base((int)p, 16)));
    }
    return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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

int main(void)
{
     char y = '$';
     int  x = 42;
     void *p = NULL;
     if (!(p = malloc(1)))
      return (-1);
     //char *s = "Yolo";
     char *s2 = "I'm CEO Bitch !";

     ft_putendl("My Ft_printf result :");
     ft_printf("Yolo ! %s %d - %u - %o - %x - %c pointer adress %p", s2, x, x, x, x, y, p);
     ft_putendl("Real Printf result :");
     printf("Yolo ! %s %d - %u - %o - %x - %c pointer adress %p", s2, x, x, x, x, y, p);
     free(p);
     return (0);
}

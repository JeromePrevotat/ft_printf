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
     /*char y = 'Y';
     int  x = 42;
     char *s = "Yolo";*/
     char *s2 = "I'm CEO Bitch !";
/*
     ft_printf("%d", x);
     ft_putchar('\n');
     ft_printf("%c", y);
     ft_putchar('\n');
     ft_printf("%s", s);
     ft_putchar('\n');*/
     ft_printf("Yolo ! %s", s2);
     ft_putchar('\n');
     return (0);
}

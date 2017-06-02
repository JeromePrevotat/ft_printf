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
#include "../inc/libft.h"
#include <stdio.h>
#include "../inc/ft_printf.h"
#include <wchar.h>

int	main(void)
{
	int ft;
	int pr;
	//char y = '$';
	int  x = -1;
	void *p = NULL;
	//wchar_t wchar = L'\x82';
	//wchar_t *wstr = L"J\130rome";
	if (!(p = malloc(1)))
		return (-1);
	//char *s = "Yolo";
	//char *s2 = "I'm CEO Bitch !";

	ft_putendl("My Ft_printf result :");
	ft = ft_printf("%d // %d // %o // %o // %x // %X // %x // %X, %p", x, x, x, x, x, x, x, x, p);
	pr = printf("%d // %d // %o // %o // %x // %X // %x // %X, %p", x, x, x, x, x, x, x, x, p);
	//ft = ft_printf("Yolo ! %s %d - %u - %#o - %x - %c pointer adress %p - %% - %C - %S", s2, x, x, x, x, y, p, wchar, wstr);
	//pr = printf("Yolo ! %s %d - %u - %#o - %x - %c pointer adress %p - %% - %C - %S", s2, x, x, x, x, y, p, wchar, wstr);
	//pr = printf("%-d", x);
	ft_putnbr(ft);
	ft_putchar('-');
	ft_putnbr(pr);
	ft_putchar('\n');
	ft_putendl("Real Printf result :");
	//free(p);
	return (0);
}

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
	/*int x = 42;
	short s = 42;
	char c = 42;
	long l = 42;
	long long ll = 42;
	intmax_t imax = 42;*/

	int ft;
	int pr;
	char y = '$';
	int  x2 = 42;
	void *p = NULL;
	wchar_t wchar = L'\x82';
	wchar_t *wstr = L"J\130rome";
	if (!(p = malloc(1)))
		return (-1);
	char *s2 = "I'm CEO Bitch !";

	ft_putendl("My Ft_printf result :");
	ft = ft_printf("Yolo ! %s % d - %u - %#o - %#x - %c pointer adress %p - %% - %C - %S", s2, x2, x2, x2, x2, y, p, wchar, wstr);
	pr = printf("Yolo ! %s %-10d - %u - %#o - %#x - %c pointer adress %p - %% - %C - %S", s2, x2, x2, x2, x2, y, p, wchar, wstr);

	//ft_putendl("My Ft_printf result :");
	//ft_printf("%d - %#o - %0d - %-d - % d - %+d - %hd - %hhd - %ld - %lld - %jd - %zd", x,x,x,x,x,x,s,c,l,ll,imax,x);
	//ft_putchar('\n');
	ft_putendl("Real Printf result :");
	//printf("%d - %#o - %0d - %-d - % d - %+d - %hd - %hhd - %ld - %lld - %jd - %zd", x,x,x,x,x,x,s,c,l,ll,imax,x);
	//ft_putendl("d - #o - 0d - -d -  d - +d - hd - hhd - ld - lld - jd - zd");
	return (0);
}

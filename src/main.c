/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c  		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/ft_printf.h"

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
	long l = 10000000000;
	void *p = NULL;
	wchar_t wchar = L'\x82';
	wchar_t *wstr = L"J\130rome";
	if (!(p = malloc(1)))
		return (-1);
	char *s2 = "I'm CEO Bitch !";

	ft_putendl("My Ft_printf result :");
	ft = ft_printf("Yolo ! %-20s %ls %ld - %u - %#o - %#x - %c pointer adress %p - %% - %C - %S", s2, wstr, l, x2, x2, x2, y, p, wchar, wstr);
	pr = printf("Yolo ! %-20s %ls %ld - %u - %#o - %#x - %c pointer adress %p - %% - %C - %S", s2, wstr, l, x2, x2, x2, y, p, wchar, wstr);

	//ft = ft_printf("Yolo ! %-20s %ld - %u - %#o - %#x - %c pointer adress %p - %% - %C", s2, l, x2, x2, x2, y, p, wchar);
	//pr = printf("Yolo ! %-20s %ld - %u - %#o - %#x - %c pointer adress %p - %% - %C", s2, l, x2, x2, x2, y, p, wchar);
	//ft_putendl("My Ft_printf result :");
	//ft_printf("%d - %#o - %0d - %-d - % d - %+d - %hd - %hhd - %ld - %lld - %jd - %zd", x,x,x,x,x,x,s,c,l,ll,imax,x);
	//ft_putchar('\n');
	ft_putendl("Real Printf result :");
	//printf("%d - %#o - %0d - %-d - % d - %+d - %hd - %hhd - %ld - %lld - %jd - %zd", x,x,x,x,x,x,s,c,l,ll,imax,x);
	//ft_putendl("d - #o - 0d - -d -  d - +d - hd - hhd - ld - lld - jd - zd");

	/*char	*str;
	char	*str2;
	wchar_t	*wstr;

	str = "Yolo 1";
	str2 = "Yolo 2";
	if (!(wstr = (wchar_t *)malloc(1 * sizeof(wchar_t))))
		return (-1);
	ft_memset(wstr, '\0', 1);
	wstr = str_to_wstr(str);
	ft_putwstr(wstr);
	ft_putchar('\n');
	wstr = wstr_memcat(wstr, str_to_wstr(str2), ft_wstrlen(str_to_wstr(str2)));
	ft_putwstr(wstr);
	ft_putchar('\n');*/

	return (0);
}

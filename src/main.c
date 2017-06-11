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
	int x = 42;
	short s = 42;
	char c = 42;
	long l = 42;
	long long ll = 42;
	intmax_t imax = 42;
	ft_putendl("My Ft_printf result :");
	ft_printf("%d - %#o - %0d - %-d - % d - %+d - %hd - %hhd - %ld - %lld - %jd - %zd", x,x,x,x,x,x,s,c,l,ll,imax,x);
	ft_putchar('\n');
	ft_putendl("Real Printf result :");
	printf("%d - %#o - %0d - %-d - % d - %+d - %hd - %hhd - %ld - %lld - %jd - %zd", x,x,x,x,x,x,s,c,l,ll,imax,x);
	ft_putendl("d - #o - 0d - -d -  d - +d - hd - hhd - ld - lld - jd - zd");
	return (0);
}

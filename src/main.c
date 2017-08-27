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

	int ret;
	int	real_ret;

	real_ret = 0;
	ret = 0;
	ft_putendl("My printf result :\n");
	//62
	//"{% c}", 0
	//72
	//"%.4S", L"我是一只猫。"
	//"%4.1S", L"Jambon"
	//"%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"
	ret = ft_printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	//ret = ft_printf("% Z%s", "test");
	//ret = ft_printf("%d", 2147483648);
	//ret = ft_printf("%015u", "4294967295");
	//ret = ft_printf("%hU", "4294967296");
	//ret = ft_printf("%U", "4294967296");

	ft_putchar('\n');
	printf("RET = %d\n", ret);
	ft_putendl("Real printf result :\n");
	real_ret = printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\nREAL_RET : %d\n", real_ret);


	/*
	WCHAR TEST

	wchar_t	*wstr;

	wstr = NULL;
	ft_putwstr(wstr);
	*/

	/*MEMORY LEAKS TEST
	//ft_printf("\\n");
	*/
	//ft_printf("%%\\n");
	/*
	ft_printf("%d\\n", 42);
	ft_printf("%d%d\\n", 42, 41);
	ft_printf("%d%d%d\\n", 42, 43, 44);
	ft_printf("%ld\\n", 2147483647);
	ft_printf("%lld\\n", 9223372036854775807);
	ft_printf("%x\\n", 505);
	ft_printf("%X\\n", 505);
	ft_printf("%p\\n", &ft_printf);
	ft_printf("%20.15d\\n", 54321);
	ft_printf("%-10d\\n", 3);
	ft_printf("% d\\n", 3);
	ft_printf("%+d\\n", 3);
	ft_printf("%010d\\n", 1);
	ft_printf("%hhd\\n", 0);
	ft_printf("%jd\\n", 9223372036854775807);
	ft_printf("%zd\\n", 4294967295);
	ft_printf("%\\n");
	ft_printf("%U\\n", 4294967295);
	ft_printf("%u\\n", 4294967295);
	ft_printf("%o\\n", 40);
	ft_printf("%%#08x\\n", 42);
	ft_printf("%x\\n", 1000);
	ft_printf("%#X\\n", 1000);
	ft_printf("%s\\n", NULL);
	ft_printf("%S\\n", L"ݗݜशব");
	ft_printf("%s%s\\n", "test", "test");
	ft_printf("%s%s%s\\n", "test", "test", "test");
	ft_printf("%C\\n", 15000);
	*/
	return (0);
}

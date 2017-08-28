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
	ret = ft_printf("%zi", LLONG_MIN);
	printf("RET : %d\n", ret);

	ft_putchar('\n');

	ft_putendl("Real printf result :\n");
	real_ret = printf("%zi", LLONG_MIN);
	printf("\nREAL_RET : %d\n", real_ret);

	//TO FIX
	//ft_printf("%D", LONG_MAX);				???
	//ft_printf("%ld", LONG_MAX);				???
	//ft_printf("%D", LONG_MIN);				ITOA ISSUE
	//ft_printf("%ld", LONG_MIN);				ITOA ISSUE
	//ret = ft_printf("%zd", LLONG_MIN);		ITOA ISSUE
	//ret = ft_printf("%zi", LLONG_MIN);		ITOA ISSUE
	//ft_printf("%li", (long)INT_MIN - 1);		RET ISSUE
	//ft_printf("%lld", LLONG_MAX);				RET ISSUE
	//ft_printf("%hhd", CHAR_MAX);				RET ISSUE
	//ft_printf("%hhd", CHAR_MAX + 42);			RET ISSUE
	//ft_printf("%hhd", CHAR_MIN - 42);			RET ISSUE
	//ft_printf("%hhi%hhi", 0, 42);				RET ISSUE
	//ft_printf("%zd", LLONG_MAX);				RET ISSUE
	//ft_printf("%lp", 42);						RET ISSUE
	//ft_printf("{%3c}", 0);					RET ISSUE
	//ft_printf("{%03c}", 0);					RET ISSUE
	//ft_printf("%#X", INT_MAX);				RET ISSUE
	//ft_printf("%#x", INT_MAX);				RET ISSUE
	//ft_printf("%8.4u", 424242424);			RET ISSUE
	//ft_printf("%4.15d", -424242);				RET ISSUE
	//ft_printf("%8.4d", 424242424);			RET ISSUE
	//ft_printf("%8.4X", 424242424);			RET ISSUE
	//ft_printf("%4.15x", 42424242);			RET ISSUE
	//ft_printf("%8.4x", 424242424);			RET ISSUE
	//ft_printf("%4.15o", 424242);				RET ISSUE
	//ft_printf("{%05.c}", 0);					WIDTH+PRECISION+CHAR NULL
	//ft_printf("{%#.5x}", 1);					PRECISION WITH PTR
	//ft_printf("{%05.s}", 0);					ZERO WITH STR ISSUE
	//ft_printf("{%05.S}", L"42 c est cool");	ZERO WITH WSTR ISSUE
	//ft_printf("{%05.Z}", 0);					WIDTH WITH UB
	//ft_printf("%15.4o", 424242);				RET ISSUE (WIDTH ?)
	//ft_printf("{% c}", 0);					RET ISSUE (CHAR NULL)
	//ft_printf("{% C}", 0);					RET ISSUE (WCHAR NULL)
	//ft_printf("{%10R}");						RET ISSUE (WIDTH PARSING UB)
	//ft_printf("{%05p}", 0);					RET ISSUE (ZERO & PTR)
	//ft_printf("{%030S}", L"我是一只猫。");		RET ISSUE & WCHAR ISSUE
	//ft_printf("{%-15Z}", 123);				RET ISSUE & RIGTH PADDING
	//ft_printf("%15.4d", -424242);				RET ISSUE & WIDTH+MINUS
	//ft_printf("%hhC, %hhC", 0, L'Á±≥');		WCHAR ISSUE
	//ft_printf("%15.4S", L"我是一只猫。");		WCHAR ISSUE
	//ft_printf("%.4S", L"我是一只猫。");			WCHAR ISSUE
	//ft_printf("%zu, %zu", 0, ULLONG_MAX);		SEGFAULT
	//ft_printf("%zo, %zo", 0, ULLONG_MAX);		SEGFAULT
	//ft_printf("%zx, %zx", 0, ULLONG_MAX);		SEGFAULT
	//ft_printf("%zX, %zX", 0, ULLONG_MAX);		SEGFAULT
	//ft_printf("{%-30S}", L"我是一只猫。");		FREE ISSUE
	/*ft_printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C \
	%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\
	%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",
	' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
	'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
	'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
	'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
	'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
	'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
	't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
		ret = ft_printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C \
	%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\
	%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",
	' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
	'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
	'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
	'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
	'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
	'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
	't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');*/ // ???




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

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
	ret = ft_printf("%.2c", NULL);
	//ret = ft_printf("% Z%s", "test");
	//ret = ft_printf("%d", 2147483648);
	//ret = ft_printf("%015u", "4294967295");
	//ret = ft_printf("%hU", "4294967296");
	//ret = ft_printf("%U", "4294967296");

	ft_putchar('\n');
	printf("RET = %d\n", ret);
	//ft_putendl("Real printf result :\n");
	//real_ret = printf("@moulitest: %.d %.0d", 42, 43);
	//printf("\nREAL_RET : %d\n", real_ret);


	/*
	//MEMORY LEAKS TEST
	ft_printf("\\n");
	//printf("\n");
	ft_printf("%%\\n");
	//printf("\n");
	ft_printf("%d\\n", 42);
	//printf("\n");
	ft_printf("%d%d\\n", 42, 41);
	//printf("\n");
	ft_printf("%d%d%d\\n", 42, 43, 44);
	//printf("\n");
	ft_printf("%ld\\n", 2147483647);
	//printf("\n");
	ft_printf("%lld\\n", 9223372036854775807);
	//printf("\n");
	ft_printf("%x\\n", 505);
	//printf("\n");
	ft_printf("%X\\n", 505);
	//printf("\n");
	ft_printf("%p\\n", &ft_printf);
	//printf("\n");
	ft_printf("%20.15d\\n", 54321);
	//printf("\n");
	ft_printf("%-10d\\n", 3);
	//printf("\n");
	ft_printf("% d\\n", 3);
	//printf("\n");
	ft_printf("%+d\\n", 3);
	//printf("\n");
	ft_printf("%010d\\n", 1);
	//printf("\n");
	ft_printf("%hhd\\n", 0);
	//printf("\n");
	ft_printf("%jd\\n", 9223372036854775807);
	//printf("\n");
	ft_printf("%zd\\n", 4294967295);
	//printf("\n");
	ft_printf("%\\n");
	//printf("\n");
	ft_printf("%U\\n", 4294967295);
	//printf("\n");
	ft_printf("%u\\n", 4294967295);
	//printf("\n");
	ft_printf("%o\\n", 40);
	//printf("\n");
	ft_printf("%%#08x\\n", 42);
	//printf("\n");
	ft_printf("%x\\n", 1000);
	//printf("\n");
	ft_printf("%#X\\n", 1000);
	//printf("\n");
	ft_printf("%s\\n", NULL);
	//printf("\n");
	ft_printf("%S\\n", L"ݗݜशব");
	//printf("\n");
	ft_printf("%s%s\\n", "test", "test");
	//printf("\n");
	ft_printf("%s%s%s\\n", "test", "test", "test");
	//printf("\n");
	ft_printf("%C\\n", 15000);
	//printf("\n");
	*/
	return (0);
}

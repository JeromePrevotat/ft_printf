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
#include <string.h>

int	main(void)
{

	char	*local;

	local = NULL;
	local = setlocale(LC_ALL, "");

	int ret;
	int	real_ret;


	real_ret = 0;
	ret = 0;
	ft_putendl("My printf result :");
	ret = ft_printf("%llX, %llX", 0, ULLONG_MAX);
	printf("\nRET : %d\n\n", ret);
	ft_putendl("Real printf result :");
	real_ret = printf("%llX, %llX", 0, ULLONG_MAX);
	printf("\nREAL_RET : %d\n", real_ret);




//	ft_printf("%p\\n", &ft_printf);
	/*
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

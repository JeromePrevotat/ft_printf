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

	int ret;
	int	real_ret;
	char	*local;

	local = NULL;
	local = setlocale(LC_ALL, "");
	real_ret = 0;
	ret = 0;
	ft_putendl("My printf result :");
	ret = ft_printf("%4.1S", L"Jambon");
	//ret = ft_printf("%4.15S", L"我是一只猫。");
	printf("\nRET : %d\n\n", ret);

	ft_putendl("Real printf result :");
	real_ret = printf("%4.1S", L"Jambon");
	//real_ret = printf("%4.15S", L"我是一只猫。");
	printf("\nREAL_RET : %d\n", real_ret);


	return (0);
}

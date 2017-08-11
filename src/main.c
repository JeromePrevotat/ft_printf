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
	//ret = ft_printf("%5%");
	//ret = ft_printf("%lld", -9223372036854775808);
	//ret = ft_printf("%015u", "4294967295");
	//ret = ft_printf("%hU", "4294967296");
	ret = ft_printf("%U", "4294967296");

	ft_putchar('\n');
	printf("RET = %d\n", ret);
	ft_putendl("Real printf result :\n");
	real_ret = printf("%U", "4294967296");
	printf("\nREAL_RET : %d\n", real_ret);
	return (0);
}

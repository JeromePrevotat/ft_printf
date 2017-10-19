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

	/*char	*local;

	local = NULL;
	local = setlocale(LC_ALL, "");*/

	int ret;
	int	real_ret;
	int i;

	real_ret = 0;
	ret = 0;
	i = 0;
	//LLONG MAX : 9223372036854775807
	ft_putendl("My printf result :");
	ret = ft_printf("%C\n", 0x08A0);
	printf("\nRET : %d\n\n", ret);
	ft_putendl("Real printf result :");
	real_ret = printf("%C\n", 0x08A0);
	printf("\nREAL_RET : %d\n", real_ret);
	//"%lX, %lX", 0, ULONG_MAX

	return (0);
}

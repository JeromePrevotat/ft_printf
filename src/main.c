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
	ret = ft_printf("%#b\n", 4);
	printf("\nRET : %d\n\n", ret);
	ft_putendl("Real printf result :");
	real_ret = printf("LONG MAX + 1 : %jd\n", LONG_MAX + 1);
	printf("\nREAL_RET : %d\n", real_ret);


	return (0);
}

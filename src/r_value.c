/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c   		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	check_ret(t_arg *arg)
{
	(void)arg;
	/*int	 ret;

	ret = 0;
	if ((arg->type == T_CHAR && arg->argv.c_arg == 0 && arg->conv != '%')
		|| (arg->type == T_WCHAR && arg->argv.wchar_arg == 0 && arg->conv != '%'))
		ret = 1 + ft_strlen(arg->converted_form);
	else
		ret = ft_strlen(arg->converted_form);
	return (ret);*/
	return (1);
}

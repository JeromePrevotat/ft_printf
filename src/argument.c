/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:59:53 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/24 18:02:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/ft_printf.h"

int	init_arg(t_arg *arg)
{
	if (arg->str_form == NULL)
	{
		if (!(arg->str_form = (char *)malloc(1 * sizeof(char))))
			return (-1);
		ft_memset(arg->str_form, '\0', 1);
	}
	if (arg->converted_form == NULL)
	{
		if (!(arg->converted_form = (char *)malloc(1 * sizeof(char))))
			return (-1);
		ft_memset(arg->converted_form, '\0', 1);
	}
	else
	{
		ft_memset(arg->str_form, '\0', ft_strlen(arg->str_form));
		ft_memset(arg->converted_form, '\0', ft_strlen(arg->converted_form));	
	}
	return (1);
}

int	fill_arg(t_arg *arg)
{
	(void)arg;
	return (1);
}

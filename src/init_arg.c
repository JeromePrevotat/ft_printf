/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c  	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	new_init_arg(t_arg **arg)
{
	if (!((*arg) = (t_arg *)malloc(1 * sizeof(t_arg))))
		return (ERROR);
	ft_memset(*arg, '\0', 1);
	(*arg)->type = 0;
	//(*arg)->conv = 0;
	(*arg)->argv.imax_arg = 0;
	(*arg)->argv.uimax_arg = 0;
	(*arg)->str_form = NULL;
	(*arg)->converted_form = NULL;
	(*arg)->width = 0;
	(*arg)->precision = 0;
	(*arg)->wchar_form = FALSE;
	if (init_str_form(arg) == ERROR || init_converted_form((*arg)) == ERROR)
		return (ERROR);
	init_flags_arg((*arg));
	return (TRUE);
}

int	init_str_form(t_arg **arg)
{
	if ((*arg)->str_form == NULL)
	{
		if (!((*arg)->str_form = (char *)malloc(1 * sizeof(char))))
			return (ERROR);
		ft_memset((*arg)->str_form, '\0', 1);
	}
	else
		ft_memset((*arg)->str_form, '\0', ft_strlen((*arg)->str_form));
	return (TRUE);
}

int	init_converted_form(t_arg *arg)
{
	if (arg->converted_form == NULL)
	{
		if (!(arg->converted_form = (char *)malloc(1 * sizeof(char))))
			return (ERROR);
		ft_memset(arg->converted_form, '\0', 2);
	}
	else
		ft_memset(arg->converted_form, '\0', ft_strlen(arg->converted_form));
	return (TRUE);
}

void	init_flags_arg(t_arg *arg)
{
	arg->flags.alt_form = FALSE;
	arg->flags.zero = FALSE;
	arg->flags.minus = FALSE;
	arg->flags.plus = FALSE;
	arg->flags.space = FALSE;
	arg->flags.h = FALSE;
	arg->flags.hh = FALSE;
	arg->flags.l = FALSE;
	arg->flags.ll = FALSE;
	arg->flags.j = FALSE;
	arg->flags.z = FALSE;
	arg->flags.precision = FALSE;
	arg->flags.width = FALSE;
}

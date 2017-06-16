/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	set_l_flag(t_arg *arg)
{
	if (arg->flags.l == FALSE && arg->flags.ll == FALSE)
	arg->flags.l = TRUE;
	else
	return (FALSE);
	return (TRUE);
}

int	set_ll_flag(t_arg *arg)
{
	if (arg->flags.ll == FALSE && arg->flags.l == FALSE)
	arg->flags.ll = TRUE;
	else
	return (FALSE);
	return (TRUE);
}

int	set_h_flag(t_arg *arg)
{
	if (arg->flags.h == FALSE && arg->flags.hh == FALSE)
		arg->flags.h = TRUE;
	else
		return (FALSE);
	return (TRUE);
}

int	set_hh_flag(t_arg *arg)
{
	if (arg->flags.hh == FALSE && arg->flags.h == FALSE)
		arg->flags.hh = TRUE;
	else
		return (FALSE);
	return (TRUE);
}

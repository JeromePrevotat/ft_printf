/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:59:53 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/24 18:02:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/ft_printf.h"

int	set_alt_form_flag(t_arg *arg)
{
	if (arg->flags.alt_form == FALSE)
		arg->flags.alt_form = TRUE;
	else
		return (FALSE);
	return (TRUE);
}

int	set_zero_flag(t_arg *arg)
{
	if (arg->flags.zero == FALSE && arg->flags.zero != OVERRIDE)
		arg->flags.zero = TRUE;
	else
		if (arg->flags.zero != OVERRIDE)
			return (FALSE);
	return (TRUE);
}

int	set_minus_flag(t_arg *arg)
{
	if (arg->flags.minus == FALSE)
	{
		arg->flags.zero = OVERRIDE;
		arg->flags.minus = TRUE;
	}
	else
		return (FALSE);
	return (TRUE);
}

int	set_plus_flag(t_arg *arg)
{
	if (arg->flags.plus == FALSE)
	{
		arg->flags.space = OVERRIDE;
		arg->flags.plus = TRUE;
	}
	else
		return (FALSE);
	return (TRUE);
}

int	set_space_flag(t_arg *arg)
{
	if (arg->flags.space == FALSE && arg->flags.space != OVERRIDE)
		arg->flags.space = TRUE;
	else
		if (arg->flags.space != OVERRIDE)
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

int	set_l_flag(t_arg *arg)
{
	if (arg->flags.l == FALSE && arg->flags.ll == FALSE)
		arg->flags.l = TRUE;
	else
		return (FALSE);
	return (TRUE);
}

int	set_j_flag(t_arg *arg)
{
	if (arg->flags.j == FALSE)
		arg->flags.j = TRUE;
	else
		return (FALSE);
	return (TRUE);
}

int	set_z_flag(t_arg *arg)
{
	if (arg->flags.z == FALSE)
		arg->flags.z = TRUE;
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

int	set_ll_flag(t_arg *arg)
{
	if (arg->flags.ll == FALSE && arg->flags.l == FALSE)
		arg->flags.ll = TRUE;
	else
		return (FALSE);
	return (TRUE);
}

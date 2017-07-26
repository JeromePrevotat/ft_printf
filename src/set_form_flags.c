/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	set_alt_form_flag(t_arg *arg)
{
	if (arg->flags.alt_form == FALSE)
		arg->flags.alt_form = TRUE;
	else
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

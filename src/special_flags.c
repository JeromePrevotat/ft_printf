/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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

int	apply_j(t_arg *arg)
{
	(void)arg;
	return (1);
}

int	apply_z(t_arg *arg)
{
	if (arg->conv == 8 || arg->conv == 10 || arg->conv == 16 || arg->conv == 160)
		arg->type = T_SIZET;
	return (1);
}

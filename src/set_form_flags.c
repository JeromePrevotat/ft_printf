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
	arg->flags.alt_form = TRUE;
	return (TRUE);
}

int	set_minus_flag(t_arg *arg)
{
	//Minus overrides zero
	arg->flags.zero = OVERRIDE;
	arg->flags.minus = TRUE;
	return (TRUE);
}

int	set_plus_flag(t_arg *arg)
{
	//Plus overrides space
	arg->flags.space = OVERRIDE;
	arg->flags.plus = TRUE;
	return (TRUE);
}

int	set_space_flag(t_arg *arg, int j)
{
	int	i;

	i = 0;
	if (arg->flags.space == OVERRIDE)
		return (TRUE);
	arg->flags.space = TRUE;
	while (arg->str_form[j + i] != '\0' && arg->str_form[j + i] == ' ')
		i++;
	if (i == 0)
		i++;
	return (i);
}

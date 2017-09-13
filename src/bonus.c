/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	bonus_conv(t_arg *arg)
{
	int	alt_form;
	int	zero;

	alt_form = FALSE;
	zero = FALSE;
	arg->type = T_INT;
	arg->bonus = TRUE;
	if (arg->flags.alt_form == TRUE)
		alt_form = TRUE;
	if ((arg->flags.zero == TRUE || arg->flags.zero == OVERRIDE) && alt_form == FALSE)
		zero = TRUE;
	init_flags_arg(arg);
	arg->flags.alt_form = alt_form;
	arg->flags.zero = zero;
}

void	convert_bonus(t_arg *arg, va_list ap)
{
	convert_argv(arg, ap);
}

void	apply_flags_bonus(t_arg *arg)
{
	if (arg->flags.alt_form == TRUE)
		apply_bonus_alt_form(arg);
	if (arg->flags.zero == TRUE)
		apply_bonus_zero(arg);
}

void apply_bonus_alt_form(t_arg *arg)
{
	/*
	int	i;

	i = 0;
	if (ft_strlen(arg->conv_form->str) % 8 != 0)
	{
		while (ft_strlen(arg->conv_form->str) + i % 8 != 0)
			i++;
	}
	*/
}

void	apply_bonus_zero(t_arg *arg)
{
	return ;
}

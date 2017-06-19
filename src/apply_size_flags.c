/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_size_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	apply_l(t_arg *arg)
{
	if (arg->type == T_CHAR || arg->type == T_WCHAR || arg->type == T_WSTR
		|| arg->type == T_PTR)
		return (0);
	else if (arg->type == T_INT || arg->type == T_SHORT)
		arg->type = T_LONG;
	else if (arg->type == T_STR)
		arg->type = T_WSTR;
	return (1);
}

int	apply_ll(t_arg *arg)
{
	(void)arg;
	return (1);
}

int	apply_h(t_arg *arg)
{
	(void)arg;
	return (1);
}

int	apply_hh(t_arg *arg)
{
	(void)arg;
	return (1);
}

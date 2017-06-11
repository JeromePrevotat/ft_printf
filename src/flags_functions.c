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

int	apply_alt_form(t_arg *arg)
{
	char *tmp;

	if (!(tmp = (char *)malloc(1 * sizeof(char))))
		return (-1);
	ft_memset(tmp, '\0', 1);
	if (arg->conv == 16)
	{
		tmp = str_memcat(tmp, "0x", 2);
		tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form));
		arg->converted_form = tmp;
	}
	if (arg->conv == 160)
	{
		tmp = str_memcat(tmp, "0X", 2);
		tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form));
		arg->converted_form = tmp;
	}
	if (arg->conv == 8 || arg->conv == 80)
	{
		tmp = str_memcat(tmp, "0", 1);
		tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form));
		arg->converted_form = tmp;
	}
	return (1);
}

int	apply_zero(t_arg *arg)
{
	(void)arg;
	return (1);
}

int	apply_minus(t_arg *arg)
{
	(void)arg;
	return (1);
}

int	apply_plus(t_arg *arg)
{
	char *tmp;

	if (!(tmp = (char *)malloc(1 * sizeof(char))))
		return (-1);
	ft_memset(tmp, '\0', 1);
	if (arg->conv == -10 && arg->argv.i_arg > 0)
	{
		tmp = str_memcat(tmp, "+", 1);
		tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form));
		arg->converted_form = tmp;
	}
	return (1);
}

int	apply_space(t_arg *arg)
{
	char *tmp;

	if (!(tmp = (char *)malloc(1 * sizeof(char))))
		return (-1);
	ft_memset(tmp, '\0', 1);
	if (arg->conv == -10 && arg->argv.i_arg > 0)
	{
		tmp = str_memcat(tmp, " ", 1);
		tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form));
		arg->converted_form = tmp;
	}
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

int	apply_l(t_arg *arg)
{
	(void)arg;
	return (1);
}

int	apply_ll(t_arg *arg)
{
	(void)arg;
	return (1);
}

int	apply_j(t_arg *arg)
{
	(void)arg;
	return (1);
}

int	apply_z(t_arg *arg)
{
	(void)arg;
	return (1);
}

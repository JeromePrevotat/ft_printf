/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                      	                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:59:53 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/24 18:02:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/ft_printf.h"

int		is_flag(t_arg *arg, size_t i)
{
	char	*flags_tab;
	int		f;

	flags_tab = init_flags_tab();
	f = 0;
	while (f < 9)
	{
		if (arg->str_form[i] == flags_tab[f])
		{
			if (i + 1 < ft_strlen(arg->str_form)
				&& arg->str_form[i] == 'h' && arg->str_form[i + 1] == 'h')
				{
					if (set_flag(arg, 'H') == FALSE)
						return (FALSE);
					else
						return (-1);
				}
			if (i + 1 < ft_strlen(arg->str_form)
				&& arg->str_form[i] == 'l' && arg->str_form[i + 1] == 'l')
				{
					if (set_flag(arg, 'L') == FALSE)
						return (FALSE);
					else
						return (-1);
				}
			if (arg->str_form[i] == '-' || arg->str_form[i] == '0')
			{
				if (set_flag(arg, arg->str_form[i]) == FALSE)
					return (FALSE);
				return (get_width(arg->str_form + i, arg));
			}
			else
				if (set_flag(arg, arg->str_form[i]) == FALSE)
					return (FALSE);
		}
		f++;
	}
	return (TRUE);
}

char	*init_flags_tab(void)
{
	char *flags_tab;

	if (!(flags_tab = (char *)malloc(9 * sizeof(char))))
		return (NULL);
	flags_tab[0] = '#';
	flags_tab[1] = '0';
	flags_tab[2] = '-';
	flags_tab[3] = '+';
	flags_tab[4] = ' ';
	flags_tab[5] = 'h';
	flags_tab[6] = 'l';
	flags_tab[7] = 'j';
	flags_tab[8] = 'z';
	return (flags_tab);
}

int		set_flag(t_arg *arg, char c)
{
	if (c == '#')
		return (set_alt_form_flag(arg));
	if (c == '0')
		return (set_zero_flag(arg));
	if (c == '-')
		return (set_minus_flag(arg));
	if (c == '+')
		return (set_plus_flag(arg));
	if (c == ' ')
		return (set_space_flag(arg));
	if (c == 'h')
		return (set_h_flag(arg));
	if (c == 'l')
		return (set_l_flag(arg));
	if (c == 'j')
		return (set_j_flag(arg));
	if (c == 'z')
		return (set_z_flag(arg));
	if (c == 'H')
		return (set_hh_flag(arg));
	if (c == 'L')
		return (set_ll_flag(arg));
	return (0);
}

int		apply_flag(t_arg *arg)
{
	if (arg->flags.alt_form == TRUE)
		apply_alt_form(arg);
	if (arg->flags.zero == TRUE)
		apply_zero(arg);
	if (arg->flags.minus == TRUE)
		apply_minus(arg);
	if (arg->flags.plus == TRUE)
		apply_plus(arg);
	if (arg->flags.space == TRUE)
		apply_space(arg);
	if (arg->flags.h == TRUE)
		apply_h(arg);
	if (arg->flags.hh == TRUE)
		apply_hh(arg);
	if (arg->flags.l == TRUE)
		apply_l(arg);
	if (arg->flags.ll == TRUE)
		apply_ll(arg);
	if (arg->flags.j == TRUE)
		apply_j(arg);
	if (arg->flags.z == TRUE)
		apply_z(arg);
	return (0);
}

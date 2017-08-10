/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ultis.c  	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		parse_flags(t_arg *arg)
{
	size_t	i;
	int		next_i;

	i = 0;
	next_i = 0;
	while (i < ft_wstrlen(arg->str_form) - 1)
	{
		next_i = is_flag(arg, i);
		if (i < ft_wstrlen(arg->str_form) && next_i > 0)
		//if (next_i > 0)
			i = i + next_i;
		else
			return (FALSE);
	}
	return (TRUE);
}

int		is_flag(t_arg *arg, size_t i)
{
	wchar_t	*flags_tab;
	int		f;
	int		j;
	int		next_i;

	next_i = -1;
	j = 0;
	flags_tab = L"#0-+ hljz.\0";
	f = 0;
	while (flags_tab[f] != '\0')
	{
		if (arg->str_form[i] == flags_tab[f])
		{
			next_i = check_flags_a(arg, i);
			if (next_i == -1)
				next_i = check_flags_b(arg, i);
		}
		f++;
	}
	if (ft_isdigit(arg->str_form[i]) == 1 && arg->str_form[i] != '0')
		next_i = set_width(arg, arg->str_form + i);
	return (next_i);
}

int		check_flags_a(t_arg *arg, size_t i)
{
	int		next_i;

	next_i = -1;
	if (i + 1 < ft_wstrlen(arg->str_form)
		&& arg->str_form[i] == 'h' && arg->str_form[i + 1] == 'h')
		next_i = set_flag(arg, 'H');
	else if (i + 1 < ft_wstrlen(arg->str_form)
		&& arg->str_form[i] == 'l' && arg->str_form[i + 1] == 'l')
		next_i = set_flag(arg, 'L');
	else if (arg->str_form[i] == '-' || arg->str_form[i] == '0')
	{
		if (set_flag(arg, arg->str_form[i]) != FALSE)
		{
			get_width(arg->str_form + i, arg);
			next_i = 1;
		}
	}
	return (next_i);
}

int		check_flags_b(t_arg *arg, size_t i)
{
	int	next_i;

	next_i = -1;
	if (arg->str_form[i] == ' ')
	{
		next_i = set_space_flag(arg, i);
		if (next_i == 0)
			next_i = ERROR;
	}
	else if (arg->str_form[i] == '.')
	{
		next_i = set_precision(arg, arg->str_form + i + 1) + 1;
		if (next_i == 0)
			next_i = ERROR;
	}
	else
	{
		next_i = set_flag(arg, arg->str_form[i]);
		if (next_i == 0)
			next_i = ERROR;
	}
	return (next_i);
}

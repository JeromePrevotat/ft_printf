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

int		is_conversion(char c)
{
	char	*conv_tab;
	int		i;

	conv_tab = init_conv_tab();
	i = 0;
	while (i < 15)
	{
		if (c == conv_tab[i])
		{
			if (conv_tab != NULL)
				free(conv_tab);
			return (TRUE);
		}
		i++;
	}
	if (conv_tab != NULL)
		free(conv_tab);
	return (FALSE);
}

char	*init_conv_tab(void)
{
	char *conv_tab;

	if (!(conv_tab = (char *)malloc(15 * sizeof(char))))
		return (NULL);
	conv_tab[0] = '%';
	conv_tab[1] = 's';
	conv_tab[2] = 'S';
	conv_tab[3] = 'p';
	conv_tab[4] = 'd';
	conv_tab[5] = 'D';
	conv_tab[6] = 'i';
	conv_tab[7] = 'o';
	conv_tab[8] = 'O';
	conv_tab[9] = 'u';
	conv_tab[10] = 'U';
	conv_tab[11] = 'x';
	conv_tab[12] = 'X';
	conv_tab[13] = 'c';
	conv_tab[14] = 'C';
	return (conv_tab);
}

int		is_flag(t_arg *arg, size_t i)
{
	char	*flags_tab;
	int		f;

	flags_tab = "#0-+ hljz.\0";
	f = 0;
	while (flags_tab[f] != '\0')
	{
		if (arg->str_form[i] == flags_tab[f])
		{
			if (i + 1 < ft_strlen(arg->str_form)
				&& arg->str_form[i] == 'h' && arg->str_form[i + 1] == 'h')
				return (set_flag(arg, 'H'));
			if (i + 1 < ft_strlen(arg->str_form)
				&& arg->str_form[i] == 'l' && arg->str_form[i + 1] == 'l')
				return (set_flag(arg, 'L'));
			if (arg->str_form[i] == '-' || arg->str_form[i] == '0')
			{
				if (set_flag(arg, arg->str_form[i]) == FALSE)
					return (ERROR);
				return (get_width(arg->str_form + i, arg));
			}
			if (arg->str_form[i] == '.')
				return (set_precision(arg, arg->str_form + i + 1) + 1);
			else
				return (set_flag(arg, arg->str_form[i]));
		}
		f++;
	}
	if (ft_isdigit(arg->str_form[i]) == 1 && arg->str_form[i] != '0')
		return (set_width(arg, arg->str_form + i));
	return (ERROR);
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
	return (FALSE);
}

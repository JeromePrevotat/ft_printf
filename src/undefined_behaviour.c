/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefined_behaviour.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*get_undefined_behaviour(t_arg *arg)
{
	int		i;

	i = 0;
	if (arg->str_form != NULL)
	{
		while (ub_is_flag(arg->str_form[i]))
			i++;
		if (i - 1 >= 0 && (ub_is_flag(arg->str_form[i - 1]) || arg->str_form[i - 1] == 'h' || arg->str_form[i - 1] == 'l'))
			return (arg->str_form + i);
		if (i - 1 >= 0)
			return (arg->str_form + i - 1);
		return (arg->str_form + i);
	}
	return (NULL);
}

/*char	*get_undefined_behaviour(t_arg *arg)
{
	int		i;
	int		j;
	int		next_i;
	char	*tmp;

	i = 0;
	j = 0;
	next_i = 1;
	tmp = NULL;
	if (arg->str_form != NULL)
	{
		while (i < ft_strlen(arg->str_form) && next_i > 0)
		{
			next_i = new_flag_parsing(arg, arg->str_form, i);
			if (next_i > 0)
				i = i + next_i;
		}
		set_conv_arg(arg);
		if (arg->conv == 0)
		{
			arg->conv = 3;
			arg->type = T_STR;
			if (!(tmp = (char *)malloc(ft_strlen(arg->str_form + i) + 1 * sizeof(char))))
				return (NULL);
			ft_memset(tmp, '\0', ft_strlen(arg->str_form + i) + 1);
			while (*(arg->str_form + i + j) != '\0')
			{
				tmp[j] = *(arg->str_form + i + j);
				j++;
			}
			tmp[j] = '\0';
			arg->converted_form = tmp;
		}
		apply_flags(arg);
		return (arg->converted_form);

		if (i - 1 >= 0 && (ub_is_flag(arg->str_form[i - 1]) || arg->str_form[i - 1] == 'h' || arg->str_form[i - 1] == 'l'))
			return (arg->str_form + i);
		if (i - 1 >= 0)
			return (arg->str_form + i - 1);
		return (arg->str_form + i);
	}
	return (NULL);
}*/

int		ub_is_flag(char c)
{
	char	*flags_tab;
	size_t	i;

	i = 0;
	flags_tab = "#0-+ hljz\0";
	while (flags_tab[i] != '\0')
	{
		if (c == flags_tab[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

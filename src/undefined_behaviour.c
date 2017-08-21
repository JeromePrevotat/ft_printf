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
	int	i;

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

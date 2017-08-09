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

wchar_t	*get_undefined_behaviour(t_arg *arg)
{
	size_t	i;

	//printf("ENTERING GUB\n");
	i = 0;
	//TEST
	//arg->str_form = L"% Z \0";
	//if (is_flag(arg, 2))
		//printf("TESTED CHAR : %C\n", arg->str_form[2]);
	//END TEST
	//printf("TESTED CHAR ; %C\n", arg->str_form[i]);
	while (is_flag(arg, i) && i < ft_wstrlen(arg->str_form))
		i++;
	//printf("STR FORM : %S\nI : %zu\n", arg->str_form, i);
	//printf("TESTED CHAR : %C\n", arg->str_form[i - 1]);
	if (i - 1 > 0 && (ub_is_flag(arg->str_form[i - 1]) || arg->str_form[i - 1] == 'h' || arg->str_form[i - 1] == 'l'))
	{
		//printf("ENTERING IF\n");
		//printf("GUB IF RETURN : %S\n", arg->str_form + i);
		return (arg->str_form + i);
	}
	if (i - 1 > 0)
	//printf("GUB RETURN : %S\n", arg->str_form + i - 1);
		return (arg->str_form + i - 1);
	return (arg->str_form + i);
}

int		ub_is_flag(wchar_t c)
{
	wchar_t	*flags_tab;
	size_t	i;

	i = 0;
	flags_tab = L"#0-+ hljz\0";
	while (flags_tab[i] != '\0')
	{
		if (c == flags_tab[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

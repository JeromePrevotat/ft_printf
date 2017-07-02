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

wchar_t	*apply_width(t_arg *arg)
{
	int		i;
	int		real_width;
	wchar_t	*tmp;

	i = 0;
	if (arg->wchar_form == FALSE)
		arg->wconverted_form = str_to_wstr(arg->converted_form);
	real_width = arg->width - ft_wstrlen(arg->wconverted_form);
	if (!(tmp = (wchar_t *)malloc((arg->width + 1) * sizeof(wchar_t))))
		return (NULL);
	ft_memset(tmp, '\0', arg->width + 1);
	while (i < real_width && real_width >= 0)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
	tmp = wstr_memcat(tmp, arg->wconverted_form, ft_wstrlen(arg->wconverted_form));
	return (tmp);
}

int	apply_l(t_arg *arg)
{
	if (arg->type == T_CHAR || arg->type == T_WCHAR || arg->type == T_WSTR
		|| arg->type == T_PTR)
		return (0);
	else if (arg->conv == -10)
		arg->type = T_LONG;
	else if (arg->conv == 8 || arg->conv == 10 || arg->conv == 16 || arg->conv == 160)
		arg->type = T_LONG;
	else if (arg->type == T_STR)
		arg->type = T_WSTR;
	return (1);
}

int	apply_ll(t_arg *arg)
{
	if (arg->conv == -10)
		arg->type = T_LLONG;
	else if (arg->conv == 8 || arg->conv == 10 || arg->conv == 16 || arg->conv == 160)
		arg->type = T_LLONG;
	return (1);
}

int	apply_h(t_arg *arg)
{
	if (arg->conv == 8 || arg->conv == 10 || arg->conv == 16 || arg->conv == 160)
		arg->type = T_SHORT;
	return (1);
}

int	apply_hh(t_arg *arg)
{
	(void)arg;
	return (1);
}

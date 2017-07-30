/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_flags.c                         		        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		set_precision(t_arg *arg, char *str_form)
{
	size_t	i;
	char	*precision;

	i = 0;
	if (arg->flags.precision == TRUE)
		return (FALSE);
	if (!(precision = (char *)malloc((ft_strlen(str_form) + 1) * sizeof(char))))
		return (FALSE);
	ft_memset(precision, '\0', ft_strlen(str_form) + 1);
	while (i < ft_strlen(str_form) && ft_isdigit(str_form[i]) == TRUE)
	{
		precision[i] = str_form[i];
		i++;
	}
	precision[i] = '\0';
	arg->precision = ft_atoi(precision);
	arg->flags.precision = TRUE;
	if (ft_strlen(precision) == 0)
		return (1);
	return (ft_strlen(precision));
}

int		apply_precision(t_arg *arg)
{
	int		i;
	wchar_t	*tmp;

	i = 0;
	if (arg->type == T_STR)
	{
		if (arg->wconverted_form == NULL)
			arg->wconverted_form = str_to_wstr(arg->converted_form);
		if (ft_wstrlen(arg->wconverted_form) < (size_t)arg->precision)
			ft_memset(arg->wconverted_form, '\0', ft_wstrlen(arg->wconverted_form));
		else
			ft_memset(arg->wconverted_form + arg->precision, '\0', ft_strlen(arg->converted_form) - arg->precision);
	}
	if (arg->type == T_SHORT || arg->type == T_INT || arg->type == T_SIZET
		|| arg->type == T_LONG || arg->type == T_LLONG)
	{
		if (arg->wconverted_form == NULL)
			arg->wconverted_form = str_to_wstr(arg->converted_form);
		if (arg->precision == 0)
		{
			ft_memset(arg->wconverted_form, '\0', ft_wstrlen(arg->wconverted_form));
			return (1);
		}
		if (ft_wstrlen(arg->wconverted_form) == 1 && arg->wconverted_form[0] == '0' && arg->precision == 0)
		{
			ft_memset(arg->wconverted_form, '\0', ft_wstrlen(arg->wconverted_form));
			return (1);
		}
		if (ft_wstrlen(arg->wconverted_form) < (size_t)arg->precision)
		{
			i = arg->precision - ft_wstrlen(arg->wconverted_form) - 1;
			if (!(tmp = (wchar_t *)malloc(i * sizeof(wchar_t))))
				return (ERROR);
			ft_memset(tmp, L'\0', i);
			while (i >= 0)
			{
				tmp[i] = L'0';
				i--;
			}
			arg->wconverted_form = wstr_memcat(tmp, arg->wconverted_form, ft_wstrlen(arg->wconverted_form), 2);
		}
	}
	return (1);
}

int		set_width(t_arg *arg, char *str_form)
{
	size_t	i;
	char	*width;

	i = 0;
	if (arg->flags.width == TRUE)
		return (ERROR);
	if (!(width = (char *)malloc(ft_strlen(str_form) * sizeof(char))))
		return (ERROR);
	ft_memset(width, '\0', ft_strlen(str_form));
	while (i < ft_strlen(str_form) && ft_isdigit(str_form[i]))
	{
		width[i] = str_form[i];
		i++;
	}
	width[i] = '\0';
	arg->width = ft_atoi(width);
	arg->flags.width = TRUE;
	if (ft_strlen(width) == 0)
		return (1);
	return (ft_strlen(width));
}

int		apply_width(t_arg *arg)
{
	int		i;
	int		real_width;
	wchar_t	*tmp;

	i = 0;
	if (arg->wconverted_form == NULL)
		arg->wconverted_form = str_to_wstr(arg->converted_form);
	real_width = arg->width - ft_wstrlen(arg->wconverted_form);
	if (!(tmp = (wchar_t *)malloc((arg->width + 1) * sizeof(wchar_t))))
		return (ERROR);
	ft_memset(tmp, '\0', arg->width + 1);
	while (i < real_width && real_width >= 0)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
	arg->wconverted_form = wstr_memcat(tmp, arg->wconverted_form, ft_wstrlen(arg->wconverted_form), 2);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                         		        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*int		set_precision(t_arg *arg, char *str_form)
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
	int		pre;
	wchar_t	*tmp;

	i = 0;
	pre = 0;
	if (arg->type == T_STR)
	{
		if (arg->wconverted_form == NULL)
			arg->wconverted_form = str_to_wstr(arg->converted_form);
		if (ft_wstrlen(arg->wconverted_form) < (size_t)arg->precision)
			ft_memset(arg->wconverted_form, '\0',
				ft_wstrlen(arg->wconverted_form));
		else
			ft_memset(arg->wconverted_form + arg->precision, '\0',
				ft_strlen(arg->converted_form) - arg->precision);
	}
	if (arg->type == T_SHORT || arg->type == T_INT || arg->type == T_SIZET
		|| arg->type == T_LONG || arg->type == T_LLONG)
	{
		if (arg->wconverted_form == NULL)
			arg->wconverted_form = str_to_wstr(arg->converted_form);
		if (arg->precision == 0)
		{
			ft_memset(arg->wconverted_form, '\0',
				ft_wstrlen(arg->wconverted_form));
			arg->wconverted_form[0] = '\0';
			return (1);
		}
		else if (ft_wstrlen(arg->wconverted_form) == 1
			&& arg->wconverted_form[0] == '0' && arg->precision == 0)
		{
			ft_memset(arg->wconverted_form, '\0',
				ft_wstrlen(arg->wconverted_form));
			arg->wconverted_form[0] = '\0';
			return (1);
		}
		else if (ft_wstrlen(arg->wconverted_form) < (size_t)arg->precision)
		{
			pre = arg->precision - ft_wstrlen(arg->wconverted_form);
			if (!(tmp = (wchar_t *)malloc(pre + 1 * sizeof(wchar_t))))
				return (ERROR);
			ft_memset(tmp, '\0', pre + 1);
			tmp[pre] = '\0';
			pre--;
			while (pre >= 0)
			{
				tmp[pre] = '0';
				pre--;
			}
			arg->wconverted_form = wstr_memcat(tmp, arg->wconverted_form,
				ft_wstrlen(arg->wconverted_form), 2);
		}
	}
	return (1);
}*/

int		set_precision(t_arg *arg, wchar_t *str_form)
{
	size_t	i;
	char	*precision;

	i = 0;
	if (arg->flags.precision == TRUE)
		return (FALSE);
	else if (arg->flags.zero == TRUE)
		arg->flags.zero = OVERRIDE;
	if (!(precision = (char *)malloc((ft_wstrlen(str_form) + 1) * sizeof(char))))
		return (FALSE);
	ft_memset(precision, '\0', ft_wstrlen(str_form) + 1);
	while (i < ft_wstrlen(str_form) && ft_isdigit(str_form[i]) == TRUE)
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
	if (arg->wconverted_form == NULL)
		arg->wconverted_form = str_to_wstr(arg->converted_form);
	if (arg->type == T_STR || arg->type == T_WSTR)
		apply_str_pre(arg);
	else if (arg->type != T_STR && arg->type != T_WSTR && arg->type != T_CHAR && arg->type != T_WCHAR)
		apply_nbr_pre(arg);
	return (1);
}

int		apply_str_pre(t_arg *arg)
{
	if (ft_wstrlen(arg->wconverted_form) > (size_t)arg->precision)
		arg->wconverted_form[arg->precision] = '\0';
	return (1);
}

int		apply_nbr_pre(t_arg *arg)
{
	wchar_t	*tmp;

	tmp = NULL;
	//if (ft_wstrlen(arg->wconverted_form) == 1 && arg->precision == 0 && argv_sign(arg) == 0)
	if (arg->precision == 0 && argv_sign(arg) == 0)
	{
		arg->wconverted_form[0] = '\0';
		return (1);
	}
	if (argv_sign(arg) < 0)
		tmp = apply_negative(arg);
	else if (argv_sign(arg) >= 0)
		tmp = apply_positive(arg);
	if (arg->wconverted_form != NULL)
		free(arg->wconverted_form);
	arg->wconverted_form = tmp;
	return (1);
}

wchar_t	*apply_negative(t_arg *arg)
{
	size_t	i;
	size_t	j;
	size_t	real_pre;
	wchar_t	*tmp;

	tmp = NULL;
	real_pre = arg->precision - ft_wstrlen(arg->wconverted_form) + 1;
	if (ft_wstrlen(arg->wconverted_form) - 1 < (size_t)arg->precision)
	{
		i = 1;
		j = 1;
		if (!(tmp = (wchar_t *)malloc((real_pre + ft_wstrlen(arg->wconverted_form) + 1) * sizeof(wchar_t))))
			return (NULL);
		ft_memset(tmp, '\0', (real_pre + ft_wstrlen(arg->wconverted_form) + 1));
		tmp[0] = '-';
		while (i < real_pre + 1)
		{
			tmp[i] = '0';
			i++;
		}
		while (j < ft_wstrlen(arg->wconverted_form))
		{
			tmp[i] = arg->wconverted_form[j];
			i++;
			j++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}

wchar_t	*apply_positive(t_arg *arg)
{
	size_t	i;
	size_t	real_pre;
	wchar_t	*tmp;

	tmp = NULL;
	real_pre = arg->precision;
	if (ft_wstrlen(arg->wconverted_form) < real_pre)
	{
		i = 0;
		if (!(tmp = (wchar_t *)malloc((real_pre - ft_wstrlen(arg->wconverted_form) + 1) * sizeof(wchar_t))))
			return (NULL);
		ft_memset(tmp, '\0', (real_pre - ft_wstrlen(arg->wconverted_form) + 1));
		while (i < real_pre - ft_wstrlen(arg->wconverted_form))
		{
			tmp[i] = '0';
			i++;
		}
		tmp[i] = '\0';
		tmp = wstr_memcat(tmp, arg->wconverted_form, ft_wstrlen(arg->wconverted_form), 1);
	}
	return (tmp);
}

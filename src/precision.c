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

int		set_precision(t_arg *arg, char *str_form)
{
	size_t	i;
	char	*precision;

	i = 0;
	if (arg->flags.zero == TRUE)
		arg->flags.zero = OVERRIDE;
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
	arg->flags.zero = OVERRIDE;
	if (ft_strlen(precision) == 0)
		return (1);
	return (ft_strlen(precision) + 1);
}

int		apply_precision(t_arg *arg)
{
	if (arg->type == T_STR || arg->type == T_WSTR)
		apply_str_pre(arg);
	else if (arg->type != T_STR && arg->type != T_WSTR && arg->type != T_CHAR && arg->type != T_WCHAR)
		apply_nbr_pre(arg);
	return (1);
}

int		apply_str_pre(t_arg *arg)
{
	if (arg->wchar_form == TRUE)
	{
		if (ft_wstrlen(arg->wconverted_form) > (size_t)arg->precision)
			arg->wconverted_form[arg->precision] = '\0';
	}
	else
		if (ft_strlen(arg->converted_form) > (size_t)arg->precision)
			arg->converted_form[arg->precision] = '\0';
	return (1);
}

int		apply_nbr_pre(t_arg *arg)
{
	wchar_t	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	tmp = NULL;
	if (arg->wchar_form == TRUE)
	{
		if (arg->precision == 0 && argv_sign(arg) == 0)
		{
			if (arg->flags.alt_form == TRUE && (arg->conv == 8 || arg->conv == 80))
				arg->wconverted_form[1] = '\0';
			else
				arg->wconverted_form[0] = '\0';
			return (1);
		}
		if (argv_sign(arg) < 0)
			tmp = str_to_wstr(apply_negative(arg));
		else if (argv_sign(arg) >= 0)
			tmp = str_to_wstr(apply_positive(arg));
		if (arg->wconverted_form != NULL)
			free(arg->wconverted_form);
		arg->wconverted_form = tmp;
	}
	else
	{
		if (arg->precision == 0 && argv_sign(arg) == 0)
		{
			if (arg->flags.alt_form == TRUE && (arg->conv == 8 || arg->conv == 80))
				arg->converted_form[1] = '\0';
			else
				arg->converted_form[0] = '\0';
			return (1);
		}
		if (argv_sign(arg) < 0)
			tmp2 = apply_negative(arg);
		else if (argv_sign(arg) >= 0)
			tmp2 = apply_positive(arg);
		if (arg->converted_form != NULL)
			free(arg->converted_form);
		arg->converted_form = tmp2;
	}
	return (1);
}

char	*apply_negative(t_arg *arg)
{
	size_t	i;
	size_t	j;
	size_t	real_pre;
	char	*tmp;

	tmp = NULL;
	real_pre = arg->precision - ft_strlen(arg->converted_form) + 1;
	if (ft_strlen(arg->converted_form) - 1 < (size_t)arg->precision)
	{
		i = 1;
		j = 1;
		if (!(tmp = (char *)malloc((real_pre + ft_strlen(arg->converted_form) + 1) * sizeof(char))))
			return (NULL);
		ft_memset(tmp, '\0', (real_pre + ft_strlen(arg->converted_form) + 1));
		tmp[0] = '-';
		while (i < real_pre + 1)
		{
			tmp[i] = '0';
			i++;
		}
		while (j < ft_strlen(arg->converted_form))
		{
			tmp[i] = arg->converted_form[j];
			i++;
			j++;
		}
		tmp[i] = '\0';
	}
	if (tmp == NULL)
		return (arg->converted_form);
	return (tmp);
}

char	*apply_positive(t_arg *arg)
{
	size_t	i;
	size_t	real_pre;
	char	*tmp;

	tmp = NULL;
	real_pre = arg->precision;
	if (ft_strlen(arg->converted_form) < real_pre)
	{
		i = 0;
		if (!(tmp = (char *)malloc((real_pre - ft_strlen(arg->converted_form) + 1) * sizeof(char))))
			return (NULL);
		ft_memset(tmp, '\0', (real_pre - ft_strlen(arg->converted_form) + 1));
		while (i < real_pre - ft_strlen(arg->converted_form))
		{
			tmp[i] = '0';
			i++;
		}
		tmp[i] = '\0';
		tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form), 1);
	}
	if (tmp == NULL)
		return (arg->converted_form);
	return (tmp);
}

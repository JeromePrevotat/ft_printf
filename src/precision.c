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
	if (arg->conv != 2 && arg->conv != 20 && arg->conv != 3 && arg->conv != 30 && arg->conv != 4 )
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
	int		end;
	int		len;
	int		i;
	wchar_t	*tmp;

	if (arg->wchar_form == TRUE)
	{
		len = 0;
		end = 0;
		tmp = NULL;
		while (*(arg->wconverted_form + end) && len < arg->precision)
		{
			if (*(arg->wconverted_form + end) <= 0x7F)
				len++;
			else if (*(arg->wconverted_form + end) <= 0x7FF)
				len = len + 2;
			else if (*(arg->wconverted_form + end) <= 0xFFFF)
				len = len + 3;
			else if (*(arg->wconverted_form + end)<= 0x10FFFF)
				len = len + 4;
			end++;
		}
		if (len < arg->precision)
			return (1);
		else
		{
			if (!(tmp = (wchar_t *)malloc(end + 1 * sizeof(wchar_t))))
				return (ERROR);
			ft_memset(tmp, '\0', end + 1);
			i = 0;
			while (i < end)
			{
				tmp[i] = *(arg->wconverted_form + i);
				i++;
			}
			tmp[i] = L'\0';
			arg->wconverted_form = tmp;
		}
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
		tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form), 0);
	}
	if (tmp == NULL)
		return (arg->converted_form);
	return (tmp);
}

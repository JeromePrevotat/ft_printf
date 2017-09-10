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
	int	i;

	i = 0;
	if (arg->precision <= 0)
	{
		arg->conv_form->str[0] = '\0';
		arg->conv_form->len = 0;
		return (1);
	}
	if (arg->type == T_WSTR)
		return (1);
	if ((int)arg->conv_form->len > arg->precision)
	{
		arg->conv_form->str[arg->precision]= '\0';
		arg->conv_form->len = arg->precision;
	}

	return (1);
}

int		apply_nbr_pre(t_arg *arg)
{
	char	*tmp;

	tmp = NULL;
	if (arg->precision == 0 && argv_sign(arg) == 0)
	{
		if (arg->flags.alt_form == TRUE && (arg->conv == 8 || arg->conv == 80))
		{
			arg->conv_form->str[1] = '\0';
			arg->conv_form->len = 1;
		}
		else if (arg->type == T_PTR)
		{
			arg->conv_form->str[2] = '\0';
			arg->conv_form->len = 2;
		}
		else
		{
			arg->conv_form->str[0] = '\0';
			arg->conv_form->len = 0;
		}
		return (1);
	}
	if (argv_sign(arg) < 0 && arg->type != T_PTR)
		tmp = apply_negative(arg);
	else if (argv_sign(arg) >= 0 && arg->type != T_PTR)
		tmp = apply_positive(arg);
	else if (arg->type == T_PTR)
		tmp = apply_ptr_precision(arg);
	arg->conv_form->str = tmp;
	arg->conv_form->len = ft_strlen(tmp);
	return (1);
}

char	*apply_negative(t_arg *arg)
{
	size_t	i;
	size_t	j;
	size_t	real_pre;
	char	*tmp;

	tmp = NULL;
	real_pre = arg->precision - arg->conv_form->len + 1;
	if ((int)arg->conv_form->len - 1 < arg->precision)
	{
		i = 1;
		j = 1;
		if (!(tmp = (char *)malloc((real_pre + arg->conv_form->len + 1) * sizeof(char))))
			return (NULL);
		ft_memset(tmp, '\0', (real_pre + arg->conv_form->len + 1));
		tmp[0] = '-';
		while (i < real_pre + 1)
		{
			tmp[i] = '0';
			i++;
		}
		while (j < arg->conv_form->len)
		{
			tmp[i] = arg->conv_form->str[j];
			i++;
			j++;
		}
		tmp[i] = '\0';
	}
	if (tmp == NULL)
		return (arg->conv_form->str);
	return (tmp);
}

char	*apply_positive(t_arg *arg)
{
	size_t	i;
	size_t	real_pre;
	char	*tmp;

	tmp = NULL;
	real_pre = arg->precision;
	if (arg->conv_form->len < real_pre)
	{
		i = 0;
		if (!(tmp = (char *)malloc((real_pre - arg->conv_form->len + 1) * sizeof(char))))

			return (NULL);
		ft_memset(tmp, '\0', (real_pre - arg->conv_form->len + 1));
		while (i < real_pre - arg->conv_form->len)
		{
			tmp[i] = '0';
			i++;
		}
		tmp[i] = '\0';
		tmp = str_memcat(tmp, arg->conv_form->str, arg->conv_form->len, 0);
	}
	if (tmp == NULL)
		return (arg->conv_form->str);
	return (tmp);
}

char	*apply_ptr_precision(t_arg *arg)
{
	char	*tmp;
	int		real_pre;
	int		i;
	int 	j;

	tmp = NULL;
	real_pre = arg->precision - arg->conv_form->len + 2;
	if ((int)arg->conv_form->len < arg->precision)
	{
		if (!(tmp = (char *)malloc(arg->precision + 1 * sizeof(char))))
			return (NULL);
		ft_memset(tmp, '\0', arg->precision + 1);
		i = 0;
		j = 0;
		while (i < 2 && i < arg->precision)
		{
			tmp[i] = arg->conv_form->str[j];
			i++;
			j++;
		}
		while (i < real_pre + 2)
		{
			tmp[i] = '0';
			i++;
		}
		while (j < (int)arg->conv_form->len)
		{
			tmp[i] = arg->conv_form->str[j];
			i++;
			j++;
		}
		tmp[i] = '\0';
	}
	if (tmp == NULL)
		return (arg->conv_form->str);
	return (tmp);
}

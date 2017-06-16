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

int	apply_alt_form(t_arg *arg)
{
	char *tmp;

	if (!(tmp = (char *)malloc(1 * sizeof(char))))
		return (-1);
	ft_memset(tmp, '\0', 1);
	if (arg->conv == 16)
	{
		tmp = str_memcat(tmp, "0x", 2);
		tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form));
		arg->converted_form = tmp;
	}
	if (arg->conv == 160)
	{
		tmp = str_memcat(tmp, "0X", 2);
		tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form));
		arg->converted_form = tmp;
	}
	if (arg->conv == 8 || arg->conv == 80)
	{
		tmp = str_memcat(tmp, "0", 1);
		tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form));
		arg->converted_form = tmp;
	}
	return (1);
}

int	apply_zero(t_arg *arg)
{
	char	*tmp;
	size_t	i;
	int		real_width;

	if (!(tmp = (char *)malloc((arg->width + 1) * sizeof(char))))
		return (-1);
	ft_memset(tmp, '\0', (arg->width + 1));
	i = 0;
	real_width = arg->width - ft_strlen(arg->converted_form);
	while (i < arg->width - ft_strlen(arg->converted_form) && real_width >= 0)
	{
		tmp[i] = '0';
		i++;
	}
	tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form));
	arg->converted_form = tmp;
	return (1);
}

int	apply_minus(t_arg *arg)
{
	char	*tmp;
	size_t	i;
	int		real_width;

	if (!(tmp = (char *)malloc((arg->width + 1) * sizeof(char))))
		return (-1);
	ft_memset(tmp, '\0', (arg->width + 1));
	i = 0;
	real_width = arg->width - ft_strlen(arg->converted_form);
	while (i < arg->width - ft_strlen(arg->converted_form) && real_width >= 0)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp = str_memcat(arg->converted_form, tmp, ft_strlen(tmp));
	arg->converted_form = tmp;
	return (1);
}

int	apply_plus(t_arg *arg)
{
	char *tmp;

	if (!(tmp = (char *)malloc(1 * sizeof(char))))
		return (-1);
	ft_memset(tmp, '\0', 1);
	if (arg->conv == -10 && arg->argv.i_arg > 0)
	{
		tmp = str_memcat(tmp, "+", 1);
		tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form));
		arg->converted_form = tmp;
	}
	return (1);
}

int	apply_space(t_arg *arg)
{
	char *tmp;

	if (!(tmp = (char *)malloc(1 * sizeof(char))))
		return (-1);
	ft_memset(tmp, '\0', 1);
	if (arg->conv == -10 && arg->argv.i_arg > 0)
	{
		tmp = str_memcat(tmp, " ", 1);
		tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form));
		arg->converted_form = tmp;
	}
	return (1);
}

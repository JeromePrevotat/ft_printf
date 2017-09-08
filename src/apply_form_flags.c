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
		return (ERROR);
	ft_memset(tmp, '\0', 1);
	if (arg->conv == 16 && argv_sign(arg) != 0)
		tmp = str_memcat(tmp, "0x", 2, 1);
	if (arg->conv == 160 && argv_sign(arg) != 0)
		tmp = str_memcat(tmp, "0X", 2, 1);
	if ((arg->conv == 8 || arg->conv == 80) && argv_sign(arg) > 0)
		tmp = str_memcat(tmp, "0", 1, 1);
	tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form), 1);
	if (arg->converted_form != NULL)
		free(arg->converted_form);
	arg->converted_form = tmp;
	return (TRUE);
}

int	apply_minus(t_arg *arg)
{
	char	*tmp;
	int		i;
	int		real_width;

	i = 0;
	if (!(tmp = (char *)malloc((arg->width + 1) * sizeof(char))))
		return (ERROR);
	ft_memset(tmp, '\0', (arg->width + 1));
	real_width = arg->width - ft_strlen(arg->converted_form);
	while (i < real_width && real_width >= 0)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
	arg->converted_form = str_memcat(arg->converted_form, tmp, ft_strlen(tmp), 1);
	return (TRUE);
}

int	apply_plus(t_arg *arg)
{
	char	*tmp;

	tmp = NULL;
	if (!(tmp = (char *)malloc(2 * sizeof(char))))
		return (ERROR);
	ft_memset(tmp, '\0', 2);
	if (arg->conv == -10 && argv_sign(arg) >= 0)
	{
		tmp = str_memcat(tmp, "+", ft_strlen("+"), 1);
		tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form), 1);
		if (arg->converted_form != NULL)
			free(arg->converted_form);
		arg->converted_form = tmp;
	}
	return (TRUE);
}

int	apply_space(t_arg *arg)
{
	char	*tmp;

	tmp = NULL;
	if (!(tmp = (char *)malloc(1 * sizeof(char))))
		return (ERROR);
	ft_memset(tmp, '\0', 1);
	if (arg->conv == -10 && argv_sign(arg) >= 0)
	{
		tmp = str_memcat(tmp, " ", 1, 1);
		tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form), 1);
		if (arg->converted_form != NULL)
			free(arg->converted_form);
		arg->converted_form = tmp;
	}

	return (TRUE);
}

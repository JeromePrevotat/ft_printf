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

int	set_zero_flag(t_arg *arg)
{
	if (arg->flags.zero == OVERRIDE || arg->flags.precision == TRUE)
	{
		arg->flags.zero = OVERRIDE;
		return (TRUE);
	}
	else
		arg->flags.zero = TRUE;
	arg->flags.width = TRUE;
	return (TRUE);
}

int	apply_zero(t_arg *arg)
{
	char	*tmp;
	int		i;
	size_t	j;
	int		real_width;

	if (arg->type == T_STR || arg->type == 0)
		return (apply_str_zero(arg));
	i = 0;
	j = 0;
	if (!(tmp = (char *)malloc((arg->width + 1) * sizeof(char))))
		return (ERROR);
	ft_memset(tmp, '\0', (arg->width + 1));
	if (arg->flags.plus == TRUE && argv_sign(arg) >= 0)
		real_width = arg->width - arg->conv_form->len - 1;
	else if (arg->type == T_PTR)
		real_width = arg->width - arg->conv_form->len - 2;
	else
		real_width = arg->width - arg->conv_form->len;
	if (arg->flags.space == TRUE)
		real_width--;
	if (arg->flags.alt_form == TRUE && (arg->conv == 16 || arg->conv == 160))
		return (apply_zero_hex_altform(arg));
	if (argv_sign(arg) == -1)
	{
		tmp[i] = '-';
		j++;
	}
	while (i < real_width && real_width >= 0)
	{
		tmp[i + j] = '0';
		i++;
	}
	while (j < arg->conv_form->len)
	{
		tmp[i + j] = arg->conv_form->str[j];
		j++;
	}
	tmp[i + j] = '\0';

	if (arg->conv_form->str != NULL)
	{
		free(arg->conv_form->str);
		arg->conv_form->str = NULL;
	}

	arg->conv_form->str = tmp;
	if (real_width >= 0)
		arg->conv_form->len = arg->conv_form->len + real_width;
	arg->flags.zero = DONE;
	return (TRUE);
}

int	apply_str_zero(t_arg *arg)
{
	int		i;
	int		real_width;
	char	*tmp;

	i = 0;
	tmp = NULL;
	real_width = arg->width - arg->conv_form->len;
	if (real_width > 0)
	{
		if (!(tmp = (char *)malloc((arg->width + 1) * sizeof(char))))
			return (ERROR);
		ft_memset(tmp, '\0', (arg->width + 1));
		while (i < real_width)
		{
			tmp[i] = '0';
			i++;
		}
		tmp[i] = '\0';
		tmp = str_memcat(tmp, arg->conv_form->str, arg->conv_form->len, 1);

		if (arg->conv_form->str != NULL)
		{
			free(arg->conv_form->str);
			arg->conv_form->str = NULL;
		}

		arg->conv_form->str = tmp;
		arg->conv_form->len = arg->conv_form->len + real_width;
		arg->flags.zero = DONE;
	}
	return (1);
}

int	apply_zero_hex_altform(t_arg *arg)
{
	int		i;
	int		real_width;
	size_t	j;
	char	*tmp;

	if (!(tmp = (char *)malloc((arg->width + 1) * sizeof(char))))
		return (ERROR);
	ft_memset(tmp, '\0', (arg->width + 1));
	real_width = arg->width - arg->conv_form->len;
	tmp[0] = arg->conv_form->str[0];
	tmp[1] = arg->conv_form->str[1];
	i = 2;
	j = 2;
	while (i - 2 < real_width && real_width >= 0)
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
	if (arg->conv_form->str != NULL)
		free(arg->conv_form->str);
	arg->conv_form->str = tmp;
	arg->conv_form->len = arg->conv_form->len + real_width;
	return (TRUE);
}

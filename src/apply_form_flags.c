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
	if (arg->conv == 8 || arg->conv == 80)
		tmp = str_memcat(tmp, "0", 1, 1);
	tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form), 1);
	if (arg->converted_form != NULL)
		free(arg->converted_form);
	arg->converted_form = tmp;
	return (TRUE);
}

int	apply_minus(t_arg *arg)
{
	wchar_t	*tmp;
	char	*tmp2;
	int		i;
	int		real_width;

	i = 0;
	if (arg->wconverted_form != NULL)
	{
		if (!(tmp = (wchar_t *)malloc((arg->width + 1) * sizeof(wchar_t))))
			return (ERROR);
		ft_memset(tmp, '\0', (arg->width + 1));
		real_width = arg->width - ft_wstrlen(arg->wconverted_form);
		while (i < real_width && real_width >= 0)
		{
			tmp[i] = ' ';
			i++;
		}
		tmp[i] = '\0';
		arg->wconverted_form = wstr_memcat(arg->wconverted_form, tmp, ft_wstrlen(tmp), 1);
	}
	else
	{
		if (!(tmp2 = (char *)malloc((arg->width + 1) * sizeof(char))))
			return (ERROR);
		ft_memset(tmp2, '\0', (arg->width + 1));
		real_width = arg->width - ft_strlen(arg->converted_form);
		while (i < real_width && real_width >= 0)
		{
			tmp2[i] = ' ';
			i++;
		}
		tmp2[i] = '\0';
		arg->converted_form = str_memcat(arg->converted_form, tmp2, ft_strlen(tmp2), 1);
	}
	return (TRUE);
}

int	apply_plus(t_arg *arg)
{
	/*wchar_t	*tmp;

	if (arg->wconverted_form == NULL)
		arg->wconverted_form = str_to_wstr(arg->converted_form);
	if (!(tmp = (wchar_t *)malloc(2 * sizeof(wchar_t))))
		return (ERROR);
	ft_memset(tmp, '\0', 2);
	if (arg->conv == -10 && argv_sign(arg) >= 0)
	{
		tmp = wstr_memcat(tmp, L"+", ft_wstrlen(L"+"), 1);
		tmp = wstr_memcat(tmp, arg->wconverted_form, ft_wstrlen(arg->wconverted_form), 1);
		if (arg->wconverted_form != NULL)
			free(arg->wconverted_form);
		arg->wconverted_form = tmp;
	}*/
	char	*tmp;
	wchar_t	*wtmp;

	tmp = NULL;
	wtmp = NULL;
	if (arg->wchar_form == TRUE)
	{
		if (!(wtmp = (wchar_t *)malloc(2 * sizeof(wchar_t))))
			return (ERROR);
		ft_memset(wtmp, '\0', 2);
		if (arg->conv == -10 && argv_sign(arg) >= 0)
		{
			wtmp = wstr_memcat(wtmp, L"+", ft_wstrlen(L"+"), 1);
			wtmp = wstr_memcat(wtmp, arg->wconverted_form, ft_wstrlen(arg->wconverted_form), 1);
			if (arg->wconverted_form != NULL)
				free(arg->wconverted_form);
			arg->wconverted_form = wtmp;
		}
	}
	else
	{
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
	}
	return (TRUE);
}

int	apply_space(t_arg *arg)
{
	char	*tmp;
	wchar_t	*wtmp;

	tmp = NULL;
	wtmp = NULL;
	//printf("ARGV SIGN : %d // ARGV : %jd\n", argv_sign(arg), arg->argv.imax_arg);
	if (arg->wchar_form == TRUE)
	{
		if (!(wtmp = (wchar_t *)malloc(1 * sizeof(wchar_t))))
			return (ERROR);
		ft_memset(wtmp, '\0', 1);
		if (arg->conv == -10 && argv_sign(arg) > 0)
		{
			wtmp = wstr_memcat(wtmp, L" ", 1, 1);
			wtmp = wstr_memcat(wtmp, arg->wconverted_form, ft_wstrlen(arg->wconverted_form), 1);
			if (arg->wconverted_form != NULL)
				free(arg->wconverted_form);
			arg->wconverted_form = wtmp;
		}
	}
	else
	{
		if (!(tmp = (char *)malloc(1 * sizeof(char))))
			return (ERROR);
		ft_memset(tmp, '\0', 1);
		if (arg->conv == -10 && argv_sign(arg) > 0)
		{
			tmp = str_memcat(tmp, " ", 1, 1);
			tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form), 1);
			if (arg->converted_form != NULL)
				free(arg->converted_form);
			arg->converted_form = tmp;
		}
	}
	return (TRUE);
}

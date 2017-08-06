/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c	                         		        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*int		set_width(t_arg *arg, char *str_form)
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
}*/

/*int		apply_width(t_arg *arg)
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
	arg->wconverted_form = wstr_memcat(tmp, arg->wconverted_form,
		ft_wstrlen(arg->wconverted_form), 2);
	return (1);
}*/

int		set_width(t_arg *arg, wchar_t *str_form)
{
	size_t	i;
	char	*width;

	i = 0;
	if (arg->flags.width == TRUE)
		return (ERROR);
	if (!(width = (char *)malloc(ft_wstrlen(str_form) * sizeof(char))))
		return (ERROR);
	ft_memset(width, '\0', ft_wstrlen(str_form));
	while (i < ft_wstrlen(str_form) && ft_isdigit(str_form[i]))
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
	if ((arg->type == T_CHAR && arg->argv.c_arg == 0) || (arg->type == T_WCHAR && arg->argv.wchar_arg == 0))
		real_width = arg->width - 1;
	else
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
	arg->wconverted_form = wstr_memcat(tmp, arg->wconverted_form,
		ft_wstrlen(arg->wconverted_form), 2);
	return (1);
}

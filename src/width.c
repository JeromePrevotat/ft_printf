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

int		set_width(t_arg *arg, char *str_form)
{
	size_t	i;
	char	*width;

	i = 0;
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
	char	*tmp;

	i = 0;
	real_width = 0;
	tmp = NULL;
	if (!(tmp = (char *)malloc((arg->width + 1) * sizeof(char))))
	return (ERROR);
	if (arg->wchar_form == TRUE)
		apply_wstr_width(arg);
	else
		apply_str_width(arg);
	free(tmp);
	return (1);
}

void	apply_str_width(t_arg *arg)
{
	char	*tmp;
	int		real_width;
	int		i;

	i = 0;
	real_width = 0;
	tmp = NULL;
	if (!(tmp = (char *)malloc((arg->width + 1) * sizeof(char))))
		return ;
	ft_memset(tmp, '\0', (arg->width + 1));
	if (arg->type == T_CHAR && arg->argv.c_arg == 0)
		real_width = arg->width - 1;
	else
		real_width = arg->width - ft_strlen(arg->converted_form);
	while (i < real_width && real_width >= 0)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
	tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form), 0);
	free(arg->converted_form);
	arg->converted_form = tmp;
}

void	apply_wstr_width(t_arg *arg)
{
	wchar_t	*tmp;
	int		real_width;
	int		i;

	i = 0;
	real_width = 0;
	tmp = NULL;
	if (!(tmp = (wchar_t *)malloc((arg->width + 1) * sizeof(wchar_t))))
		return ;
	ft_memset(tmp, '\0', (arg->width + 1));
	if (arg->type == T_WCHAR && arg->argv.wchar_arg == 0)
		real_width = arg->width - 1;
	else
		real_width = arg->width - ft_wstr_blen(arg->wconverted_form);
	while (i < real_width && real_width >= 0)
	{
		tmp[i] = L' ';
		i++;
	}
	tmp[i] = L'\0';
	arg->wconverted_form = wstr_memcat(tmp, arg->wconverted_form, ft_wstr_blen(arg->wconverted_form), 0);
}

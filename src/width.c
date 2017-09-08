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
	apply_str_width(arg);
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
		//real_width = arg->width - ft_strlen(arg->converted_form);
		real_width = arg->width - arg->converted_form->len;
	if (real_width >= 0)
	{
		while (i < real_width)
		{
			tmp[i] = ' ';
			i++;
		}
		tmp[i] = '\0';
		//tmp = str_memcat(tmp, arg->converted_form, ft_strlen(arg->converted_form), 0);
		tmp = str_memcat(tmp, arg->converted_form->str, arg->converted_form->len, 0);
		//free(arg->converted_form->str);
		arg->converted_form->str = tmp;
		arg->converted_form->len = arg->converted_form->len + real_width;
	}
}

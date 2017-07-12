/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c  	                      	                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*str_memcat(char *mem1, const char *mem2, size_t size)
{
	char	*tmp;

	if (!(tmp = (char *)malloc((ft_strlen(mem1) + size + 1) * sizeof(char))))
		return (NULL);
	ft_memset(tmp, '\0', (size_t)(ft_strlen(mem1) + size + 1));
	ft_memcpy(tmp, mem1, ft_strlen(mem1));
	ft_memcpy(tmp + ft_strlen(mem1), mem2, size);
	tmp[ft_strlen(mem1) + size] = '\0';
	//if (mem1 != NULL)
		//free(mem1);
	return (tmp);
}

int		get_width(char *str, t_arg *arg)
{
	size_t	j;
	size_t	i;
	char	*tmp;

	j = 1;
	while (j < ft_strlen(str) && ft_isdigit(str[j]))
		j++;
	if (!(tmp = (char *)malloc((j + 1) * sizeof(char))))
		return (ERROR);
	ft_memset(tmp, '\0', j + 1);
	i = 0;
	while (i < j)
	{
		tmp[i] = str[i + 1];
		i++;
	}
	arg->width = ft_atoi(tmp);
	return (j);
}

int		argv_sign(t_arg *arg)
{
	if ((arg->type == T_SHORT || arg->type == T_INT) && (arg->argv.sh_arg < 0 || arg->argv.i_arg < 0))
		return (-1);
	if ((arg->type == T_LONG || arg->type == T_LLONG) && (arg->argv.l_arg < 0 || arg->argv.ll_arg < 0))
		return (-1);
	if ((arg->type == T_SHORT || arg->type == T_INT) && (arg->argv.sh_arg > 0 || arg->argv.i_arg > 0))
		return (1);
	if ((arg->type == T_LONG || arg->type == T_LLONG) && (arg->argv.l_arg > 0 || arg->argv.ll_arg > 0))
		return (1);
	return (0);
}

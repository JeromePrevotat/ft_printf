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

char	*str_memcat(char *mem1, char *mem2, size_t size, int del)
{
	char	*tmp;

	if (!(tmp = (char *)malloc((ft_strlen(mem1) + size + 1) * sizeof(char))))
		return (NULL);
	ft_memset(tmp, '\0', (size_t)(ft_strlen(mem1) + size + 1));
	ft_memcpy(tmp, mem1, ft_strlen(mem1));
	ft_memcpy(tmp + ft_strlen(mem1), mem2, size);
	tmp[ft_strlen(mem1) + size] = '\0';
	sfree(mem1, mem2, del);
	return (tmp);
}

void sfree(char *mem1, char *mem2, int del)
{
	if (del == 1 && mem1 != NULL)
		free(mem1);
	if (del == 2 && mem2 != NULL)
		free(mem2);
	if (del == 3 && mem1 != NULL && mem2 != NULL)
	{
		free(mem1);
		free(mem2);
	}
}

int		get_width(wchar_t *str, t_arg *arg)
{
	size_t	j;
	size_t	i;
	char	*tmp;

	j = 1;
	while (j < ft_wstrlen(str) && ft_isdigit(str[j]))
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

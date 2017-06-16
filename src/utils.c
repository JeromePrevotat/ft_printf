/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:59:53 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/24 18:02:45 by admin            ###   ########.fr       */
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
	if (mem1 != NULL)
		free(mem1);
	return (tmp);
}

int		get_width(char *str, t_arg *arg)
{
	size_t	j;
	size_t	i;
	char	*tmp;

	j = 1;
	while (j < ft_strlen(str) - 1 && ft_isdigit(str[j]))
		j++;
	if (!(tmp = (char *)malloc((j + 1) * sizeof(char))))
		return (-1);
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

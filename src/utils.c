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

#include "libft.h"
#include "ft_printf.h"

char	*str_memcat(char *mem1, const char *mem2, size_t size)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(ft_strlen(mem1) + size + 1)))
		return (NULL);
	ft_memset(tmp, '\0', (size_t)(ft_strlen(mem1) + size + 1));
	ft_memcpy(tmp, mem1, ft_strlen(mem1));
	ft_memcpy(tmp + ft_strlen(mem1), mem2, size);
	tmp[ft_strlen(mem1) + size] = '\0';
	if (mem1 != NULL)
		free(mem1);
	return (tmp);
}

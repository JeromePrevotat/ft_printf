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

char 	*str_memcat(char *mem1, const char *mem2, size_t size)
{
	char *tmp;

	if (!(tmp = (char *)malloc(ft_strlen(mem1) + size + 1)))
		return (NULL);
	ft_memset(tmp, '\0', (size_t)(ft_strlen(mem1) + size + 1));
	ft_memcpy(tmp, mem1, ft_strlen(mem1));
	ft_memcpy(tmp + ft_strlen(mem1), mem2, size);
	tmp[ft_strlen(mem1) + size] = '\0';
	free(mem1);
	return (tmp);
}
/*
static int	ft_nb_len(int n)
{
	unsigned int	nb;
	int				nb_len;

	nb = n;
	nb_len = 1;
	if (n < 0)
	{
		nb = -n;
		nb_len++;
	}
	while (nb / 10 > 0)
	{
		nb_len++;
		nb = nb / 10;
	}
	return (nb_len);
}

char		*ft_itoa_base(int n, int base)
{
	char			*str;
	int				nb_len;
	unsigned int	nb;

	nb_len = ft_nb_len(n);
	nb = n;
	if (n < 0)
		nb = -n;
	str = (char *)malloc((nb_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[nb_len] = '\0';
	nb_len--;
	while (nb_len >= 0)
	{
		str[nb_len] = nb % 10 + '0';
		nb = nb / 10;
		nb_len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}*/

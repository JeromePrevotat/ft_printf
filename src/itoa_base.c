/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:43:04 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/22 13:57:44 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/ft_printf.h"

static int	ft_nb_len(long n, int base)
{
	unsigned long	nb;
	int				nb_len;

	nb = n;
	nb_len = 1;
	if (n < 0)
	{
		nb = -n;
		nb_len++;
	}
	while (nb / base > 0)
	{
		nb_len++;
		nb = nb / base;
	}
	return (nb_len);
}

char		*itoa_base(long n, int base)
{
	char			*str;
	int				nb_len;
	unsigned long	nb;

	nb_len = ft_nb_len(n / base, base);
	nb = n;
	if (n < 0)
		nb = -n;
	if (!(str = (char *)malloc((nb_len + 1) * sizeof(char))))
		return (NULL);
	ft_memset(str, '\0', nb_len + 1);
	while (nb_len >= 0)
	{
		if (nb % base >= 10)
		str[nb_len] = 'a' + ((nb % base) - 10);
		else
			str[nb_len] = nb % base + '0';
		nb = nb / base;
		nb_len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

static int	ft_nb_len_unsigned(unsigned long n, int base)
{
	unsigned long	nb;
	int			nb_len;

	nb = n;
	nb_len = 1;
	while (nb / base > 0)
	{
		nb_len++;
		nb = nb / base;
	}
	return (nb_len);
}

char		*itoa_base_unsigned(unsigned long n, int base)
{
	char			*str;
	int				nb_len;
	unsigned long	nb;
	char 			hex;

	hex = 'a';
	if (base == 160)
	{
		base = 16;
		hex = 'A';
	}
	nb_len = ft_nb_len_unsigned(n / base, base);
	nb = n;
	if (!(str = (char *)malloc((nb_len + 1) * sizeof(char))))
		return (NULL);
	ft_memset(str, '\0', nb_len + 1);
	while (nb_len >= 0)
	{
		if (nb % base >= 10)
			str[nb_len] = hex + ((nb % base) - 10);
		else
			str[nb_len] = nb % base + '0';
		nb = nb / base;
		nb_len--;
	}
	return (str);
}

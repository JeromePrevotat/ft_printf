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

#include "libft.h"
#include "ft_printf.h"

static int	ft_nb_len(int n, int base)
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
	while (nb / base > 0)
	{
		nb_len++;
		nb = nb / base;
	}
	return (nb_len);
}

char		*itoa_base(int n, int base)
{
	char			*str;
	int				nb_len;
	unsigned int	nb;

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

static int	ft_nb_len_unsigned(unsigned int n, int base)
{
	unsigned int	nb;
	int			nb_len;

	nb = n;
	nb_len = 1;
	if (base == 160)
		base = 16;
	while (nb / base > 0)
	{
		nb_len++;
		nb = nb / base;
	}
	return (nb_len);
}

char		*itoa_base_unsigned(unsigned int n, int base)
{
	char			*str;
	int			nb_len;
	unsigned int	nb;
	char 		hex;

	hex = 'a';
	if (base == 16)
		hex = 'a';
	if (base == 160)
	{
		hex = 'A';
		base = 16;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c  	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_nb_len_sh(short n, int base)
{
	unsigned short	nb;
	int				nb_len;

	nb = n;
	nb_len = 0;
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

char		*itoa_base_sh(short n, int base)
{
	char			*str;
	int				nb_len;
	unsigned short	nb;

	nb_len = ft_nb_len_sh(n, base);
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

static int	ft_nb_len(int n, int base)
{
	unsigned int	nb;
	int				nb_len;

	nb = n;
	nb_len = 0;
	if (n < 0)
		nb = -n;
	if (n < 0 && base != 8 && base != 16)
		nb_len++;
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

	nb_len = ft_nb_len(n, base);
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
	if (n < 0 && base != 8 && base != 16)
		str[0] = '-';
	return (str);
}

static int	ft_nb_len_unsigned(unsigned int n, int base)
{
	unsigned int	nb;
	int			nb_len;

	nb = n;
	nb_len = 0;
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
	int				nb_len;
	unsigned int	nb;
	char 			hex;

	hex = 'a';
	if (base == 160)
	{
		base = 16;
		hex = 'A';
	}
	nb_len = ft_nb_len_unsigned(n, base);
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

/*static int	ft_nb_len_long(unsigned long n, int base)
{
	unsigned long	nb;
	int			nb_len;

	nb = n;
	nb_len = 0;
	while (nb / base > 0)
	{
		nb_len++;
		nb = nb / base;
	}
	return (nb_len);
}*/

static int	ft_nb_len_long(long n, int base)
{
	long		nb;
	int			nb_len;

	nb = n;
	nb_len = 0;
	if (n < 0)
	{
		nb_len++;
		nb = -n;
	}
	while (nb / base > 0)
	{
		nb_len++;
		nb = nb / base;
	}
	return (nb_len);
}

/*char		*itoa_base_long(long n, int base)
{
	char			*str;
	int				nb_len;
	unsigned long	nb;
	char 			hex;

	printf("ENTERING ITOA BASE LONG\n");
	printf("N : %jd // BASE : %d\n", n, base);
	hex = 'a';
	if (base == 160)
	{
		base = 16;
		hex = 'A';
	}
	nb_len = ft_nb_len_long(n, base);
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
}*/

char		*itoa_base_long(long n, int base)
{
	char			*str;
	int				nb_len;
	long			nb;
	char 			hex;

	hex = 'a';
	if (base == 160)
	{
		base = 16;
		hex = 'A';
	}
	nb_len = ft_nb_len_long(n, base);
	nb = n;
	if (!(str = (char *)malloc((nb_len + 1) * sizeof(char))))
		return (NULL);
	ft_memset(str, '\0', nb_len + 1);
	if (n < 0)
		nb = -n;
	while (nb_len >= 0)
	{
		if (nb % base >= 10)
			str[nb_len] = hex + ((nb % base) - 10);
		else
			str[nb_len] = nb % base + '0';
		nb = nb / base;
		nb_len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

static int	ft_nb_len_unsigned_long(unsigned long n, int base)
{
	unsigned long	nb;
	int			nb_len;

	nb = n;
	nb_len = 0;
	while (nb / base > 0)
	{
		nb_len++;
		nb = nb / base;
	}
	return (nb_len);
}

char		*itoa_base_unsigned_long(unsigned long n, int base)
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
	nb_len = ft_nb_len_unsigned_long(n, base);
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

static int	ft_nb_len_llong(long long n, int base)
{
	unsigned long long	nb;
	int					nb_len;

	nb_len = 0;
	nb = n;
	if (n < 0)
		nb_len++;
	while (nb / base > 0)
	{
		nb_len++;
		nb = nb / base;
	}
	return (nb_len);
}

char		*itoa_base_llong(long long n, int base)
{
	char				*str;
	int					nb_len;
	unsigned long long	nb;
	char 				hex;

	hex = 'a';
	if (base == 160)
	{
		base = 16;
		hex = 'A';
	}
	nb_len = ft_nb_len_llong(n, base);
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
	if (n < 0)
		str[0] = '-';
	return (str);
}

static int	ft_nb_len_unsigned_llong(unsigned long long n, int base)
{
	unsigned long long	nb;
	int					nb_len;

	nb = n;
	nb_len = 0;
	while (nb / base > 0)
	{
		nb_len++;
		nb = nb / base;
	}
	return (nb_len);
}

char		*itoa_base_unsigned_llong(unsigned long long n, int base)
{
	char				*str;
	int					nb_len;
	unsigned long long	nb;
	char 				hex;

	hex = 'a';
	if (base == 160)
	{
		base = 16;
		hex = 'A';
	}
	nb_len = ft_nb_len_unsigned_llong(n, base);
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

static int	ft_nb_len_imax(intmax_t n, int base)
{
	intmax_t	nb;
	int			nb_len;

	nb = n;
	nb_len = 0;
	while (nb / base > 0)
	{
		nb_len++;
		nb = nb / base;
	}
	return (nb_len);
}

char		*itoa_base_imax(intmax_t n, int base)
{
	char				*str;
	int					nb_len;
	intmax_t			nb;
	char 				hex;

	hex = 'a';
	if (base == 160)
	{
		base = 16;
		hex = 'A';
	}
	nb_len = ft_nb_len_imax(n, base);
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

static int	ft_nb_len_uimax(uintmax_t n, int base)
{
	uintmax_t	nb;
	int			nb_len;

	nb = n;
	nb_len = 0;
	while (nb / base > 0)
	{
		nb_len++;
		nb = nb / base;
	}
	return (nb_len);
}

char		*itoa_base_uimax(uintmax_t n, int base)
{
	char				*str;
	int					nb_len;
	uintmax_t			nb;
	char 				hex;

	hex = 'a';
	if (base == 160)
	{
		base = 16;
		hex = 'A';
	}
	nb_len = ft_nb_len_uimax(n, base);
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

static int	ft_nb_len_st(size_t n, int base)
{
	size_t	nb;
	int			nb_len;

	nb = n;
	nb_len = 0;
	while (nb / base > 0)
	{
		nb_len++;
		nb = nb / base;
	}
	return (nb_len);
}

char		*itoa_base_st(size_t n, int base)
{
	char			*str;
	int				nb_len;
	size_t			nb;
	char 			hex;

	hex = 'a';
	if (base == 160)
	{
		base = 16;
		hex = 'A';
	}
	nb_len = ft_nb_len_st(n, base);
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

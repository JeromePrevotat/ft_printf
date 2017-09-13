/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	binary_conv(t_arg *arg)
{
	int		base;
	char	*tmp;

	tmp = NULL;
	base = arg->conv;
	if (argv_sign(arg) >= 0)
		tmp = itoa_base_imax(arg->argv.imax_arg, base);
	else
		tmp = cmp2(arg, base);
	arg->conv_form->len = ft_strlen(tmp);
	if (arg->conv_form->str != NULL)
	{
		free(arg->conv_form->str);
		arg->conv_form->str = NULL;
	}
	arg->conv_form->str = ft_strdup(tmp);
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
}

char	*cmp2(t_arg *arg, int base)
{
	char	*tmp;
	int		len;

	len = get_len(arg);
	tmp = NULL;
	//Conversion
	//arg->argv.imax_arg = ((~arg->argv.imax_arg) & 1);
	//Malloc en fonction de la taille du type de la var
	//Total = Sizeof(var) * Sizeof(1 Bytes) + 1
	if (!(tmp = (char *)malloc((len) * sizeof(char))))
		return (NULL);
	ft_memset(tmp, '\0', len);
	//Fill tmp
	//Test bit AND 1 shifted size - i on the left to math the actual tested bit
	//TRUE : bit = 1 ; FALSE : bit = 0
	tmp[len] = '\0';
	len--;
	while (len >= 0)
	{
		tmp[len] = ((arg->argv.i_arg) & (1 << len)) ? '1' : '0';
		len--;
	}
	return (strrev(tmp));
}

int		get_len(t_arg *arg)
{
	int	len;

	len = 0;
	if (arg->type == T_SHORT)
	{
		len = sizeof(short) * 8;
		arg->argv.i_arg = arg->argv.imax_arg;
	}
	if (arg->type == T_INT)
	{
		len = sizeof(int) * 8;
		arg->argv.i_arg = arg->argv.imax_arg;
	}
	if (arg->type == T_LONG)
	{
		len = sizeof(long) * 8;
		arg->argv.l_arg = arg->argv.imax_arg;
	}
	if (arg->type == T_LLONG)
	{
		len = sizeof(long long) * 8;
		arg->argv.ll_arg = arg->argv.imax_arg;
	}
	if (arg->type == T_IMAX)
		len = sizeof(intmax_t) * 8;
	return (len);
}

char	*strrev(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!(tmp = (char *)malloc(ft_strlen(str) + 1 * sizeof(char))))
		return (NULL);
	ft_memset(tmp, '\0', ft_strlen(str) + 1);
	printf("str[len] : >%c<\n", str[ft_strlen(str)]);
	while (i < ft_strlen(str))
	{
		printf("str len : %zu\n", ft_strlen(str));
		tmp[i] = str[ft_strlen(str) - i - 1];
		i++;
	}
	tmp[i] = '\0';
	if (str != NULL)
		free(str);
	return (tmp);
}

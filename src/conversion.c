/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:59:53 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/24 18:02:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/ft_printf.h"

int		is_conversion(char c)
{
	char	*conv_tab;
	int		i;

	conv_tab = init_conv_tab();
	i = 0;
	while (i < 15)
	{
		if (c == conv_tab[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*init_conv_tab(void)
{
	char *conv_tab;

	if (!(conv_tab = (char *)malloc(15 * sizeof(char))))
		return (NULL);
	conv_tab[0] = '%';
	conv_tab[1] = 's';
	conv_tab[2] = 'S';
	conv_tab[3] = 'p';
	conv_tab[4] = 'd';
	conv_tab[5] = 'D';
	conv_tab[6] = 'i';
	conv_tab[7] = 'o';
	conv_tab[8] = 'O';
	conv_tab[9] = 'u';
	conv_tab[10] = 'U';
	conv_tab[11] = 'x';
	conv_tab[12] = 'X';
	conv_tab[13] = 'c';
	conv_tab[14] = 'C';
	return (conv_tab);
}

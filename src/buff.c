/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c 		  	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	init_buffer(t_buff *buff)
{
	buff->str = NULL;
	buff->len = 0;
}

void write_buffer(t_buff *buff)
{
	size_t	i;

	i = 0;
	/*while (i < buff->len)
	{
		write(1, buff->str + i, 1);
		i++;
	}*/

	write(1, buff->str, buff->len);
}

void cat_buffer(t_buff *buff, t_arg *arg)
{
	size_t	i;
	size_t	j;
	char	*new_buff;

	i = 0;
	j = 0;
	if (!(new_buff = (char *)malloc((arg->conv_form->len + buff->len + 1) * sizeof(char))))
		return ;
	ft_memset(new_buff, '\0', arg->conv_form->len + buff->len + 1);
	while (i < buff->len)
	{
		new_buff[i] = buff->str[i];
		i++;
	}
	while (j < arg->conv_form->len)
	{
		new_buff[i + j] = arg->conv_form->str[j];
		j++;
	}
	new_buff[i + j] = '\0';
	buff->len = buff->len + arg->conv_form->len;

	if (buff->str != NULL)
	{
		free(buff->str);
		buff->str = NULL;
	}
	buff->str = new_buff;
}

void cat_str_buffer(t_buff *buff, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*new_buff;

	i = 0;
	j = 0;
	if (!(new_buff = (char *)malloc((size + buff->len + 1) * sizeof(char))))
		return;
	ft_memset(new_buff, '\0', size + buff->len + 1);
	while (i < buff->len)
	{
		new_buff[i] = buff->str[i];
		i++;
	}
	while (j < size)
	{
		new_buff[i + j] = src[j];
		j++;
	}
	new_buff[i + j] = '\0';

	if (buff->str != NULL)
	{
		free(buff->str);
		buff->str = NULL;
	}

	buff->str = new_buff;
	buff->len = buff->len + size;
}

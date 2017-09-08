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

int	init_buffer(t_buff **buff)
{
	if (!((*buff) = (t_buff *)malloc(1 * sizeof(t_buff))))
		return (ERROR);
	if (!((*buff)->str = (char *)malloc(1 * sizeof(char))))
		return (ERROR);
	ft_memset((*buff)->str, '\0', 1);
	(*buff)->len = 0;
	return (1);
}

void write_buffer(t_buff *buff)
{
	size_t	i;

	i = 0;
	while (i < buff->len)
	{
		write(1, buff->str + i, 1);
		i++;
	}

	//write(1, buff->str, buff->len);
}

void cat_buffer(t_buff *buff, t_buff *src)
{
	size_t	i;
	size_t	j;
	char	*new_buff;

	i = 0;
	j = 0;
	if (!(new_buff = (char *)malloc((src->len + buff->len + 1) * sizeof(char))))
		return;
	ft_memset(new_buff, '\0', src->len + buff->len + 1);
	while (i < buff->len)
	{
		new_buff[i] = buff->str[i];
		i++;
	}
	while (j < src->len)
	{
		new_buff[i + j] = src->str[j];
		j++;
	}
	new_buff[i + j] = '\0';
	buff->len = buff->len + src->len;
	free(buff->str);
	//free(src->str);
	//free(src);
	buff->str = new_buff;
}

void cat_str_buffer(t_buff *buff, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*new_buff;

	i = 0;
	j = 0;
	if (!(new_buff = (char *)malloc((size + buff->len) * sizeof(char))))
		return;
	ft_memset(new_buff, '\0', size + buff->len);
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
	//free(buff->str);
	buff->str = new_buff;
	buff->len = buff->len + size;
}

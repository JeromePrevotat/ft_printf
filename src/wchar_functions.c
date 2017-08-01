/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

wchar_t	*str_to_wstr(const char *str)
{
	wchar_t	*wstr;
	size_t	i;

	i = 0;
	if (!(wstr = (wchar_t *)malloc((ft_strlen(str) + 1) * sizeof(wchar_t))))
		return (NULL);
	ft_memset(wstr, '\0', (ft_strlen(str) + 1));
	while (str[i] != '\0')
	{
		wstr[i] = str[i];
		i++;
	}
	wstr[i] = '\0';
	return (wstr);
}

wchar_t	*wstr_memcat(wchar_t *mem1, wchar_t *mem2, size_t size, int del)
{
	wchar_t *tmp;

	tmp = NULL;
	if (mem1 == NULL)
	{
		if (!(mem1 = (wchar_t *)malloc(1 * sizeof(wchar_t))))
			return (NULL);
		ft_memset(mem1, '\0', 1);
	}
	tmp = wcat(mem1, mem2, size);
	wfree(mem1, mem2, del);
	return (tmp);
}

wchar_t	*wcat(wchar_t *mem1, wchar_t *mem2, size_t size)
{
	wchar_t *tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(tmp = (wchar_t *)malloc((ft_wstrlen(mem1) + size + 1) * sizeof(wchar_t))))
		return (NULL);
	ft_memset(tmp, '\0', (ft_wstrlen(mem1) + size + 1));
	//SEGFAULT HERE
	while (mem1[i] != '\0')
	{
		tmp[i] = mem1[i];
		i++;
	}
	while (mem2[j] != '\0' && size != 0)
	{
		tmp[i] = mem2[j];
		i++;
		j++;
		size--;
	}
	tmp[i] = '\0';
	return (tmp);
}

void wfree(wchar_t *mem1, wchar_t *mem2, int del)
{
	if (del == 1 && mem1 != NULL)
		free(mem1);
	if (del == 2 && mem2 != NULL)
		free(mem2);
	if (del == 3 && mem1 != NULL && mem2 != NULL)
	{
		free(mem1);
		free(mem2);
	}
}

size_t	ft_wstrlen(const wchar_t *str)
{
	int	len;

	if (!str)
		return (ERROR);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putwstr(wchar_t *wstr)
{
	size_t i;

	if (!wstr)
		return ;
	i = 0;
	while (wstr[i] != '\0')
	{
		ft_putwchar(wstr[i]);
		i++;
	}
}

void	ft_putwchar(wchar_t c)
{
	write(1, &c, 1 * sizeof(wchar_t));
}

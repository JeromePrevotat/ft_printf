/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:59:53 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/24 18:02:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF
# define TRUE 1
# define FALSE 0
# include <stdarg.h>

int  ft_printf(const char *format, ...);

//Parsing.c
void parsing(const char *format, va_list ap);
int check_existing_conv(char c, char *conv_list);
char  *assign_va_arg(int type, va_list ap, char *str);

//Select_type.c
void init_list(char *conv_list);
int select_type(char c);
char *convert(int x, int type);

//Utils.c
char 	*str_memcat(char *mem1, const char *mem2, size_t size);

//Itoa_base.c
char		*itoa_base(int n, int base);
char		*itoa_base_unsigned(unsigned int n, int base);

#endif

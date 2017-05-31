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

int		ft_printf(const char *format, ...);

//Parsing.c
<<<<<<< HEAD
int		parsing(const char *format, va_list ap);
=======
void	parsing(const char *format, va_list ap);
>>>>>>> 7d1059df80994d3b0bd1e3352e5f04b26ae17231
int		check_existing_conv(char c, char *conv_list);
char	*assign_va_arg(int type, va_list ap, char *str);

//Select_type.c
void	init_list(char *conv_list);
int		select_type(char c);
char	*convert(int x, int type);
<<<<<<< HEAD

//Cat.c
char	*cat_int(char *str, va_list ap, int type);
char	*cat_char(char *str, va_list ap);
char	*cat_wchar(char *str, va_list ap);
char	*cat_str(char *str, va_list ap);
char	*cat_wstr(char *str, va_list ap);
char	*cat_ptr(char *str, va_list ap);
=======
>>>>>>> 7d1059df80994d3b0bd1e3352e5f04b26ae17231

//Utils.c
char	*str_memcat(char *mem1, const char *mem2, size_t size);
char 	*str_wmemcat(char *mem1, const wchar_t *mem2, size_t size);

//Itoa_base.c
<<<<<<< HEAD
char	*itoa_base(long n, int base);
char	*itoa_base_unsigned(unsigned long n, int base);
=======
char	*itoa_base(int n, int base);
char	*itoa_base_unsigned(unsigned int n, int base);
>>>>>>> 7d1059df80994d3b0bd1e3352e5f04b26ae17231

#endif

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

typedef struct		s_flags
{
	int				hashtag;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				z;
}					t_flags;

typedef struct		s_argument
{
	union
	{
		short		s_arg;
		int			i_arg;
		long		l_arg;
		long long	ll_arg;
		char		c_arg;
		char		*str_arg;
		wchar_t		wchar_arg;
		wchar_t		*wstr_arg;
	}				argv;
	t_flags			flags;
	int				type;
	char			*str_form;
	char			*converted_form;
}					t_arg;

enum
{
	T_SHORT, T_INT, T_LONG, T_LLONG, T_CHAR, T_STR, T_WCHAR, T_WSTR
};

int		ft_printf(const char *format, ...);

//Parsing.c
int		parsing(const char *format, va_list ap);
int		parse_format_arg(const char *format, t_arg *arg);

//Conversion.c
int		is_conversion(char c);
char	*init_conv_tab();

//Argument.c
int	init_arg(t_arg *arg);
int	fill_arg(t_arg *arg);

//Utils.c
char	*str_memcat(char *mem1, const char *mem2, size_t size);
char 	*str_wmemcat(char *mem1, const wchar_t *mem2, size_t size);

//Itoa_base.c
char	*itoa_base(int n, int base);
char	*itoa_base_unsigned(unsigned int n, int base);
char	*itoa_base_long(unsigned long n, int base);

#endif

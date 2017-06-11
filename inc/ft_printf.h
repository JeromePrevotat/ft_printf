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
# define OVERRIDE 3
# include <stdarg.h>

typedef struct		s_flags
{
	int				alt_form;
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
		void		*ptr;
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
	int				conv;
	char			*str_form;
	char			*converted_form;
}					t_arg;

enum
{
	T_SHORT, T_INT, T_LONG, T_LLONG, T_CHAR, T_STR, T_WCHAR, T_WSTR, T_PTR
};

int		ft_printf(const char *format, ...);

//Parsing.c
int		parsing(const char *format, va_list ap);
int		parse_format_arg(const char *format, t_arg *arg, va_list ap);

//Conversion.c
int		is_conversion(char c);
char	*init_conv_tab();
char	*convert(int x, int type);


//Argument.c
int		init_arg(t_arg *arg);
int		fill_arg(t_arg *arg, va_list ap);
int		convert_argv(t_arg *arg, va_list ap);

//Arg_functions.c
int		init_flags_arg(t_arg *arg);
int		init_type_arg(t_arg *arg);
int		init_conv_arg(t_arg *arg);
int		parse_flags(t_arg *arg);

int		int_conv(t_arg *arg, va_list ap);
int		long_conv(t_arg *arg, va_list ap);
int		llong_conv(t_arg *arg, va_list ap);
int		char_conv(t_arg *arg, va_list ap);
int		str_conv(t_arg *arg, va_list ap);
int		wchar_conv(t_arg *arg, va_list ap);
int		wstr_conv(t_arg *arg, va_list ap);
int		ptr_conv(t_arg *arg, va_list ap);

//Flags.c
int		is_flag(t_arg *arg, size_t i);
char	*init_flags_tab();
int		set_flag(t_arg *arg, char c);
int		apply_flag(t_arg *arg);

//Flags_functions.c
int		set_alt_form_flag(t_arg *arg);
int		set_zero_flag(t_arg *arg);
int		set_minus_flag(t_arg *arg);
int		set_plus_flag(t_arg *arg);
int		set_space_flag(t_arg *arg);

int		set_h_flag(t_arg *arg);
int		set_l_flag(t_arg *arg);
int		set_j_flag(t_arg *arg);
int		set_z_flag(t_arg *arg);
int		set_hh_flag(t_arg *arg);

int		set_ll_flag(t_arg *arg);


int		apply_alt_form(t_arg *arg);
int		apply_zero(t_arg *arg);
int		apply_minus(t_arg *arg);
int		apply_plus(t_arg *arg);
int		apply_space(t_arg *arg);

int		apply_h(t_arg *arg);
int		apply_hh(t_arg *arg);
int		apply_l(t_arg *arg);
int		apply_ll(t_arg *arg);
int		apply_j(t_arg *arg);

int		apply_z(t_arg *arg);

//Utils.c
char	*str_memcat(char *mem1, const char *mem2, size_t size);
char 	*str_wmemcat(char *mem1, const wchar_t *mem2, size_t size);

//Itoa_base.c
char	*itoa_base(int n, int base);
char	*itoa_base_unsigned(unsigned int n, int base);
char	*itoa_base_long(unsigned long n, int base);

#endif

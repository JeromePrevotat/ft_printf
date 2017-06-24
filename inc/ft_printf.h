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
# define ERROR -1
# define TRUE 1
# define FALSE 0
# define OVERRIDE 3

# include "./libft.h"
# include <stdarg.h>
# include <wchar.h>

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

typedef union		u_argv
{
	void			*ptr;
	size_t			st_arg;
	short			sh_arg;
	int				i_arg;
	long			l_arg;
	long long		ll_arg;
	char			c_arg;
	char			*str_arg;
	wchar_t			wchar_arg;
	wchar_t			*wstr_arg;
}					t_argv;

typedef struct		s_argument
{
	t_argv			argv;
	t_flags			flags;
	int				type;
	int				conv;
	int				width;
	char			*str_form;
	char			*converted_form;
	wchar_t			*wconverted_form;
	int				wchar_form;
}					t_arg;

enum
{
	T_SIZET, T_SHORT, T_INT, T_LONG, T_LLONG, T_CHAR, T_STR, T_WCHAR, T_WSTR, T_PTR
};



//Ft_printf.c
int					ft_printf(const char *format, ...);
int					parsing(const char *format, va_list ap);
int					parse_format_arg(const char *format, t_arg *arg, va_list ap);
int					parse_flags(t_arg *arg);
int					init_parsing_var(wchar_t **wstr, t_arg **arg);

//Parsing_utils.c
int					is_conversion(char c);
char				*init_conv_tab(void);
int					is_flag(t_arg *arg, size_t i);
char				*init_flags_tab(void);
int					set_flag(t_arg *arg, char c);

//Init_arg.c
int					init_arg(t_arg *arg);
int					fill_arg(t_arg *arg, va_list ap);
void				init_flags_arg(t_arg *arg);
void				init_type_arg(t_arg *arg); //USELESS ?
void				init_conv_arg(t_arg *arg);

//Convert.c
int					convert_argv(t_arg *arg, va_list ap);
char				*convert(t_arg *arg);
int					apply_form_flag(t_arg *arg);
int					apply_size_flag(t_arg *arg);

//Special_flags.c
int					set_j_flag(t_arg *arg);
int					set_z_flag(t_arg *arg);
int					apply_j(t_arg *arg);
int					apply_z(t_arg *arg);

//Set_size_flags.c
int					set_l_flag(t_arg *arg);
int					set_ll_flag(t_arg *arg);
int					set_h_flag(t_arg *arg);
int					set_hh_flag(t_arg *arg);

//Set_form_flags.c
int					set_alt_form_flag(t_arg *arg);
int					set_zero_flag(t_arg *arg);
int					set_minus_flag(t_arg *arg);
int					set_plus_flag(t_arg *arg);
int					set_space_flag(t_arg *arg);

//Apply_size_flags.c
int					apply_l(t_arg *arg);
int					apply_ll(t_arg *arg);
int					apply_h(t_arg *arg);
int					apply_hh(t_arg *arg);

//Apply_form_flags.c
int					apply_alt_form(t_arg *arg);
int					apply_zero(t_arg *arg);
int					apply_minus(t_arg *arg);
int					apply_plus(t_arg *arg);
int					apply_space(t_arg *arg);

//Nbr_conv.c
int					st_conv(t_arg *arg, va_list ap);
int					short_conv(t_arg *arg, va_list ap);
int					int_conv(t_arg *arg, va_list ap);
int					long_conv(t_arg *arg, va_list ap);
int					llong_conv(t_arg *arg, va_list ap);
int					ptr_conv(t_arg *arg, va_list ap);

//Char_conv.c
int					char_conv(t_arg *arg, va_list ap);
int					str_conv(t_arg *arg, va_list ap);
int					wchar_conv(t_arg *arg, va_list ap);
int					wstr_conv(t_arg *arg, va_list ap);

//Itoa_base.c
char				*itoa_base(int n, int base);
char				*itoa_base_unsigned(unsigned int n, int base);
char				*itoa_base_long(long n, int base);

//Utils.c
char				*str_memcat(char *mem1, const char *mem2, size_t size);
int					get_width(char *str, t_arg *arg);
int					argv_sign(t_arg *arg);

//Wchar_functions.c
wchar_t				*str_to_wstr(const char *str);
wchar_t				*wstr_memcat(wchar_t *mem1, const wchar_t *mem2, size_t size);
size_t				ft_wstrlen(const wchar_t *str);
void				ft_putwchar(wchar_t c);
void				ft_putwstr(wchar_t *wstr);


#endif

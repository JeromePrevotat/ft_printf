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
# define DONE 4

# include "./libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>
# include <limits.h>
# include <locale.h>

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
	int				precision;
	int				width;
}					t_flags;

typedef union				u_argv
{
	void					*ptr;
	size_t					st_arg;
	unsigned short			ush_arg;
	short					sh_arg;
	unsigned int			ui_arg;
	int						i_arg;
	unsigned long			ul_arg;
	long					l_arg;
	unsigned long long		ull_arg;
	long long				ll_arg;
	uintmax_t				uimax_arg;
	intmax_t				imax_arg;
	unsigned char			uc_arg;
	char					c_arg;
	char					*str_arg;
	wchar_t					wchar_arg;
	wchar_t					*wstr_arg;
}							t_argv;

typedef struct		s_argument
{
	t_argv			argv;
	t_flags			flags;
	int				type;
	int				conv;
	int				width;
	int				precision;
	char			*str_form;
	char			*converted_form;
	wchar_t			*wconverted_form;
	int				wchar_form;
}					t_arg;

enum
{
	T_SIZET, T_USHORT, T_SHORT, T_UINT, T_INT, T_ULONG, T_LONG, T_ULLONG, T_LLONG, T_IMAX, T_UIMAX,
	T_UCHAR, T_CHAR, T_STR, T_WCHAR, T_WSTR, T_PTR
};

//Ft_printf.c
int					ft_printf(const char *format, ...);
int					get_arg(char *format, t_arg *arg, va_list ap);
void				get_arg_str_form(char *format, t_arg *arg, va_list ap);

//Cat_functions.c
int					cat_format(char *format, va_list ap);

//Flags_parsing.c
int					new_flag_parsing(t_arg *arg, char *format, size_t i);
int					new_check_flags_a(t_arg *arg, char *format, size_t i);
int					new_check_flags_b(t_arg *arg, char *format, size_t i);

//Parsing_utils.c
int					new_is_conversion(char c);
int					set_flag(t_arg *arg, char c);

//Undefined_behaviour.c
char				*get_undefined_behaviour(t_arg *arg);
int					ub_is_flag(char c);

//Init_arg.c
int					init_str_form(t_arg **arg);
int					init_converted_form(t_arg *arg);
int					init_wconverted_form(t_arg *arg);
void				init_flags_arg(t_arg *arg);
int					new_init_arg(t_arg **arg);

//Fill_arg.c
int					fill_arg(t_arg *arg, va_list ap);
void				set_type_arg(t_arg *arg);
void				set_conv_arg(t_arg *arg);
void				set_nb_conv_arg(t_arg *arg, char c);
void				set_char_conv_arg(t_arg *arg, char c);

//Convert.c
int					convert_argv(t_arg *arg, va_list ap);
void				nb_convert_argv(t_arg *arg, va_list ap);
void				char_convert_argv(t_arg *arg, va_list ap);
char				*convert(t_arg *arg);

void				apply_size_flag(t_arg *arg);
void				apply_flags(t_arg *arg);

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
//int					set_space_flag(t_arg *arg, int j);
int					set_space_flag(t_arg *arg, char *format, int j);

//Apply_size_flags.c
int					apply_l(t_arg *arg); //TO DO WINT_T (%lc)
int					apply_ll(t_arg *arg);
int					apply_h(t_arg *arg);
int					apply_hh(t_arg *arg);

//Apply_form_flags.c
int					apply_alt_form(t_arg *arg);
int					apply_zero(t_arg *arg);
int					apply_minus(t_arg *arg);
int					apply_plus(t_arg *arg);
int					apply_space(t_arg *arg);

//Width.c
int					set_width(t_arg *arg, char *str_form);
int					apply_width(t_arg *arg);
void				apply_str_width(t_arg *arg);
void				apply_wstr_width(t_arg *arg);

//Precision.c
int					set_precision(t_arg *arg, char *str_form);
int					apply_precision(t_arg *arg);
int					apply_str_pre(t_arg *arg);
int					apply_nbr_pre(t_arg *arg);
char				*apply_negative(t_arg *arg);
char				*apply_positive(t_arg *arg);
char				*apply_ptr_precision(t_arg *arg);

//Zero_flag.c
int					set_zero_flag(t_arg *arg);
int					apply_zero(t_arg *arg);
int					apply_zero_hex_altform(t_arg *arg);
int					apply_str_zero(t_arg *arg);
int					apply_wstr_zero(t_arg *arg);

//Nbr_conv.c
void				st_conv(t_arg *arg, va_list ap);
void				ushort_conv(t_arg *arg, va_list ap);
void				short_conv(t_arg *arg, va_list ap);
void				uint_conv(t_arg *arg, va_list ap);
void				int_conv(t_arg *arg, va_list ap);
void				ulong_conv(t_arg *arg, va_list ap);
void				long_conv(t_arg *arg, va_list ap);
void				ullong_conv(t_arg *arg, va_list ap);
void				llong_conv(t_arg *arg, va_list ap);
void				imax_conv(t_arg *arg, va_list ap);
void				uimax_conv(t_arg *arg, va_list ap);
void				ptr_conv(t_arg *arg, va_list ap);

//Char_conv.c
int					uchar_conv(t_arg *arg, va_list ap);
int					char_conv(t_arg *arg, va_list ap);
void				str_conv(t_arg *arg, va_list ap);
void				wchar_conv(t_arg *arg, va_list ap);
void				wstr_conv(t_arg *arg, va_list ap);

//R_value.c
int					check_ret(t_arg *arg);

//Itoa.c
char				*itoa_base_uimax(uintmax_t n, int base);
char				*itoa_base_imax(intmax_t n, int base);

//Utils.c
char				*str_memcat(char *mem1, char *mem2, size_t size, int del);
void				sfree(char *mem1, char *mem2, int del);
//int					get_width(wchar_t *str, t_arg *arg);
int					get_width(char *str, t_arg *arg);
int					argv_sign(t_arg *arg);

//Wchar_functions.c
wchar_t				*str_to_wstr(const char *str);
size_t				ft_wstr_blen(const wchar_t *str);
size_t				ft_wstr_clen(const wchar_t *wstr);
void				ft_putwchar(wchar_t c);
void				ft_putwstr(wchar_t *wstr);
wchar_t				*wstr_memcat(wchar_t *mem1, wchar_t *mem2, size_t size, int del);
wchar_t				*wcat(wchar_t *mem1, wchar_t *mem2, size_t size);
void				wfree(wchar_t *mem1, wchar_t *mem2, int del);


#endif

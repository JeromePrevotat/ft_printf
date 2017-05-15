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

int  ft_printf(const char *format, ...);
void parsing(const char *format, va_list ap);
void init_list(char *conv_list);
void check_existing_conv(char c, char *conv_list, void *type);
void select_type(char c, void *type);

#endif

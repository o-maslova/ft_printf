/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:54:14 by omaslova          #+#    #+#             */
/*   Updated: 2018/08/14 10:54:15 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <locale.h>
# include "./libft/libft.h"
//# define PRECISION 

typedef struct		s_arg
{
	char			*buff;
	char			type;
	intmax_t		d;
	uintmax_t		u;
	char			*str;
	wchar_t			*w_str;
	int				width;
	short int		is_up;
}					t_arg;

typedef struct		s_flags
{
	short int		minus;
	short int		plus;
	short int		hash;
	short int		nul;
	short int		space;
	short int		negative;
	short int		prsn;
	short int		dot;
	short int		format;
	short int		astr;
	short int		hh;
	short int		h;
	short int		ll;
	short int		l;
	short int		j;
	short int		z;
}					t_flags;



int					ft_printf(char *fmt, ...);
void				output_d(va_list tmp, t_arg *var, t_flags *flags);
void				output_o(va_list tmp, t_arg *var, t_flags *flags);
void				output_u(va_list tmp, t_arg *var, t_flags *flags);
void				output_x(va_list tmp, t_arg *var, t_flags *flags);
void				output_c(va_list tmp, t_arg *var, t_flags *flags, int *ret);
t_flags				*initialization(t_flags *flags);
void				define_flag(char *str, t_flags *var, int lim);
void				cast_d(t_arg *var, t_flags *fl);
void				cast_o(t_arg *var, t_flags *fl);
int					define_operator(char *str, t_arg *var, t_flags *flags);
char				*print_str(t_arg *var, t_flags *flags);
char				*print_d(t_arg *var, t_flags *flags);
char				*print_u(t_arg *var, t_flags *flags);
char				*print_o(t_arg *var, t_flags *flags);
char				*print_x(t_arg *var, t_flags *flags);
char				*print_c(t_arg *var, t_flags *fl);
char				*new_join(char *s1, char *s2);
char				*to_upper(char *buff);
void				undef_beh(t_flags *flags, char c);
void				undef_beh_type(char *str);
char				*set_precision(int len, char *buff, t_flags *flags);
char				*set_pad(int width, char *buff, t_flags *flags);
char				*ft_itoa_base(uintmax_t nb, int base);
char				*ft_uitoa(uintmax_t n);
int					print_unicode(t_arg *var, t_flags *flags);

#endif
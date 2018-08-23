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
# include "./libft/libft.h"
//# define PRECISION 

typedef struct      s_arg
{
    char            *f_out;
    char            *buff;
    char            type;
    intmax_t        d;
    uintmax_t       u;
    char            c;
    char            *str;
    int             width;
    short int       is_up;
}                   t_arg;

typedef struct      s_flags
{
    short int       minus;
    short int       plus;
    short int       hash;
    short int       nul;
    short int       space;
    short int       negative;
    short int       prsn;
    short int       format;
    short int       astr;
}                   t_flags;

void	foo(char *fmt, ...);
void    print_str(t_arg *var, t_flags *flags);
void    print_d(t_arg *var, t_flags *flags);
void    print_u(t_arg *var, t_flags *flags);
void    print_o(t_arg *var, t_flags *flags);
char    *print_x(t_arg *var, t_flags *flags);
char    *to_upper(char *buff);
void    undef_beh(t_flags *flags);
void    undef_beh_type(char *str);
char    *set_precision(int width, int len, char *buff, t_flags *flags);
char    *set_pad(int width, int len, char *buff, t_flags *flags);
char    *ft_itoa_base(intmax_t nb, int base);


#endif

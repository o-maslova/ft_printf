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
    int             format;
    int             d;
    char            c;
    char            *str;
    int             width;
}                   t_arg;

typedef struct      s_flags
{
    short int       minus;
    short int       plus;
    short int       hash;
    short int       nul;
    short int       space;
    
}                   t_flags;

void    print_str(t_arg *var, t_flags *flags);
void    print_d(t_arg *var, t_flags *flags);

#endif

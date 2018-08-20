/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefine_behavior.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:34:53 by omaslova          #+#    #+#             */
/*   Updated: 2018/08/20 15:34:59 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    undef_beh(t_flags *flags)
{
    if (flags->plus == 1)
        ft_putstr("flag '+' results in undefined behavior with 'u' conversion specifier\n");
    else if (flags->hash == 1)
        ft_putstr("flag '#' results in undefined behavior with 'u' conversion specifier\n");
    else if (flags->space == 1)
        ft_putstr("flag ' ' results in undefined behavior with 'u' conversion specifier\n");
   // exit (1);
}

void    undef_beh_type(char *str)
{
    ft_putstr("format specifies type '");
    ft_putstr(str);
    ft_putstr("'  but the argument has type 'long'");
}

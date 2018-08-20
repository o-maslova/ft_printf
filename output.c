/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 11:43:35 by omaslova          #+#    #+#             */
/*   Updated: 2018/08/19 11:43:37 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    str_pad(int width, char c, t_flags *flags)
{
    int i;

    i = 0;
    if (flags->negative && flags->nul != 1)
        i--;
    if (flags->nul == 1 && flags->negative == 1)
        ft_putchar('-');
    else if (flags->plus == 1 && flags->nul == 1)
        ft_putchar('+');
    else if (flags->space == 1 && flags->negative != 1)
    {
        ft_putchar(' ');
        i++;
    }
    while (i++ < width && flags->minus != 1)
        ft_putchar(c);
}

void    print_str(t_arg *var, t_flags *flags)
{
    int len;

    len = ft_strlen(var->str);
    if (var->width > 0 && var->width > len && flags->minus != 1)
        str_pad(var->width - len, ' ', flags);
    ft_putstr(var->str);
}
// void    print_c(t_arg *var, t_flags *flags)
// {
//     ft_putchar(var->c);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:02:18 by omaslova          #+#    #+#             */
/*   Updated: 2018/08/20 12:02:23 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *set_pad(int width, int len, char *buff, t_flags *flags)
{
    int i;

    i = 0;
    if (flags->plus == 1 && flags->negative != 1 && flags->nul == 1)
        buff[i++] = '+';
    else if (flags->negative == 1 && flags->nul == 1)
        buff[i++] = '-';
    else if (flags->space == 1)
        buff[i++] = ' ';
    if (flags->plus == 1 && flags->nul != 1)
        if (flags->negative != 1)
            buff[--width] = '+';
   // width = flags->hash == 1 ? width -1 : width;
    while (i < width && width != len)
    {
        if (flags->nul == 1)
            buff[i++] = '0';
        else if (flags->hash == 1 && i == width - 1)
            buff[i++] = '0';
        else
            buff[i++] = ' ';
    }
    // if (flags->hash == 1)
    //     buff[i] = '0';
    return (buff);
}

char    *set_precision(int width, int len, char *buff, t_flags *flags)
{
    int i;
    int tmp;

    i = 0;
    tmp = 0;
    if (width == len && flags->negative != 1)
        width = flags->precision - len;
    tmp = flags->precision > len ? width - (flags->precision - len) : width;
    // tmp = flags->minus == 1 ? 0 : tmp;
    while (tmp > 0 && i < tmp)
        buff[i++] = ' ';
    if (flags->plus == 1 || flags->negative == 1)
    {
        i = i > 0 ? i - 1 : i;
        if (flags->negative == 1)
            buff[i++] = '-';
        else
            buff[i++] = '+';
    }
    while (i < width && flags->precision > len)
        buff[i++] = '0';
    return (buff);    
}

void    print_d(t_arg *var, t_flags *flags)
{
    char    *str;
    char    *buff;
    int     len;
    
    if ((flags->nul == 1 || flags->precision > 0) && var->d < 0)
        var->d = -var->d;
    str = ft_itoa(var->d);
    len = ft_strlen(str);
    var->width = var->width > len ? var->width - len : len;
    if (flags->minus != 1)
    {
        buff = (char *)malloc(sizeof(char) * (var->width));
        if (flags->precision > 0)
            buff = set_precision(var->width, len, buff, flags);
        else
            buff = set_pad(var->width, len, buff, flags);
        buff = ft_strjoin(buff, str);
    }
    else if (flags->plus == 1 && flags->negative != 1)
        buff = ft_strjoin("+", str);
    else if (flags->space == 1 && flags->negative != 1)
        buff = ft_strjoin(" ", str);
    else
        buff = ft_strdup(str);
    ft_putstr(buff);
}

void    print_o(t_arg *var, t_flags *flags)
{
    char    *str;
    char    *buff;
    int     len;
    
    str = define_num(var->d, 8);
    len = ft_strlen(str);
    var->width = var->width > len ? var->width - len : len;
    buff = (char *)malloc(sizeof(char) * (var->width));
    // if (flags->minus == 1 && flags->precision > len)
    //     buff = set_precision(var->width, len, buff, flags);
    if (flags->precision > 0)
        buff = set_precision(var->width, len, buff, flags);
    if (var->width > 0)
        buff = set_pad(var->width, len, buff, flags);
    buff = ft_strjoin(buff, str);
    // if (flags->minus != 1)
    // {
        
    //     if (flags->precision > 0)
    //         buff = set_precision(var->width, len, buff, flags);
    //     else
    //         buff = set_pad(var->width, len, buff, flags);
    //     buff = ft_strjoin(buff, str);
    // }
    if (flags->hash == 1 || var->width <= len)
        buff = ft_strjoin("0", str);
    else
        buff = ft_strdup(str);
    ft_putstr(buff);
}
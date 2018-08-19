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
    while (i < width && width != len)
    {
        if (flags->nul == 1)
            buff[i++] = '0';
        else
            buff[i++] = ' ';
    }
    return (buff);
}

void    print_str(t_arg *var, t_flags *flags)
{
    int len;

    len = ft_strlen(var->str);
    if (var->width > 0 && var->width > len && flags->minus != 1)
        str_pad(var->width - len, ' ', flags);
    ft_putstr(var->str);
}

char    *set_precision(int width, int len, char *buff, t_flags *flags)
{
    int i;
    int tmp;

    i = 0;
    tmp = 0;
    if (flags->precision > len && width != len)
        tmp = width - (flags->precision - len);
    if (width == len)
        width = flags->precision - len;
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
   width = flags->negative == 1 ? width + 1 : width;
    while (i < width)
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

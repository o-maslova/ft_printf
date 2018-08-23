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

char    *set_pad(int width, int len, char *buff, t_flags *fl)
{
    int i;

    i = 0;
    if (fl->plus == 1 && fl->negative != 1 && fl->nul == 1)
        buff[i++] = '+';
    else if (fl->negative == 1 && fl->nul == 1 && fl->astr != 1)
        buff[i++] = '-';
    else if (fl->space == 1)
        buff[i++] = ' ';
    while (i < width && width != len)
    {
        if (fl->nul == 1 && fl->astr != 1)
            buff[i++] = '0';
        else if (fl->hash == 1 && i == width - 1 && fl->format != 1)
            buff[i++] = '0';
        else
            buff[i++] = ' ';
    }
    if (fl->plus == 1 && fl->nul != 1)
        if (fl->negative != 1)
            buff[width - 1] = '+';
    buff[i] = '\0';
    if (fl->format == 1 && fl->nul != 1)
        buff = ft_strjoin(buff, "0x");
    return (buff);
}

char    *set_precision(int width, int len, char *buff, t_flags *fl)
{
    int i;
    int tmp;

    i = 0;
    tmp = 0;
    if (width == len && fl->negative != 1)
        width = fl->prsn - len;
    tmp = fl->prsn > len ? width - (fl->prsn - len) : width;
    while (tmp > 0 && i < tmp)
        buff[i++] = ' ';
    if (fl->plus == 1 || fl->negative == 1)
    {
        i = i > 0 ? i - 1 : i;
        if (fl->negative == 1)
            buff[i++] = '-';
        else
            buff[i++] = '+';
    }
    while (i < width && fl->prsn > len)
        buff[i++] = '0';
    buff[i] = '\0';
    return (buff);    
}

void    print_d(t_arg *var, t_flags *fl)
{
    char    *str;
    char    *buff;
    int     len;
    
    if ((fl->nul == 1 || fl->prsn > 0) && var->d < 0 && fl->astr != 1)
        var->d = -var->d;
    str = ft_itoa(var->d);
    len = ft_strlen(str);
    var->width = var->width > len ? var->width - len : len;
    if (fl->minus != 1 || fl->prsn > 0)
    {
        buff = (char *)malloc(sizeof(char) * (var->width + 1));
        if (fl->prsn > 0)
            buff = set_precision(var->width, len, buff, fl);
        else
            buff = set_pad(var->width, len, buff, fl);
        buff = ft_strjoin(buff, str);
    }
    else if (fl->plus == 1 && fl->negative != 1)
        buff = ft_strjoin("+", str);
    else if (fl->space == 1 && fl->negative != 1)
        buff = ft_strjoin(" ", str);
    else
        buff = ft_strdup(str);
    ft_putstr(buff);
}

void    print_o(t_arg *var, t_flags *fl)
{
    char    *str;
    char    *buff;
    int     len;
    
    str = ft_itoa_base(var->d, 8);
    len = ft_strlen(str);
    var->width = var->width > len ? var->width - len : len;
    buff = (char *)malloc(sizeof(char) * (var->width + 1));
    if (fl->minus != 1)
    {
        if (fl->prsn > 0)
            buff = set_precision(var->width, len, buff, fl);
        else
            buff = set_pad(var->width, len, buff, fl);
        buff = ft_strjoin(buff, str);
    }
    else if (fl->prsn > 0)
        buff = ft_strjoin(set_precision(len, len, buff, fl), str);
    else if (fl->hash == 1)
        buff = ft_strjoin("0", str);
    else
        buff = ft_strdup(str);
    ft_putstr(buff);
}

char    *print_x(t_arg *var, t_flags *fl)
{
    char    *str;
    char    *buff;
    int     len;
    
    str = ft_itoa_base(var->d, 16);
    len = ft_strlen(str);
    len = fl->hash == 1 ? len + 2 : len;
    var->width = var->width > len ? var->width - len : len;
    buff = (char *)malloc(sizeof(char) * (var->width + 1));
    if (fl->minus != 1)
    {
        if (fl->prsn > 0)
            buff = set_precision(var->width, len, buff, fl);
        else
            buff = set_pad(var->width, len, buff, fl);
        buff = ft_strjoin(buff, str);
    }
    else if (fl->prsn > 0)
        buff = ft_strjoin(set_precision(len, len, buff, fl), str);
    else
        buff = ft_strdup(str);
    if (fl->format == 1 && (fl->nul == 1 || fl->minus == 1))
        buff = ft_strjoin("0x", buff);
    return (buff);
}
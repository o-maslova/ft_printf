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

char    *set_pad(int width, char *buff, t_flags *fl)
{
    int i;

    i = 0;
    while (i < width)
    {
        if (fl->nul == 1 && fl->minus != 1)
        {
            if (fl->plus == 1 || fl->negative == 1)
                buff[0] = fl->negative == 1 ? '-' : '+';
            else if (fl->space == 1)
                buff[0] = ' ';
            buff[i++] = '0';
        }
        else
            buff[i++] = ' ';
        if (fl->format == 1 && fl->nul == 1)
        {
            buff[0] = '0';
            buff[1] = 'x';
        }
    }
    buff[i] = '\0';
    return (buff);
}

char    *set_precision(int len, char *str, t_flags *fl)
{
    int i;
    int tmp;
    char *buff;

    i = 0;
    tmp = fl->prsn > len ? fl->prsn - len : 0;
    if (tmp || len > 1)
    {
        buff = (char *)malloc(sizeof(char) * (tmp + 1));
        while (i < tmp)
            buff[i++] = '0';
        buff[i] = '\0';
        return (ft_strjoin(buff, str));
    }
    return ("");
}

char    *print_d(t_arg *var, t_flags *fl)
{
    char    *str;
    char    *buff;
    int     len;
    char    c[2];
    
    var->d = fl->negative == 1 ? -var->d : var->d;
    str = ft_itoa(var->d);
    if (fl->prsn > 0)
        str = set_precision(ft_strlen(str), str, fl);
    if (fl->nul != 1 && (fl->plus == 1 || fl->space == 1 || fl->negative == 1))
    {
        if (fl->plus == 1)
            c[0] = fl->negative == 1 ? '-' : '+';
        else if (fl->space == 1 && fl->negative != 1)
            c[0] = ' ';
        else if (fl->negative == 1)
            c[0] = '-';
        c[1] = '\0';
        str = ft_strjoin(c, str);
    }
    len = ft_strlen(str);
    var->width = var->width > len ? var->width - len : 0;
    buff = (char *)malloc(sizeof(char) * (var->width + 1));
    buff = set_pad(var->width, buff, fl);
    if (fl->minus == 1)
        buff = ft_strjoin(str, buff);
    else
        buff = ft_strjoin(buff, str);
    return (buff);
}

char    *print_o(t_arg *var, t_flags *fl)
{
    char    *str;
    char    *buff;
    int     len;
    char    c[2];
    
    str = ft_itoa_base(var->u, 8);
    if (fl->prsn >= 0)
        str = set_precision(ft_strlen(str), str, fl);
    if (fl->nul != 1 && (fl->hash == 1 || fl->space == 1))
    {
        c[0] = fl->hash == 1 ? '0' : ' ';
        c[1] = '\0';
        str = ft_strjoin(c, str);
    }
    len = ft_strlen(str);
    var->width = var->width > len ? var->width - len : 0;
    buff = (char *)malloc(sizeof(char) * (var->width + 1));
    buff = set_pad(var->width, buff, fl);
    if (fl->minus == 1)
        buff = ft_strjoin(str, buff);
    else
        buff = ft_strjoin(buff, str);
    return (buff);
}

char    *print_x(t_arg *var, t_flags *fl)
{
    char    *str;
    char    *buff;
    int     len;

    str = ft_itoa_base(var->u, 16);
    if (fl->nul == 1 && fl->minus == 1)
        fl->nul = 0;
    if (fl->prsn >= 0)
        str = set_precision(ft_strlen(str), str, fl);
    if (fl->format == 1 && fl->nul != 1 && *str && *str != '0')
        str = ft_strjoin("0x", str);
    len = ft_strlen(str);
    var->width = var->width > len ? var->width - len : 0;
    buff = (char *)malloc(sizeof(char) * (var->width + 1));
    buff = set_pad(var->width, buff, fl);
    if (fl->minus == 1)
        buff = ft_strjoin(str, buff);
    else
        buff = ft_strjoin(buff, str);
    return (buff);
}
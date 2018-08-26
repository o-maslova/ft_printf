/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uinteger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:35:10 by omaslova          #+#    #+#             */
/*   Updated: 2018/08/20 15:35:16 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	power(uintmax_t n, int i)
{
	uintmax_t num;

	num = n;
	if (i == 0)
		return (1);
	while (i > 1)
	{
		num *= n;
		i--;
	}
	return (num);
}

char		*ft_uitoa(uintmax_t n)
{
	int		    i;
	int		    j;
	char	    *str;
    uintmax_t   nb;

    i = 0;
	j = 0;
    nb = n;
    while (nb / 10 > 0)
	{
		nb /= 10;
		i++;
	}
    nb = n;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
 	while (i >= 0)
	{
		str[j++] = (nb / (power(10, i))) + 48;
		nb = nb % (power(10, i--));
	}
	str[j] = '\0';
	return (str);
}

char    *print_u(t_arg *var, t_flags *fl)
{
    char    *str;
    char    *buff;
    int     len;
    
    str = ft_uitoa(var->u);
    if (fl->plus == 1 || fl->space == 1 || fl->hash ==  1)
    {
        undef_beh(fl, var->type);
        return (NULL);
    }
    if (fl->prsn > 0)
        str = set_precision(ft_strlen(str), str, fl);
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

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

void    print_u(t_arg *var, t_flags *flags)
{
    char    *str;
    char    *buff;
    int     len;
    
    if (flags->plus == 1 || flags->space == 1 || flags->hash ==  1)
    {
        undef_beh(flags);
        return ;
    }
    str = ft_uitoa(var->u);
    len = ft_strlen(str);
    var->width = var->width > len ? var->width - len : len;
    if (flags->minus != 1 || flags->prsn > len)
    {
        buff = (char *)malloc(sizeof(char) * (var->width) + 1);
        if (flags->prsn > 0)
            buff = set_precision(var->width, len, buff, flags);
        else
            buff = set_pad(var->width, len, buff, flags);
        buff = ft_strjoin(buff, str);
    }
    else
        buff = ft_strdup(str);
    ft_putstr(buff);
}

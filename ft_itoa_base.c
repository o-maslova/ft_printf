/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:44:40 by omaslova          #+#    #+#             */
/*   Updated: 2018/08/20 15:44:42 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char        define_sym(int num)
{
    if (num == 10)
        return ('a');
    if (num == 11)
        return ('b');
    if (num == 12)
        return ('c');
    if (num == 13)
        return ('d');
    if (num == 14)
        return ('e');
    if (num == 15)
        return ('f');
    else
        return (num + 48);
}

char        *define_num(intmax_t nb, int base)
{
    int i;
    char *num;
    intmax_t tmp;

    i = 1;
	nb = nb < 0 ? 4294967295 + nb + 1 : nb;
	tmp = nb;
  	while (tmp > base)
    {
        i++;
        tmp /= base;
    }
    num = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
    while (nb > base)
    {
        num[i++] = define_sym(nb % base);
		nb = nb / base;
    }
    num[i++] = define_sym(nb);
    num[i] = '\0';
    return (num);
}

// char		*ft_itoa_base(intmax_t nb, int base)
// {
// 	int count;
//     int i;
//     char *num;
//     intmax_t tmp;

//     i = 0;
//     count = 1;
//     tmp = nb;
// 	if (nb < 0)
// 	{
// 		nb = nb * -1 + 1;
// 	}
//     while (tmp > base)
//     {
//         count++;
//         tmp /= base;
//     }
//     num = (char *)malloc(sizeof(char) * (count + 1));
//     while (nb > base)
//     {
//         nb = nb / base;
//         num[i++] = define_sym(nb % base);
//     }
//     num[i++] = define_sym(nb);
//     num[i] = '\0';
//     return (num);
// }
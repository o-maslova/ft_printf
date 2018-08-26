/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:40:08 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/11 17:09:58 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_of_digits(intmax_t nb)
{
	int i;

	i = 1;
	while (nb / 10 > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(intmax_t nb)
{
	int			i;
	int			j;
 	intmax_t    num;
	char		*str;

	j = 0;
	num = 1;
	i = count_of_digits(nb);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i -= 1;
    while (i--)
        num = num * 10;
	while (num > 0)
	{
		str[j++] = (nb / num) + 48;
		nb = nb % num;
        num /= 10;
	}
	str[j] = '\0';
	return (str);
}

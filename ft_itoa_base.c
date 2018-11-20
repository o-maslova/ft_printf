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

char	*to_upper(char *buff)
{
	int i;

	i = -1;
	while (buff[++i] != '\0')
		buff[i] = ft_toupper(buff[i]);
	return (buff);
}

char	define_sym(int num)
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

int		count_num(uintmax_t nb, int base)
{
	int i;

	i = 1;
	while (nb > (uintmax_t)base)
	{
		i++;
		nb = nb / base;
	}
	return (i);
}

char	*rev_str(char *str)
{
	int		i;
	int		j;
	char	tmp;

	j = 0;
	i = ft_strlen(str) - 1;
	while (j < i + 1)
	{
		tmp = str[i];
		str[i--] = str[j];
		str[j++] = tmp;
	}
	return (str);
}

char	*ft_itoa_base(uintmax_t nb, int base)
{
	int		i;
	char	*num;

	num = ft_memalloc(count_num(nb, base) + 1);
	i = 0;
	while (nb >= (uintmax_t)base)
	{
		num[i++] = define_sym(nb % base);
		nb = nb / base;
	}
	num[i++] = define_sym(nb);
	num = rev_str(num);
	return (num);
}

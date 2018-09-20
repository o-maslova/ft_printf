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

char	*ft_uitoa(uintmax_t n)
{
	int			i;
	char		*str;
	uintmax_t	nb;
	uintmax_t	num;

	i = 0;
	num = 1;
	nb = n;
	while (nb / 10 > 0)
	{
		nb /= 10;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * ++i)))
		return (NULL);
	while (--i > 0)
		num *= 10;
	while (num > 0)
	{
		str[i++] = n / num + 48;
		n = n % num;
		num /= 10;
	}
	str[i] = '\0';
	return (str);
}

char	*print_u(t_arg *var, t_flags *fl)
{
	char	*str;
	char	*buff;
	int		len;

	str = ft_uitoa(var->u);
	if (fl->prsn > 0)
		str = set_precision(ft_strlen(str), str, fl);
	len = ft_strlen(str);
	var->width = var->width > len ? var->width - len : 0;
	buff = (char *)malloc(sizeof(char) * (var->width + 1));
	buff = set_pad(var->width, buff, fl);
	if (fl->minus == 1)
		var->buff = ft_strjoin(str, buff);
	else if (*str == '0')
		var->buff = buff;
	else
		var->buff = ft_strjoin(buff, str);
	free(str);
	free(buff);
	return (var->buff);
}

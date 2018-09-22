/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_and_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 21:38:28 by omaslova          #+#    #+#             */
/*   Updated: 2018/08/27 21:38:30 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_o(t_arg *var, t_flags *fl)
{
	char	*str;
	char	*buff;
	int		len;
	char	c[2];

	str = ft_itoa_base(var->u, 8);
	if (fl->prsn >= 0)
		str = set_precision(ft_strlen(str), str, fl);
	if (fl->nul != 1 && *str != '0' && fl->hash == 1)//|| fl->space == 1))
	{
		c[0] = fl->hash == 1 ? '0' : ' ';
		c[1] = '\0';
		var->str = ft_strjoin(c, str);
		free(str);
		str = var->str;
	}
	len = ft_strlen(str);
	var->width = var->width > len ? var->width - len : 0;
	buff = (char *)malloc(sizeof(char) * (var->width + 1));
	buff = set_pad(var->width, buff, fl);
	var->buff = fl->minus == 1 ? ft_strjoin(str, buff) : ft_strjoin(buff, str);
	free(buff);
	free(str);
	return (var->buff);
}

char	*print_x(t_arg *var, t_flags *fl)
{
	char	*str;
	char	*buff;
	int		len;

	str = ft_itoa_base(var->u, 16);
	if (fl->nul == 1 && fl->minus == 1)
		fl->nul = 0;
	if (fl->prsn >= 0)
		str = set_precision(ft_strlen(str), str, fl);
	if ((fl->format == 1 && fl->nul != 1 && *str && var->u != 0)
		|| var->t == 'p')
	{
		var->str = ft_strjoin("0x", str);
		free(str);
		str = var->str;
	}
	len = ft_strlen(str);
	var->width = var->width > len ? var->width - len : 0;
	buff = (char *)malloc(sizeof(char) * (var->width + 1));
	buff = set_pad(var->width, buff, fl);
	var->buff = fl->minus == 1 ? ft_strjoin(str, buff) : ft_strjoin(buff, str);
	free(buff);
	free(str);
	return (var->buff);
}

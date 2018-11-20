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

void	print_o(t_arg *var, t_flags *fl)
{
	char	*str;
	char	*tmp;
	int		len;

	str = ft_itoa_base(var->u, 8);
	if (fl->prsn >= 0)
		str = set_precision(ft_strlen(str), str, fl);
	if (fl->nul != 1 && *str != '0' && fl->hash == 1)
	{
		var->str = fl->hash == 1 ? ft_strjoin("0", str) : ft_strjoin(" ", str);
		free(str);
		str = var->str;
	}
	len = ft_strlen(str);
	var->width = var->width > len ? var->width - len : 0;
	tmp = (char *)malloc(sizeof(char) * (var->width + 1));
	tmp = set_pad(var->width, tmp, fl);
	if (fl->minus == 1)
		concat(str, tmp, var);
	else
		concat(tmp, str, var);
	free(tmp);
	free(str);
}

void	print_x(t_arg *var, t_flags *fl, int up)
{
	char	*str;
	char	*tmp;
	int		len;

	str = !up ? ft_itoa_base(var->u, 16) : to_upper(ft_itoa_base(var->u, 16));
	if (fl->nul == 1 && fl->minus == 1)
		fl->nul = 0;
	if (fl->prsn >= 0)
		str = set_precision(ft_strlen(str), str, fl);
	if (fl->format == 1 && fl->nul != 1 && *str && var->u != 0)
	{
		var->str = !up ? ft_strjoin("0x", str) : ft_strjoin("0X", str);
		free(str);
		str = var->str;
	}
	len = ft_strlen(str);
	var->width = var->width > len ? var->width - len : 0;
	tmp = (char *)malloc(sizeof(char) * (var->width + 1));
	tmp = set_pad(var->width, tmp, fl);
	if (fl->minus == 1)
		concat(str, tmp, var);
	else
		concat(tmp, str, var);
	free(tmp);
	free(str);
}

void	print_p(t_arg *var, t_flags *fl)
{
	char	*str;
	char	*tmp;
	int		len;

	str = ft_itoa_base(var->u, 16);
	if (fl->nul == 1 && fl->minus == 1)
		fl->nul = 0;
	if (fl->prsn >= 0)
		str = set_precision(ft_strlen(str), str, fl);
	if ((*str || fl->prsn >= 0) && fl->nul != 1)
	{
		var->str = ft_strjoin("0x", str);
		free(str);
		str = var->str;
	}
	len = ft_strlen(str);
	var->width = var->width > len ? var->width - len : 0;
	tmp = (char *)malloc(sizeof(char) * (var->width + 1));
	tmp = set_pad(var->width, tmp, fl);
	if (fl->minus == 1)
		concat(str, tmp, var);
	else
		concat(tmp, str, var);
	free(tmp);
	free(str);
}

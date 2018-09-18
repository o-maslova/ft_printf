/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 17:18:32 by omaslova          #+#    #+#             */
/*   Updated: 2018/09/02 17:18:35 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_unicode(t_arg *var)
{
	int i;

	i = 0;
	if (var->d <= 0x7F)
		var->buff[i++] = (char)var->d;
	else if (var->d <= 0x7FF)
	{
		var->buff[i++] = 0xC0 | (var->d >> 6);
		var->buff[i++] = 0x80 | (var->d & 0x3F);
	}
	else if (var->d <= 0xFFFF)
	{
		var->buff[i++] = 0xE0 | (var->d >> 12);
		var->buff[i++] = 0x80 | ((var->d >> 6) & 0x3F);
		var->buff[i++] = 0x80 | (var->d & 0x3F);
	}
	else if (var->d <= 0x10FFFF)
	{
		var->buff[i++] = 0xF0 | (var->d >> 18);
		var->buff[i++] = 0x80 | ((var->d >> 12) & 0x3F);
		var->buff[i++] = 0x80 | ((var->d >> 6) & 0x3F);
		var->buff[i++] = 0x80 | (var->d & 0x3F);
	}
	var->buff[i] = '\0';
	return (i);
}

void	print_uni_str(t_arg *var, int *ret)
{
	while (*var->w_str)
	{
		var->d = *var->w_str;
		*ret += print_unicode(var);
		ft_putstr(var->buff);
		ft_bzero(var->buff, 5);
		var->w_str++;
		var->d = 0;
	}
}

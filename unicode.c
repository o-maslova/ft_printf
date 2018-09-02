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

void	print_unicode(t_arg *var)
{
	if (var->d <= 0x7F)
		var->buff[0] = (char)var->d;
	else if (var->d <= 0x7FF)
	{
		var->buff[0] = 0xC0 | (var->d >> 6);
		var->buff[1] = 0x80 | (var->d & 0x3F);
		var->buff[2] = '\0';
	}
	else if (var->d <= 0xFFFF)
	{
		var->buff[0] = 0xE0 | (var->d >> 12);
		var->buff[1] = 0x80 | ((var->d >> 6) & 0x3F);
		var->buff[2] = 0x80 | (var->d & 0x3F);
		var->buff[3] = '\0';
	}
	else if (var->d <= 0x10FFFF)
	{
		var->buff[0] = 0xF0 | (var->d >> 18);
		var->buff[1] = 0x80 | ((var->d >> 12) & 0x3F);
		var->buff[2] = 0x80 | ((var->d >> 6) & 0x3F);
		var->buff[3] = 0x80 | (var->d & 0x3F);
		var->buff[4] = '\0';
	}
}

void	print_uni_str(t_arg *var, int **ret)
{
	while (*var->w_str)
	{
		var->d = *var->w_str;
		print_unicode(var);
		ft_putstr(var->buff);
		ft_bzero(var->buff, 5);
		var->w_str++;
		*ret += 1;
		var->d = 0;
	}
}

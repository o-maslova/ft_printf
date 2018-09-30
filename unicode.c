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
		var->str[i++] = (char)var->d;
	else if (var->d <= 0x7FF)
	{
		var->str[i++] = 0xC0 | (var->d >> 6);
		var->str[i++] = 0x80 | (var->d & 0x3F);
	}
	else if (var->d <= 0xFFFF)
	{
		var->str[i++] = 0xE0 | (var->d >> 12);
		var->str[i++] = 0x80 | ((var->d >> 6) & 0x3F);
		var->str[i++] = 0x80 | (var->d & 0x3F);
	}
	else if (var->d <= 0x10FFFF)
	{
		var->str[i++] = 0xF0 | (var->d >> 18);
		var->str[i++] = 0x80 | ((var->d >> 12) & 0x3F);
		var->str[i++] = 0x80 | ((var->d >> 6) & 0x3F);
		var->str[i++] = 0x80 | (var->d & 0x3F);
	}
	var->str[i] = '\0';
	return (i);
}

int		print_with_width(t_arg *var, int res, t_flags *fl)
{
	int		len;
	char	*str;

	free(var->str);
	len = ft_strlen(g_buff);
	g_k = g_k - res;
	print_str(var, fl, &g_buff[len - res]);
	res = ft_strlen(g_buff);
	return (res);
}

int		print_no_locale(t_arg *var, int ret, t_flags *fl)
{
	int		check;
	int		i;

	i = 0;
	check = -1;
	var->str = (char *)malloc(sizeof(char) * 5);
	while (MB_CUR_MAX == 1 && var->w_str[i] && check <= 0)
		check = var->w_str[i++] <= 255 ? 0 : i;
	i = 0;
	while (*var->w_str && i < fl->prsn)
	{
		if (*var->w_str <= 255)
		{
			g_buff[g_k++] = (char)*var->w_str;
			if (g_k >= BUFF_SIZE)
				nul_the_buf(g_buff, NULL, var);
			i += 1;
		}
		var->w_str++;
	}
	if (check > 0 && i > fl->prsn)
		i = -1;
	free(var->str);
	return (i);
}

int		print_uni_str(t_arg *var, int ret, t_flags *fl)
{
	int		check;
	int		i;

	i = 0;
	check = -1;
	var->str = (char *)malloc(sizeof(char) * 5);
	while (MB_CUR_MAX == 1 && var->w_str[i] && check <= 0)
		check = var->w_str[i++] <= 255 ? 0 : i;
	i = 0;
	while (*var->w_str && (fl->prsn == -1 || i < fl->prsn) && i != -1)
	{
		var->d = *var->w_str;
		var->nul = var->d == 0 ? 1 : 0;
		i += print_unicode(var);
		buff_join(g_buff, var->str, var);
		ft_bzero(var->str, 5);
		var->w_str++;
	}
	if (var->width > i)
		return (print_with_width(var, i, fl));
	free(var->str);
	return (i);
}

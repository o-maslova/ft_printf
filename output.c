/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:47:44 by omaslova          #+#    #+#             */
/*   Updated: 2018/11/20 16:53:36 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_d(va_list tmp, t_arg *var, t_flags *fl)
{
	if (var->t == 'D' || var->t == 'd')
	{
		var->d = va_arg(tmp, intmax_t);
		if (fl->l == 0)
			fl->l = var->t == 'D' ? 1 : 0;
		cast_d(var, fl);
		if ((var->width == 0 || fl->minus == 1) && fl->nul == 1)
			fl->nul = 0;
		fl->negative = var->d < 0 ? 1 : 0;
		if (fl->negative == 1 && -var->d < 0)
			var->u = -var->d;
		print_d(var, fl);
	}
	if (var->t == 'i')
	{
		var->d = va_arg(tmp, intmax_t);
		cast_d(var, fl);
		fl->negative = var->d < 0 ? 1 : 0;
		print_d(var, fl);
	}
}

void	output_o_u_x(va_list tmp, t_arg *var, t_flags *flags)
{
	if (var->t == 'o' || var->t == 'O')
	{
		var->u = va_arg(tmp, uintmax_t);
		if (flags->l == 0)
			flags->l = var->t == 'O' ? 1 : 0;
		cast_o(var, flags);
		print_o(var, flags);
	}
	if (var->t == 'u' || var->t == 'U')
	{
		var->u = va_arg(tmp, uintmax_t);
		if (var->t == 'u')
			cast_o(var, flags);
		print_u(var, flags);
	}
	if (var->t == 'x' || var->t == 'X')
	{
		var->u = va_arg(tmp, uintmax_t);
		cast_o(var, flags);
		flags->format = flags->hash == 1 ? 1 : 0;
		if (var->t == 'X')
			print_x(var, flags, 1);
		else
			print_x(var, flags, 0);
	}
}

int		output_wc(va_list tmp, t_arg *var)
{
	int res;

	res = 0;
	var->d = va_arg(tmp, wchar_t);
	var->nul = var->d == 0 ? 1 : 0;
	if (MB_CUR_MAX == 1 && var->d != 0 && var->d > 255)
		return (-1);
	else if (MB_CUR_MAX == 1 && var->d != 0 && var->d <= 255)
		g_buff[g_k++] = (char)var->d;
	else
	{
		var->str = (char *)malloc(sizeof(char) * 5);
		res = print_unicode(var);
		buff_join(g_buff, var->str, var);
		free(var->str);
	}
	return (res);
}

int		output_ws(va_list tmp, t_arg *var, t_flags *fl)
{
	int res;

	res = 0;
	var->w_str = va_arg(tmp, wchar_t *);
	if (var->w_str == NULL)
		print_str(var, fl, NULL);
	else if (fl->prsn == 0)
		print_str(var, fl, NULL);
	else if (MB_CUR_MAX == 1)
		res = print_no_locale(var, fl);
	else
		res = print_uni_str(var, fl);
	return (res);
}

int		output_c(va_list tmp, t_arg *var, t_flags *fl)
{
	int res;

	res = 0;
	if (var->t == 'S' || (var->t == 's' && fl->l == 1))
		res = output_ws(tmp, var, fl);
	else if (var->t == 'C' || (var->t == 'c' && fl->l == 1))
		res = output_wc(tmp, var);
	else if (var->t == 'c')
	{
		var->d = va_arg(tmp, int);
		if (fl->l == 1 && MB_CUR_MAX != 1)
		{
			res += print_unicode(var);
			buff_join(g_buff, var->str, var);
			free(var->str);
		}
		else if (MB_CUR_MAX == 1 && var->d > 255)
			return (-1);
		else
		{
			var->d = (char)var->d;
			var->nul = var->d == 0 ? 1 : 0;
			print_c(var, fl);
		}
	}
	return (res);
}

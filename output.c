/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:47:44 by omaslova          #+#    #+#             */
/*   Updated: 2018/08/29 15:47:48 by omaslova         ###   ########.fr       */
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
		var->buff = print_d(var, fl);
	}
	if (var->t == 'i')
	{
		var->d = va_arg(tmp, intmax_t);
		cast_d(var, fl);
		fl->negative = var->d < 0 ? 1 : 0;
		var->buff = print_d(var, fl);
	}
}

void	output_o_and_u(va_list tmp, t_arg *var, t_flags *flags)
{
	if (var->t == 'o' || var->t == 'O')
	{
		var->u = va_arg(tmp, uintmax_t);
		if (flags->l == 0)
			flags->l = var->t == 'O' ? 1 : 0;
		cast_o(var, flags);
		var->buff = print_o(var, flags);
	}
	if (var->t == 'u' || var->t == 'U')
	{
		var->u = va_arg(tmp, uintmax_t);
		if (var->t == 'u')
			cast_o(var, flags);
		var->buff = print_u(var, flags);
	}
}

void	output_x(va_list tmp, t_arg *var, t_flags *flags)
{
	if (var->t == 'x')
	{
		var->u = va_arg(tmp, uintmax_t);
		cast_o(var, flags);
		flags->format = flags->hash == 1 ? 1 : 0;
		var->buff = print_x(var, flags);
	}
	if (var->t == 'X')
	{
		var->is_up = 1;
		var->u = va_arg(tmp, uintmax_t);
		cast_o(var, flags);
		flags->format = flags->hash == 1 ? 1 : 0;
		var->buff = print_x(var, flags);
		var->buff = to_upper(var->buff);
	}
}

int		output_C(va_list tmp, t_arg *var, t_flags *flags, int ret)
{
	if (var->t == 'C')
	{
		var->d = va_arg(tmp, wchar_t);
		var->nul = var->d == 0 ? 1 : 0;
		if (MB_CUR_MAX == 1 && var->d != 0 && var->d > 255)
			return (-1);
		else if (MB_CUR_MAX == 1 && var->d != 0 && var->d <= 255)
			*var->buff = (char)var->d;
		else
			ret = print_unicode(var);
	}
	return (ret);
}

int		output_S(va_list tmp, t_arg *var, t_flags *fl, int ret, char *buff)
{
	if (var->t == 'S')
	{
		var->w_str = va_arg(tmp, wchar_t *);
		var->nul = var->w_str == 0 ? 1 : 0;
		if (var->w_str == NULL)
		{
			free(var->buff);
			print_str(var, fl);
			ret = fl->prsn > 0 ? ret + fl->prsn : ret + 6;
		}
		else if (fl->prsn == 0)
		{
			var->buff = print_str(var, fl);
			ret = ft_strlen(var->buff);
		}
		else
			ret = print_uni_str(var, ret, fl, buff);
	}
	return (ret);
}

int		output_c(va_list tmp, t_arg *var, t_flags *fl, int ret, char *buff)
{
	var->buff = (char *)malloc(sizeof(char) * 5);
	if (var->t == 'S')
		ret = output_S(tmp, var, fl, ret, buff);
	if ( var->t == 'C')
		ret = output_C(tmp, var, fl, ret);
	if (var->t == 'c')
	{
		var->d = va_arg(tmp, int);
		if (fl->l == 1 && MB_CUR_MAX != 1)
			ret += print_unicode(var);
		else if (MB_CUR_MAX == 1 && var->d > 255)
			return (-1);
		else
		{
			var->d = (char)var->d;
			var->nul = var->d == 0 ? 1 : 0;
			var->buff = print_c(var, fl);
			ret = ft_strlen(var->buff);
		}
	}
	return (ret);
}

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

void	output_d(va_list tmp, t_arg *var, t_flags *flags)
{
	if (var->t == 'D' || var->t == 'd')
	{
		var->d = va_arg(tmp, intmax_t);
		if (flags->l == 0)
			flags->l = var->t == 'D' ? 1 : 0;
		cast_d(var, flags);
		if ((var->width == 0 || flags->minus == 1) && flags->nul == 1)
			flags->nul = 0;
		flags->negative = var->d < 0 ? 1 : 0;
		if (flags->negative == 1 && -var->d < 0)
			var->u = -var->d;
		var->buff = print_d(var, flags);
	}
	if (var->t == 'i')
	{
		var->d = va_arg(tmp, intmax_t);
		cast_d(var, flags);
		flags->negative = var->d < 0 ? 1 : 0;
		var->buff = print_d(var, flags);
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

void	output_c(va_list tmp, t_arg *var, t_flags *flags, int *ret)
{
	if (var->t == 'c')
	{
		var->d = va_arg(tmp, int);
		var->d = (char)var->d;
		if (var->d == 0)
			(*ret) += 1;
		var->buff = print_c(var, flags);
		(*ret) += ft_strlen(var->buff);
		ft_putstr(var->buff);
		if (var->d == 0)
			ft_putchar(var->d);
	}
	if (var->t == 'C')
	{
		var->buff = (char *)malloc(sizeof(char) * 5);
		var->d = va_arg(tmp, wchar_t);
		print_unicode(var);
		ft_putstr(var->buff);
	}
	if (var->t == 'S')
	{
		var->buff = (char *)malloc(sizeof(char) * 5);
		var->w_str = va_arg(tmp, wchar_t *);
		print_uni_str(var, &ret);
	}
}

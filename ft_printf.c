/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:36:46 by omaslova          #+#    #+#             */
/*   Updated: 2018/08/20 15:36:50 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ouput_s_and_p(va_list tmp, t_arg *var, t_flags *flags)
{
	if (var->t == '%')
	{
		var->d = (char)'%';
		var->buff = print_c(var, flags);
	}
	if (var->t == 's')
	{
		var->str = va_arg(tmp, char*);
		var->buff = print_str(var, flags);
	}
	if (var->t == 'p')
	{
		var->u = va_arg(tmp, unsigned long int);
		flags->format = 1;
		var->buff = print_x(var, flags);
	}
	if (flags->astr == 1)
	{
		var->width = va_arg(tmp, unsigned int);
		var->width = var->width < 0 ? 0 : var->width;
	}
	if (flags->dot == 1)
		flags->prsn = va_arg(tmp, unsigned int);
}

int		output(va_list tmp, t_arg *var, t_flags *flags)
{
	int ret;

	ret = 0;
	if (!var->t)
		return (0);
	if (var->t == 's' || var->t == 'p' || var->t == '%')
		ouput_s_and_p(tmp, var, flags);
	if (var->t == 'd' || var->t == 'D' || var->t == 'i')
		output_d(tmp, var, flags);
	if (var->t == 'x' || var->t == 'X')
		output_x(tmp, var, flags);
	if (var->t == 'u' || var->t == 'U' || var->t == 'o' || var->t == 'O')
		output_o_and_u(tmp, var, flags);
	if (var->t == 'c' || var->t == 'C' || var->t == 'S')
		output_c(tmp, var, flags, &ret);
	else
	{
		ret += ft_strlen(var->buff);
		ft_putstr(var->buff);
	}
	free(var->buff);
	return (ret);
}

int		symbol_check(char *str, t_flags *fl, t_arg *var, va_list ap)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	while (*str)
	{
		while (*str == '%')
		{
			++str;
			fl = initialization(fl);
			var->width = 0;
			if ((i = define_operator(str, var, fl)))
				ret += output(ap, var, fl);
			else if (*str == ' ')
				str++;
			str = str + i;
		}
		if (*str == '\0' || ret == -1)
			break ;
		ft_putchar(*str++);
		ret++;
	}
	return (ret);
}

int		ft_printf(char *str, ...)
{
	t_flags		*flags;
	t_arg		*var;
	va_list		ap;
	int			ret;

	va_start(ap, str);
	flags = (t_flags *)malloc(sizeof(t_flags));
	var = (t_arg *)malloc(sizeof(t_arg));
	ret = symbol_check(str, flags, var, ap);
	free(var);
	free(flags);
	va_end(ap);
	return (ret);
}

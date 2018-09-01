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

int		output(va_list tmp, t_arg *var, t_flags *flags)
{
	int ret;

	ret = 0;
	if (flags->astr == 1)
	{
		var->width = va_arg(tmp, unsigned int);
		var->width = var->width < 0 ? 0 : var->width;
	}
	if (flags->dot == 1)
		flags->prsn = va_arg(tmp, unsigned int);
	if (!var->type)
		return (-1);
	if (var->type == '%')
	{
		var->d = (char)'%';
		var->buff = print_c(var, flags);
	}
	if (var->type == 's')
	{
		var->str = va_arg(tmp, char*);
		var->buff = print_str(var, flags);
	}
	if (var->type == 'S')
	{
		var->w_str = va_arg(tmp, wchar_t *);
		print_unicode(var, flags);
	}
	if (var->type == 'D')
	{

	}
	if (var->type == 'p')
	{
		var->u = va_arg(tmp, unsigned long int);
		flags->format = 1;
		var->buff = print_x(var, flags);
	}
	if (var->type == 'd' || var->type == 'i')
		output_d(tmp, var, flags);
	if (var->type == 'x' || var->type == 'X')
		output_x(tmp, var, flags);
	if (var->type == 'u' || var->type == 'U')
		output_u(tmp, var, flags);
	if (var->type == 'o' || var->type == 'O')
		output_o(tmp, var, flags);
	if (var->type == 'c' || var->type == 'C')
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
	while (*str != '\0')
	{
		while (*str == '%')
		{
			++str;
			fl = initialization(fl);
			var->width = 0;
			if ((i = define_operator(str, var, fl)))
				ret += output(ap, var, fl);
			str = str + i;
		}
		if (*str == '\0')
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

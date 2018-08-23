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

t_flags	*initialization(t_flags *flags)
{
	flags->minus = 0;
	flags->plus = 0;
    flags->hash = 0;
    flags->nul = 0;
    flags->space = 0;
    flags->negative = 0;
    flags->prsn = 0;
    flags->format = 0;
    flags->astr = 0;
 	return (flags);
}

void	define_flag(char *str, t_flags *var, int lim)
{
	int i;
	
	i = 0;
	while (i < lim && *str)
	{
		if (str[i] == '-')
			var->minus = 1;
		if (str[i] == '+')
			var->plus = 1;
		if (str[i] == '0')
			var->nul = 1;
		if (str[i] == '#')
			var->hash = 1;
		if (str[i] == ' ')
			var->space = 1;
		if (str[i] == '*')
			var->astr = 1;
		if (str[i] == '.')
			var->prsn = ft_atoi(&str[++i]);
		i++;
	}
}

char	define_type(char c)
{
	if (c == 's')
		return ('s');
	if (c == 'd')
		return ('d');
	if (c == 'e')
		return ('e');
	if (c == 'i')
		return ('i');
	if (c == 'u')
		return ('u');
	if (c == 'o')
		return ('o');
	if (c == 'x')
		return ('x');
	if (c == 'X')
		return ('X');
	return (0);
}

int		define_operator(char *str, t_arg *var, t_flags *flags)
{
	int i;
	
	i = 0;
	while (str[i] != 's' && str[i] != 'd' && str[i] != 'e' && str[i] != 'i'
			&& str[i] != 'u'  && str[i] != 'o' && str[i] != 'x' && str[i] != 'X' && str[i] != '\0')
		i++;
	if (i > 0)
	{
		define_flag(str, flags, i);
		var->width = ft_atoi(str);
	}
	if (str[i])
		var->type = define_type(str[i]);
	return (++i);
}

void	output(va_list tmp, t_arg *var, t_flags *flags)
{
	if (flags->astr == 1)
	{
		var->width = va_arg(tmp, unsigned int);
		var->width = var->width < 0 ? 0 : var->width;
	}
	if (var->type == 's')
	{
		var->str = va_arg(tmp, char *);
		print_str(var, flags);
	}
	if (var->type == 'd')
	{
		var->d = va_arg(tmp, int);
		flags->negative = var->d < 0 ? 1 : 0;
		print_d(var, flags);
	}
	// if (t == 'c')
	// {
	// 	var->c = va_arg(tmp, char);
	// 	print_c(var, flags);
	// }
	if (var->type == 'S')
	{

	}
	if (var->type == 'D')
	{

	}
	if (var->type == 'p')
	{

	}
	if (var->type == 'i')
	{

	}
	if (var->type == 'o')
	{
		var->d = va_arg(tmp, int);
		print_o(var, flags);
	}
	if (var->type == 'O')
	{

	}
	if (var->type == 'u')
	{
		var->u = va_arg(tmp, unsigned int);
		print_u(var, flags);
	}
	if (var->type == 'U')
	{

	}
	if (var->type == 'x')
	{
		var->d = va_arg(tmp, int);
		flags->format = flags->hash == 1 ? 1 : 0;
		ft_putstr(print_x(var, flags));
	}
	if (var->type == 'X')
	{
		var->is_up = 1;
		var->d = va_arg(tmp, int);
		flags->format = flags->hash == 1 ? 1 : 0;
		var->buff = print_x(var, flags);
		ft_putstr(to_upper(var->buff));
	}
	if (var->type == 'c')
	{

	}
	if (var->type == 'C')
	{

	}
}

void	foo(char *fmt, ...)
{
	t_flags *flags;
	t_arg *var;
	va_list ap;
	int i;

	i = 0;
	va_start(ap, fmt);
	flags = (t_flags *)malloc(sizeof(t_flags));
	var = (t_arg *)malloc(sizeof(t_arg));
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			flags = initialization(flags);
			var->width = 0;
			i = define_operator(fmt, var, flags);
			output(ap, var, flags);
			fmt = fmt + i;
		}
		ft_putchar(*fmt++);
	}
	va_end(ap);
}

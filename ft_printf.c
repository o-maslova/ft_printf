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
    flags->prsn = -1;
	flags->dot = 0;
    flags->format = 0;
    flags->astr = 0;
	flags->hh = 0;
	flags->h = 0;
	flags->ll = 0;
	flags->l = 0;
	flags->j = 0;
 	return (flags);
}

void	define_flag(char *str, t_flags *var, int lim)
{
	int i;
	
	i = -1;
	while (++i < lim && *str)
	{
		if (str[i] == '-')
			var->minus = 1;
		if (str[i] == '+')
			var->plus = 1;
		if (str[i] == '0')
		{
			if (str[i - 1] < '1' || str[i - 1] > '9')
				var->nul = 1;
		}
		if (str[i] == '#')
			var->hash = 1;
		if (str[i] == ' ')
			var->space = 1;
		if (str[i] == '*')
			var->astr = 1;
		if (str[i] == '.')
		{
			var->dot = str[i + 1] == '*' ? 1 : 0;
			var->prsn = ft_atoi(&str[++i]);
		}
	}
}

char	define_type(char c)
{
	if (c == 's')
		return ('s');
	if (c == 'c')
		return ('c');
	if (c == 'd')
		return ('d');
	if (c == 'e')
		return ('e');
	if (c == 'i')
		return ('i');
	if (c == 'u')
		return ('u');
	if (c == 'U')
		return ('U');
	if (c == 'o')
		return ('o');
	if (c == 'O')
		return ('O');
	if (c == 'p')
		return ('p');
	if (c == 'x')
		return ('x');
	if (c == 'X')
		return ('X');
	if (c == '%')
		return ('%');
	return (0);
}

void	modificator_check(char *str, t_flags *fl)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'h')
		{
			if (str[++i] == 'h')
				fl->hh = 1;
			else
				fl->h = 1;
		}
		if (str[i] == 'l')
		{
			if (str[++i] == 'l')
				fl->ll = 1;
			else
				fl->l = 1;
		}
		fl->j = str[i] == 'j' ? 1 : 0;
		i++;
	}
}

int		define_operator(char *str, t_arg *var, t_flags *flags)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (str[i] != 's' && str[i] != 'c' && str[i] != 'd' && str[i] != 'e'
			&& str[i] != 'i' && str[i] != 'u' && str[i] != 'U' && str[i] != 'o'
			&& str[i] != 'O'&& str[i] != 'x' && str[i] != 'X' && str[i] != 'p' && str[i] != '%')
		i++;
	modificator_check(ft_strsub(str, 0, i), flags);
	if (i > 0)
	{
		define_flag(str, flags, i);
		while (str[j] == '#' || str[j] == '-' || str[j] == '+')
			j++;
		var->width = ft_atoi(&str[j]);
		var->width = var->width < 0 ? -var->width : var->width;
	}
	if (str[i])
		var->type = define_type(str[i]);
	return (++i);
}

void	cast_d(t_arg *var, t_flags *fl)
{
	if (fl->hh == 1)
		var->d = (char)var->d;
	else if (fl->h == 1)
		var->d = (short)var->d;
	else if (fl->ll == 1)
		var->d = (long long)var->d;
	else if (fl->l == 1)
		var->d = (long)var->d;
	else if (fl->z == 1)
		var->d = (size_t)var->d;
}

void	cast_o(t_arg *var, t_flags *fl)
{
	if (fl->hh == 1)
		var->u = (unsigned char)var->u;
	else if (fl->h == 1)
		var->u = (unsigned short)var->u;
	else if (fl->ll == 1)
		var->u = (unsigned long long)var->u;
	else if (fl->l == 1)
		var->u = (unsigned long)var->u;
	else if (fl->z == 1)
		var->u = (size_t)var->u;
}

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
	if (var->type == 'd')
	{
		var->d = va_arg(tmp, intmax_t);
		if (var->d < 0)
			cast_o(var, flags);
		else
			cast_d(var, flags);
		flags->negative = var->d < 0 ? 1 : 0;
		var->buff = print_d(var, flags);
	}
	if (var->type == 'S')
	{

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
	if (var->type == 'i')
	{
		var->d = va_arg(tmp, intmax_t);
		cast_d(var, flags);
		flags->negative = var->d < 0 ? 1 : 0;
		var->buff = print_d(var, flags);
	}
	if (var->type == 'o')
	{
		var->u = va_arg(tmp, uintmax_t);
		cast_o(var, flags);
		var->buff = print_o(var, flags);
	}
	if (var->type == 'O')
	{
		var->u = va_arg(tmp, uintmax_t);
		flags->l = 1;
		cast_o(var, flags);
		var->buff = print_o(var, flags);
	}
	if (var->type == 'u')
	{
		var->u = va_arg(tmp, uintmax_t);
		cast_o(var, flags);
		var->buff = print_u(var, flags);
	}
	if (var->type == 'U')
	{
		var->u = va_arg(tmp, uintmax_t);
		flags->l = 1;
		cast_o(var, flags);
		var->buff = print_u(var, flags);
	}
	if (var->type == 'x')
	{
		// cast_o(var, flags);
		var->u = va_arg(tmp, uintmax_t);
		cast_o(var, flags);
		flags->format = flags->hash == 1 ? 1 : 0;
		var->buff = print_x(var, flags);
	}
	if (var->type == 'X')
	{
		var->is_up = 1;
		var->u = va_arg(tmp, uintmax_t);
		cast_o(var, flags);
		flags->format = flags->hash == 1 ? 1 : 0;
		var->buff = print_x(var, flags);
		var->buff = to_upper(var->buff);
	}
	if (var->type == 'c')
	{
		var->d = va_arg(tmp, int);
		var->d = (char)var->d;
		if (var->d == 0)
			ret += 1;	
		var->buff = print_c(var, flags);
	}
	if (var->type == 'C')
	{

	}
	ret += ft_strlen(var->buff);
	ft_putstr(var->buff);
	return (ret);
}

int		ft_printf(char *fmt, ...)
{
	t_flags *flags;
	t_arg *var;
	va_list ap;
	int i;
	int ret;

	i = 0;
	ret = 0;
	va_start(ap, fmt);
	flags = (t_flags *)malloc(sizeof(t_flags));
	var = (t_arg *)malloc(sizeof(t_arg));
	while (*fmt != '\0')
	{
		while (*fmt == '%')
		{
			fmt++;
			flags = initialization(flags);
			var->width = 0;
			i = define_operator(fmt, var, flags);
			ret += output(ap, var, flags);
			fmt = fmt + i;
		}
		if (*fmt == '\0')
			break ;
		ft_putchar(*fmt++);
		ret++;
	}
	va_end(ap);
	return(ret);
}

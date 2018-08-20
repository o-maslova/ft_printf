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

char	*define_flag(char *str, t_flags *var)
{
	char *ptr;

	ptr = NULL;
	while (*str)
	{
		if (ft_strchr(str, '-'))
			var->minus = 1;
		else if (ft_strchr(str, '+'))
			var->plus = 1;
		else if (ft_strchr(str, '0'))
			var->nul = 1;
		else if (ft_strchr(str, '#'))
			var->hash = 1;
		else if (ft_strchr(str, ' '))
			var->space = 1;
		else if ((ptr = ft_strchr(str, '.')))
		{
			var->precision = ft_atoi(++ptr);
			break ;
		}
		else
			break ;
		str++;
	}
	return (str);
}

char	define_operator(char *str, t_arg *var, t_flags *flags)
{
	int i;
	int j;
	
	i = 0;
	j = -1;
	while (str[i] != 's' && str[i] != 'd' && str[i] != 'e' && str[i] != 'i' && str[i] != 'u'  && str[i] != 'o')
		i++;
	var->width = 0;
	if (i > 0)
	{
		var->f_out = (char *)malloc(sizeof(char) * i);
		while (++j < i)
			var->f_out[j] = str[j];
		var->f_out = define_flag(str, flags);
		var->width = ft_atoi(var->f_out);
	}
	if (str[i] == 's')
		return ('s');
	if (str[i] == 'd')
		return ('d');
	if (str[i] == 'e')
		return ('e');
	if (str[i] == 'i')
		return ('i');
	if (str[i] == 'u')
		return ('u');
	if (str[i] == 'o')
		return ('o');
	return (0);
}

void	output(char t, va_list tmp, t_arg *var, t_flags *flags)
{
	if (t == 's')
	{
		var->str = va_arg(tmp, char *);
		print_str(var, flags);
	}
	if (t == 'd')
	{
		var->d = va_arg(tmp, int);
		if (var->d < 0)
			flags->negative = 1;
		print_d(var, flags);
	}
	// if (t == 'c')
	// {
	// 	var->c = va_arg(tmp, char);
	// 	print_c(var, flags);
	// }
	if (t == 'S')
	{

	}
	if (t == 'D')
	{
	}
	if (t == 'p')
	{
	}
	if (t == 'i')
	{
	}
	if (t == 'o')
	{
		var->d = va_arg(tmp, int);
		// if (var->d < 0)
		// 	flags->negative = 1;
		print_o(var, flags);
	}
	if (t == 'O')
	{
	}
	if (t == 'u')
	{
		var->u = va_arg(tmp, unsigned int);
		print_u(var, flags);
	}
	if (t == 'U')
	{

	}
	if (t == 'x')
	{

	}
	if (t == 'X')
	{

	}
	if (t == 'c')
	{

	}
	if (t == 'C')
	{

	}
}

void	foo(char *fmt, ...)
{
	t_flags *flags;
	va_list ap;
	t_arg *var;
	char *ptr;
	
	flags = (t_flags *)malloc(sizeof(t_flags));
	va_start(ap, fmt);
	var = (t_arg *)malloc(sizeof(t_arg));
	while (*fmt)
	{
		ptr = ft_strchr(fmt, '%');
		if (ptr)
		{
			var->buff = ft_strsub(fmt, 0, ptr - fmt);
			fmt += ptr - fmt;
			if (*fmt == '%')
			{
				if (var->buff != NULL && *var->buff != '\0')
					ft_putstr(var->buff);
				var->type = define_operator(++fmt, var, flags);
				output(var->type, ap, var, flags);
			}
			fmt++;
		}
		else
			break ;
	}
	printf("\n");
	va_end(ap);
}

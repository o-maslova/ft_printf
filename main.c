/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:15:50 by omaslova          #+#    #+#             */
/*   Updated: 2018/08/14 11:15:54 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// void	set_precision(char *str, int i, int lim)
// {
	
// }

char	*define_flag(char *str, t_flags *var)
{
	while (*str)
	{
		if (*str == '-')
			var->minus = 1;
		else if (*str == '+')
			var->plus = 1;
		else if (*str == '0')
			var->nul = 1;
		else if (*str == '#')
			var->hash = 1;
		else if (*str == ' ')
			var->space = 1;
		else
			break ;
		// if (*str == '.')
		// 	set_precision(&str[++i], i, lim);
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
	while (str[i] != 's' && str[i] != 'd' && str[i] != 'e' && str[i] != 'i')
		i++;
	if (i > 0)
	{
		var->f_out = (char *)malloc(sizeof(char) * (i + 1));
		var->format = 1;
		while (++j < i)
			var->f_out[j] = str[j];
		var->f_out = define_flag(var->f_out, flags);
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
		i++;
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
		print_d(var, flags);
	}
	if (t == 'c')
	{
		var->c = va_arg(tmp, int);
	//	printf("%c", c);
	}
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

	}
	if (t == 'O')
	{
	}
	if (t == 'u')
	{
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
	char t;
	
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
				t = define_operator(++fmt, var, flags);
				output(t, ap, var, flags);
			}
			fmt++;
		}
		else
			break ;
	}
	printf("\n");
	va_end(ap);
}

int main(int argc, char **argv)
{
	int i;
	char *str;
	char *str2;
	char *str3;

	(void)argc;
	i = 1;
	str = argv[1];
	str2 = argv[2];
	str3 = argv[3];
	foo("%012d\n", -45);
	printf("%012d\n", -45);

	// while (i < argc)
	// 	foo(argv[i++]);
	return (0);
}
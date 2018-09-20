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

void	invalid(t_arg *var, t_flags *fl, char *str)
{
	char	*ptr;
	char	*buff;
	int		len;
	int		i;
	int		lim;

	// i = check(str, ft_strlen(str));
	// while (str)
	var->str = ft_strnew(2);
	var->str[0] = var->t;
	var->str[1] = '\0';
	if ((fl->dot == -1 || fl->dot == 1) && fl->prsn + 1 >= var->width)
		fl->nul = 0;
	// if (fl->prsn >= 0)
	// 	var->str = set_precision(ft_strlen(var->str), var->str, fl);
	// if (fl->nul != 1 && (fl->plus == 1 || fl->space == 1))
	// 	str = if_nul(fl, str);
	// len = ft_strlen(var->str);
	var->width = var->width > 1 ? var->width - 1 : 0;
	buff = (char *)malloc(sizeof(char) * (var->width + 1));
	buff = set_pad(var->width, buff, fl);
	// printf("buff = %s\n", buff);
	// printf("var->str = %s\n", var->str);
	if (fl->minus == 1)
		var->buff = ft_strjoin(var->str, buff);
	else
		var->buff = ft_strjoin(buff, var->str);
	free(buff);
	free(var->str);
}

int		output(va_list tmp, t_arg *var, t_flags *flags, char *str)
{
	int ret;

	ret = 0;
	if (!var->t)
		return (0);
	else if (var->t == 's' || var->t == 'p' || var->t == '%')
		ouput_s_and_p(tmp, var, flags);
	else if (var->t == 'd' || var->t == 'D' || var->t == 'i')
		output_d(tmp, var, flags);
	else if (var->t == 'x' || var->t == 'X')
		output_x(tmp, var, flags);
	else if (var->t == 'u' || var->t == 'U' || var->t == 'o' || var->t == 'O')
		output_o_and_u(tmp, var, flags);
	else if (var->t != 'c' && var->t != 'C' && var->t != 'S' && var->width > 0)
		invalid(var, flags, str);
	if (var->t == 'c' || var->t == 'C' || var->t == 'S')
		output_c(tmp, var, flags, &ret);
	else
	{
		ret += ft_strlen(var->buff);
		ft_putstr(var->buff);
	}
	ft_bzero(var->buff, ft_strlen(var->buff));
	// free(var->buff);
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
			initialization(fl, var);
			var->width = 0;
			if ((i = define_operator(str, var, fl)))
				ret += output(ap, var, fl, str);
			else if (*str == ' ')
				str++;
			str = str + i;
			// ft_bzero(var->buff, ft_strlen(var->buff));
		}
		if (*str == '\0')
			break ;
		// if (*var->buff == '\0')
		// 	free(var->buff);
		ft_putchar(*str++);
		ret++;
	}
	var->buff = !var->buff ? ft_memalloc(1) : var->buff;
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

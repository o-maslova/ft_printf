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

void	invalid(t_arg *var, t_flags *fl)
{
	char	*buff;
	char	*ptr;

	// var->str = ft_strnew(2);
	// var->str[0] = var->t;
	// var->str[1] = '\0';
	if ((ptr = ft_strchr(var->str, '}')) || (ptr = ft_strchr(var->str, '\n')))
	{
		buff = ft_strsub(var->str, 0, ptr - var->str);
		free(var->str);
		var->str = ft_strdup(buff);
		free(buff);
	}
	if ((fl->dot == -1 || fl->dot == 1) && fl->prsn + 1 >= var->width)
		fl->nul = 0;
	var->width = var->width > 1 ? var->width - 1 : 0;
	buff = (char *)malloc(sizeof(char) * (var->width + 1));
	buff = set_pad(var->width, buff, fl);
	if (fl->minus == 1)
		var->buff = ft_strjoin(var->str, buff);
	else
		var->buff = ft_strjoin(buff, var->str);
	free(buff);
	free(var->str);
}

int		output(va_list tmp, t_arg *var, t_flags *flags, char *str, int *ex)
{
	int ret;

	ret = 0;
	if (!var->t)
		return (0);
	if (flags->astr != 0)
	{
		var->tmp_w = va_arg(tmp, int);
		var->width = flags->astr > 0 ? var->tmp_w : var->width;
		flags->minus = var->width < 0 ? 1 : 0;
	}
	if (flags->astr == 1 && flags->dot == 1)
		flags->prsn = va_arg(tmp, int);
	var->width = var->width < 0 ? -var->width : var->width;
	if (var->t == 's' || var->t == 'p' || var->t == '%')
		ouput_s_and_p(tmp, var, flags);
	else if (var->t == 'd' || var->t == 'D' || var->t == 'i')
		output_d(tmp, var, flags);
	else if (var->t == 'x' || var->t == 'X')
		output_x(tmp, var, flags);
	else if (var->t == 'u' || var->t == 'U' || var->t == 'o' || var->t == 'O')
		output_o_and_u(tmp, var, flags);
	else if (var->t != 'c' && var->t != 'C' && var->t != 'S')
		invalid(var, flags);
	if (var->t == 'c' || var->t == 'C' || var->t == 'S')
		return (output_c(tmp, var, flags, ret, ex));
	ret += ft_strlen(var->buff);
	ft_putstr(var->buff);
	ft_bzero(var->buff, ft_strlen(var->buff));
	// free(var->buff);
	return (ret);// = var->ex == 1 ? -1 : ret));
}

int		symbol_check(char *str, t_flags *fl, t_arg *var, va_list ap, int *ex)
{
	int			i;
	int 		j;
	int			ret;

	i = 0;
	j = 0;
	ret = 0;
	while (*str)
	{
		if (var->ex && ft_strchr(str, 'S') && !ft_strchr(str, NULL))
				ret = -2;
		while (*str == '%')
		{
			++str;
			initialization(fl, var);
			if ((i = define_operator(str, var, fl)))
				ret = ((j = output(ap, var, fl, str, ex)) >= 0) ? ret + j : j;
			// printf("\nj = %d\n", j);
				// ret += output(ap, var, fl, str);
			str = str + i;
			// if (*str == ' ' && ret < 0)
			// 	str++;
			// ret = MB_CUR_MAX == 1 ? -1 : ret;
			// ft_bzero(var->buff, ft_strlen(var->buff));
			// free(var->buff);
		}
		if (!*str || *str == '\0' || ret == -2)//(var->ex && !ft_strchr(str, 'C')))// && (ft_strchr(str, 'S') || ft_strchr(str, 'C'))))
			break ;
		// if (*var->buff == '\0')
		// 	free(var->buff);
		ft_putchar(*str++);
		ret = ret < 0 ? -1 : ret + 1;
	}
	ret = *ex ? -1 : ret;
	var->buff = !var->buff ? ft_memalloc(1) : var->buff;
	return (ret);
}

int		ft_printf(char *str, ...)
{
	t_flags		*flags;
	t_arg		*var;
	va_list		ap;
	static int	ex;
	int			ret;

	va_start(ap, str);
	flags = (t_flags *)malloc(sizeof(t_flags));
	var = (t_arg *)malloc(sizeof(t_arg));
	if (ft_strchr(str, 'S') && MB_CUR_MAX == 1)
		ex = 1;
	var->ex = ex;
	var->tmp = ft_strdup(str);
	ret = symbol_check(var->tmp, flags, var, ap, &ex);
	free(var);
	free(flags);
	va_end(ap);
	return (ret);
}

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

int		output(va_list tmp, t_arg *var, t_flags *flags, char *str, char *buff)
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
		return (output_c(tmp, var, flags, ret, buff));
	ret = ft_strlen(var->buff);
	// ft_putstr(var->buff);
	// ft_bzero(var->buff, ft_strlen(var->buff));
	// free(var->buff);
	return (ret);// = var->ex == 1 ? -1 : ret));
}

/*int		check_str(char *str, t_arg *var)
{
	int i;
	int check;

	i = 0;
	check = ft_strchr(str, 'c') ? 1 : 0;
	while (str[i] != '\0')
	{
		if (MB_CUR_MAX == 1 && (var->t == 'S' || var->t == 'C' || var->t == 'c')
			&& (unsigned char)str[i] > 255)
		{
			str[i] = '\0';
			return (-1);
		}
		// printf("str[i] = %c   ", str[i]);
		// if (check == 1 && (unsigned char)str[i++] > 255)
		// 	return (-1);
	}
	return (1);
}*/

int		print(char *buff, int res, t_arg *var)
{
	int i;
	int j;
	int check;

	i = 0;
	j = 0;
	check = -1;
	if (buff[i] == '\0' && res != 0 && buff[i + 1] != '\0')
		ft_putchar(buff[i++]);
	while (j < k)
	{
		if (MB_CUR_MAX == 1 && buff[j] == 0)
			check = 1;
		else
			check = (unsigned char)buff[j] > 255 ? j : 0;
		j++;
	}
	// printf("k = %d\n", k);
	while ((buff[i] != '\0') || check == 1)
	{	
		write(1, &buff[i++], 1);
		if (buff[i] == '\0' && (buff[i] != '\0' || i < k))
			write(1, &buff[i++], 1);
		check = -1;
	}
	if (k == 1 && buff[i] == '\0' && var->nul == 1 && MB_CUR_MAX != 1)
		write(1, &buff[i++], 1);
	// if (i < width && buff[i] == '\0')
	// 	write(1, &buff[i++], 1);
	if ((MB_CUR_MAX == 1 && check != -1) || res == -1)
		return (-1);
	return (i);
}


void	buff_join(char *buff, char *str, int ret, t_arg *var)
{
	// static int	k;
	int			i;
	int			len;

	i = 0;
	if (!str)
		return ;
	len = ft_strlen(str);
	while (i < len && k < BUFF_SIZE)
	{
		buff[k++] = str[i++];
	}
	if (var->nul == 1)
	{
		if (var->width > 0)
			buff[var->width] = '\0';
		else
			buff[k] = '\0';
		k++;
	}
	
	// if (k == BUFF_SIZE)
	// {
	// 	k = 0;
	// 	print(buff);
	// 	ft_bzero(buff, 100);
	// }
}

int		symbol_check(char *str, t_flags *fl, t_arg *var, va_list ap, char *buff)
{
	int			i;
	int 		j;
	int			ret;

	i = 0;
	j = 0;
	ret = 0;
	while (*str)
	{
		while (*str == '%' && k < BUFF_SIZE)
		{
			++str;
			initialization(fl, var);
			if ((i = define_operator(str, var, fl)))
				ret = output(ap, var, fl, str, buff);
			buff_join(buff, var->buff, ret, var);
			str = str + i;
			ft_bzero(var->buff, ft_strlen(var->buff));
		}
		if (ret == -1)
			ft_bzero(&buff[k - j], BUFF_SIZE - k);
		j = MB_CUR_MAX == 1 ? j + 1 : j;
		if (*str != '\0')
			buff[k++] = *str++;
	}
	return (ret);
}

int		ft_printf(char *str, ...)
{
	t_flags		*flags;
	t_arg		*var;
	va_list		ap;
	static int	ret;
	char		buff[BUFF_SIZE];

	k = 0;
	va_start(ap, str);
	flags = (t_flags *)malloc(sizeof(t_flags));
	var = (t_arg *)malloc(sizeof(t_arg));
	ft_bzero(buff, 100);
	ret = symbol_check(str, flags, var, ap, buff);
	// printf("res_1 = %d\n", ret);
	// print(list, flags, var, ret);
	ret = print(buff, ret, var);
	// printf("res_2 = %d\n\n", print(buff));
	// print(list, flags, var, ret);
	free(var);
	free(flags);
	va_end(ap);
	return (ret);
}

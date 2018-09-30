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

int		output(va_list tmp, t_arg *var, t_flags *flags, char *str)
{
	if (!var->t)
		return (0);
	if (flags->astr != 0)
	{
		var->tmp_w = va_arg(tmp, int);
		var->width = flags->astr > 0 ? var->tmp_w : var->width;
		flags->minus = var->width < 0 ? 1 : 0;
		var->tmp_w = var->tmp_w < 0 ? -var->tmp_w : var->tmp_w;
	}
	if (flags->astr == 1 && flags->dot == 1)
		flags->prsn = va_arg(tmp, int);
	var->width = var->width < 0 ? -var->width : var->width;
	if ((var->t == 's' && flags->l != 1) || var->t == 'p' || var->t == '%')
		ouput_s_and_p(tmp, var, flags);
	else if (var->t == 'd' || var->t == 'D' || var->t == 'i')
		output_d(tmp, var, flags);
	else if (var->t == 'x' || var->t == 'X' || var->t == 'u' || var->t == 'U'
		|| var->t == 'o' || var->t == 'O')
		output_o_u_x(tmp, var, flags);
	else if (var->t != 'c' && var->t != 'C' && var->t != 'S' && var->t != 's')
		invalid(var, flags);
	if (var->t == 'c' || var->t == 'C' || var->t == 'S' || var->t == 's')
		return (output_c(tmp, var, flags));
	return (ft_strlen(g_buff));
}

void	continue_check(int *check)
{
	int j;

	j = 0;
	while (j < g_k)
	{
		if (MB_CUR_MAX == 1 && g_buff[j] == 0)
			*check = 1;
		else
			*check = (unsigned char)g_buff[j] > 255 ? j : 0;
		j++;
	}
}

int		print(char *buff, int res, t_arg *var)
{
	int i;
	int check;

	i = 0;
	check = -1;
	if (buff[i] == '\0' && res != -1 && buff[i + 1] != '\0')
		ft_putchar(buff[i++]);
	continue_check(&check);
	while ((buff[i] != '\0') || check == 1)
	{
		write(1, &buff[i++], 1);
		if (buff[i] == '\0' && (buff[i] != '\0' || i < g_k))
			write(1, &buff[i++], 1);
		check = -1;
	}
	if (g_k == 1 && buff[i] == '\0' && var->nul == 1 && MB_CUR_MAX != 1)
		write(1, &buff[i++], 1);
	if ((MB_CUR_MAX == 1 && check != -1) || res == -1)
		return (-1);
	return (i);
}

int		symbol_check(char *str, t_flags *fl, t_arg *var, va_list ap)
{
	int			i;
	int			j;
	int			ret;

	i = 0;
	j = 0;
	ret = 0;
	while (*str)
	{
		while (*str == '%')
		{
			++str;
			initialization(fl, var);
			if ((i = define_operator(str, var, fl)))
				ret = output(ap, var, fl, str);
			str = str + i;
		}
		ret == -1 ? ft_bzero(&g_buff[g_k - j], BUFF_SIZE - g_k) : 0;
		j = MB_CUR_MAX == 1 ? j + 1 : j;
		if (*str != '\0' && g_k < BUFF_SIZE)
			g_buff[g_k++] = *str++;
		if (g_k >= BUFF_SIZE)
			nul_the_buf(g_buff, NULL, var);
	}
	return (ret);
}

int		ft_printf(char *str, ...)
{
	t_flags		*flags;
	t_arg		*var;
	va_list		ap;
	static int	res;

	g_k = 0;
	g_result = 0;
	va_start(ap, str);
	flags = (t_flags *)malloc(sizeof(t_flags));
	var = (t_arg *)malloc(sizeof(t_arg));
	ft_bzero(g_buff, 100);
	if (symbol_check(str, flags, var, ap) == -1)
		res = -1;
	res = print(g_buff, res, var);
	g_result = res == -1 ? res : g_result + res;
	free(var);
	free(flags);
	va_end(ap);
	return (g_result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <omaslova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:44:08 by omaslova          #+#    #+#             */
/*   Updated: 2018/09/30 18:44:11 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ouput_s_and_p(va_list tmp, t_arg *var, t_flags *flags)
{
	char *str;

	if (var->t == '%')
	{
		var->d = (char)'%';
		print_c(var, flags);
	}
	if (var->t == 's')
	{
		str = va_arg(tmp, char*);
		print_str(var, flags, str);
	}
	if (var->t == 'p')
	{
		var->u = va_arg(tmp, unsigned long int);
		flags->format = 1;
		print_p(var, flags);
	}
	if (flags->astr == 1)
	{
		var->width = va_arg(tmp, unsigned int);
		var->width = var->width < 0 ? 0 : var->width;
	}
	if (flags->dot == 1)
		flags->prsn = va_arg(tmp, unsigned int);
}

void	first_check(t_arg *var)
{
	char	*tmp;
	char	*ptr;
	char	*ptr2;

	ptr = ft_strchr(var->str, '}');
	ptr2 = ft_strchr(var->str, '\n');
	if (ptr || ptr2)
	{
		ptr = !ptr ? ptr2 : ptr;
		tmp = ft_strsub(var->str, 0, ptr - var->str);
		free(var->str);
		var->str = ft_strdup(tmp);
		free(tmp);
	}
}

void	invalid(t_arg *var, t_flags *fl)
{
	char	*tmp;

	first_check(var);
	if ((fl->dot == -1 || fl->dot == 1) && fl->prsn + 1 >= var->width)
		fl->nul = 0;
	var->width = var->width > 1 ? var->width - 1 : 0;
	tmp = (char *)malloc(sizeof(char) * (var->width + 1));
	tmp = set_pad(var->width, tmp, fl);
	if (fl->minus == 1 && *tmp != '\0')
		concat(var->str, tmp, var);
	else if (*tmp != '\0')
		concat(tmp, var->str, var);
	else
		g_buff[g_k++] = var->t;
	free(tmp);
	free(var->str);
}

void	nul_the_buf(char *buff, char *str, t_arg *var)
{
	int i;

	i = 0;
	g_k = 0;
	g_result += print(buff, g_result, var);
	ft_bzero(buff, BUFF_SIZE);
	if (str)
	{
		while (str[i] != '\0' && g_k < BUFF_SIZE)
			g_buff[g_k++] = str[i++];
		if (g_k >= BUFF_SIZE)
			nul_the_buf(g_buff, &str[i], var);
	}
}

void	buff_join(char *buff, char *str, t_arg *var)
{
	int			i;
	int			len;

	i = 0;
	if (!str)
		return ;
	len = ft_strlen(str);
	while (i < len && g_k < BUFF_SIZE)
		g_buff[g_k++] = str[i++];
	if (var->nul == 1)
	{
		if (var->width > 0)
			buff[var->width] = '\0';
		else
			buff[g_k] = '\0';
		g_k++;
	}
	if (g_k >= BUFF_SIZE)
		nul_the_buf(g_buff, &str[i], var);
}

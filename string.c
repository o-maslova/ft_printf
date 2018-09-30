/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:25:09 by omaslova          #+#    #+#             */
/*   Updated: 2018/08/29 15:25:13 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	concat(char *buff, char *str, char *tmp, t_arg *var)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0' && g_k < BUFF_SIZE)
			g_buff[g_k++] = str[i++];
		if (g_k >= BUFF_SIZE)
			nul_the_buf(g_buff, &str[i], var);
	}
	i = 0;
	if (tmp)
	{
		while (tmp[i] != '\0' && g_k < BUFF_SIZE)
			g_buff[g_k++] = tmp[i++];
		if (g_k >= BUFF_SIZE)
			nul_the_buf(g_buff, &tmp[i], var);
	}
}

void	print_str(t_arg *v, t_flags *fl, char *str)
{
	char	*tmp;
	int		len;

	v->str = !str ? ft_strdup("(null)") : ft_strdup(str);
	len = v->str ? ft_strlen(v->str) : 0;
	if ((fl->prsn >= 0 && fl->prsn < len) || v->width > 0)
	{
		str = fl->prsn > 0 ? ft_strsub(v->str, 0, fl->prsn) : ft_strdup(v->str);
		if (fl->prsn == 0)
			ft_bzero(str, ft_strlen(str));
		len = ft_strlen(str);
		v->width = v->width > len ? v->width - len : 0;
		tmp = (char *)malloc(sizeof(char) * (v->width + 1));
		tmp = set_pad(v->width, tmp, fl);
		if (fl->minus == 1)
			concat(g_buff, str, tmp, v);
		else
			concat(g_buff, tmp, str, v);
		free(str);
		free(tmp);
	}
	else if (v->str)
		concat(g_buff, v->str, NULL, v);
	free(v->str);
}

void	print_c(t_arg *var, t_flags *fl)
{
	int		len;
	char	*tmp;

	len = var->width == 0 ? 1 : var->width;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	tmp = set_pad(var->width - 1, tmp, fl);
	if (fl->minus == 1 && var->d != 0)
	{
		ft_memmove(&tmp[1], &tmp[0], var->width);
		tmp[0] = (char)var->d;
	}
	else
		tmp[len - 1] = (char)var->d;
	tmp[len] = '\0';
	buff_join(g_buff, tmp, var);
	free(tmp);
}

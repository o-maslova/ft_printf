/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:02:18 by omaslova          #+#    #+#             */
/*   Updated: 2018/08/20 12:02:23 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_pad(int width, char *buff, t_flags *fl)
{
	int i;

	i = 0;
	while (i < width)
	{
		if (fl->dot == -1 || fl->dot == 1)
			fl->nul = 0;
		if (fl->nul == 1 && fl->minus != 1)
		{
			if ((fl->plus == 1 || fl->negative == 1) && i == 0)
				buff[i++] = fl->negative == 1 ? '-' : '+';
			else if (fl->space == 1 && i == 0)
				buff[i++] = ' ';
			buff[i++] = '0';
		}
		else
			buff[i++] = ' ';
		if (fl->format == 1 && fl->nul == 1)
		{
			buff[0] = '0';
			buff[1] = 'x';
		}
	}
	buff[i] = '\0';
	return (buff);
}

char	*set_precision(int len, char *str, t_flags *fl)
{
	int		i;
	int		tmp;
	char	*buff;
	char	*tmp2;

	i = 0;
	tmp = fl->prsn > len ? fl->prsn - len : 0;
	buff = (char *)malloc(sizeof(char) * (tmp + 1));
	if (tmp || len > 1)
	{
		while (i < tmp)
			buff[i++] = '0';
		buff[i] = '\0';
		tmp2 = ft_strjoin(buff, str);
		free(buff);
		free(str);
		return (tmp2);
	}
	else
		free(str);
	return (buff);
}

char	*if_nul(t_flags *fl, char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 1;
	j = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (fl->plus == 1)
		new_str[0] = fl->negative == 1 ? '-' : '+';
	else if (fl->space == 1 && fl->negative != 1)
		new_str[0] = ' ';
	else if (fl->negative == 1)
		new_str[0] = '-';
	while (str[j] != '\0')
		new_str[i++] = str[j++];
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	*print_d(t_arg *var, t_flags *fl)
{
	char	*str;
	char	*buff;
	int		len;

	if ((fl->dot == -1 || fl->dot == 1) && fl->prsn + 1 >= var->width)
		fl->nul = 0;
	var->d = fl->negative == 1 ? -var->d : var->d;
	if (fl->negative == 1 && var->d < 0)
		str = ft_uitoa(var->u);
	else
		str = ft_itoa(var->d);
	if (fl->prsn >= 0)
		str = set_precision(ft_strlen(str), str, fl);
	if (fl->nul != 1 && (fl->negative == 1 || fl->plus == 1 || fl->space == 1))
		str = if_nul(fl, str);
	len = ft_strlen(str);
	var->width = var->width > len ? var->width - len : 0;
	buff = (char *)malloc(sizeof(char) * (var->width + 1));
	buff = set_pad(var->width, buff, fl);
	var->buff = fl->minus == 1 ? ft_strjoin(str, buff) : ft_strjoin(buff, str);
	free(buff);
	free(str);
	return (var->buff);
}

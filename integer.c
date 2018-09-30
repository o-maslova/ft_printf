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

char	*set_pad(int width, char *tmp, t_flags *fl)
{
	int i;

	i = 0;
	while (i < width)
	{
		if (fl->nul == 1 && fl->minus != 1)
		{
			if ((fl->plus == 1 || fl->negative == 1) && i == 0)
				tmp[i++] = fl->negative == 1 ? '-' : '+';
			else if (fl->space == 1 && i == 0)
				tmp[i++] = ' ';
			else
				tmp[i++] = '0';
		}
		else
			tmp[i++] = ' ';
		if (fl->format == 1 && fl->nul == 1)
		{
			tmp[0] = '0';
			tmp[1] = 'x';
		}
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*set_precision(int len, char *str, t_flags *fl)
{
	int		i;
	int		tmp;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	tmp = fl->prsn > len ? fl->prsn - len : 0;
	tmp1 = (char *)malloc(sizeof(char) * (tmp + 1));
	if (tmp || len > 1)
	{
		while (i < tmp)
			tmp1[i++] = '0';
		tmp1[i] = '\0';
		tmp2 = ft_strjoin(tmp1, str);
		free(tmp1);
		free(str);
		return (tmp2);
	}
	else
		free(str);
	return (tmp1);
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

void	print_d(t_arg *v, t_flags *fl)
{
	char	*str;
	char	*tmp;
	int		len;

	if ((fl->dot == -1 || fl->dot == 1) && fl->prsn + 1 >= v->width)
		fl->nul = 0;
	v->d = fl->negative == 1 ? -v->d : v->d;
	if (fl->negative == 1 && v->d < 0)
		str = ft_uitoa(v->d);
	else
		str = ft_itoa(v->d);
	str = fl->prsn >= 0 ? set_precision(ft_strlen(str), str, fl) : str;
	if (fl->nul != 1 && (fl->negative == 1 || fl->plus == 1 || fl->space == 1))
		str = if_nul(fl, str);
	len = ft_strlen(str);
	if (v->width < len && v->width != 0 && fl->plus == 1)
		v->width = 1;
	else
		v->width = v->width > len ? v->width - len : 0;
	tmp = (char *)malloc(sizeof(char) * (v->width + 1));
	tmp = set_pad(v->width, tmp, fl);
	fl->minus == 1 ? concat(g_buff, str, tmp, v) : concat(g_buff, tmp, str, v);
	free(tmp);
	free(str);
}

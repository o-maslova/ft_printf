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

char	*print_str(t_arg *var, t_flags *fl)
{
	char	*buff;
	int		len;

	if (!var->str)
		var->str = ft_strdup("(null)");
	len = var->str ? ft_strlen(var->str) : 0;
	if ((fl->prsn >= 0 && fl->prsn < len) || var->width > 0)
	{
		var->str = ft_strsub(var->str, 0, fl->prsn);
		len = ft_strlen(var->str);
		var->width = var->width > len ? var->width - len : 0;
		buff = (char *)malloc(sizeof(char) * (var->width + 1));
		buff = set_pad(var->width, buff, fl);
		if (fl->minus == 1)
			var->buff = ft_strjoin(var->str, buff);
		else
			var->buff = ft_strjoin(buff, var->str);
		free(var->str);
		free(buff);
	}
	else if (var->str)
		var->buff = ft_strdup(var->str);
	return (var->buff);
}

char	*print_c(t_arg *var, t_flags *fl)
{
	int len;

	len = var->width == 0 ? 1 : var->width;
	var->buff = (char *)malloc(sizeof(char) * (len + 1));
	var->buff = set_pad(var->width - 1, var->buff, fl);
	if (fl->minus == 1)
	{
		ft_memmove(&var->buff[1], &var->buff[0], var->width);
		var->buff[0] = (char)var->d;
	}
	else
		var->buff[len - 1] = (char)var->d;
	var->buff[len] = '\0';
	return (var->buff);
}

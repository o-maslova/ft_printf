/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:58:35 by omaslova          #+#    #+#             */
/*   Updated: 2018/09/01 17:58:39 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cast_d(t_arg *var, t_flags *fl)
{
	if (fl->hh == 1)
		var->d = (char)var->d;
	else if (fl->h == 1)
		var->d = (short)var->d;
	else if (fl->ll == 1)
		var->d = (long long)var->d;
	else if (fl->l == 1)
		var->d = (long)var->d;
	else if (fl->z == 1)
		var->d = (size_t)var->d;
	else if (fl->j == 1)
		var->d = var->d;
	else
		var->d = (int)var->d;
}

void	cast_o(t_arg *var, t_flags *fl)
{
	if (fl->hh == 1)
		var->u = (unsigned char)var->u;
	else if (fl->h == 1)
		var->u = (unsigned short)var->u;
	else if (fl->ll == 1)
		var->u = (unsigned long long)var->u;
	else if (fl->l == 1)
		var->u = (unsigned long)var->u;
	else if (fl->z == 1)
		var->u = (size_t)var->u;
	else if (fl->j == 1)
		var->u = var->u;
	else
		var->u = (unsigned int)var->u;
}

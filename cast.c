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

void	initialization(t_flags *flags, t_arg *var)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->hash = 0;
	flags->nul = 0;
	flags->space = 0;
	flags->negative = 0;
	flags->prsn = -1;
	flags->dot = 0;
	flags->format = 0;
	flags->astr = 0;
	flags->hh = 0;
	flags->h = 0;
	flags->ll = 0;
	flags->l = 0;
	flags->j = 0;
	var->str = NULL;
	var->nul = 0;
}

void	cast_d(t_arg *var, t_flags *fl)
{
	if (fl->hh == 1 && var->t != 'D')
		var->d = (char)var->d;
	else if (fl->h == 1 && var->t != 'D')
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
	if (fl->hh == 1 && var->t != 'O')
		var->u = (unsigned char)var->u;
	else if (fl->h == 1 && var->t != 'O')
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

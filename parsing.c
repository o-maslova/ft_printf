/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:50:43 by omaslova          #+#    #+#             */
/*   Updated: 2018/08/29 15:50:46 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*initialization(t_flags *flags)
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
	return (flags);
}

void	define_flag(char *str, t_flags *var, int lim)
{
	int i;

	i = -1;
	while (++i < lim && *str)
	{
		if (str[i] == '-')
			var->minus = 1;
		if (str[i] == '+')
			var->plus = 1;
		if (str[i] == '0')
			if (str[i - 1] < '1' || str[i - 1] > '9')
				var->nul = 1;
		if (str[i] == '#')
			var->hash = 1;
		if (str[i] == ' ')
			var->space = 1;
		if (str[i] == '*')
			var->astr = 1;
		if (str[i] == '.')
		{
			var->dot = str[i + 1] == '*' ? 1 : -1;
			var->prsn = ft_atoi(&str[++i]);
		}
	}
}

void		modificator_check(char *str, t_flags *fl, int lim)
{
	int i;

	i = 0;
	while (i < lim)
	{
		if (str[i] == 'h')
		{
			if (str[i + 1] == 'h')
				fl->hh = 1;
			fl->h = 1;
		}
		if (str[i] == 'l')
		{
			if (str[i + 1] == 'l')
				fl->ll = 1;
			fl->l = 1;
		}
		fl->j = str[i] == 'j' ? 1 : 0;
		fl->z = str[i] == 'z' ? 1 : 0;
		i++;
	}
}

int		define_operator(char *str, t_arg *var, t_flags *flags)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[i] != 's' && str[i] != 'c' && str[i] != 'd' && str[i] != 'e'
			&& str[i] != 'i' && str[i] != 'u' && str[i] != 'U' && str[i] != 'o'
			&& str[i] != 'O' && str[i] != 'x' && str[i] != 'X' && str[i] != 'S'
			&& str[i] != 'p' && str[i] != 'D' && str[i] != 'C' && str[i] != '%'
			&& str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n' || !str[i])
		return (0);
	tmp = ft_strsub(str, 0, i);
	modificator_check(tmp, flags, i);
	define_flag(str, flags, i);
	while (str[j] == '#' || str[j] == '-' || str[j] == '+' || str[j] == '0')
		j++;
	var->width = ft_atoi(&str[j]);
	var->width = var->width < 0 ? -var->width : var->width;
	if (str[i])
		var->type = str[i];
	free(tmp);
	return (++i);
}

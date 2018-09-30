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
			var->astr = (ft_strchr("123456789", str[i + 1])) ? -1 : 1;
		if (str[i] == '.')
		{
			var->dot = str[i + 1] == '*' ? 1 : -1;
			var->prsn = ft_atoi(&str[++i]);
		}
	}
}

int		check(char *str, int lim)
{
	int check;
	int j;

	check = 0;
	j = 0;
	while (j < lim)
	{
		if (ft_strchr("0123456789hljz#+-.*", str[j]))
			return (1);
		if (str[j] == ' ' && str[j + 1] == '\0')
			return (1);
		else if (str[j] == ' ' && lim == 1)
			return (1);
		if (str[j] == ' ')
			check++;
		j++;
	}
	if (check == lim)
		return (1);
	return (0);
}

void	modificator_check(char *str, t_flags *fl, int lim)
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

int		define_continue(t_arg *v, int i, char *str, char *trash)
{
	char *tmp;
	char *ptr;

	if (!ft_strchr("sSpdDioOuUxXcC%", v->t))
	{
		if (v->width > 0)
			v->str = ft_strdup(&str[i]);
		else
			v->str = ft_strsub(&str[i], 0, i);
		ptr = ft_strchr(v->str, '}');
		tmp = ptr ? ptr : ft_strchr(v->str, '\n');
		i = tmp - v->str <= 1 ? i : tmp - v->str;
	}
	free(trash);
	return (i);
}

int		define_operator(char *str, t_arg *v, t_flags *flags)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while ((!ft_isalpha(str[i]) || str[i] == 'h' || str[i] == 'l' ||
			str[i] == 'j' || str[i] == 'z') && str[i] != '\0' && str[i] != '%')
		i++;
	if ((i > 0 && str[i] != '%' && !check(str, i)) || !str)
		return (0);
	tmp = ft_strsub(str, 0, i);
	if (*tmp == '\0' && *str == '\0')
	{
		free(tmp);
		return (0);
	}
	modificator_check(tmp, flags, i);
	define_flag(str, flags, i);
	while (ft_strchr("#-+0*", str[j]))
		j++;
	v->width = ft_atoi(&str[j]);
	v->t = str[i] ? str[i] : 0;
	i = define_continue(v, i, str, tmp);
	return (++i);
}

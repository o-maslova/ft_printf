/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:27:22 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/10 17:40:06 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int				sign;
	long long		nb;

	nb = 0;
	sign = 0;
	while (*str == 32 || *str == '\t' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 + *str++ - 48;
	return (sign ? -nb : nb);
}

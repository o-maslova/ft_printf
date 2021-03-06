/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:28:59 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/10 17:01:38 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb == -2147483648)
	{
		nb = nb % 1000000000;
		nb = -nb;
		ft_putchar('-');
		ft_putchar('2');
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

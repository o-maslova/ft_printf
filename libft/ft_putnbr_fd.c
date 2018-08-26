/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:22:01 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/10 19:05:41 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd)
	{
		if (n < 0 && n != -2147483648)
		{
			n = -n;
			ft_putchar_fd('-', fd);
		}
		if (n == -2147483648)
		{
			n = n % 1000000000;
			n = -n;
			ft_putchar_fd('-', fd);
			ft_putchar_fd('2', fd);
		}
		if (n < 10)
			ft_putchar_fd((n + '0'), fd);
		else
		{
			ft_putnbr_fd((n / 10), fd);
			ft_putchar_fd((n % 10 + '0'), fd);
		}
	}
}

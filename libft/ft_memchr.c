/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:55:33 by omaslova          #+#    #+#             */
/*   Updated: 2018/03/29 19:13:13 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	symbol;
	size_t			i;

	i = 0;
	symbol = (unsigned char)c;
	while (i < n)
	{
		if (*((unsigned char*)s) == symbol)
			return ((unsigned char*)s);
		s++;
		i++;
	}
	return (0);
}

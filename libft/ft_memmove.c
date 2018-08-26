/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:47:01 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/02 17:18:21 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	i = 0;
	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (source > dest)
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			dest[len - 1] = source[len - 1];
			len--;
		}
	}
	return ((unsigned char*)dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:06:55 by omaslova          #+#    #+#             */
/*   Updated: 2018/03/30 12:56:02 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char*)src;
	s2 = (unsigned char*)dst;
	while (i < n)
	{
		s2[i] = s1[i];
		if (s1[i] == (unsigned char)c)
			return (s2 + i + 1);
		i++;
	}
	return (NULL);
}

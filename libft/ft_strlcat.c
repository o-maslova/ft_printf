/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:25:19 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/12 16:02:19 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	buffer;
	size_t	sum;

	i = 0;
	if (!dst && !src)
		return (0);
	sum = ft_strlen(dst) + ft_strlen(src);
	d_len = ft_strlen(dst);
	if ((d_len > (dstsize - 1)) || dstsize == 0)
		return (dstsize + ft_strlen(src));
	buffer = dstsize - 1;
	j = d_len;
	while (buffer > d_len && src[i] != '\0')
	{
		dst[j++] = src[i++];
		buffer--;
	}
	dst[j] = '\0';
	return (sum);
}

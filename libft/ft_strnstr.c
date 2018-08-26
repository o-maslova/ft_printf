/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:18:30 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/13 11:06:13 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	k = 0;
	if (*needle == '\0' || haystack == needle)
		return ((char*)haystack);
	while (needle[i] != '\0')
		i++;
	while (haystack[k] != '\0' && k < len)
	{
		j = 0;
		while (haystack[k + j] != '\0' && haystack[k + j] == needle[j] && \
		k + j < len)
			j++;
		if (j == i)
			return ((char*)&haystack[k]);
		k++;
	}
	return (NULL);
}

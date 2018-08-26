/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:24:45 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/13 11:06:55 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	else if (haystack == needle)
		return ((char*)haystack);
	while (needle[i] != '\0')
		i++;
	while (haystack[k] != '\0')
	{
		j = 0;
		while (haystack[k + j] && needle[j] != '\0' && \
		haystack[k + j] == needle[j])
			j++;
		if (j == i)
			return ((char*)&haystack[k]);
		k++;
	}
	return (0);
}

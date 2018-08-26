/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:35:01 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/03 19:56:59 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	i = 0;
	s_len = 0;
	str = NULL;
	if (s)
	{
		s_len = ft_strlen(s);
		if ((str = (char *)malloc(sizeof(char) * (len + 1))))
		{
			while (i < len && s[start] != '\0')
			{
				str[i] = s[start];
				start++;
				i++;
			}
			str[i] = '\0';
		}
	}
	return (str);
}

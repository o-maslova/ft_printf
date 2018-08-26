/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:14:53 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/03 17:24:59 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	str = NULL;
	if (s)
	{
		len = ft_strlen(s);
		if ((str = (char *)malloc(sizeof(char) * (len + 1))))
		{
			while (i < len)
			{
				str[i] = f(i, s[i]);
				i++;
			}
			str[i] = '\0';
		}
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:54:18 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/03 17:14:27 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;
	size_t	len;

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
				str[i] = f(s[i]);
				i++;
			}
			str[i] = '\0';
		}
	}
	return (str);
}

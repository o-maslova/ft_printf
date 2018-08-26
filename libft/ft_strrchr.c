/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 11:56:52 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/12 14:01:44 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int check;
	int i;

	i = 0;
	check = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char*)&s[i]);
		i--;
	}
	if ((char)c == '\0' && s[i] == '\0')
		return ((char*)&s[i]);
	return (NULL);
}

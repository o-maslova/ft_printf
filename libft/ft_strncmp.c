/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:39:42 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/11 14:46:51 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && i < n - 1)
		{
			s1++;
			s2++;
			i++;
		}
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

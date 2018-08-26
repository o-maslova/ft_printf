/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:48:54 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/11 14:20:49 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	int		check;

	i = 0;
	check = 0;
	if (!s1 || !s2)
		return (0);
	if (s1 == s2 || n == 0)
		return (1);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i] && i < n)
		{
			check = 1;
			i++;
		}
		else if (i >= n)
			break ;
		else
		{
			check = 0;
			break ;
		}
	}
	return (check);
}

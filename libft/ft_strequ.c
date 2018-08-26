/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:25:34 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/11 12:31:44 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int check;

	check = 0;
	if (s1 && s2)
	{
		if (s1 == s2)
			return (1);
		while (*s1 != '\0' || *s2 != '\0')
		{
			if (*s1 == *s2)
			{
				s1++;
				s2++;
				check = 1;
			}
			else
			{
				check = 0;
				break ;
			}
		}
	}
	return (check);
}

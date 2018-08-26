/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:06:23 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/03 14:54:56 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if ((str = (char *)malloc(sizeof(char) * size)))
	{
		while (i <= size)
		{
			str[i] = 0;
			i++;
		}
	}
	return (str);
}

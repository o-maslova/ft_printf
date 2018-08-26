/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:09:19 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/03 15:12:35 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	str = NULL;
	i = 0;
	if ((str = (char *)malloc(sizeof(char) * (size + 1))))
	{
		while (i <= size)
			str[i++] = '\0';
	}
	return (str);
}

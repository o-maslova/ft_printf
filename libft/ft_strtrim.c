/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:09:21 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/11 12:31:13 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (len > 0 && (s[len] == 32 || s[len] == '\n' || s[len] == '\t'))
		len--;
	while ((*s == 32 || *s == '\n' || *s == '\t') && len >= 0)
	{
		s++;
		len--;
	}
	len += 1;
	return (ft_strsub(s, 0, len));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:15:06 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/13 12:02:07 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	num;
	size_t	i;

	i = 0;
	num = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		num++;
	}
	return (num);
}

static size_t	count_letters(char const *s, char c)
{
	size_t	let_num;
	size_t	i;

	i = 0;
	let_num = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		let_num++;
	}
	return (let_num);
}

static t_list	*node_fulling(char const *s, size_t num)
{
	size_t	i;
	size_t	len;
	t_list	*list;
	char	*word;

	i = 0;
	word = NULL;
	if (!(word = (char *)malloc(sizeof(char) * (num + 1))))
		return (NULL);
	while (i < num)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	len = ft_strlen(word) + 1;
	if (!(list = ft_lstnew(word, len)))
		return (NULL);
	return (list);
}

t_list			*ft_lst_split(char const *s, char c)
{
	size_t	num_w;
	size_t	num_l;
	size_t	i;
	t_list	*list;

	i = 0;
	list = NULL;
	if (!s)
		return (NULL);
	num_w = count_words(s, c);
	while (i < num_w)
	{
		while (*s == c)
			s++;
		num_l = count_letters(s, c);
		if (!(ft_lst_push_back(&list, node_fulling(s, num_l))))
			return (NULL);
		s += num_l;
		i++;
	}
	return (list);
}

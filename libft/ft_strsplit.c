/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:22:29 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/10 17:41:50 by omaslova         ###   ########.fr       */
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

static void		arr_fulling(char const *s, char *word, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	size_t	num_w;
	size_t	num_l;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	num_w = count_words(s, c);
	if (!(words = (char **)malloc(sizeof(char *) * (num_w + 1))))
		return (NULL);
	while (i < num_w)
	{
		while (*s == c)
			s++;
		num_l = count_letters(s, c);
		if (!(words[i] = (char *)malloc(sizeof(char) * (num_l + 1))))
			return (NULL);
		arr_fulling(s, words[i], num_l);
		s += num_l;
		i++;
	}
	words[i] = 0;
	return (words);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:47:16 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/13 11:12:24 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_push_back(t_list **alst, t_list *new)
{
	t_list	*lst;
	t_list	*tmp;

	lst = NULL;
	if (!(*alst))
		*alst = new;
	else
	{
		lst = *alst;
		while (lst->next)
			lst = lst->next;
		if (!(tmp = (t_list *)malloc(sizeof(t_list))))
			return (0);
		if (!(tmp->content = malloc(sizeof(*(new->content)) * \
		new->content_size)))
			return (0);
		ft_memcpy(tmp->content, new->content, new->content_size);
		tmp->content_size = new->content_size;
		tmp->next = NULL;
		lst->next = tmp;
	}
	return (1);
}

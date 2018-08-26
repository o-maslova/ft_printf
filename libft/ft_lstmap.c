/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:57:07 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/13 11:12:43 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*elem;

	tmp = NULL;
	tmp2 = NULL;
	elem = NULL;
	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			if (!(ft_lst_push_back(&tmp2, f(tmp))))
				return (NULL);
			tmp = tmp->next;
		}
	}
	return (tmp2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:06:09 by omaslova          #+#    #+#             */
/*   Updated: 2018/04/13 13:07:52 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_swap(t_list **first, t_list **second)
{
	t_list *tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

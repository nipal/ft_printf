/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 07:42:13 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/07 07:48:58 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void				ft_lstadd(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}


void				ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*node;

	if (!(node = *alst))
	{
		*alst = new;
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = new;
}

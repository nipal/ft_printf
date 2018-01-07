/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 07:51:02 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/07 07:55:34 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*beg;
	t_list	*node;

	beg = NULL;
	while (lst)
	{
		node = f(lst);
		ft_lstadd_back(&beg, node);
		lst = lst->next;
	}
	return (beg);
}

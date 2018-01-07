/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 08:01:46 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/07 08:07:01 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void				ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;

	node = *alst;
	while (node)
	{
		ft_lstdelone(&(node->next), del);
	}
}

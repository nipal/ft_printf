/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 07:04:38 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/21 08:25:59 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# define SIZE_BUFF	128 // + 1 |--> '\0'

typedef	struct	s_buff
{
	char	buffer[SIZE_BUFF + 1];
	int		id;
}				t_buff;

//static	int		push_buffer(t_list *begin, int *nb_buffer, t_buff *buf)
//{
//	t_list	*node;
//	int		size;
//	int		nb_buff;
//
//	nb_buff = *nb_buffer;
//	*nb_buffer = 0;
//	size = (nb_buff * SIZE_BUFF) + buf->id;
//	if (!(str = malloc((size + 1) * sizeof(char))))
//		return (-1);
//	ft_memmove(str + nb_buff * SIZE_BUFF, buf->buffer, buf->id);
//	node = begin;
//	while (nb_buff && node)
//	{
//		ft_memmove(str + nb_buff * SIZE_BUFF, node->content, SIZE_BUFF);
//		node = node->next;
//		nb_buff--;
//	}
//	write(fd, str, size);
//	ft_lstdel(&begin);
//	buf->id = 0;
//	return (size);
//}
//
//int		buffer(char *str, int size, int fd)
//{
//	static	t_list	*begin = NULL;
//	static	t_buff	buf = {"", 0};
//	static	int		nb_buff = 0;
//	char			*str;
//
//	if (!str)
//		return (push_buffer(begin, nb_buff, &buf));
//	while (size > 0)
//	{
//		if ((SIZE_BUFF - buf.id) > size)
//		{
//			buf.id += size;
//			ft_memmove(buf.buffer + buf.id, str, size);
//			size = 0;
//			continue ;
//		}
//		size -= SIZE_BUFF - buf.id;
//		ft_memmove(buf.buffer + buf.id, str, SIZE_BUFF - buf.id);
//		ft_lstadd(&begin, ft_lstnew(buf.buffer, buf.id));
//		buf.id = 0;
//		nb_buff++;
//	}
//	return (0);
//}
//
//	la meme pour les floatant?
//
//
		// on ecrit dans buf
		// si il est plein on le push
		// si str n'est pas vide on recomence

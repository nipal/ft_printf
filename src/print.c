/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:03:13 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/31 22:21:41 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ///////////////////////////////////////////////////////
*/

void			buffer_init(t_buffer *b)
{
	b->current = &(b->beg);
	b->beg.id = 0;
	b->beg.next = NULL;
	b->block_nb = 1;
}

static	void	buffer_node_add(t_buffer *b)
{
	t_buf	*node;

	if (!(node = malloc(sizeof(t_buf))))
		return ((void)dprintf(2, "t_buf alloc faille: %s : %d\n",
					__FILE__, __LINE__ - 1));
	node->id = 0;
	node->next = NULL;
	node->data[0] = '\0';
	bzero(node->data, sizeof(node->data));
	if (b->current)
		b->current->next = node;
	b->current = node;
	b->block_nb++;
}


void			buffer_push_data(t_buffer *b, char *data, int size)
{
	int		rest;
	int		jump;
	t_buf	*buf;

	buf = b->current;
	while (size > 0)
	{
		rest = (BUFF_LARGE - buf->id);
		jump = (rest >= size) ? size : rest;
		memmove(buf->data + buf->id, data, jump);
		buf->id += jump;
		data += jump;
		if (rest < size)
		{
			buffer_node_add(b);
			buf = b->current;
		}
		size -= jump;
	}
}

void			buffer_push_nchar(t_buffer *b, char c, int nb)
{
	int		rest;
	int		jump;
	t_buf	*buf;

	buf = b->current;
	while (nb > 0)
	{
		rest = (BUFF_LARGE - buf->id);
		jump = (rest >= nb) ? nb : rest;
		memset(buf->data + buf->id, c, jump);
		buf->id += jump;
		if (rest < nb)
		{
			buffer_node_add(b);
			buf = b->current;
		}
		nb -= jump;
	}
}

//	Il vaudrait mieux les vide tous sauf le premier...
//	En fait on connaitra tout le temps le premier
static	void	buffer_reset(t_buffer *b)
{
	t_buf	*node;
	t_buf	*tmp;

	node = b->beg.next;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	buffer_init(b);
}

/*
**	///////////////////////////////////////////////////////
*/


void			buffer_output_fd(t_buffer *b, int fd)
{
	t_buf	*node;

	node = &(b->beg);
	while (node)
	{
		write(fd, node->data, node->id);
		node = node->next;
	}
	buffer_reset(b);
}

void	buffer_output_standar(t_buffer *b)
{
	buffer_output_fd(b, 0);
	buffer_reset(b);
}

void			buffer_output_string(t_buffer *b, char *dest)
{
	t_buf	*node;
	int	i;

	i  = 0;
	node = &(b->beg);
	while (node)
	{
		memmove(dest + i * BUFF_LARGE, node->data, node->id);
		node = node->next;
		i++;
	}
	dest[i * BUFF_LARGE] = '\0';
	buffer_reset(b);
}

void			buffer_output_string_size(t_buffer *b, char *dest, int len)
{
	int		id;
	int		size;
	t_buf	*node;

	id = 0;
	node = &(b->beg);
	while (node && len > 0)
	{
		size = ((len - BUFF_LARGE) < 0) ? len : BUFF_LARGE;
		memmove(dest + id, node->data, size);
		node = node->next;
		id += BUFF_LARGE;
		len -= BUFF_LARGE;
	}
	dest[id - BUFF_LARGE + size] = '\0';
	buffer_reset(b);
}

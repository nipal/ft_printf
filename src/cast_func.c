/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 03:03:45 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/06 07:37:19 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	caste_s1(t_type *type)
{
	t_type	tmp;

	tmp->ld = 0;
	tmp->c = type.c;
	*type = tmp;
}


void	caste_u1(t_type *type)
{
	t_type	tmp;

	tmp->ld = 0;

	tmp->uc = type->uc;
	*type = tmp;
}


void	caste_s2(t_type *type)
{
	t_type	tmp;

	tmp->ld = 0;
	tmp->s = type->s;
	*type = tmp;
}


void	caste_u2(t_type *type)
{
	t_type	tmp;

	tmp->ld = 0;
	tmp->us = type->us;
	*type = tmp;
}


void	caste_s4(t_type *type)
{
	t_type	tmp;

	tmp->ld = 0;
	tmp->i = type->i;
	*type = tmp;
}


void	caste_u4(t_type *type)
{
	t_type	tmp;

	tmp->ld = 0;
	tmp->ui = type->ui;
	*type = tmp;
}


void	caste_s8(t_type *type)
{
	t_type	tmp;

	tmp->ld = 0;
	tmp->l = type->l;
	*type = tmp;
}


void	caste_u8(t_type *type)
{
	t_type	tmp;

	tmp->ld = 0;
	tmp->ul = type->ul;
	*type = tmp;
}

void	caste_nothing(t_type *type)
{
	(void)type;
}


void	init_caste_func(void (*f[10])(t_type *var))
{
	f[0b0000] = caste_s4;
	f[0b0001] = caste_u4;
	f[0b0010] = caste_s1;
	f[0b0011] = caste_u1;
	f[0b0100] = caste_s2;
	f[0b0101] = caste_u2;
	f[0b0110] = caste_nothing;
	f[0b0111] = caste_nothing;
	f[0b1000] = caste_s8;
	f[0b1001] = caste_u8;
}

// il faudra appliquer cette fonction uniquement pour des type entier
// la fonction est proteger des overflow et autre valeur no desirable
void	integer_apply_caste(t_fparam *p, t_type *var)
{
	static	void	(*f[10])(t_type *var);
	static	int		init = 1;
	int				id;

	if (init)
	{
		init = 0;
		init_caste_func(f);
	}
	if ((id = p->state >> e_id_size_caste) >= 0 && id < 10)
		f[id](var);
}


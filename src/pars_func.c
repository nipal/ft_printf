/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 21:49:45 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/07 06:04:06 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"


/*
(char **prev_hard, char *now, t_fparam *p)

	e_flag_plus		= 1l << 8,
	e_flag_minus	= 1l << 9,
	e_flag_space	= 1l << 10,
	e_flag_zero		= 1l << 11,
	e_flag_lang_nb	= 1l << 12,
	e_flag_sparate	= 1l << 13,
	e_flag_hash		= 1l <<	14,
*/

//	== flag ==
char	*flag_add_plus(char *now, t_fparam *p)
{
	 (void)now; (void)p;

	p->state |= e_flag_plus;
	return (now + 1);
}


char	*flag_add_minus(char *now, t_fparam *p)
{
	 (void)now; (void)p;
	p->state |= e_flag_minus;
	return (now + 1);
}

char	*flag_add_space(char *now, t_fparam *p)
{
	 (void)now; (void)p;
	p->state |= e_flag_space;
	return (now + 1);
}

char	*flag_add_zero(char *now, t_fparam *p)
{
	 (void)now; (void)p;
	p->state |= e_flag_zero;
	return (now + 1);
}

char	*flag_add_lang_nb(char *now, t_fparam *p)
{
	 (void)now; (void)p;
	p->state |= e_flag_lang_nb;
	return (now + 1);
}

char	*flag_add_separate(char *now, t_fparam *p)
{
	 (void)now; (void)p;
	p->state |= e_flag_sparate;
	return (now + 1);
}

char	*flag_add_hash(char *now, t_fparam *p)
{
	 (void)now; (void)p;
	p->state |= e_flag_hash;
	return (now + 1);
}

//	================================
//	========== type caste ==========
//	================================

// TODO: un tableu de fonction pour caster la valeur comme il faut
// 		On va faire ca avec le type multi-type

char	*flag_set_size_unsigned(char *now, t_fparam *p)
{
	 (void)now; (void)p;
	p->state |= e_is_unsigned;	// on offset un nombre les bit d'a[res sont reserver
	return (now + 1);
}


char	*flag_set_cast_s1(char *now, t_fparam *p)
{
	if (((p->state >> e_id_size_caste) & 0xF) < 1)
	{
		p->state &= ~(0xFl << e_id_size_caste);
		p->state |= e_size_define |  1l << e_id_size_caste;	
	}
	return (now + 1);
}

char	*flag_set_cast_s2(char *now, t_fparam *p)
{
	
	if (now[1] != 'h')
	{
		if (((p->state >> e_id_size_caste) & 0xF) < 2)
		{
			p->state &= ~(0xFl << e_id_size_caste);
			p->state |= e_size_define | 2l << e_id_size_caste;
		}
		return (now + 1);
	}
	return (flag_set_cast_s1(now + 1, p));
}

char	*flag_set_cast_s4(char *now, t_fparam *p)
{
	
	if (((p->state >> e_id_size_caste) & 0xF) < 4)
	{
		p->state &= ~(0xFl << e_id_size_caste);
		p->state |= e_size_define | 4l << e_id_size_caste;
	}
	return (now + 1);
}

char	*flag_set_cast_s8(char *now, t_fparam *p)
{
	
	if (((p->state >> e_id_size_caste) & 0xF) < 8)
	{
		p->state &= ~(0xFl << e_id_size_caste);
		p->state |= e_size_define | 8l << e_id_size_caste;	
	}

	if (now[1] != 'l')
		return (now + 2);
	return (now + 1);
	
}


char	*flag_set_cast_u1(char *now, t_fparam *p)
{
	
	if (((p->state >> e_id_size_caste) & 0xF) < 2)
	{
		p->state &= ~(0xFl << e_id_size_caste);
	p->state = e_size_define | e_is_unsigned | (p->state & ~(0xFl << e_id_size_caste)) | 1l << e_id_size_caste;	// on offset un nombre les bit d'a[res sont reserver
	}
	return (now + 1);
}

char	*flag_set_cast_u2(char *now, t_fparam *p)
{
	
	if (((p->state >> e_id_size_caste) & 0xF) < 2)
	{
		p->state &= ~(0xFl << e_id_size_caste);
		p->state |= e_size_define | e_is_unsigned | (2l << e_id_size_caste);	// on offset un nombre les bit d'a[res sont reserver
	}
	return (now + 1);
}

char	*flag_set_cast_u4(char *now, t_fparam *p)
{
	
	if (((p->state >> e_id_size_caste) & 0xF) < 4)
	{
		p->state &= ~(0xFl << e_id_size_caste);
		p->state |= e_size_define | e_is_unsigned | (4l << e_id_size_caste);	// on offset un nombre les bit d'a[res sont reserver
	}
	return (now + 1);
}

char	*flag_set_cast_u8(char *now, t_fparam *p)
{
	
	if (((p->state >> e_id_size_caste) & 0xF) < 8)
	{
		p->state &= ~(0xFl << e_id_size_caste);
		p->state |= e_size_define | e_is_unsigned | (8l << e_id_size_caste);	// on offset un nombre les bit d'a[res sont reserver
	}

	return (now + 1);
}

char	*flag_set_long_double(char *now, t_fparam *p)
{
	
	p->state |= e_cast_long_double;
	return (now + 1);
}

//		h
//		l
//		L
//		z
//		j
//		t

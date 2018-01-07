/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 07:35:16 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/07 03:26:08 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_number(char *format, int *number)
{
	int 	nb;
	char	c;

	nb = 0;
	while ((c = *(format++)) >= '0' && c <= '9' )
		nb = nb * 10 + (c - '0');
	*number = nb;
	return (format);
}

// min size
// 		adrr
// precision
// 		adrr

char	*set_senario_star(char **prev_hard, char *now, t_fparam *p)
{
	(void)prev_hard;
	char	*beg;
	int		number;

	beg = ++now;
	p->state &= ~(e_has_min_width_next_arg | e_has_min_width_arg) // efface les trace au cas ou
	p->state |= e_has_min_width;
	if (*now >= '0' && *now <= '9')
	{
		now = get_number(now, &number);
		if (*now == '$')
		{
			p->state |= e_has_min_width_arg;
			p->id_width = number;
			return (now + 1);
		}
	}
	p->state |= e_has_min_width_next_arg;
	return (beg);
}

//	is 	 nbr
//	w
//	is 	 *[nbr,$]   --> else PARSE_BACK
//	else PARSE_ERROR

char	*set_senario_point(char **prev_hard, char *now, t_fparam *p)
{
	int				number;
	char		c;
	char		*beg;

	e->state |= e_has_precision;
	p->state &= ~(e_has_precision_next_arg | e_has_precision_arg)
	if ((c = *now) >= '0' && c <= '9')
		return (get_number(now, &number));
	else if (c == '*')
	{
		beg = now;
		if (((c = *now) >= '0') && c <= '9')
		{
			if (*(now = get_number(now, &number)) == '$')
			{
				p->id_preci = number;
				p->state |= e_has_precision_arg;
				return (now + 1);
			}
		}
		p->state |= e_has_precision_next_arg;
		return (beg);
	}
	return (set_parse_error(prev_hard, now, p));
}

char	*set_senario_nbr(char **prev_hard, char *now, t_fparam *p)
{
	int		number;
	char	*beg;

	(void)prev_hard;
	beg = now;
	if (*(now = get_number(now, &number)) == '$')
	{
		e->state |= e_has_value_arg;
		e->id_width = number;
		return (now + 1);
	}
	e->state |= e_has_min_width;
	e->width = number;
	return (beg);
}

// =========================================================================
//	Possible chaine		: precision, min_siz, id_arg
// -------------------------------------------------------------------------
//						| ------------------ |
// 	nbr					|					 | is min_size
// 	*,					|-> define size min	 | next_arg is min_size		(int)
// 	*,(nbr,$)			| 					 | is id_arg minsize 		(int)
//						| ------------------ |

//						| ------------------ |
// 	nbr,$				|->    arg value     | is id_arg of value
//						| ------------------ |

//						| ------------------ |
// '.',nbr				|					 | is precision
// '.',*				|-> define size min	 | next_arg is precision	(int)
// '.',(*,nbr,$)		| 					 | is id_arg precisione 	(int)
//						| ------------------ |
// =========================================================================
//

// =========================================================================
//	first input:			|output|
// -------------------------------------------------------------------------
//		.				| precision, arg_id preci , BACK_PARSING, PARSE_ERROR
//		*				| min_width, arg_id min_width, BACK_PARSING, 
//		nbr				| min_width, arg_id value, 
// -------------------------------------------------------------------------
//
//	min_width			--> la valeur de "min_width"
//	precision			--> la valeur de "precision"
//	arg_id min_width	--> "min_width" est le Keme argumet
//	arg_id precision	--> "precision" est le Keme argumet
//	arg_id value		--> "value" est le Keme argumet
//	BACK_PARSING		--> l'enchainement en incomplet  de token il faut con siderer une partie autrement
//	PARSE_ERROR			--> il y a un enchainement illegale de token
// =========================================================================



// =========================================================================
// =========================================================================


//typedef	struct	s_fparam
//{
//	long	state;			// la ou toute les option sont determiner
//	int		id_width;
//	int		id_preci;
//	int		id_arg;
//
//	int		width;			// l'entier qui corespond a la taille minimum, neg si addr
//	int		precision;		// l'entier qui corespond a la precision, neg si addr
//	t_type	arg;			// la valeur de l'argument a traiter et sont type
//}				t_fparam;
//
//

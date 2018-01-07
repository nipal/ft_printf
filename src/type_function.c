/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 05:40:08 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/07 07:30:18 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// une fonction qui va un peu orchestrer l'evenement

char	*print_unsigned_decimal(char *now, t_fparam *p)
{
	(void)p;
	//	la chaine de nombre brute
	//	min_size/precision
	//	remplissage
	//
	//	push du mallion
	//	reinitialisation pour le prochain
	return (now);
}


#define BUFF_SIZ 128
char	*parse_signed_decimal(char *now, t_fparam *p)
{
	(void)p;
	//	push le parametre
	return (now);
}


/*
	static	char	buf[BUFF_SIZ];
	static	int		size = 0;
	char			fill;

	symbole_base1(SYM_MIN);								// mais c'est optionel pck osef dela base au dela de 10
	size = put_integer_s(p->arg.l, 10, buf, BUFF_SIZ);	//	la chaine de nombre brute	
	//	remplissage
	if (p->state & (e_has_min_width | e_has_precision))
	{
		//	min_size/precision
	}
	//
	//	push du mallion
	//	reinitialisation pour le prochain
*/

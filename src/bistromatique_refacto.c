/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatique_refacto.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:55:35 by fjanoty           #+#    #+#             */
/*   Updated: 2018/02/09 22:20:02 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatique.h"

//	On va recopier ici des fonciton en le mettqnt a propre
//	Ca sera plus simple d'avoir les fonction similaire cote a cote
//	En implementant toute les fonctionalite, donc la virgule et tout
//	Et si possible en 

void	bistro_copie(t_bistro *from, t_bistro *to)
{
	memmove(to->number, from->number, from->block_max * sizeof(from->number[0]));
	to->block_max = from->block_max;
	to->sign = from->sign;
	to->cote = from->coma;
}

void	bistro_add_minimal_in(t_bistro *a, t_bistro *b, t_bistro *result)
{
	int		i;
	int		max;
	long	tmp;
	long	ret;
	int		block_min;

	block_min = 0;
	i = 0;
	ret = 0;
	max = 1 + ((a->block_max > b->block_max) ? a->block_max : b->block_max);
	while (i < max)
	{
		tmp = a->number[i] + b->number[i] + ret;
		ret = tmp / BISTRO_UNITE;
		result->number[i] = tmp % BISTRO_UNITE;
		i++;
	}
	if (i < max && ret)
		result->number[i] = ret;
	result->block_max = max + (i < max && ret);
	// il faudra rajouter la position de la virgule
}

/*
	Est-ce que c'est necessaire d'ajuster les nombre de block si on pratique la
	baisse de precision. Par exemple si on n'elague pas les n premiere variable
	on peut economiser des calcule.
	MAIS ca ne sera rentable que si e coup de la varification d'optimisation
	ne sois pas plus lourde que les cas ou on benefissie d'optimisation
*/

void	bistro_sub_minimal_in(t_bistro *a, t_bistro *b, t_bistro *result)
{
	(void)a;(void)b;(void)result;
	int		i;
	int		max;
	long	tmp;
	long	add;
	long	ret;
	int		last_used;

	i = 0;
	max = a->block_max;
	ret = 0;
	last_used = 0;
	while (i < max)
	{
		tmp = a->number[i] - (b->number[i] + ret);
		add = (((-tmp / BISTRO_UNITE) + 1) * BISTRO_UNITE);
		ret = (tmp < 0) ? add : 0;
		result->number[i] = (((tmp < 0) * add) + tmp) % BISTRO_UNITE;
		if (result->number[i])
			last_used = i;
		i++;
	}
	result->block_max = last_used;
	// il faudra rajouter la position de la virgule
}

/*
** louncher contexte
** 		CONDITION
** 		STACK ORDER
** 		LOUNCH FUNC
** 		SET SIGN
**---------
**	On pourrait stoquer des valeur en mode boolean dans un long
**	et donc economiser plein de fonction, Pour acceder a la valeur on peu:
**			- un define (rapide) --> on rajoute le bit de signe
**			- une enume (+formel, compile_time)
*/

void	bistro_add_in(t_bistro *a, t_bistro *b, t_bistro *result)
{
	char			sign_eq;
	int				arg1_is_a;
	int				func_is_add;
	int				sign_is_pos;
	t_bistro_sa		arg;
	void			(*f)(t_bistro *a, t_bistro *b, t_bistro *result);

	sign_eq = !((a.sign ^ b.sign) & (1l << ((sizeof(a.sign) * 8) - 1)));
	arg1_is_a = (sign_eq || bistro_is_sup(a, b));
	sign_is_pos = (!sign_eq && ((a.sign > 0) ^ (bistro_is_sup_eq(b, a))))
				|| (a.sign > 0 && b.sign > 0);

	f = (func_is_add) ? bistro_add_minimal_in : bistro_sub_minimal_in;
	arg = (arg1_is_a) ? (t_bistro_sa){a, b} : (t_bistro_sa){b, a};
	f(arg.v1, arg.v2, result);
	result.sign = (sign_is_pos) ? 1 : -1;
}

void	bistro_sub_in(t_bistro *a, t_bistro *b, t_bistro *result)
{
	char			tmp;
	char			sign_eq;
	int				arg1_is_a;
	int				func_is_sub;
	int				sign_is_neg;
	t_bistro_sa		arg;
	void			(*f)(t_bistro *a, t_bistro *b, t_bistro *result);

	tmp = ((a.sign > 0) ^ (bistro_is_sup(a, b)));
	sign_eq = !((a.sign ^ b.sign) & (1l << ((sizeof(a.sign) * 8) - 1)));
	arg1_is_a = !sign_eq || tmp;
	sign_is_neg = ((a.sign < 0) && (b.sign > 0)) || tmp;

	f = (func_is_sub) ? bistro_sub_minimal_in : bistro_add_minimal_in;
	arg = (arg1_is_a) ? (t_bistro_sa){a, b} : (t_bistro_sa){b, a};
	f(arg.v1, arg.v2, result);
	result.sign = (sign_is_neg) ? -1 : 1;
}

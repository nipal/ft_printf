/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_enume.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 02:25:19 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/06 02:35:27 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

enum	e_simple
{
	e_toto,
	e_tata,
	e_titi
};


enum	e_large
{
	e_to = 1l << 53,
	e_ta,
	e_ti
};

enum	e_large2
{
	e_to2 = 1l,
	e_ta2,
	e_ti2
};



//
//enum	e_float
//{
//	e_to1 = 0.433,
//	e_ta2,
//	e_ti3
//};
//

void	test_enum_size()
{
	printf("size:	simple	[%zu]	val{%d	%d	%d}\n", sizeof(enum e_simple), e_toto, e_tata, e_titi);
	printf("size:	large	[%zu]	val{%lu	%lu	%lu}\n", sizeof(enum e_large), e_to, e_ta, e_ti);
	printf("size:	large2	[%zu]	val{%d	%d	%d}\n", sizeof(enum e_large2), e_to2, e_ta2, e_ti2);
//	printf("size:	flaot	[%zu]	val{%d	%d	%d}\n", sizeof(enum e_float), e_to1, e_ta2, e_ti3);
}

int	main()
{
	test_enum_size();
	return (0);
}

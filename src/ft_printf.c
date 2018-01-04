/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:14:45 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/10 08:42:36 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
d, i ,o, u,
x, X,
e, E,
f, F,
g, G,
a, A,
c,
s,
C,
S,
p,
n,
m,
%

================
d, i ,o, u, x, X, e, E, f, F, g, G, a, A, c, s, C, S, p, n, m, %

*/

//  key, name,{values, ...}


int	ft_printf(const char *format, ...)
{
	va_list			ap;				// variable variadique
	(void)format;(void)ap;
	return (0);
}

//	va_list		ap_copy = va_copy(ap, ap_copy);
//	va_end(ap_copy);

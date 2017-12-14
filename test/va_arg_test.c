/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 07:03:28 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/09 07:49:38 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef	struct	s_vec3
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_vec3;

void foo(char *fmt, ...)
{
	t_vec3	v;
    va_list ap;
    long d;
    char *s;
	long	c;

    va_start(ap, fmt);
    while (*fmt)
        switch (*fmt ++) {
        case 's':              /* chaîne */
            s = va_arg (ap, char *);
            printf("chaîne %s\n", s);
            break;
        case 'd':              /* entier */
            d = va_arg (ap, long);
            printf("int %d\n", (int)d);
            break;
        case 'c':              /* caractère */
            /* need a cast here since va_arg only
               takes fully promoted types */
            c = va_arg (ap, long);
            printf("char %c\n", (char)c);
            break;
       case 'v':              /* caractère */
            /* need a cast here since va_arg only
               takes fully promoted types */
            v = va_arg (ap, t_vec3);
            printf("t_vec3 {%f, %f, %f, %f}\n", v.x, v.y, v.z, v.w);
            break;
        }
    va_end(ap);
}

int	main()
{
	t_vec3	v = {34, -7, 12.98, 4242};
	char	*str = "vvvvvvvvvdddcccccvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

	foo(str);
	printf("====================\n");
	foo(str, 13, 37, 42, 'l', 'a', 'p', 'i', 'n', v);
	return (0);
}

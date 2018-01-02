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

void foo_test(char *fmt, ...)
{
    va_list 			ap;
	long	double		var;
	char			   *t;
	char				c;
	int					i;
	short				s;
	long				l;
	float				f;
	double				d;
	unsigned	char	uc;
	unsigned	short	us;
	unsigned	int		ui;
	unsigned	long	ul;

    va_start(ap, fmt);
    while (*fmt)
        switch (*fmt ++) {
        case 'c':
			 c = va_arg(ap, long double);
			 printf(" |%c|", c);
            break;
        case 'i':
			 i = va_arg(ap, long double);
			 printf(" |%d|", i);
            break;
        case 'f':
			 f = va_arg(ap, long double);
			 printf(" |%f|", f);
            break;
        case 'd':
			 d = va_arg(ap, long double);
			 printf(" |%f|", d);
            break;
        case 's':
			 s = va_arg(ap, long double);
			 printf(" |%hd|", s);
            break;
        case 'l':
			 l = va_arg(ap, long double);
			 printf(" |%ld|", l);
            break;
        case 't':
//			 t = (char*)va_arg(ap, long double);
			 t = (char*)va_arg(ap, char *);
			 printf(" |%s|", t);
            break;
        case 'C':
			 uc = va_arg(ap, long double);
			 printf(" |%hhu|", uc);
            break;
        case 'S':
			 us = va_arg(ap, long double);
			 printf(" |%hu|", us);
            break;
        case 'I':
			 ui = va_arg(ap, long double);
			 printf(" |%u|", ui);
            break;
        case 'L':
			 ul = va_arg(ap, long double);
			 printf(" |%lu|", ul);
            break;
        case 'D':
			 var = va_arg(ap, long double);
			 printf(" |%Lf|", var);
            break;
        }
	printf("\n");
    va_end(ap);
}

void foo_test_adrr(char *fmt, ...)
{
    va_list 			ap;
	char			   *t;
	char				c;
	int					i;
	short				s;
	long				l;
	float				f;
	double				d;
	unsigned	char	uc;
	unsigned	short	us;
	unsigned	int		ui;
	unsigned	long	ul;
	long double dodo;

	int	truc = 1;

	void*		var;
	int	toto = -1;
	int	tata = -2;
    va_start(ap, fmt);
    while (*fmt)
	{
//		var = va_arg(ap, void*);
		var = va_arg(ap, void*);
//		var = va_arg(ap, long double);
        switch (*fmt ++) {
        case 'c':
			 c = *(char*)&var;
			 printf(" |%c|", c);
            break;
        case 'i':
			 i = *((int*)&var);
			 printf(" |%d|", i);
            break;
        case 'f':
			 f = *((float*)&var);
			 printf(" |%f|", f);
            break;
        case 'd':
			 d = *((double*)&var);
			 printf(" |%f|", d);
            break;
        case 's':
			 s = *((short*)&var);
			 printf(" |%hd|", s);
            break;
        case 'l':
			 l = *((long*)&var);
			 printf(" |%ld|", l);
            break;
        case 't':
			 t = *((char**)&var);
			 printf(" |%s|", t);
            break;
        case 'C':
			 uc = *((unsigned char*)&var);
			 printf(" |%hhu|", uc);
            break;
        case 'S':
			 us = *((unsigned short*)&var);
			 printf(" |%hu|", us);
            break;
        case 'I':
			 ui = *((unsigned int*)&var);
			 printf(" |%u|", ui);
            break;
        case 'L':
			 ul = *((unsigned long*)&var);
			 printf(" |%lu|", ul);
            break;
        case 'D':
			 dodo = *((long double *)&var);
			 printf(" |%Lf|", dodo);
            break;
        }
	}
	printf("\n");
    va_end(ap);
}



void	va_arg_general_fonction()
{
	t_vec3	v = {34, -7, 12.98, 4242};
	char	*str = "vvvvvvvvvdddcccccvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";

	foo(str);
	printf("====================\n");
	foo(str, 13, 37, 42, 'l', 'a', 'p', 'i', 'n', v);

}

void	long_double_test()
{
	char	*str = "%t %c %i %s %l %f %d %C %S %I %L %D";
	char	str_printf[] = "|%t| |%c| |%i| |%s| |%l| |%f| |%d| |%C| |%S| |%I| |%L| |%D|\n";
	
//	foo_test(str, "youpi tralala", 'A', -1233231, -2332, 1231231231123, 0.99323, 0.00030000012, 255, -1, -1, 0.000000000000000000000000000000000000000000042424242);
//	printf(str_printf, "youpi tralala", 'A', -1233231, -2332, 1231231231123, 0.99323, 0.00030000012, 255, -1, -1, 0.000000000000000000000000000000000000000000042424242);

//	foo_test_adrr(str, "youpi tralala", 'A', -1233231, -2332, 1231231231123, 0.99323, 0.00030000012, 255, -1, -1, 0.000000000000000000000000000000000000000000042424242);

	foo_test_adrr("iiiiiii", 1, 2, 3, 4, 5, 6, 7);
	foo_test_adrr("D", 0.1);
	foo_test_adrr("", 1);
	
}


int	main()
{
	long_double_test();
	return (0);
}


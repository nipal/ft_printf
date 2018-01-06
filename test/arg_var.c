/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:45:00 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/06 12:12:55 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 08:31:28 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/06 11:44:19 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// -> exit(0)
#include <stdio.h>	// printf
#include <stdarg.h>	// va_list + va_...

// type: char, short, int, long, float, double, long double
//
typedef	union	u_type
{
	char				c;		//	1
	short				s;		//	2
	int					i;		//	3
	long				l;		//	4
	unsigned	char	uc;		//	5
	unsigned	short	us;		//	6
	unsigned	int		ui;		//	7
	unsigned	long	ul;		//	8
	float				f;		//	9
	double				d;		//	10
	long	double		ld;		//	11
	char				*t;		//	12
	void				*p;		//	13
}				t_utype;

t_utype	get_char(va_list ap)
{
	t_utype v;

	v.ld = 0;
	v.c = va_arg(ap, int);
	return (v);
}

t_utype	get_short(va_list ap)
{
	t_utype v;

	v.ld = 0;
	v.s = va_arg(ap, int);
	return (v);
}

t_utype	get_int(va_list ap)
{
	t_utype v;

	v.ld = 0;
	v.i = va_arg(ap, int);
	return (v);
}

t_utype	get_long(va_list ap)
{
	t_utype v;

	v.ld = 0;
	v.l = va_arg(ap, long);
	return (v);
}

t_utype	get_unsigned_char(va_list ap)
{
	t_utype v;

	v.ld = 0;
	v.uc = va_arg(ap, unsigned  int);
	return (v);
}

t_utype	get_unsigned_short(va_list ap)
{
	t_utype v;

	v.ld = 0;
	v.us = va_arg(ap, unsigned  int);
	return (v);
}

t_utype	get_unsigned_int(va_list ap)
{
	t_utype v;

	v.ld = 0;
	v.ui = va_arg(ap, unsigned  int);
	return (v);
}

t_utype	get_unsigned_long(va_list ap)
{
	t_utype v;

	v.ld = 0;
	v.ul = va_arg(ap, unsigned  long);
	return (v);
}



t_utype	get_float(va_list ap)
{
	t_utype v;

	v.ld = 0;
	v.f = va_arg(ap, double);
	return (v);
}

t_utype	get_double(va_list ap)
{
	t_utype v;

	v.ld = 0;
	v.d = va_arg(ap, double);
	return (v);
}

t_utype	get_long_double(va_list ap)
{
	t_utype v;

	v.ld = 0;
	v.ld = va_arg(ap, long double);
	return (v);
}

t_utype	get_ptr(va_list ap)
{
	t_utype v;

	v.ld = 0;
	v.p = va_arg(ap, void*);
	return (v);
}

t_utype	get_txt(va_list ap)
{
	t_utype v;

	v.ld = 0;
	v.t = va_arg(ap, char*);
	return (v);
}

void	init_get_val(t_utype (*f[13])(va_list ap))
{
		f[0] = get_char;
		f[1] = get_short;
		f[2] = get_int;
		f[3] = get_long;
		f[4] = get_unsigned_char;
		f[5] = get_unsigned_short;
		f[6] = get_unsigned_int;
		f[7] = get_unsigned_long;
		f[8] = get_float;
		f[9] = get_double;
		f[10] = get_long_double;
		f[11] = get_ptr;
		f[12] = get_txt;
}

void	print_char(t_utype val)
{
	printf("char				:%c\n", val.c);
}

void	print_short(t_utype val)
{
	printf("short				:%hd\n", val.s);
}

void	print_int(t_utype val)
{
	printf("int					:%d\n", val.i);
}

void	print_long(t_utype val)
{
	printf("long				:%ld\n", val.l);
}

void	print_unsigned_char(t_utype val)
{
	printf("unsigned_char		:%hhu\n", val.uc);
}

void	print_unsigned_short(t_utype val)
{
	printf("unsigned_short		:%hu\n", val.us);
}

void	print_unsigned_int(t_utype val)
{
	printf("unsigned_int		:%u\n", val.ui);
}

void	print_unsigned_long(t_utype val)
{
	printf("unsigned_long		:%lu\n", val.ul);
}


void	print_float(t_utype val)
{
	printf("float				:%f\n", val.f);
}

void	print_double(t_utype val)
{
	printf("double				:%f\n", val.f);
}



void	print_long_double(t_utype val)
{
	printf("long_double			:%Lf\n", val.ld);
}

void	print_ptr(t_utype val)
{
	printf("pointer				:%p\n", val.p);
}

void	print_text(t_utype val)
{
	printf("text				:%s\n", val.t);
}





void	print_val(int type, t_utype val)
{
	static	void	(*f[13])(t_utype val);
	static	int		init = 1;

	if (init)
	{
		init = 0;
		f[0] = print_char;
		f[1] = print_short;
		f[2] = print_int;
		f[3] = print_long;
		f[4] = print_unsigned_char;
		f[5] = print_unsigned_short;
		f[6] = print_unsigned_int;
		f[7] = print_unsigned_long;
		f[8] = print_float;
		f[9] = print_double;
		f[10] = print_long_double;
		f[11] = print_ptr;
		f[12] = print_text;
	}
	if (type >= 0 && type < 12)
		f[type](val);
}

t_utype	get_arg(int type_pass, int type_final, int id_end, va_list ap)
{
	static	int	begin = 1;
	static	t_utype	(*f[13])(va_list ap);
	int		i;
	va_list	copy;
	t_utype	val;

	if (begin)
	{
		begin = 0;
		init_get_val(f);
	}
	if (type_pass < 0 || type_final < 0 || type_pass >= 13 || type_final >= 13 || id_end < 0)		// on test si les parametre son bon
		printf("error input		pass:%d	final:%d	end:%d\n", type_pass, type_final, id_end), exit(0);
	va_copy(copy, ap);				// on copy le debut
	i = 1;
	while (i < id_end - 1) 			// on passe les precedente valeur
	{
		val = f[type_pass](copy);
		i++;
	}
	val = f[i](copy);				// on recupere le type souhaiter
	va_end(copy);					// on libere la memoire
	return (val);					// on retourne l'argument en quesdtion
}


char	*get_name_type(int id_type)
{
	static	char	name_type[13][20] = {	"char           ",
											"short          ",
											"int            ",
											"long           ",
											"unsigned char  ",
											"unsigned short ",
											"unsigned int   ",
											"unsigned long  ",
											"float          ",
											"double         ",
											"long double    ",
											"pointer        ",
											"string         "};
	if (id_type >= 0 && id_type < 13)
		return (((char *)name_type) + (20 * id_type) * sizeof(char));
	else
		return (NULL);
}
//	t_utype	get_arg(int type_pass, int type_final, int id_end, va_list ap)

// test all possibilities
void	test_variadique_all(int nb_arg, ...)
{
	int		i, j, k, max_type;
	va_list ap;
	t_utype	val;

	printf("\n\n===================================\n");
	printf("nb arg->%d\n", nb_arg);
    va_start(ap, nb_arg);
	max_type = 13;
	k = 0;
	while (k < nb_arg)					// try on all variable to be the end
	{
		printf("\n############### id__arg_end_type->%d %s####################\n", k, get_name_type(k));	
		i = 0;
		while (i < max_type)			// try with all type for paste paste
		{
			printf("\n--------------- arg_pass_type->%d %s--------------------\n", i, get_name_type(i));	
			j = 0;
			while (j < max_type - 1)	// au debut on teste sans les chaine de charactere
			{
				val = get_arg(i, j, k, ap);
				print_val(j, val);
				j++;
			}
			i++;
		}
		k++;
	}
	va_end(ap);
}

// test all possibilities
//	t_utype	get_arg(int type_pass, int type_final, int id_end, va_list ap)
//	void	print_val(int type, t_utype val)
void	test_variadique_end(int nb_arg, ...)
{
	int		i, j, k, max_type;
	va_list ap;
	t_utype	val;

	printf("\n\n===================================\n");
	printf("nb arg->%d\n", nb_arg);
    va_start(ap, nb_arg);
	max_type = 13;
	k = 0;
	while (k < nb_arg)					// try on all variable to be the end
	{
		printf("\n############### id_arg_type->%d %s####################\n", k, get_name_type(k));	
		i = 0;
		while (i < max_type)			// try with all type for paste paste
		{
			val = get_arg(i, i, k, ap);
			print_val(i, val);
			i++;
		}
		k++;
	}
	va_end(ap);
}

void	test_0()
{
	printf("\n\n\n\n");
//	test_variadique_all(12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	test_variadique_end(12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

void	test_neg1()
{
	printf("\n\n\n\n");
//	test_variadique_all(12, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	test_variadique_end(12, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
}

void	test_prog()
{
	printf("\n\n\n\n");
//	test_variadique_all(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	test_variadique_end(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
}



void	test_1()
{
	char				c	 = 0;
	short				s	 = 0;
	int					i	 = 0;	
	long				l	 = 0;
	unsigned	char	uc	 = 0;
	unsigned	short	us	 = 0;
	unsigned	int		ui	 = 0;
	unsigned	long	ul	 = 0;
	float				f	 = 0;
	double				d	 = 0;
	long	double		ld	 = 0;
	void				*p	 = 0;

	// test with nothing
	test_variadique_all(12, c, s, i, l, uc, us, ui, ul, f, d, ld, p);

	c	 = -1;
	s	 = -1;
	i	 = -1;	
	l	 = -1;
	uc	 = -1;
	us	 = -1;
	ui	 = -1;
	ul	 = -1;
	f	 = -1;
	d	 = -1;
	ld	 = -1;
	p	 = (void*)-1;
	// test with minus one
	test_variadique_all(12, c, s, i, l, uc, us, ui, ul, f, d, ld, p);

	c	 = -42;
	s	 = -2342;
	i	 = -2352353;	
	l	 = -53425353452345;
	uc	 = 255;
	us	 = -25252;
	ui	 = -252525252;
	ul	 = -25252;
	f	 = 0.0000000125;
	d	 = 0.0000000000000000001;
	ld	 = -0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
	p	 = (void*)test_variadique_all;
	// test with minus one
	test_variadique_all(12, c, s, i, l, uc, us, ui, ul, f, d, ld, p);

}

int	main()
{
//	test_1();
//	test_0();
//	test_neg1();
	test_prog();
	return (0);
}

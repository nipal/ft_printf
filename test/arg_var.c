/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:45:00 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/09 13:43:31 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// -> exit(0)
#include <stdio.h>	// printf
#include <stdarg.h>	// va_list + va_...
#include <string.h>

// type: char, short, int, long, float, double, long double

//char	*name_type(int id)
//{
//	char 	tab[13][32] = { "char", "short", "int", "long", "unsigned char", "unsigned short", "unsigned int", "unsigned long", "float", "double", "long double", "char *", "void *"};
//	
//	if (id < 0 || id >= 13)
//		return (NULL);
//	return (((char*)tab) + (id * 32) * sizeof(char));
//}
//
//



//		c;		//	0
//		s;		//	1
//		i;		//	2
//		l;		//	3
//		uc;		//	4
//		us;		//	5
//		ui;		//	6
//		ul;		//	7
//		f;		//	8
//		d;		//	9
//		ld;		//	10
//		*t;		//	11
//		*p;		//	12

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
											"char *         ",
											"void *         "
	
	};
	if (id_type >= 0 && id_type < 13)
		return (((char *)name_type) + (20 * id_type) * sizeof(char));
	else
		return (NULL);
}

int		get_size_type(int id_type)
{
	static	int	size_type[13] = {
									sizeof(char           ),	//	0
									sizeof(short          ),    //	1
									sizeof(int            ),    //	2
									sizeof(long           ),    //	3
									sizeof(unsigned char  ),    //	4
									sizeof(unsigned short ),    //	5
									sizeof(unsigned int   ),    //	6
									sizeof(unsigned long  ),    //	7
									sizeof(float          ),    //	8
									sizeof(double         ),    //	9
								//	sizeof(long double    ),    //	10
									10,    //	10
									sizeof(char *         ),    //	11
									sizeof(void *         )};   //	12

	if (id_type >= 0 && id_type < 13)
		return (size_type[id_type]);
	return (-1);
}

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
		f[11] = get_txt;
		f[12] = get_ptr;
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
///////////////////////////////////////////
void	print_bit_str(unsigned char *data, int size, char *s)
{
	int	i;
	int	j;
	int	nb_char;
	int	id;
	char	*str;

	nb_char = (size * 8);
	if (!(str = malloc(((nb_char) + 1) * sizeof(char))))
		return ;
	str[(size * 8)] = '\0';
	j = size - 1;
	while (j >= 0)
	{
		i = 7;
		while (i >= 0)
		{
			id = (7 - i) + ((size - 1 - j) * 8);
			str[id] = (data[j] & (1 << i)) ? '1' : '0';
			i--;
		}
		j--;
	}
	printf("%s%s\n", s, str);
	free(str);
/**/}

void	print_bit_buffer(unsigned char *data, int size, char *str)
{
	int	i;
	int	j;
	int	nb_char;
	int	id;

	nb_char = (size * 8);
	str[(size * 8)] = '\0';
	j = size - 1;
	while (j >= 0)
	{
		i = 7;
		while (i >= 0)
		{
			id = (7 - i) + ((size - 1 - j) * 8);
			str[id] = (data[j] & (1 << i)) ? '1' : '0';
//			printf("--id:%d[%c]--	", id, str[id]);
			i--;
		}
		j--;
	}
	str[(size * 8)] = '\0';
//	printf("\n");
//	printf("%s%s\n", s, str);
//	free(str);
/**/}



//t_utype	get_arg(int type_pass, int type_final, int id_end, va_list ap)

void	test_arg(int nb_arg, int type_end, ...)
{
	int	i;
	int	j;
	t_utype	tab_val[13], tmp;
	static	int	begin = 1;
	static	t_utype	(*f[13])(va_list ap);
	va_list	ap;
	va_list	copy;
	t_utype	val;

	char	valu[256];

	if (begin)
	{
		begin = 0;
		init_get_val(f);
	}
	va_start(ap, type_end);

	// pour tout les type
	j = 0;
	while (j < 13)
	{
		va_copy(copy, ap);
		i = 0;
		while (i < (nb_arg - 1))
		{
			tmp = f[j](copy);
			i++;
		}
		tab_val[j] = f[type_end](copy);
		va_end(copy);
		j++;
	}
	printf("-----------------------------------------------\n");
	j = 0;
	while (j < 13)
	{
		print_bit_buffer((void*)(tab_val + j), get_size_type(type_end), valu);
		printf("|%s|->	[%s]{%s}\n", get_name_type(j), valu, get_name_type(type_end));
		j++;
	}
	printf("\n");
	va_end(ap);
}
//		c;		//	0
//		s;		//	1
//		i;		//	2
//		l;		//	3
//		uc;		//	4
//		us;		//	5
//		ui;		//	6
//		ul;		//	7
//		f;		//	8
//		d;		//	9
//		ld;		//	10
//		*t;		//	11
//		*p;		//	12


void	diff_prioriti_variadique()
{
	t_utype		uval;
	char	 	c1 = 0  ,c2 = -1, c3 = 1, c4 = 0b10101010, c5 = 0b1111;
	short	 	s1 = 0  ,s2 = -1, s3 = 1, s4 = 0b1010101010101010, s5 = 0b11111111;
	int		 	i1 = 0  ,i2 = -1, i3 = 1, i4 = 0b10101010101010101010101010101010, i5 = 0b1111111111111111;
	float	 	f1 = 0  ,f2 = -1, f3 = 1, f4 = 0b10101010101010101010101010101010, f5 = 0b1111111111111111;
	long	 	l1 = 0  ,l2 = -1, l3 = 1, l4 = 0b1010101010101010101010101010101010101010101010101010101010101010, l5 = 0b11111111111111111111111111111111;
	double	 	d1 = 0  ,d2 = -1, d3 = 1, d4 = 0b1010101010101010101010101010101010101010101010101010101010101010, d5 = 0b11111111111111111111111111111111;
	char		*t1 = 0  ,*t2 = -1, *t3 = 1, *t4 = 0b1010101010101010101010101010101010101010101010101010101010101010, t5 = 0b11111111111111111111111111111111;
	long double	ld1 = 0 ,ld2 = 1.0 / 0.0, ld3 = 0.0 / 0.0, ld4 = 0.0000000000000000000000000000000000000001112223334445566777, ld5 = 0b1111111111111111111111111111111111111111;
	////////////////////////
	

	memset(&uval, 0x1, 10);
//	uval.ld = 4242.13371337;
//	uval.ld = 424242.0001337;
//	ld2 = uval.ld;


	c2  = uval.c ; 
	s2  = uval.s ; 
	i2  = uval.i ; 
	f2  = uval.f ; 
	l2  = uval.l ; 
	d2  = uval.d ; 
	t2  = uval.t ; 
	ld2 = uval.ld ; 



	print_bit_str(&uval, sizeof(uval), "===>		");
//printf("\n__________test_aligne__________\n");	
//
//printf("\n__________smal->big__________\n");	
//
//printf("\n__________big->smal__________\n");	

printf("\n=============================\n=======%s=======\n=============================\n", get_name_type(0));
//	char
	printf("%hhd\n", uval.c);
	test_arg(5, 0,  c1, c2, c3, c4, c2);
	test_arg(9, 0,  c3, s3, i3, f3, l3, d3, t3, ld3, c2);
	test_arg(9, 0,  ld3, t3, d3, l3, f3, i3, s3, c3, c2);

printf("\n=============================\n=======%s=======\n=============================\n", get_name_type(1));
//	short
	printf("%hd\n", uval.s);
	test_arg(5, 1,  s1, s2, s3, s4, s2);
	test_arg(9, 1,  c3, s3, i3, f3, l3, d3, t3, ld3, s2);
	test_arg(9, 1,  ld3, t3, d3, l3, f3, i3, s3, c3, s2);

printf("\n=============================\n=======%s=======\n=============================\n", get_name_type(2));
//	int
	printf("%d\n", uval.i);
	test_arg(5, 2,  i1, i2, i3, i4, i2);
	test_arg(9, 2,  c3, s3, i3, f3, l3, d3, t3, ld3, i2);
	test_arg(9, 2,  ld3, t3, d3, l3, f3, i3, s3, c3, i2);

printf("\n=============================\n=======%s=======\n=============================\n", get_name_type(8));
// 	float
	printf("%f\n", uval.f);
	test_arg(5, 8,  f1, f2, f3, f4, f2);
	test_arg(9, 8,  c3, s3, i3, f3, l3, d3, t3, ld3, f2);
	test_arg(9, 8,  ld3, t3, d3, l3, f3, i3, s3, c3, f2);

printf("\n=============================\n=======%s=======\n=============================\n", get_name_type(3));
//	long
	printf("%ld\n", uval.l);
	test_arg(5, 3,  l1, l2, l3, l4, l2);
	test_arg(9, 3,  c3, s3, i3, f3, l3, d3, t3, ld3, l2);
	test_arg(9, 3,  ld3, t3, d3, l3, f3, i3, s3, c3, l2);

printf("\n=============================\n=======%s=======\n=============================\n", get_name_type(9));
//	double
	printf("%f\n", uval.d);
	test_arg(5, 9, d1, d2, d3, d4, d2);
	test_arg(9, 9, c3, s3, i3, f3, l3, d3, t3, ld3, d2);
	test_arg(9, 9, ld3, t3, d3, l3, f3, i3, s3, c3, d2);

printf("\n=============================\n=======%s=======\n=============================\n", get_name_type(11));
// 	text
	printf("%p\n", uval.t);
	test_arg(5, 11, t1, t2, t3, t4, t2);
	test_arg(9, 11, c3, s3, i3, f3, l3, d3, t3, ld3, t2);
	test_arg(9, 11, ld3, t3, d3, l3, f3, i3, s3, c3, t2);

printf("\n=============================\n=======%s=======\n=============================\n", get_name_type(10));
//	long double
	printf("%Lf\n", uval.ld);
	test_arg(5, 10, ld1, ld2, ld3, ld4, ld2);
	test_arg(9, 10, c3, s3, i3, f3, l3, d3, t3, ld3, ld2);
	test_arg(9, 10, ld3, t3, d3, l3, f3, i3, s3, c3, ld2);
	test_arg(9, 10, ld1, ld2, ld3, ld3, c1, i2, c2, c3, ld2);
}

int	main()
{
//	test_1();
//	test_0();
//	test_neg1();
//	test_prog();
	
	diff_prioriti_variadique();
	
//	printf("sizeof(long double):%d\n", get_size_type(10));
	return (0);
}

/*
	integer, ptr:	-->	(pop) LONG
*/

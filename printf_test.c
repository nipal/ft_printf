/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 07:44:34 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/10 09:35:36 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>


void	truc()
{
	unsigned	char		c;
	unsigned	short		s;
	unsigned	int			i;
	unsigned	long		l;
	unsigned	long	int	li;
	unsigned	long	int	ref;
	
	printf("%zu\n", sizeof(unsigned	char));
	printf("%zu\n", sizeof(unsigned	short));
	printf("%zu\n", sizeof(unsigned	int));
	printf("%zu\n", sizeof(unsigned	long));
	printf("%zu\n", sizeof(unsigned	long	int	));
	printf("%zu\n", sizeof(unsigned	long	int));
	// on load tout en long
	// si besoin on recaste magic en double


}

unsigned char	ud1(long val)
{
	return ((unsigned char)val);
}

unsigned short		ud2(long val)
{
	return ((unsigned short)val);
}

unsigned int		ud4(long val)
{
	return ((unsigned int)val);
}

unsigned int		ud8(long val)
{
	return ((unsigned long)val);
}

unsigned char	d1(long val)
{
	return ((unsigned char)val);
}

unsigned short		d2(long val)
{
	return ((unsigned short)val);
}

unsigned int		d4(long val)
{
	return ((unsigned int)val);
}

unsigned int		d8(long val)
{
	return ((unsigned long)val);
}



void	test_cast_transpose()
{
	long	val = -1231232131323 + 30;
	int		vi1, vi2, vi3;
	short	vs1, vs2, vs3;
	char	vc1, vc2, vc3;

	vi1 = ud4(val);
	vi2 = val & 0xFFFFFFFF;

	vs1 = ud2(val);
	vs2 = val & 0xFFFF;

	vc1 = ud1(val);
	vc2 = val & 0xFF;
	printf("%d:%d	%d:%d	%d:%d\n", vi1, vi2, vs1, vs2, vc1, vc2);
	printf("%d	%hd	%hhd\n", vi1, vs1, vc1);

	printf("A->>%1$d, %d, %d. %d\n", 4, 3, 2, 1); // on change juste celui qu'il prend
	printf("B->>%2$d, %d, %d. %d\n", 4, 3, 2, 1);
	printf("C->>%3$d, %d, %d. %d\n", 4, 3, 2, 1);
	printf("D->>%4$d, %d, %d. %d\n", 4, 3, 2, 1);

	printf("----------------\n");

	printf("A->>%d, %1$d, %d. %d\n", 4, 3, 2, 1); // on change juste celui qu'il prend
	printf("B->>%d, %2$d, %d. %d\n", 4, 3, 2, 1);
	printf("C->>%d, %3$d, %d. %d\n", 4, 3, 2, 1);
	printf("D->>%d, %4$d, %d. %d\n", 4, 3, 2, 1);

	printf("----------------\n");

	printf("A->>%d, %d, %1$d. %d\n", 4, 3, 2, 1); // on change juste celui qu'il prend
	printf("B->>%d, %d, %2$d. %d\n", 4, 3, 2, 1);
	printf("C->>%d, %d, %3$d. %d\n", 4, 3, 2, 1);
	printf("D->>%d, %d, %4$d. %d\n", 4, 3, 2, 1);

	printf("----------------\n");

	printf("A->>%d, %d, %d. %1$d\n", 4, 3, 2, 1); // on change juste celui qu'il prend
	printf("B->>%d, %d, %d. %2$d\n", 4, 3, 2, 1);
	printf("C->>%d, %d, %d. %3$d\n", 4, 3, 2, 1);
	printf("D->>%d, %d, %d. %4$d\n", 4, 3, 2, 1);

	printf("----------------\n");

	printf("A->>%1$d, %1$d, %1$d. %1$d\n", 4, 3, 2, 1); // on change juste celui qu'il prend
	printf("B->>%2$d, %2$d, %2$d. %2$d\n", 4, 3, 2, 1);
	printf("C->>%3$d, %3$d, %1$d. %3$d\n", 4, 3, 2, 1);
	printf("D->>%4$d, %1$d, %d. %d\n", 4, 3, 2, 1);

	printf("----------------\n");

	printf("A->>%1$d, %*1$d, %*1$d. %*1$d\n", 4, 3, 2, 1); // on change juste celui qu'il prend
	printf("B->>%2$d, %*1$d, %*2$d. %*3$d\n", 4, 3, 2, 1);
	printf("C->>%3$d, %*1$d, %d. %d\n", 4, 3, 2, 1);
	printf("D->>%4$d, %*1$d, %d. %d\n", 4, 3, 2, 1);

}

void	ptr_test()
{
	void	*pt;
	int	a, c, d, e, f, b;
	ptrdiff_t	pdiff;

	pdiff = &b - &a;

	pt = &a - &b;

	printf("%p	%tp\n", pt, pt);
	printf("%p	%tp\n", pdiff, pdiff);
}

void	perturb()
{
	int	val, v2, v3, v4, v5;

	val = 0;
	printf("coucou les gens.\n%n", &val);
	printf("---=>%n%n%n 		%n 		 %n\n", &val, &v2, &v3, &v4, &v5);
}

void	test_with_ret()
{
	char	buf[1024];
	int		ret;
	float	f = 0;
//	float	f = 999999;

	ret = sprintf(buf, "%0a", f);
printf("ret:%d	-->{%s}\n", ret, buf);
	ret = sprintf(buf, "%#e", f);
printf("ret:%d	-->{%s}\n", ret, buf);
	ret = sprintf(buf, "%#f", f);
printf("ret:%d	-->{%s}\n", ret, buf);
	ret = sprintf(buf, "%#g", f);
printf("ret:%d	-->{%s}\n", ret, buf);

printf("========== %s ==========\n", __func__);//===<<<>>
}

void	test_printf()
{
	long	a = 2345;
	char	c = 'R';
	char	*str = "yolo swag";
	float	f = -456.6546;
	printf("[%-010c]\n", c);
	printf("[%.3   20la]\n", f);
	printf("[%0-111d]", str);
printf("========== %s ==========\n", __func__);//===<<<>>
}

void	test_int()
{
	int	l = 511101;
	printf("-------------------------\n");
	printf("d:%d|%d|%d|	[%*1$d]\n",0, 15, 40, l, 0, 15, 40);
	printf("i:%d|%d|%d|	[%*2$i]\n",0, 15, 40, l, 0, 15, 40);
	printf("d:%d|%d|%d|	[%*3$d]\n",0, 15, 40, l, 0, 15, 40);
	printf("d:%d|%d|%d|	[%-*1$d]\n",0, 15, 40, l, 0, 15, 40);
	printf("i:%d|%d|%d|	[%-*2$i]\n",0, 15, 40, l, 0, 15, 40);
	printf("d:%d|%d|%d|	[%-*3$d]\n",0, 15, 40, l, 0, 15, 40);


	printf("d:%d|%d|%d|	[%*1d]\n",0, 15, 40, l, 0, 15, 40);
	printf("i:%d|%d|%d|	[%*2i]\n",0, 15, 40, l, 0, 15, 40);
	printf("d:%d|%d|%d|	[%*3d]\n",0, 15, 40, l, 0, 15, 40);
	printf("d:%d|%d|%d|	[%-*1d]\n",0, 15, 40, l, 0, 15, 40);
	printf("i:%d|%d|%d|	[%-*2i]\n",0, 15, 40, l, 0, 15, 40);
	printf("d:%d|%d|%d|	[%-*3d]\n",0, 15, 40, l, 0, 15, 40);

	printf("d:%d|%d|%d|	[%20.d]\n",0, 15, 40, l, 0, 15, 40);
	printf("i:%d|%d|%d|	[%20.i]\n",0, 15, 40, l, 0, 15, 40);
	printf("d:%d|%d|%d|	[%.20d]\n",0, 15, 40, l, 0, 15, 40);
	printf("i:%d|%d|%d|	[%.20i]\n",0, 15, 40, l, 0, 15, 40);
	printf("d:%d|%d|%d|	[%-.20d]\n",0, 15, 40, l, 0, 15, 40);
	printf("i:%d|%d|%d|	[%-.20i]\n",0, 15, 40, l, 0, 15, 40);

	printf("f:[%f]\n", l);
	printf("F:[%F]\n", l);
	printf("g:[%g]\n", l);
	printf("G:[%G]\n", l);
printf("========== %s ==========\n", __func__);//===<<<>>
}

void	other_test()
{
	int	b = 11111111110;
	int	*nb = &b;

	printf("-------------------------\n");
	printf("[%p]\n", nb);
	printf("hh [%hhd]\n", b);
	printf("h  [%hd]\n", b);
	printf("   [%d]\n", b);
	printf("l  [%ld]\n", b);
	printf("ll [%lld]\n", b);
	printf("hl [%hld]\n", b);
	printf("lhh[%lhhd]\n", b);
	printf("n  [%p]\n", nb);
	printf("j  [%jd]\n", b);
	printf("z  [%zd]\n", b);

printf("========== %s ==========\n", __func__);//===<<<>>
}

void	other_test_2()
{
	long c = 11111111233;
	printf("-------------------------\n");
	printf("hh [%hhc]\n", c);
	printf("h  [%hc]\n", c);
	printf("   [%c]\n", c);
	printf("l  [%lc]\n", c);
	printf("ll [%llc]\n", c);
	printf("hl [%hlc]\n", c);
	printf("lhh[%lhhc]\n", c);
	printf("n  [%p]\n", c);
printf("========== %s ==========\n", __func__);//===<<<>>
}

void	type_length_test()
{
	printf("long				:%zu\n", sizeof(long));
	printf("long long			:%zu\n", sizeof(long long));
	printf("long long int			:%zu\n", sizeof(long long int));
	printf("double				:%zu\n", sizeof(double));
	printf("long double			:%zu\n", sizeof(long double));

printf("========== %s ==========\n", __func__);//===<<<>>
}

void	nb_arg_test()
{
	int		width = 10;
	int		num = 1337;
	int		yo = 20;
	float	f = 3.14915; // achtung 

	printf("[%aq.2f]\n", 1234567.89);
	printf("[%2$*1$*3$*1$d]\n", width, num, yo);
	printf("[%2$*1$d]\n", width, num);
	printf("[%20.2f]\n", f);
	printf("[%*2$.*3$f]\n", f, 20, 2);
printf("========== %s ==========\n", __func__);//===<<<>>
}

void	print_bit(unsigned char *data, int size)
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
	printf("%s\n", str);
	free(str);
/**/}

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

void	sharp_test()
{
	double	d = 42.1337;
	double	k = 33.777;
	long	l = 42;
	long	a1 = 44.3333;
	long	a2 = 22.1111;
	long	a3 = 33.2222;
	double	b = l;
	long	f = l;

	print_bit(&d, sizeof(d));
	printf("f:d	[%#f]\n", k);
	printf("f:l	[%f, %f, %f]\n", l, l, l);
	printf("f:l	[%f]\n", a1);
	printf("f:l	[%f]\n", a2);
	printf("f:l	[%f]\n", a3);
	printf("ld:l	[%ld]\n", l);
	printf("f:b	[%f]\n", b);
	printf("a:d	[%#a#e#gf]\n", d);
printf("========== %s ==========\n", __func__);//===<<<>>
}

void	mantis_size_test()
{
	float	f = 1.0 / 0.0;
	double	d = 1.0 / 0.0;
	long double	ld = 1.0 / 0.0;

	printf("float:%zu\n", sizeof(float));
	printf("double:%zu\n", sizeof(double));
	printf("long double:%zu\n", sizeof(long double));
	printf("---------------\n");
	print_bit_str(&f, sizeof(float), "float		:");
	print_bit_str(&d, sizeof(double), "double		:");
	print_bit_str(&ld, sizeof(long double), "long double	:");
	printf("---------------\n");
	printf("float		[%f]\n", f);
	printf("double		[%f]\n", d);
	printf("long double	[%Lf]\n", ld);

printf("========== %s ==========\n", __func__);//===<<<>>
}

void	print_bit_test()
{
	int		a;
	long	b;
	float	f;
	double	d;

	a = 1234;
	b = 123123;
	f = 3.14115;
	d = 3.14115;
	printf("int:	%d		", a);
	print_bit(&a, sizeof(a));
	printf("long:	%ld		", b);
	print_bit(&b, sizeof(b));
	printf("float:	%f	", f);
	print_bit(&f, sizeof(f));
	printf("double:	%f	", d);
	print_bit(&d, sizeof(d));
printf("========== %s ==========\n", __func__);//===<<<>>
}

void	print_float_bit(float f, char *s)
{
	char	str[35];
	int		i;
	int		j;
	int		data;

	data = *(int*)&f;
	str[34] = '\0';
	j = 0;
	i = 0;
	while (i < 32)
	{
		str[j] = (data & (1 << (31 - i))) ? '1' : '0';
		if (i == 0 || i == 8)
		{
			j++;
			str[j] = '|';
		}
		i++;
		j++;
	}
	printf("%s:[%200.150a]:	%s\n", s, f, str);
}

void	mutiple_float_value()
{
	float	f1, f2, f3, f4, f5, f6, f7, f8, f9;
	float	a, inf;
	int		i;

	inf = 1.0 / 0.0;
	*((int*)(&f1)) = 0b01111111100000000000000000000000;
	*((int*)(&f2)) = 0b00000000100000100000000000000000;
	*((int*)(&f3)) = 0b00000001000000010000000000000000;
	*((int*)(&f4)) = 0b00000010000000001000000000000000;
	*((int*)(&f5)) = 0b00000100000000000100000000000000;
	*((int*)(&f6)) = 0b00001000000000000010000000000000;
	*((int*)(&f7)) = 0b00010000000000000001000000000000;
	*((int*)(&f8)) = 0b00100000000000000000100000000000;
	*((int*)(&f9)) = 0b01000000000000000000010000000000;

	print_float_bit(inf, "		:::>");
	a = 1.0;
	for (i = 0; i < 10; i++)
	{
		a = (float)(1 << i);
		print_float_bit(a, "	:::>");
		a += 1;
		print_float_bit(a, "	:::>");
	printf("---\n");
	}
	printf("-----------------]\n");

///////////////[print part]///////////////////
	printf("\n\nf1[%.20f]\n", f1);
	print_bit_str(&f1, sizeof(f1), "f1");
	printf("\n\nf2[%.20f]\n", f2);
	print_bit_str(&f2, sizeof(f2), "f2");
	printf("\n\nf3[%.20f]\n", f3);
	print_bit_str(&f3, sizeof(f3), "f3");
	printf("\n\nf4[%.20f]\n", f4);
	print_bit_str(&f4, sizeof(f4), "f4");
	printf("\n\nf5[%.20f]\n", f5);
	print_bit_str(&f5, sizeof(f5), "f5");
	printf("\n\nf6[%.20f]\n", f6);
	print_bit_str(&f6, sizeof(f6), "f6");
	printf("\n\nf7[%.20f]\n", f7);
	print_bit_str(&f7, sizeof(f7), "f7");
	printf("\n\nf8[%.20f]\n", f8);
	print_bit_str(&f8, sizeof(f8), "f8");
	printf("\n\nf9[%.20f]\n", f9);
	print_bit_str(&f9, sizeof(f9), "f9");
printf("========== %s ==========\n", __func__);//===<<<>>
}

void	float_structure_test()
{
	int		i;
	int		j;
	float	f;
	float	f2;

	i = 0;
	while (i < 6)
	{
		j = 1 << i;
		while (j < (1 << (i + 1)))
		{
			f = (float)j;
			printf("i:%d	%d::", i, j);
			print_float_bit(f, "	");
			j++;
		}
		printf("------\n");
		i++;
	}
printf("========== %s ==========\n", __func__);//===<<<>>
}

void	float_expo_all_mantis_0()
{
	int		i;
	float	f;

	for (i = 0; i < 256; i++)
	{
		*((int*)&f) = i << 23;
		print_float_bit(f, "");
		*((int*)&f) = i << 23 | 1;
		print_float_bit(f, "");
	}
printf("========== %s ==========\n", __func__);//===<<<>>
}

void	float_precision_test()
{
	float	f1 = 	0.00000000000000000000000000000000000001175494350822287507968736537222245677818665556772087521508751706278417259454727172851562500;
	float	f2 = 	0.00000000000000000000000000000000000001175494350822287507968736537222245677818665556772087521508751706278417259454727172851562600;
	float	f3 = 	0.00000000000000000000000000000000000001175494350822287507968736537222245677818665556772087521508751706278417259454727172851562700;
	float	f4 = 	0.00000000000000000000000000000000000001175494350822287507968736537222245677818665556772087521508751706278417259454727172851562800;

	float	g1 =	0.00000000000000000000000000000000000001175494350822287507968736537222245677818665556772087521508751706278417259454727172851562400;
	float	g2 =	0.00000000000000000000000000000000000001999999999999999999999999999222245677818665556772087521508751706278417259454727172851562400;
	float	g3 =	0.00000000000000000000000000000000000002150988701644575015937473074444491355637331113544175043017503412556834518909454345703125000;
	float	g4 =	0.00000000000000000000000000000000000002350988701644575015937473074444491355637331113544175043017503412556834518909454345703124000;
/*
0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
0.00000000000000000000000000000000000001175494350822287507968736537222245677818665556772087521508751706278417259454727172851562500;
0.00000000000000000000000000000000000002350988701644575015937473074444491355637331113544175043017503412556834518909454345703125000;
*/

	print_float_bit(f1, "f1");
	print_float_bit(f2, "f2");
	print_float_bit(f3, "f3");
	print_float_bit(f4, "f4");


	print_float_bit(g1, "g1");
	print_float_bit(g2, "g2");
	print_float_bit(g3, "g3");
	print_float_bit(g4, "g4");
printf("========== %s ==========\n", __func__);//===<<<>>
}

void	valid_format()
{
	int	ret1 = printf("oui%wxz%kwr%d\n", 6, 7, 8, 9);
	int	ret2 =	printf("   %   % %09 % -% .5%  %d\n", 6, 7, 8, 9);
	printf("r1:%d	r2:%d\n", ret1, ret2);
printf("========== %s ==========\n", __func__);//===<<<>>
}
// le unite devient le % et on lui applique la modification

void	test_nb_neg()
{
	printf("=>{%hhd}\n", -0b11111000);
	printf("=>{%hhd}\n", -0b11111001);
	printf("=>{%hhd}\n", -0b11111010);
	printf("=>{%hhd}\n", -0b11111011);
	printf("=>{%hhd}\n", -0b11111100);
	printf("=>{%hhd}\n", -0b11111101);
	printf("=>{%hhd}\n", -0b11111110);
	printf("=>{%hhd}\n", -0b11111111);
	printf("\n\n\n\n\n%d	%d\n", -5 , (~(10)+1));
}


void	test_neg_bitwise(int a, int b)
{
	int	r1 = -a;;
	int	r2 = ((~a) + 1);
	printf("a:%d	b:%d\n", a, b);
	printf("-----------------------\n");
	printf("r1:%d	r2:%d\n", r1, r2);
//	+1
//	*truc
	r1 = a + b;
	r2 = ((((a) ^ (b))));
	printf("r1:%d	r2:%d\n", r1, r2);

	printf("a + b:%d\n", (a + b));
	printf("a - b:%d\n", (a - b));
	printf("a * b:%d\n", (a * b));
	printf("a / b:%d\n", (a / b));
	printf("a %% b:%d\n", (a % b));

	printf("----------\n");

	printf("a ^ b:%d\n", (a ^ b));
	printf("a & b:%d\n", (a & b));
	printf("a | b:%d\n", (a | b));
	// 10, -32
	// b-4, e-1
	printf("1==>%d\n", (a));
	printf("2==>%d\n", (~a));
	printf("3==>%d\n", (((((~a)+b)))));
	printf("4==>%d\n", (((~((~a)+b)))));
	printf("5==>%d\n", ((~(~((~a)+b))+b)));
	printf("6==>%d\n", (~(~(~((~a)+b))+b)));
	printf("7==>%d\n", ~(~(~(~((~a)+b))+b))+b);
	// a ^ b, a | b, a & b
	printf("\n\n[%d]::%d\n", (a + b), ((a & b) << 1) | (a ^ b));
	// a
	// b
	// a ^ b
	// a - b
	// ~((~a)+1)
}

void	print_cond(int a, int b)
{
	if	((a | b) == ((a ^ b) | (a & b)))
		printf("");
	else
		printf("NON4\n");
	if	((a | b) == ((a ^ b) + (a & b)))
		printf("");
	else
		printf("NON3\n");
	if	((a | b) == ((a ^ b) ^ (a & b)))
		printf("");
	else
		printf("NON2\n");
	if	(!(((a ^ b) & (a & b))))
		printf("");
	else
		printf("NON1\n");
}

void	test_bitwse(int ac ,char **av)
{
	if (ac >= 3)
	{
		int	a = atoi(av[1]);
		int	b = atoi(av[2]);
	//	test_neg_bitwise(atoi(a, b);
		print_cond(a, b);
	}

	int	i, j;
	for(j = -1000; j < 1000; j += 10)
	{
		for(i = -1000; i < 1000; i += 10)
		{
			print_cond(i, j);
		}
	}
}

void	prc_test()
{
	/*  on a des % comme type, et on les module  */
	printf("%.25%  %-10% %0 45%\n");
	printf("%.25%  % - 10 % % 0 45 %\n");

	printf("%#f  %#d\n", 424242, 0.1337);
	printf("%#f  %#d_%d\n", 111112, 0.6666, 343.87);
	printf("%1f %d_%f\n", 433333, 0.7777, 34);
	printf("%1f %d_%f	%d	-%0\n", 433333, 0.7777, 34, 36, 456, 76);
	
	/*  on a des modifieur */


}

void	multiple_precision()
{
	double	f = 42.1337;

	printf("[%f]\n", f);
	printf("[%.4f]\n", f);
	printf("[%.4.1f]\n", f);
	printf("[%.4.8.1f]\n", f);
	printf("[%.4.8.1.10f]\n", f);
}

void	multiple_int_min_size()
{
	int	d = 42424242;
	printf("[%03d]\n", d);
	printf("[%03 010d]\n", d);
	printf("[%03 010 08]\n", d);
	printf("[%03 010 08 014d]\n", d);
	printf("[%03 010 08 014 011d]\n", d);
}

void	multiple_left_justified()
{
	int	d = 42424242;
	printf("[%-03d]\n", d);
	printf("[%03 - 010d]\n", d);
	printf("[%03-010-08]\n", d);
	printf("[%03 - 010 08 014d]\n", d);
	printf("[%03-010 - 08-014-011d]\n", d);
}

void	space_inside_multiple()
{
	int	d = 42424242;
	printf("[%-03d]\n", d);
	printf("[%03  -  010d]\n", d);
	printf("[%03-010-08d]\n", d);
	printf("[% 03-010-08d]\n", d);
	printf("[%03    -    010 08 014d]\n", d);
	printf("[%03-010 - 08-014-011d]\n", d);
	printf("[%03-010 - 08-014-011 d]\n", d);
	printf("[%03-010 - 08-014-011    d]\n", d);

	d *= -1;
	printf("[%-03d]\n", d);
	printf("[%03  -  010d]\n", d);
	printf("[%03-010-08d]\n", d);
	printf("[% 03-010-08d]\n", d);
	printf("[%03    -    010 08 014d]\n", d);
	printf("[%03-010 - 08-014-011d]\n", d);
	printf("[%03-010 - 08-014-011 d]\n", d);
	printf("[%03-010 - 08-014-011    d]\n", d);

	d *= -1;
	printf("[%+-03d]\n", d);
	printf("[%03 + -  010d]\n", d);
	printf("[%03-+010-08d]\n", d);
	printf("[% 03-+010+-08d]\n", d);
	printf("[%03   ++ -  +  010 08 014d]\n", d);
	printf("[%03-010 +- 08-014-011d]\n", d);
	printf("[%03-+010 - 08-014-011 d]\n", d);
	printf("[%03-+010 - 08-014-011    d]\n", d);

	d *= -1;
	printf("[%+-03d]\n", d);
	printf("[%03 + -  010d]\n", d);
	printf("[%03-+010-08d]\n", d);
	printf("[% 03-+010-08d]\n", d);
	printf("[%03  +  -    010 08 014d]\n", d);
	printf("[%03-+010 - 08-014-011d]\n", d);
	printf("[%03-010++ - 08-014-011 d]\n", d);
	printf("[%03-010 +- 08-014-011    d]\n", d);
}

void	space_egal()
{
	int		d = 4256;
	float	f = 42.1337;
	printf("1[%d\n", d);
	printf("2[% d\n", d);
	printf("3[%\td\n", d);
	printf("4[%\vd\n", d);
	printf("5[%\nd\n", d);
	printf("6[%\rd\n", d);

	printf("-------------\n");

	printf("1[%5.2f]\n", f);	
	printf("2[% 5 . 2 f]\n", f);	
	printf("3[% 5.2 f]\n", f);	
	printf("4[%\t5.\t2\tf]\n", f);	
	printf("5[%\r5.2f]\n", f);	
	printf("6[%5.2f]\n", f);	

	printf("-------------\n");
	printf("1[%5.2f]\n", f);	
	printf("2[% 5.2 f]\n", f);	
	printf("3[% 5.2 f]\n", f);	
	printf("4[%  5.2 f]\n", f);	
	printf("5[%   5.2 f]\n", f);	
	printf("6[%     5.2f]\n", f);	
}

//	|size:
//	|------
//	|hh	1
//	|h	2
//	|	4
//	|l	8
//	|ll	8
//	|q	8
//	|j	8
//	|z	8
//	|t	8


void	size_arg_priority_test()
{
	long	long	int	ll = -3172638712687361287;
	long	l = (long)ll;
	int		i = (int)l;
	short	s = (short)l;
	char	c = (char)l;

	printf("ll:%lld	l:%ld	d:%d	s:%hd	c:%hhd\n", ll, l, i, s, c);
	printf("ll:%lld	l:%ld	d:%d	s:%hd	c:%hhd\n", ll, ll, ll, ll, ll);

	printf("---=================---------------\n");

//	printf("l:%ld	d:%d	s:%hd	c:%hhd\n", l, i, s, c);
//	printf("l:%ld	d:%d	s:%hd	c:%hhd\n", ll, ll, ll, ll);

	printf("q:%qd\n", l);
	printf("j:%jd\n", l);
	printf("z:%zd\n", l);
	printf("t:%td\n", l);
	printf("all:%qjztd\n", l);
	printf("------------------\n");

	printf("qd		:[%qd]\n", l);
	printf("qjd		:[%qjd]\n", l);
	printf("zqjd	:[%zqjd]\n", l);
	printf("qjtzd	:[%qjtzd]\n", l);
	printf("qjztd	:[%qjztd]\n", l);
	printf("------------------\n");
	printf("%d\n", l);
	printf("%hhd\n", l);
	printf("%ld\n", l);
	printf("%hhld\n", l);
	printf("%hld\n", l);
	printf("%lhd\n", l);
	printf("%lhhd\n", l);
	printf("%hhhd\n", l);
	printf("------------------\n");
	printf("ld  		:%ld\n", l);
	printf("hhd 		:%hhd\n", l);
	printf("d  		:%d\n", l);
	printf("hhd 		:%hhd\n", l);
	printf("hd 		:%hd\n", l);
	printf("hd 		:%hd\n", l);
	printf("hhd 		:%hhd\n", l);
	printf("hhhd 		:%hhhd\n", l);
	printf("hhhhd		:%hhhhd\n", l);

}

void	size_arg_char_priority_test()
{
	long	long	int	ll = -3172638712687361287 + 50 + 13;
	long	l = (long)ll;
	int		i = (int)l;
	short	s = (short)l;
	char	c = (char)l;

	printf("l:%lc	c:%c	s:%hc	c:%hhc\n", l, i, s, c);
	printf("l:%lc	c:%c	s:%hc	c:%hhc\n", ll, ll, ll, ll);
	printf("\n%c%c%c%c\n", c, i, s, c);

	printf("\n---=================---------------\n");


	printf("q:%qc\n", l);
	printf("j:%jc\n", l);
	printf("z:%zc\n", l);
	printf("t:%tc\n", l);
	printf("all:%qjztc\n", l);
	printf("------------------\n");

	printf("qc		:[%qc]\n", l);
	printf("qjc		:[%qjc]\n", l);
	printf("zqjc	:[%zqjc]\n", l);
	printf("qjtzc	:[%qjtzc]\n", l);
	printf("qjztc	:[%qjztc]\n", l);
	printf("------------------\n");
	printf("%c\n", l);
	printf("%hhc\n", l);
	printf("%lc\n", l);
	printf("%hhlc\n", l);
	printf("%hlc\n", l);
	printf("%lhc\n", l);
	printf("%lhhc\n", l);
	printf("%hhhc\n", l);
	printf("------------------\n");
	printf("lc  		:%lc\n", l);
	printf("hhc 		:%hhc\n", l);
	printf("c  		:%c\n", l);
	printf("hhc 		:%hhc\n", l);
	printf("hc 		:%hc\n", l);
	printf("hc 		:%hc\n", l);
	printf("hhc 		:%hhc\n", l);
	printf("hhhc 		:%hhhc\n", l);
	printf("hhhhc		:%hhhhc\n", l);

}

int	main(int ac, char **av)
{
//	test_with_ret();
//	test_printf();
//	test_int();
//	other_test();
//	other_test_2();
//	nb_arg_test();
//	sharp_test();
//	print_bit_test();
//	mantis_size_test();
//	mutiple_float_value();
//	float_structure_test();
	float_expo_all_mantis_0();
//	float_precision_test();
//	valid_format();
//printf("========== %s ==========\n", __func__);//===<<<>>
//	test_nb_neg();
//	test_bitwse(ac, av);


//	prc_test();
//	multiple_precision();		// last
//	multiple_int_min_size();	// last
//	multiple_left_justified();	// ok
//	space_inside_multiple();	// if one or more space --> do one before number (it is the signe place)

//	truc();
//	test_cast_transpose();
//	perturb();
//	ptr_test();
	
//	space_egal();		//	anly the regular space are ignored || the \[vtrn] reproduce the space and broke the chaine
//	size_arg_char_priority_test();
	return (0);
}

/*
	to parse:::::: {0123456789hlLqjzt+-. *$#}

	solo:	-->[+- 0Lqjztl] 		(and not in number)
	combo:	-->[ .nb | nb. | nb$ | *nb$ | hh | h]	:: nb -->number [1-9][0-9]*

//	##cast#	[hlqjzt]
//	|size:|
//	|-----|
//	|hh	 1|
//	|h	 2|		
//	|	 4|
//	|l	 8|
//	|ll	 8|
//	|q	 8|
//	|j	 8|
//	|z	 8|
//	|t	 8|
//
[+- 0L lqjkt] 	one shot ->0 when it-is first of number

[h|.|1-9|*|#]		combo_init
[h|0|0-9|$|type]		combo_end


TODO:	tester les limite des combo
Il a certain enchainement qui permettent des espace: 
		#->type,
 		*->[1-9],
		[[0-1]-9]->$


'' ==> tout autre symbole que les proposition

*		->	['', 1-9]
h		-> 	['', h]
.		->	['', [1-9]]
[1-9]	->	['' ,'$', '[0-9]', '.']
[0-9]	->	['' ,'$', '[0-9]', '.']
0		->	['', [1-9]]
#		->	[type]

:	*
:	*[1-9][0-9]...$
:	* [1-9][0-9]... $
:	h
:	hh
:	[1-9][0-9]...
:	[1-9][0-9]...'.'
:	'.'[1-9][0-9]...
:	'.'
:	0[1-9][0-9]...
:	#[type]

//	Quand on commence un combo, on ouvre un senario. Il faut le respecter si non
//	voild ce qui va se passer >





priority:
[h-l size_mode] 	--> the bigger
other:				--> the laste value
*/




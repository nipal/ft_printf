/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_long_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:25:22 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/21 00:00:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef	long double	t_ld;

typedef	struct	s_lf
{
	long		mantis;
	short		expo;		// don le bit de signe
}				t_lf;

union			u_lf
{
	long	double	fval;
	t_lf			comp;
};

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
	printf("%s", str);
	free(str);
/**/}

void	print_bit_str(unsigned char *data, int size, char *s_beg, char *s_end)
{
	printf("%s", s_beg);
	print_bit(data, size);
	printf("%s", s_end);
/**/}

void	print_bit_str_val(unsigned char *data, int size, char *s_beg, char *s_end)
{
	long	val;

	val = 0;
	if (size <= 8)
	{
		if (size == 8)
			val = *((long*)data);
		else if (size == 4)
			val = *((int*)data);
		else if (size == 2)
			val = *((short*)data) - 16446;
		else
			val = *((char*)data);
	}
	printf("%s", s_beg);
	printf("		|%20ld|	", val);
	print_bit(data, size);
	printf("%s", s_end);
/**/}



void	print_long_double_str_precision(long double val, char *s_beg, char *s_end, int precision)
{
	union	u_lf	conv;

	printf("------------------------------------------\n");

	printf("%s", s_beg);
	printf("			value							==> %.*Lf <==\n", precision, val);
	conv.fval = val;
	print_bit_str_val((unsigned char *)&val,                sizeof(val),   "			long double		-->|", "\n");
	print_bit_str_val((unsigned char *)&(conv.comp.mantis), sizeof(long),  "			mantisse		-->|", "\n");
	print_bit_str_val((unsigned char *)&(conv.comp.expo),   sizeof(short), "			expo			-->|", "\n");
	printf("%s", s_end);
}


void	print_long_double_str(long double val, char *s_beg, char *s_end)
{
	print_long_double_str_precision(val, s_beg, s_end, 200);
}


char	*make_title(char *text, int min_size, char vert, char hrz)
{
	int		i;
	int		name_len;
	int		line_len;
	int		len;
	int		beg;
	char	*title;

	name_len = strlen(text);
//	name_len = (name_len < min_size) ? min_size : name_len;	// max: man_len | min_size

	line_len = ((name_len < min_size) ? min_size : name_len) + 3;	// max: man_len | min_size
	beg = ((name_len < min_size) ? (min_size - name_len) / 2 : 0) + line_len + 1; // indice ou on va ecrire 

	len = (line_len) * 3;
	if (!(title = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	bzero(title, len + 1);
	i = 0;
	while (i < 3)
	{
		memset(title + (line_len * i) + 1, ((i == 1) ? ' ' : hrz) , line_len - 3);
		title[(line_len * i)] = vert;
		title[(line_len * (i + 1)) - 2] = vert;
		title[(line_len * (i + 1)) - 1] = '\n';
		i++;
	}
	memmove(title + beg, text, name_len);
	return (title);
}

void	test_long_double_composition()
{
	t_ld	pinf, minf, nan, one, zero;
	char	*s;

	pinf = +1.0 / +0.0;
	minf = -1.0 / +0.0;
	nan = 0.0 / 0.0;
	one = +1.0;
	zero = 0.0;
	
	print_long_double_str(pinf, (s = make_title("+inf ", 5, '|', '-')), "\n");
	free(s);
	print_long_double_str(minf, (s = make_title("-inf ", 5, '|', '-')), "\n");
	free(s);
	print_long_double_str(nan,  (s = make_title(" nan ", 5, '|', '-')), "\n");
	free(s);
	print_long_double_str(one,  (s = make_title(" one ", 5, '|', '-')), "\n");
	free(s);
	print_long_double_str(zero, (s = make_title(" zero", 5, '|', '-')), "\n");
	free(s);
	printf("\n\n=============================\n");
	printf("=============================\n");
	printf("=============================\n\n");
}

void	bcl_1()
{
	int		i;
	int		max;
	char	id_str[4];
	t_ld	val;

	max = 100;
	i = 0;
	id_str[2] = '\n';
	id_str[3] = '\0';
	while (i < max)
	{
		id_str[0] = ((i / 26) + 'a');
		id_str[1] = ((i % 26) + 'a');
		val = i;
		if (!((i - 1) & (i)) || i == 0)
			printf("**\n**\n====== %d  =======\n**\n**\n", (i));
		print_long_double_str(val, id_str, "\n");
		i++;
	}
}

void	bcl_expo(long mantis)
{
	int		i;
	int		max;
	char	id_str[4];
	union	u_lf val;

	max = 100;
	i = 0;
	id_str[2] = '\n';
	id_str[3] = '\0';
	bzero(&val, sizeof(val));
	val.comp.mantis = mantis;
	while (i < max)
	{
		id_str[0] = ((i / 26) + 'a');	id_str[1] = ((i % 26) + 'a');
		val.comp.expo = i + 16320;
		if (!((i - 1) & (i)) || i == 0)
			printf("**\n**\n====== %d  =======\n**\n**\n", (i));
		print_long_double_str(val.fval, id_str, "\n");
		i++;
	}
}

void	bcl_mantis(short expo)
{
	int		i;
	int		max;
	char	id_str[4];
	union	u_lf val;

	max = 32;

	i = 0;
	id_str[2] = '\n';
	id_str[3] = '\0';
//	bzero(&val, sizeof(val));
	val.fval = 0.0;
	val.comp.expo = expo;
	while (i < max)
	{
		id_str[0] = ((i / 26) + 'a');	id_str[1] = ((i % 26) + 'a');
		val.comp.mantis = i;
		if (!((i - 1) & (i)) || i == 0)
			printf("**\n**\n====== %d  =======\n**\n**\n", (i));
		print_long_double_str_precision(val.fval, id_str, "\n", 20000);
		i++;
	}
}

/*
 *
typedef	struct	s_lf
{
	long		mantis;
	short		expo;		// don le bit de signe
}				t_lf;

union			u_lf
{
	long	double	fval;
	t_lf			comp;
};
*/


/*
	Construction de plusieur long double ataon la valeur 1
*/ 
void	test_similariti()
{
	int	i;
	union	u_lf	a1, a2;

	i = 0;
	while (i < 64)
	{
		a1.comp.mantis = 1L << i;
		a1.comp.expo = 16383 - i + 63;
		print_long_double_str_precision(a1.fval, "", "", 20000);
		i++;
	}
}

/*
	--> Construction de plusieur long double ataon la valeur 1
	--> Comparaision de tout ces nombre
*/ 
void	test_similariti_2()
{
	int	i, j;
	union	u_lf	a1, diff, tab[64];

	// construct value
	i = 0;
	while (i < 64)
	{
		a1.comp.mantis = 1L << i;
		a1.comp.expo = 16383 - i + 63;
		tab[i] = a1;
		i++;
	}
	//	print value
	i = 0;
	while (i < 64)
	{
//		printf("[%3d]:	%.10Lf\n", i, tab[i].fval);
		i++;
	}
	printf("=================  compare  ==================\n");
	// test value
	j = 0;
	while (j < 64)
	{
		i = 0;
		while (i < 64)
		{
			if (tab[j].fval != tab[i].fval)
			{
			//	diff.fval = tab[j].fval - tab[i].fval;
			//	printf("[%3d][%3d]They arn't the same!!!::	diff:%.20000f\n", j, i, diff.fval);
			}
			else
				printf("[%3d][%3d]They are equal\n", j, i);
			i++;
		}
		j++;
	}

}

/*
Si la mantisse des long double ne respecte pas la convention/l'equivalent du bit implicite des float ou des double,
printf affichera ca valeur mais c'est une valeur qui ne serra pas exploitable.
*/
void	test_similariti_3()
{
	union	u_lf a, b, c, d, e, f, g, h, k, l, m, n, o, p, q;

	a.comp.expo = 16383 + 63;
	a.comp.mantis = 1;
	b.comp.expo = 16383 + 63;
	b.comp.mantis = 2;

	c.fval = b.fval + a.fval;
	d.fval = b.fval - a.fval;
	e.fval = b.fval * a.fval;
	f.fval = b.fval / a.fval;

printf("a:%Lf	b:%Lf	c:%Lf	d:%Lf	e:%Lf	f:%Lf\n", a.fval, b.fval, c.fval, d.fval, e.fval, f.fval);
print_long_double_str(a.fval, "_\na|\n-", "\n");
print_long_double_str(b.fval, "_\nb|\n-", "\n");
print_long_double_str(c.fval, "_\nc|\n-", "\n");
print_long_double_str(d.fval, "_\nd|\n-", "\n");
print_long_double_str(e.fval, "_\ne|\n-", "\n");
print_long_double_str(f.fval, "_\nf|\n-", "\n");
printf("*******************************************\n");
printf("*******************************************\n");

long	double	one = 1.0;

	b.fval = a.fval;
	g.fval = a.fval + 0.0;
	h.fval = a.fval * 1;
	k.fval = a.fval * 1.0;
	l.fval = a.fval + a.fval;
	m.fval = 		(long double)a.fval;
	n.fval = 		*((long double*)&a.fval);
	o.fval = a.fval * 2.0;
	p.fval = a.fval * one;

	c.fval = b.fval + a.fval;
	d.fval = b.fval - a.fval;
	e.fval = b.fval * a.fval;
	f.fval = b.fval / a.fval;

printf("a:%Lf	b:%Lf	c:%Lf	d:%Lf	e:%Lf	f:%Lf\n", a.fval, b.fval, c.fval, d.fval, e.fval, f.fval);
print_long_double_str(a.fval, "_\na|\n-", "\n");
print_long_double_str(b.fval, "_\nb|\n-", "\n");
print_long_double_str(c.fval, "_\nc|\n-", "\n");
print_long_double_str(d.fval, "_\nd|\n-", "\n");
print_long_double_str(e.fval, "_\ne|\n-", "\n");
print_long_double_str(f.fval, "_\nf|\n-", "\n");

printf("\n*******************************************\n");
printf("*******************************************\n\n");






print_long_double_str(b.fval, "__________________\n = a.fval        |\n__________________\n", "\n");
print_long_double_str(g.fval, "__________________\n + 0.0;          |\n__________________\n", "\n");
print_long_double_str(h.fval, "__________________\n * 1;            |\n__________________\n", "\n");
print_long_double_str(k.fval, "__________________\n * 1.0;          |\n__________________\n", "\n");
print_long_double_str(o.fval, "__________________\n * 2.0;          |\n__________________\n", "\n");
print_long_double_str(p.fval, "__________________\n * one;          |\n__________________\n", "\n");
print_long_double_str(l.fval, "__________________\n + a.fval;       |\n__________________\n", "\n");
print_long_double_str(m.fval, "__________________\n (long double)   |\n__________________\n", "\n");
print_long_double_str(n.fval, "__________________\n *(long double*)&|\n__________________\n", "\n");



	if (a.fval > b.fval)
		printf("a > b");
	if (a.fval >= b.fval)
		printf("a >= b");
	if (a.fval == b.fval)
		printf("a == b");
	if (a.fval <= b.fval)
		printf("a <= b");
	if (a.fval < b.fval)
		printf("a < b");



	b = a;
	printf("\n\na:%Lf	b:%Lf\n", a.fval, b.fval);
	if (a.fval == b.fval)
		printf("ok smart		:%Lf\n", a.fval);
	else
		printf("too strict		:%Lf\n", a.fval);

}

void	test_make_title()
{
	char	*s;

	s = make_title("Lapin est le plus beau", 100, '|', '=');
	printf("%s", s);
	s = make_title("c'est trop simple", 100, '|', '=');
	printf("%s", s);
	s = make_title("on peut ecrire plein de truc c'est boien mis en forme", 100, '|', '=');
	printf("%s", s);
	s = make_title("meintenant plus d'excuse", 100, '|', '=');
	printf("%s", s);
}

int	main()
{
	test_long_double_composition();
//	test_nan_div();
//	bcl_1();
//	bcl_expo(1L << 63);
//	bcl_mantis(0);
//	test_similariti();
//	test_similariti_2();
//	test_similariti_3();
//	test_make_title();
	return (0);
}

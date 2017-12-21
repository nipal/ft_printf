#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BISTRO_LEN 30
#define BISTRO_UNITE 1000000

#define BISTRO_DEBUG 1
#define F_TO_INT *(int*)&
#define INT_TO_F *(float*)&

typedef struct	s_bistro
{
	int		sign;
	long	number[BISTRO_LEN];		// la data du nombre
	int		block_mult;				// le nombre de block qu'on multiplie // moins sur
	int		block_max;				// le nombre de block utiliser
}				t_bistro;

void	bistro_set_0_in(t_bistro *nb)
{
	bzero(nb, sizeof(t_bistro));
}

void	bistro_copie(t_bistro *from, t_bistro *to)
{
	int	i;

	i = 0;
	while (i < BISTRO_LEN)
	{
		to->number[i] = from->number[i];
		i++;
	}
}

void	bistro_add_in(t_bistro *a, t_bistro *b, t_bistro *result)
{
	int		i;
	long	tmp;
	long	ret;

	i = 0;
	ret = 0;
	while (i < BISTRO_LEN)
	{
		tmp = a->number[i] + b->number[i] + ret;
		ret = tmp / BISTRO_UNITE;
		result->number[i] = tmp % BISTRO_UNITE;
		i++;
	}
}

void	bistro_mult_one_in(t_bistro *a, long nb, t_bistro *result)
{
	int			i;
	long		tmp;
	long		ret;
	long		ret_add;
	t_bistro	tmp_nb;

	i = 0;
	ret = 0;
	ret_add = 0;
	bzero(&tmp_nb, sizeof(tmp_nb));
	while (i < BISTRO_LEN)
	{
		tmp = a->number[i] * nb + ret;
		ret = tmp / BISTRO_UNITE;
		tmp_nb.number[i] = tmp % BISTRO_UNITE;
//		printf("-------------------------\n");
//		printf("a[%d] * nb:	%ld * %ld = %ld\n", i, a->number[i], nb, tmp_nb.number[i]);
		i++;
	}
	bistro_copie(&tmp_nb, result);
}

//	on decale tout les nombre, osef la perte d'info
void	bistro_pow_unite_in(t_bistro *a, int pow, t_bistro *result)
{
	int	i;

	if (pow > 0)
	{
		i = BISTRO_LEN - 1;
		while (i >= pow)
		{
			result->number[i] = a->number[i - pow];
			i--;
		}
		while (i >= 0)
		{
			result->number[i] = 0;
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < BISTRO_LEN - pow)
		{
			result->number[i] = a->number[i + pow];
			i++;
		}
		while (i < BISTRO_LEN)
		{
			result->number[i] = 0;
			i++;
		}	
	}
}

void	bistro_mult_in(t_bistro *a, t_bistro *b, t_bistro *result)
{
	t_bistro	tmp;
	t_bistro	tmp_sum;
	int			i;

	bzero(&tmp, sizeof(tmp));
	bzero(&tmp_sum, sizeof(tmp_sum));
	i = 0;
	while (i < BISTRO_LEN)
	{
		bistro_mult_one_in(a, b->number[i], &tmp);
		bistro_pow_unite_in(&tmp, i, &tmp);
		bistro_add_in(&tmp, &tmp_sum, &tmp_sum);
		i++;
	}
	bistro_copie(&tmp_sum, result);
}

//	ne fonctionne bien qu'avec un nb < BISTRO_UNITE
void	bistro_pow_in(int nb, int pow, t_bistro *res)
{
	if (pow <= 0)
	{
		bzero(res, sizeof(t_bistro));
		res->number[0] = (pow < 0) ? 0: 1;
		return ;
	}
	else if (pow & 1)
	{
		bistro_pow_in(nb, pow - 1, res);
		bistro_mult_one_in(res, nb, res);
	}
	else
	{
		bistro_pow_in(nb, pow / 2, res);
		bistro_mult_in(res, res, res);
	}
}

void	bistro_print(t_bistro *nb)
{
	int	i;

	i = BISTRO_LEN - 1;
	while (i >= 0)
	{
		printf("%06ld ", nb->number[i]);
		i--;
	}
	printf("\n");
}

void	bistro_print_str(t_bistro *nb, char *str)
{
	int		i;
	char	c;

	i = BISTRO_LEN - 1;
	printf("%s", str);
	while (i >= 0)
	{
		if (BISTRO_DEBUG == 1)
  			printf("%06ld", nb->number[i]);
		else
			printf("%06ld ", nb->number[i]);
		i--;
	}
	printf("\n");
}

# define SYM_ASK 0
# define SYM_MIN 1
# define SYM_MAJ 2

char	**symbole_base1(int flag)
{
	static	char	symbole_min[17] = "0123456789abcdef";
	static	char	symbole_maj[17] = "0123456789ABCDEF";
	static	char	*now = NULL;
	
	if (!now)
		now = symbole_min;
	if (flag == SYM_MIN)
		now = symbole_min;
	else if (flag == SYM_MAJ)
		now = symbole_maj;
	return (&now);
}

int	put_integer_s(long val, int base, char *buff, int buff_len)
{
	int				i;
	int				nb;
	int				s;
	static	char	**ptr = NULL;
	char			*symbol;
	
	if (!ptr)
		ptr = symbole_base1(SYM_ASK);
	symbol = *ptr;
	s = val < 0;
	val = (val > 0) ? val : -val;
	i = 0;
	if (!val)
		return (!!(buff[buff_len - 1] = '0'));
	while (val)
	{
		buff[buff_len - i - 1] = symbol[(val % base)];
		val /= base;
		i++;
	}
	if (!s)
		return (i);
	buff[buff_len - i - 1] = '-';
	return (++i);
}

int	put_integer_u(unsigned long val, int base, char *buff, int buff_len)
{
	int				i;
	int				nb;
	static	char	**ptr = NULL;
	char			*symbol;
	
	if (!ptr)
		ptr = symbole_base1(SYM_ASK);
	symbol = *ptr;
	i = 0;
	if (!val)
		return (!!(buff[buff_len] = '0'));
	while (val)
	{
		buff[buff_len - i] = symbol[(val % base)];
		val /= base;
		i++;
	}
		return (i);
}

/////////////
void	test_put_integer()
{
	char	buff[42];
	int		ret;
	int		a = 0xFF;
	int		b = 0;
	int		c = -1;
	int		d = 1;
	int		e = -0xFF;

	e = 0;
	*(unsigned int*)(&e) = (unsigned int)-0xFF;

	buff[41] = '\0';
	printf("min:------------\n");
	ret = put_integer_s(a, 2, buff, sizeof(buff) - 2);	
//	printf("a,2 %10d	%s\n", a, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(a, 4, buff, sizeof(buff) - 2);
//	printf("a,4 %10d	%s\n", a, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(a, 8, buff, sizeof(buff) - 2);
//	printf("a,8 %10o	%s\n", a, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(a, 16, buff, sizeof(buff) - 2);
//	printf("a,16 %10x	%s\n", a, buff + (sizeof(buff) - 1 - ret));
//
//	ret = put_integer_s(b, 2, buff, sizeof(buff) - 2);	
//	printf("b,2 %10d	%s\n", b, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(b, 4, buff, sizeof(buff) - 2);
//	printf("b,4 %10d	%s\n", b, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(b, 8, buff, sizeof(buff) - 2);
//	printf("b,8 %10o	%s\n", b, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(b, 16, buff, sizeof(buff) - 2);
//	printf("b,16 %10x	%s\n", b, buff + (sizeof(buff) - 1 - ret));

//	ret = put_integer_s(d, 2, buff, sizeof(buff) - 2);	
//	printf("d,2 %10d	%s\n", d, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(d, 4, buff, sizeof(buff) - 2);
//	printf("d,4 %10d	%s\n", d, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(d, 8, buff, sizeof(buff) - 2);
//	printf("d,8 %10o	%s\n", d, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(d, 16, buff, sizeof(buff) - 2);
//	printf("d,16 %10x	%s\n", d, buff + (sizeof(buff) - 1 - ret));

	ret = put_integer_s(c, 2, buff, sizeof(buff) - 2);	
	printf("c,2 %10d	%s\n", c, buff + (sizeof(buff) - 1 - ret));
	ret = put_integer_s(c, 4, buff, sizeof(buff) - 2);
	printf("c,4 %10d	%s\n", c, buff + (sizeof(buff) - 1 - ret));

//	c = 0;
//	*(unsigned int*)(&c) = (unsigned int)(-1);

	ret = put_integer_u((unsigned int)c, 8, buff, sizeof(buff) - 2);
	printf("c,8 %10o	%s\n", c, buff + (sizeof(buff) - 1 - ret));
	ret = put_integer_u((unsigned int)c, 16, buff, sizeof(buff) - 2);
	printf("c,16 %10x	%s\n", c, buff + (sizeof(buff) - 1 - ret));


	ret = put_integer_s(e, 2, buff, sizeof(buff) - 2);	
	printf("e,2 %10d	%s\n", e, buff + (sizeof(buff) - 1 - ret));
	ret = put_integer_s(e, 4, buff, sizeof(buff) - 2);
	printf("e,4 %10d	%s\n", e, buff + (sizeof(buff) - 1 - ret));

//	e = 0;
//	*(unsigned int*)(&e) = (unsigned int)(-0xFF);

	ret = put_integer_u((unsigned int)e, 8, buff, sizeof(buff) - 2);
	printf("e,8 %10o	%s\n", e, buff + (sizeof(buff) - 1 - ret));
	ret = put_integer_u((unsigned int)e, 16, buff, sizeof(buff) - 2);
	printf("e,16 %10x	%s\n", e, buff + (sizeof(buff) - 1 - ret));

	printf("maj:------------\n");
	symbole_base1(SYM_MAJ);

//	ret = put_integer_s(a, 2, buff, sizeof(buff) - 2);	
//	printf("a,2 %10d	%s\n", a, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(a, 4, buff, sizeof(buff) - 2);
//	printf("a,4 %10d	%s\n", a, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(a, 8, buff, sizeof(buff) - 2);
//	printf("a,8 %10o	%s\n", a, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(a, 16, buff, sizeof(buff) - 2);
//	printf("a,16 %10x	%s\n", a, buff + (sizeof(buff) - 1 - ret));
//
//	ret = put_integer_s(b, 2, buff, sizeof(buff) - 2);	
//	printf("b,2 %10d	%s\n", b, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(b, 4, buff, sizeof(buff) - 2);
//	printf("b,4 %10d	%s\n", b, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(b, 8, buff, sizeof(buff) - 2);
//	printf("b,8 %10o	%s\n", b, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(b, 16, buff, sizeof(buff) - 2);
//	printf("b,16 %10x	%s\n", b, buff + (sizeof(buff) - 1 - ret));

//	ret = put_integer_s(d, 2, buff, sizeof(buff) - 2);	
//	printf("d,2 %10d	%s\n", d, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(d, 4, buff, sizeof(buff) - 2);
//	printf("d,4 %10d	%s\n", d, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(d, 8, buff, sizeof(buff) - 2);
//	printf("d,8 %10o	%s\n", d, buff + (sizeof(buff) - 1 - ret));
//	ret = put_integer_s(d, 16, buff, sizeof(buff) - 2);
//	printf("d,16 %10X	%s\n", d, buff + (sizeof(buff) - 1 - ret));


//	c = -1;
	ret = put_integer_s(c, 2, buff, sizeof(buff) - 2);	
	printf("c,2 %10d	%s\n", c, buff + (sizeof(buff) - 1 - ret));
	ret = put_integer_s(c, 4, buff, sizeof(buff) - 2);
	printf("c,4 %10d	%s\n", c, buff + (sizeof(buff) - 1 - ret));

//	c = 0;
//	*((unsigned int*)(&c)) = (unsigned int)-1;
	ret = put_integer_u((unsigned int)c, 8, buff, sizeof(buff) - 2);
	printf("c,8 %10o	%s\n", c, buff + (sizeof(buff) - 1 - ret));
	ret = put_integer_u((unsigned int)c, 16, buff, sizeof(buff) - 2);
	printf("c,16 %10X	%s\n", c, buff + (sizeof(buff) - 1 - ret));

//	e = -0XFF;
	ret = put_integer_s(e, 2, buff, sizeof(buff) - 2);	
	printf("e,2 %10d	%s\n", e, buff + (sizeof(buff) - 1 - ret));
	ret = put_integer_s(e, 4, buff, sizeof(buff) - 2);
	printf("e,4 %10d	%s\n", e, buff + (sizeof(buff) - 1 - ret));

//	e = 0;
//	*(unsigned int*)(&e) = (unsigned int)-0XFF;
	ret = put_integer_u((unsigned int)e, 8, buff, sizeof(buff) - 2);
	printf("e,8 %10o	%s\n", e, buff + (sizeof(buff) - 1 - ret));
	ret = put_integer_u((unsigned int)e, 16, buff, sizeof(buff) - 2);
	printf("e,16 %10X	%s\n", e, buff + (sizeof(buff) - 1 - ret));
}
/////////////

//

/*
int	put_integer_u(unsigned long val, int base, char *buff, int buff_len)
{
	int				i;
	int				nb;
	int				s;
	static	char	**base = NULL;
	
	if (!base)
		base = symbole_base1(SYM_ASK);
	i = 0;
	if (!val)
		return (!!(buff[buff_len] = '0'));
	while (val)
	{
		buff[buff_len - i] = symbol[(val % base)];
		val /= base;
		i++;
	}
	return (i);
}
*/
//	on renvoie un poointeur sur le debut du nombre

//char	*bistro_to_a(t_bistro *nb, char *buff, int len)
//{
//	int		l;
//	int		i;
//	char	c;
//	int		beg;
//
//	i = len - 1;
//	l = BISTRO_LEN - 1;
//	while()
//	{
//		i -= put_integer_min(nb->number[l], );
//	}
//	return (buff + i);
//}

void	bistro_define_len(t_bistro *nb, int *nb_block, int *nb_digit)
{
	int		i;
	int		pow_10;
	
	i = BISTRO_LEN - 1;
	while (i >= 0 && !nb->number[i])
		i--;
	*nb_block = i + 1;
	*nb_digit = 6 * i;
	pow_10 = 1;
	if (!*nb_block)
		*nb_digit = 0;
	else
		while (pow_10 < BISTRO_UNITE && nb->number[i] >= pow_10 && pow_10 *= 10)
			*nb_digit++;
}

//	on pourrai aussi faire un truc comme pour les int
//int	put_integer_s(long val, int base, char *buff, int buff_len)
int		bistro_to_str(t_bistro *nb, char *buff, int len_buff)
{
	int		nb_digit;
	int		nb_block;
	int		i;
	int		j;

	str[BISTRO_LEN * 6] = '\0';
	bistro_define_len(nb, &nb_block, &nb_digit);
	i = 0;
	j = len_buff - 6;
	while (i < nb_block - 1)
	{
		put_integer_s(nb->number[i] + BISTRO_UNITE, 10, buff + j - 1, 7); // il fut mettre combien??
		j -= 6;
		i++;
	}
	put_integer_s(nb->number[i], 10, buff + j, 6);
	return (nb_digit);
}

/////////////////// FLOAT /////////////////////////////////////////

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
	printf("%s:[%200.150f]:	[%s]\n", s, f, str);
}

long	power(long val, int pow)
{
	long	tmp;

	if (pow <= 0)
		return (1);
	else if (pow & 1)
		return (val * power(val, pow - 1));
	tmp = power(val, pow / 2);
	return (tmp * tmp);
}

float	float_add_mantis(float val, int add)
{
	int	value;

	value = F_TO_INT val;
	value += add;
	return (INT_TO_F value);
}

float	float_construct(int sign, int a, int b)
{
	int	val;

	val = (!!(sign) << 31) | ((a & ((1 << 8) - 1)) << 23) | (b & ((1 << 23) - 1));
	return (INT_TO_F val);
}

void	float_get_value(float f, int *sign, int *expo, int *mantis)
{
	*sign = !!((F_TO_INT f) & 1 << 31);	// 0-> '+'	1-> '-'
	*expo = ((F_TO_INT f) >> 23 & 0xFF) - 127;
	*mantis = (F_TO_INT f) & ((1 << 23) - 1);
}

void	float_print_info(float f)
{
	int	sign;
	int	expo;
	int	mantis;

	float_get_value(f, &sign, &expo, &mantis);
	print_float_bit(f, "");
	printf("%202c	[%c|%8d|%23d]\n", ' ', ((sign) ? '-' : '+'), expo, mantis);
//	printf();
}


//////////////// 	 TEST FLOAT	    //////////////////////////////////////////

void	test_float()
{
	float_print_info(1);
}

void	test_type_char_size()
{
	float			f;
	double			d;
	long	double	ld;

	f = 1.0 / 0.0;
	d = 1.0 / 0.0;
	ld = 1.0 / 0.0;
	print_bit_str(&f, sizeof(f), "inf	float");
	print_bit_str(&d, sizeof(d), "inf	double");
	print_bit_str(&ld, sizeof(ld), "inf	long double");
}

void	print_float_check_diff(float f, char *str)
{
	printf("%s", str);
	printf("printf->	%.170f\n", f);
	printf("yours->		");
	print_float(f);
}

void	test_print_float()
{
	float 	f0_0 	= float_construct(0, 0, 0);
	float 	f_min 	= float_construct(0, 0, 1);
	float 	f0_2 	= float_construct(0, 0, 2);
	float 	f0_3 	= float_construct(0, 0, 3);
	float 	f0_4 	= float_construct(0, 0, 4);
	float	f1_0	= float_construct(0, 1, 0);
	float	f1_1	= float_construct(0, 1, 1);
	float	f2_0	= float_construct(0, 2, 0);
	float	f2_1	= float_construct(0, 2, 1);
	float	f3_0	= float_construct(0, 3, 0);
	float	f3_1	= float_construct(0, 3, 1);
	float	f3_10	= float_construct(0, 3, 10);

	float	f128_0	= float_construct(0, 128, 0);
	float	f128_1	= float_construct(0, 128, 1);
	float	f129_0	= float_construct(0, 129, 0);
	float	f129_1	= float_construct(0, 129, 1);
	float	f130_0	= float_construct(0, 130, 0);
	float	f130_1	= float_construct(0, 130, 1);
	float	f130_10	= float_construct(0, 130, 10);


	float	f_max_0	= float_construct(0, 254, 0);
	float	f_max 	= float_construct(0, 254, (1 << 23) - 1);


	print_float_check_diff(f0_0,    "------------------------------------ f0_0 ------------------------------------\n");
	print_float_check_diff(f_min,   "------------------------------------ f0_1 ------------------------------------\n");
	print_float_check_diff(f0_2,  "\n------------------------------------ f0_2 ------------------------------------\n");
	print_float_check_diff(f0_3,  "\n------------------------------------ f0_3 ------------------------------------\n");
	print_float_check_diff(f0_4,  "\n------------------------------------ f0_4 ------------------------------------\n");
	print_float_check_diff(f1_0,  "\n------------------------------------ f1_0 ------------------------------------\n");
//	print_float_check_diff(f1_1,  "\n------------------------------------ f1_1 ------------------------------------\n");
//	print_float_check_diff(f2_0,  "\n------------------------------------ f2_0 ------------------------------------\n");
//	print_float_check_diff(f2_1,  "\n------------------------------------ f2_1 ------------------------------------\n");
//	print_float_check_diff(f3_0,  "\n------------------------------------ f3_0 ------------------------------------\n");
//	print_float_check_diff(f3_1,  "\n------------------------------------ f3_1 ------------------------------------\n");
//	print_float_check_diff(f3_10, "\n------------------------------------ f3_10 ------------------------------------\n");

//	print_float_check_diff(f128_0,  "\n------------------------------------ f128_0 ------------------------------------\n");
//	print_float_check_diff(f128_1,  "\n------------------------------------ f128_1 ------------------------------------\n");
//	print_float_check_diff(f129_0,  "\n------------------------------------ f129_0 ------------------------------------\n");
//	print_float_check_diff(f129_1,  "\n------------------------------------ f129_1 ------------------------------------\n");
//	print_float_check_diff(f130_0,  "\n------------------------------------ f130_0 ------------------------------------\n");
//	print_float_check_diff(f130_1,  "\n------------------------------------ f130_1 ------------------------------------\n");
//	print_float_check_diff(f130_10, "\n------------------------------------ f130_10 ------------------------------------\n");
//
//	print_float_check_diff(f_max, "\n------------------------------------ f_max ------------------------------------\n");
//	print_float_check_diff(f_max_0, "\n------------------------------------ f_max_0 ------------------------------------\n");
}

//////////////// TEST BISTROMATIQUE //////////////////////////////////////////

void	test_bitro_print()
{
	t_bistro	a;

	bzero(&a, sizeof(a));
	a.number[0] = 42;
	a.number[1] = 1945;
	a.number[2] = 990099;
	a.number[3] = 3;
	bistro_print(&a);
}

void	test_bistro_all()
{
	t_bistro	a, b, c, d, e, f, g, h, j, k1, k2, k3;
	int			i;

	bzero(&a, sizeof(a));
	bzero(&b, sizeof(b));
	bzero(&c, sizeof(c));
	bzero(&d, sizeof(d));
	bzero(&e, sizeof(e));
	bzero(&f, sizeof(f));
	bzero(&g, sizeof(f));
	bzero(&h, sizeof(f));
	bzero(&j, sizeof(f));
	bzero(&k1, sizeof(f));
	bzero(&k2, sizeof(f));
	bzero(&k3, sizeof(f));
	i = 0;
	a.number[0] = 18;
	b.number[0] = 9;
	while (i < BISTRO_LEN - 2)
	{
		if (i < 4)
		{
			a.number[i + 1] = a.number[i] * 10 + a.number[0];
			b.number[i + 1] = b.number[i] * 10 + b.number[0];
		}
		else
		{
			a.number[i + 1] = a.number[i];
			b.number[i + 1] = b.number[i];
		}
		i++;
	}
	i = 0;
	d.number[0] = 1;
	e.number[0] = 2;
	g.number[0] = 3;
	h.number[0] = 4;
	j.number[0] = 5;
	k1.number[0] = 5;
	k2.number[0] = 5;
	while (i < (BISTRO_LEN / 2) - 1)
	{
		if (i < 5)
		{
			d.number[i + 1] = d.number[i] * 10 + d.number[0];
			e.number[i + 1] = e.number[i] * 10 + e.number[0];
			g.number[i + 1] = g.number[i] * 10 + g.number[0];
			h.number[i + 1] = h.number[i] * 10 + h.number[0];
			j.number[i + 1] = j.number[i] * 10 + j.number[0];
		}
		else
		{
			d.number[i + 1] = d.number[i];
			e.number[i + 1] = e.number[i];
			g.number[i + 1] = g.number[i];
			h.number[i + 1] = h.number[i];
			j.number[i + 1] = j.number[i];
		}
		i++;
	}
	bistro_print_str(&g, "\n\ng: 33.. * 3		");
	bistro_print_str(&h, "h: 44.. * 100		");
	bistro_print_str(&j, "j: 55.. * 100		");
	bistro_print_str(&k1, "k2:			");
	bistro_print_str(&k2, "k1:			");


	bistro_add_in(&a, &b, &c);
	bistro_mult_in(&d, &e, &f);
	bistro_mult_one_in(&g, 3, &g);
	bistro_mult_one_in(&h, 100, &h);
	bistro_mult_one_in(&j, 23455, &j);
	bistro_mult_in(&k1, &k2, &k3);

	bistro_print_str(&a, "\n\na:			");
	bistro_print_str(&b, "a:			");
	bistro_print_str(&c, "a + b:			");

	bistro_print_str(&d, "\nd:			");
	bistro_print_str(&e, "e:			");
	bistro_print_str(&f, "d * e:			");

	bistro_print_str(&g, "\ng: 33.. * 3		");
	bistro_print_str(&h, "h: 44.. * 100		");
	bistro_print_str(&j, "j: 55.. * 12455		");

	bistro_print_str(&k1, "\nk1:			");
	bistro_print_str(&k2, "k2:			");
	bistro_print_str(&k3, "k1 * k2:		");



}

void	debug_mult_one()
{
	int	i;
	t_bistro	a, b, c, d;

	bzero(&a, sizeof(t_bistro));
	bzero(&b, sizeof(t_bistro));
	bzero(&c, sizeof(t_bistro));
	bzero(&d, sizeof(t_bistro));
	i = 0;
	a.number[0] = 1;
	b.number[0] = 2;
	while (i < BISTRO_LEN - 2)
	{
		a.number[i + 1] = a.number[i];
		if (i < 5)
		{
			b.number[i + 1] = b.number[i] * 10 + b.number[0];
		}
		else
		{
			b.number[i + 1] = b.number[i];
		}
		i++;
	}

	bistro_mult_one_in(&b, 532654, &c);
	bistro_mult_one_in(&a, 532654, &d);

	bistro_print_str(&a, "a				");
	bistro_print_str(&b, "b				");
	bistro_print_str(&d, "\n\na * 532654			");
	bistro_print_str(&c, "b * 532654			");
}

void	test_bistro_pow()
{
	t_bistro	nb;

	bistro_pow_in(5, 97, &nb);
	bistro_print_str(&nb, "5 ^ 97:	");
}

void	test_bistromatique()
{
//	test print
//	test_bitro_print();
//	test_bistro_all();
//	debug_mult_one();
//	test_bistro_pow();

//	test power		+ make power
//	test coma_print	+ make coma_print
	
}

void	test_the_float()
{
	test_float();
}

int		main()
{
//	test_bistromatique();
//	test_the_float();
//	test_type_char_size();
//	test_print_float();
	test_put_integer();
	return (0);
}

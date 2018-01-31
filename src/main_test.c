/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:10:43 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/31 22:23:13 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int		all_different(char *format, int id_fmt)
{
	char	c;
	int		cond;
	int		id;
	int		j;

//	printf("=========== all_different  ===================\n");
	id = id_fmt;
	cond = 1;
	while (--id >= 0)
	{
		c = format[id];
		j = id + 1;
//		printf("j:%d	id:%d	id_fmt:%d\n", j, id, id_fmt);
		while (j <= id_fmt)
		{
			if (format[j] == c)
				cond = 0;
//			printf("%s\n%*c^ %*c[%d] %s\n", format, j, ' ', id_fmt - j + 1, ' ', j, ((cond) ? " <--- XXXXX": ""));
			j++;
		}
		if (!cond)
			return (0);
	}
	return (1);
}






//	
//	for len in range [1, 5]
//		for i in range []
//

double	log_a(double val, double base)
{
	if (val == 0)
		return (0);
	if (base > 0)
		return (log(val) / log(base));
	else
		return (0.0 / 0.0);
}

void	flag_test_general(double val)
{
	char	format[33];
	char	result[512];
	char	str_format[33] = "                                ";
	char	flags[] = " +-0";	// len = 5
//	char	flags[] = " -0";	// len = 5
	int		flags_size;
	int		i, j, k, l, m;
	int		tmp;
	double	max;
	(void)i;(void)j;(void)k;(void)m;(void)l;(void)str_format;(void)flags;(void)flags_size;(void)val;(void)result;

	flags_size = sizeof(flags) / sizeof(char) - 1;
	str_format[flags_size] = '\0';
	max = pow(flags_size, flags_size); 

	printf("flags_size:%d	val:%f\n", flags_size, val);
	printf("max:%f\n", max);
	printf("=========================\n");
	i = 0;
	while (i < max)
	{
		bzero(format, sizeof(format));
		tmp = i;
		j = 0;
		while (j < flags_size)
		{
			k = tmp % flags_size;
			tmp /= flags_size;
			str_format[flags_size - j - 1] = flags[k];
			j++;
		}
		if (1||all_different(str_format, flags_size - 1))
		{
			m = (int)log_a(i, flags_size);
			sprintf(format, "%%%-sd", str_format + (flags_size - m - 1));
			bzero(result, sizeof(result));
			sprintf(result, format, (int)val);
			printf("%-*s => {%s}\n", flags_size + 2, format, result);
		}
		i++;
	}
}
/*

typedef	enum	e_type
{
	e_char = 0,
	e_short,
	e_int,
	e_long,
	e_unsigned_char,
	e_unsigned_short,
	e_unsigned_int,
	e_unsigned_long,
	e_float,
	e_double,
	e_long_double,
	e_char_ptr,
	e_void_ptr
}				t_id_type;

typedef	union	u_type
{
	char				c;
	short				s;
	int					i;
	long				l;
	unsigned	char	uc;
	unsigned	short	us;
	unsigned	int		ui;
	unsigned	long	ul;
	float				f;
	double				d;
	long	double		ld;
	char				*t;	// text
	void				*p;
}				t_utype;

typedef	struct	s_type
{
	t_id_type	id;
	t_utype		val;
}				t_type;
*/

# define SMALL_BUFF 33
# define LARGE_BUFF 513

int		id_is_free(int *id_used, int nb_used, int value)
{
	while (--nb_used >= 0)
		if (id_used[nb_used] == value)
			return (0);
	return (1);
}

void	flag_set_id_free(int *id_used, int *id_free, int nb_used, int max_id)
{
	int	i;	
	int	j;

	i = 0;
	j = 0;
	while (i < max_id)
	{
		if (id_is_free(id_used, nb_used, i))
		{
			id_free[j] = i;
			j++;
		}
	}
}
void	test_all()
{
	char	type[] = "diouxXeEfFgGaAcCsSpnm%";
	int		type_size;
	char	type_format[SMALL_BUFF];

	char	flag[] = " +-0#";
	int		flag_size;
	char	flag_format[SMALL_BUFF];
	int		flag_id_used[SMALL_BUFF][SMALL_BUFF];
	int		flag_id_free[SMALL_BUFF][SMALL_BUFF];


	flag_size = sizeof(flag) / sizeof(char);

	int		i, j, k, l, m, n, o, id_type, len;

	(void)flag;(void)flag_size;(void)i;(void)j;(void)k;(void)l;(void)m;(void)n;(void)o;(void)id_type;
	(void)flag_format;(void)flag_id_used;(void)flag_id_free;(void)type_size;(void)type_format;(void)type;
	bzero(flag_format, sizeof(flag_format));
	id_type = 0; // 'd'
	
	/////////////// combinatoire sur les flag tous ensemble && individuelement ///////////////////
	len = 1;
	while (len <= flag_size) // pour toute les taille
	{
		m = 0;
		while (m < len)
		{
			// copie prev
			flag_set_id_free(&(flag_id_used[m][0]), &(flag_id_free[m][0]), m, flag_size);
			k = 0;
			while (k < flag_size - m - 1)
			{
				flag_id_used[m][m] = flag_id_free[m][k];
				k++;
			}
			m++;
		}
		len++;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////



//		sprintf(flag_format, "%%%s%c", flag_format, type[id_type]); // <--- add everything
}


///////// recursivite //////////////////////////////////

int		recurs_char_is_free(char *id_used, int curs, char value)
{
	while (--curs >= 0)
		if (id_used[curs] == value)
			return (0);
	return (1);
}

void	recurs_set_char_free(char *org, char *id_used, char *id_free, int curs, int len)
{
	int	i;	
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (recurs_char_is_free(id_used, curs, org[i]))
		{
			id_free[j] = org[i];
			j++;
		}
		i++;
	}
}

/*
	char *org			: chaine originale
	char *tmp			: chaine re assembler
	int len				: nb char in originale
	int stape_end		: nb char combined -> stop condition
	int stape			: actual stape
	int *sum			: sum of all combined char
	int (*f)(char *s)	: print fuction or what ever callback
*/

void	test_combin_recurs(char *org, char *tmp, int len, int stape_end, int stape, int *sum, int (*f)(char *s))
{
	int 	i;
	char	free[len + 1];

	if (stape < stape_end) // construction part (recusrtion)
	{
		recurs_set_char_free(org, tmp, free, stape, len);					// construction des case possible
		i = 0;
		while (i < len - stape)												// pour chaque cas possible
		{
			tmp[stape] = free[i];											// on place le charactere
			test_combin_recurs(org, tmp, len, stape_end, stape + 1, sum, f);		// on lance la recurtion d'apres
			i++;
		}
	}
	else // printf part
	{
		(*sum)++;				// on incremente le nombre de mots construit
		tmp[stape] = '\0';
		ft_putstr("|");
		f(tmp);				// <-- on execute la fonciton d'impression 
		ft_putstr("|");
		ft_putstr("\n");
	}
}
////////////////////////////////////////////

/*
	Ici on prend une chaine de charactere et on fait toute les combinaison possible
	entre ces caratere puis on les imprime.
	-
	On fera la meme chose avec un tableau de chaine de charactere

	On construit chaque etape par recusrtion.
	Il y a un buffer qui lui permet de construire les possibilite en fonction des charatere qui ne sont pas encore present.
	Puis de les imprimer.
	-
	Pour le tableau de chaine de charactere il faudrait faire la meme chose avec des tableau d'indice de chaine de charactere

*/

void	test_recursion()
{
	/////// flag  //////////
	char	*str = " +-#0", s1[SMALL_BUFF], s2[SMALL_BUFF];
	int		i, max, nb_flags;
	////// cast ////////////
//	char	all_cast[10][SMALL_BUFF] = {"hh", "h", "", "l", "ll", "q", "j", "z", "t", "L"};
//	(void)all_cast;


	bzero(s1 ,sizeof(s1));
	bzero(s2 ,sizeof(s2));
	strcpy(s1, str);
	nb_flags = 0;
	
	max = strlen(s1);
	i = 0;
	while (i <= max)
	{
		test_combin_recurs(s1, s2, max, i, 0, &nb_flags, ft_putstr);
		printf("==================\n");
		i++;
	}
	printf("sum:%d\n", nb_flags);
}

/*
	flag			[DONE]
	caste			
	with
	.precision
	type
*/

void	wait_4_input_trace(char *file, int line)
{
	char	key;

	printf("\nfile:%20s line:%d\t\t-- presse any key --\n", file, line);
	read(0, &key, 1);
}

void	wait_4_input()
{
	char	key;

	printf("\t\t-- presse any key --\n");
	read(0, &key, 1);
}

void	buffer_description(t_buffer *b)
{
	
	int		one_buf_size = sizeof(b->beg.data);
	
	printf("single buffer size:%d\n", one_buf_size);
}

void	test_buffer_function()
{
	t_buffer			b;
	int					one_buf_size = sizeof(b.beg.data);
	char				str1[] = " <<=\n";
	char				str_nbr[BUFF_SMALL];
	int					nbr_len;
	int					str1_size;
//	int					size;
	int					i;
	char				*tmp;
	int					tmp_size;

	(void)one_buf_size;(void)tmp;(void)tmp_size;
	str1_size = sizeof(str1);
//	printf("len(%s):%d\n", str1, str1_size);
	buffer_init(&b);

	i = 1;
	while (i < (1 << 30))
	{			
		sprintf(str_nbr , "%d", (i - 1));
		nbr_len = strlen(str_nbr);
		buffer_push_nchar(&b, ' ', 12 - nbr_len);
		buffer_push_data(&b, str_nbr, nbr_len);
		buffer_push_data(&b, str1, strlen(str1));
		i <<= 1;
	}
	buffer_output_standar(&b);
//	buffer_output_standar(&b);
//	tmp_size = (sizeof(b.beg.data) * b.block_nb + b.current->id + 1);
//	tmp = (char*)malloc(tmp_size * sizeof(char));
//	buffer_output_string(&b, tmp);
//	buffer_output_string_size(&b, tmp, 115);
//	printf("%s", tmp);
}

int	main(void)
{
//	test_print_float();
//	test_print_float_precision();
//	flag_test_general(-1.0);	
//	test_recursion();

	test_buffer_function();
	return (0);
}

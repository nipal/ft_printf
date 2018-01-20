/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:10:43 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/17 22:41:55 by fjanoty          ###   ########.fr       */
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

void	test_combin_recurs(char *org, char *tmp, int len, int end, int stape, int *sum, int (*f)(char *s))
{
	int 	i;
	char	free[len + 1];
//	int		len_free;

	if (stape < end)
	{
		recurs_set_char_free(org, tmp, free, stape, len);
		i = 0;
		while (i < len - stape)
		{
			tmp[stape] = free[i];
			test_combin_recurs(org, tmp, len, end, stape + 1, sum, f);
			i++;
		}
	}
	else
	{
		(*sum)++;
		tmp[stape] = '\0';
		ft_putstr("|");
		f(tmp);
		ft_putstr("|");
		ft_putstr("\n");
	}
}
////////////////////////////////////////////



void	test_recursion()
{
	/////// flag  //////////
	char	*str = " +-#0", s1[SMALL_BUFF], s2[SMALL_BUFF];
	int		i, max, nb_flags;
	////// cast ////////////
	char	all_cast[10][SMALL_BUFF] = {"hh", "h", "", "l", "ll", "q", "j", "z", "t", "L"};
	(void)all_cast;


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

int	main(void)
{
//	test_print_float();
//	test_print_float_precision();
//	flag_test_general(-1.0);
	
	test_recursion();
	return (0);
}

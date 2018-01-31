/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unite_test_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:44:46 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/20 23:00:49 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Ici on va faire des test pour avoir un panel de va_liste pour faire des teste
	potentielemnt egale mais par des bias different vis a vis de l'empilement/emplacement
	des variable dans la valiste, ainsi que les pointeur des dite variable pour modeler
	a l'infini les possibliter avec un minimum de fonction au prealable

*/



#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <limits.h>

#define BUFF_SMALL	32
#define BUFF_LARGE	1024

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

/// Attention on ne peu pas staquer plus de 32 argument
typedef	struct	s_arg
{
	va_list		arg;
	t_type		addr1[BUFF_SMALL];		// addr on send
	t_type		addr2[BUFF_SMALL];		// addr on recieve
	int			arg_nb;
}				t_arg;
//
//t_type	type_get_from_long(long val)
//{
//	t_type v;
//
//	bzero(&v, sizeof(t_type));
//	v.val.l = val;
//	v.id = e_long;
//	return (v);
//}
//
//void	f_long(t_type addr_arg, int arg_nb, ...)
//{
//	t_arg	p;
//	int		i;
//	int		i_max;
//	va_list	ap;
//
//	i_max = (BUFF_SMALL < arg_nb) ? BUFF_SMALL : arg_nb;
//	memmove(&(p.addr1), addr_arg, sizeof(t_type) * i_max);
//	p.arg_nb = arg_nb;
//	va_start(p.arg, arg_nb);
//
//	va_copy(ap, p.arg);
//	i = 0;
//	while (i < i_max)
//	{
//		bzero(p.addr2 + i, sizeof(t_type));
//		p.addr2[i].val.l = va_arg(ap, long);
//		void	*ptr = &(va_arg(ap, long));
//		(void)ptr;
//		i++;
//	}
//	
//	va_end(ap);
//	va_end(p.arg);
//}
//
long	f_1(long val)
{
	return (val);	
}


double	f_2(double val)
{
	return (val);	
}

void	test_acces_to_stacked_value()
{
	char	s1[BUFF_LARGE];
	char	s2[BUFF_LARGE];
	char	s3[BUFF_LARGE];
	char	s4[BUFF_LARGE];

	long	(*f[2])(long a);
	double	(*g[2])(double a);
	void	*tmp;

	bzero(s1, BUFF_LARGE);
	bzero(s2, BUFF_LARGE);
	bzero(s3, BUFF_LARGE);
	bzero(s4, BUFF_LARGE);

	tmp = f_1;
	f[0] = tmp;
	g[0] = tmp;

	tmp = f_2;
	f[1] = tmp;
	g[1] = tmp;
	
	double	max;
	double	i;


	char 	str_true[] = " TRUE ";
	char 	str_false[] = " FALSE ";
	char	*s;

	double	delta = 5000;
	i = 0;
	i = 2.0 * INT64_MAX;
	i = INT64_MAX;
	i = INT64_MAX >> 15;
	i = INT64_MAX >> 12;
	i = INT64_MAX >> 9;
	i = INT64_MAX >> 6;
	i -= delta / 2;
	max = i +  delta;
	printf("beg:%f	end:%f	delta:%f\n", i, max, delta);
	int	j = 0;
	int	k1 = 0;
	int	k2 = 0;
	int	same_1 = 0, same_2 = 0;

	// --

	// --


	while (i < max)
	{
		sprintf(s3, "%f",g[0](i));
		sprintf(s4, "%f",g[1](i));

		if ((same_1 = strcmp(s1, s3)))
			k1++;
		if ((same_2 = strcmp(s2, s4)))
			k2++;


		printf("c1:%s	c2:%s\n", ((same_1) ? "TRUE" : "FALSE"), ((same_2) ? "TRUE" : "FALSE"));
	//	printf("s1:{%s1}\ns2:{%s}\ns3:{%s}\ns4:{%s}\n", s1, s2, s3, s4);
//		printf("f --> %s\n", (strcmp(s1, s2) ? " LOSE " : "  WIN "));
		int cond = strcmp(s3, s4);
			printf("[%d, %d]>> [%d]:g(%f) --> %s\n", k1, k2, j, i, (cond) ? " str diff " : " str EQ ");

		memmove(s1, s3, BUFF_LARGE);
		memmove(s2, s4, BUFF_LARGE);

		bzero(s3, BUFF_LARGE);
		bzero(s4, BUFF_LARGE);
		j++;
		i += delta / 1000.0; 
	}

}

int	main()
{
	test_acces_to_stacked_value();
	return (0);
}



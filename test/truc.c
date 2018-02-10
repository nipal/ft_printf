/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 01:46:10 by fjanoty           #+#    #+#             */
/*   Updated: 2018/02/05 01:36:27 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>



//	printf(" %d \n" , 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 ,16, 17, 18,19, 20);
void	test_arg_witdth_and_prcision()
{
	printf("|%d| |%0+*.*d| |%d|\n", 42, 0, 20, 1337, 7557);
	printf("|%d| |%0.*+*d| |%d|\n", 42, 0, 20, 1337, 7557);
                               
	printf("|%d| |%0+*.*d| |%d|\n", 42, 0, 20,    0, 7557);
	printf("|%d| |%0.*+*d| |%d|\n", 42, 0, 20,    0, 7557);
}

void	init_long(long *tab_nb, int nb, long beg, long end)
{
	int	i;
	long double delta;

	if (nb <= 0)
		return ;
	delta = (long double)(end - beg) / -nb;
	i = 0;
	while (i < nb)
	{
		tab_nb[nb - 1 - i] = i * 100;
		i++;
	}
}

void	init_double(double *tab_nb, int nb, double beg, double end)
{
	int	i;
	long double delta;

	if (nb <= 0)
		return ;
	delta = (long double)(end - beg) / -nb;
	i = 0;
	while (i < nb)
	{
		tab_nb[nb - 1 - i] = 0.001 * i;
		i++;
	}
}

void	init_long_double(long double *tab_nb, int nb, long double beg, long double end)
{
	int	i;
	long double delta;

	if (nb <= 0)
		return ;
	delta = (long double)(end - beg) / -nb;
	i = 0;
	while (i < nb)
	{
		tab_nb[nb - 1 - i] = 42 + 0.00001 * i;
		i++;
	}
}

//--

void	print_long_tab(long *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%ld\n", tab[len - 1 - i]);
		i++;
	}
}

void	print_double_tab(double *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%f\n", tab[len - 1 - i]);
		i++;
	}
}

void	print_long_double_tab(long double *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%Lf\n", tab[len - 1 - i]);
		i++;
	}
}

//		###########################################

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
	char				c;                       /* a */
	short				s;                       /* b */
	int					i;                       /* c */
	long				l;                       /* d */
	unsigned	char	uc;                      /* e */
	unsigned	short	us;                      /* f */
	unsigned	int		ui;                      /* g */
	unsigned	long	ul;                      /* h */
	float				f;                       /* i */
	double				d;                       /* j */
	long	double		ld;                      /* k */
	char				*t;                      /* l */
	void				*p;                      /* m */
}				t_utype;                          

typedef	struct	s_type
{
	t_id_type	id;
	t_utype		val;
}				t_type;

///printf("===============\n");

void	print_char(t_utype val)
{
	printf("%hhd\n", val.c);
}

void	print_short(t_utype val)
{
	printf("%hd\n", val.s);
}

void	print_int(t_utype val)
{
	printf("%d\n", val.i);
}

void	print_long(t_utype val)
{
	printf("%ld\n", val.l);
}

void	print_unsigned_char(t_utype val)
{
	printf("%hhu\n", val.uc);
}

void	print_unsigned_short(t_utype val)
{
	printf("%hu\n", val.us);
}

void	print_unsigned_int(t_utype val)
{
	printf("%u\n", val.ui);
}

void	print_unsigned_long(t_utype val)
{
	printf("%lu\n", val.ul);
}

void	print_float(t_utype val)
{
	printf("%f\n", val.f);
}

void	print_double(t_utype val)
{
	printf("%f\n", val.d);
}

void	print_long_double(t_utype val)
{
	printf("%Lf\n", val.ld);
}

void	print_char_ptr(t_utype val)
{
	printf("%s\n", val.t);
}

void	print_void_ptr(t_utype val)
{
	printf("%p\n", val.p);
}




//printf("===============\n");
t_utype	depope_char(va_list ap)
{
	t_utype arg;

	arg.c = va_arg(ap, char);
	return(arg);
}

t_utype	depope_short(va_list ap)
{
	t_utype arg;

	arg.s = va_arg(ap, short);
	return(arg);
}

t_utype	depope_int(va_list ap)
{
	t_utype arg;

	arg.i = va_arg(ap, int);
	return(arg);
}

t_utype	depope_long(va_list ap)
{
	t_utype arg;

	arg.l = va_arg(ap, long);
	return(arg);
}

t_utype	depope_unsigned_char(va_list ap)
{
	t_utype arg;

	arg.uc = va_arg(ap, unsigned char);
	return(arg);
}

t_utype	depope_unsigned_short(va_list ap)
{
	t_utype arg;

	arg.us = va_arg(ap, unsigned short);
	return(arg);
}

t_utype	depope_unsigned_int(va_list ap)
{
	t_utype arg;

	arg.ui = va_arg(ap, unsigned int);
	return(arg);
}

t_utype	depope_unsigned_long(va_list ap)
{
	t_utype arg;

	arg.ul = va_arg(ap, unsigned long);
	return(arg);
}

t_utype	depope_float(va_list ap)
{
	t_utype arg;

	arg.f = va_arg(ap, float);
	return(arg);
}

t_utype	depope_double(va_list ap)
{
	t_utype arg;

	arg.d = va_arg(ap, double);
	return(arg);
}

t_utype	depope_long_double(va_list ap)
{
	t_utype arg;

	arg.ld = va_arg(ap, long double);
	return(arg);
}

t_utype	depope_char_ptr(va_list ap)
{
	t_utype arg;

	arg.t = va_arg(ap, char *);
	return(arg);
}

t_utype	depope_void_ptr(va_list ap)
{
	t_utype arg;

	arg.p = va_arg(ap, void *);
	return(arg);
}


//	ici on enregistre les type des variable
void	set_arg(char *fmt, t_type *tab, int *size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while ((c = fmt[i]))
	{
		if (c >= 'a' && c <= 'm')
			tab[j++].id = c - 'a';
		i++;
	}
	*size = j;
}

//	ici on depope les argument et on les staque dans le tableau
void	get_arg(va_list ap, t_type *tab, int size)
{
	int		i;
	const	t_utype	(*depope[])(va_list ap) = {depope_char, depope_short, depope_int, depope_long,
										 depope_unsigned_char, depope_unsigned_short, depope_unsigned_int, depope_unsigned_long,
										 depope_float, depope_double, depope_long_double,
										 depope_char_ptr, depope_void_ptr
													};

	i = 0;
	while (i < size)
	{
		tab[i].val = depope[tab[i].id](ap);
		i++;
	}
	
}

//	ici on met la data
void	print_arg(char *fmt, t_type *tab)
{
	const	void	(*print_func[])(char *fmt, t_utype *tab) = {print_char, print_short, print_int, print_long, print_unsigned_char, print_unsigned_short, print_unsigned_int, print_unsigned_long,
				print_float, print_double, print_long_double, print_char_ptr, print_void_ptr};
	int		i;
	char	c;

	i = 0;
	while ((c = fmt[i]))
	{
		if (c >= 'a' && c <= 'm')
		{
			
		}
		else
			printf("%c", c);
		i++;
	}
}


void	test_id_colision_arg()
{
	long		l1 = 1, l2 = 2, l3 = 3, l4 = 4, l5 = 5, l6 = 6, l7 = 7, l8 = 8, l9 = 9, l10 = 10, l11 = 11, l12 = 12;
	double		d1 = 0, d2 = 0.02, d3 = 0.03, d4 = 0.04, d5 = 0.05, d6 = 0.06, d7 = 0.07, d8 = 0.08, d9 = 0.09, d10 = 0.010, d11 = 0.011, d12 = 0.012;
	long double	ld1 = 420.001, ld2 = 420.002, ld3 = 420.003, ld4 = 420.004, ld5 = 420.005, ld6 = 420.006, ld7 = 420.007, ld8 = 420.008, ld9 = 420.009, ld10 = 420.0010, ld11 = 420.0011, ld12 = 420.0012;

	long tt = 1;
	d1 = *((double*)&tt);
//	init_long(&l12, 12, 300, -1337);
//	init_double(&d12, 12, .003, -0.001337);
//	init_long_double(&ld12, 12, .12, 0.1);
////	##############
//	printf("======================\n");
//	printf("======================\n");
//	print_long(&l12, 12);
//	printf("======================\n");
//
//	print_double(&d12, 12);
//	printf("======================\n");
//	print_long_double(&ld12, 12);
//	##############
	

//	printf("%150 1$d	 ||\n %150 1$f	 ||\n %150 1$Lf	\n\n%150 1$d	 ||\n %150 1$f	 ||\n %150 1$Lf	 ||\n \n\n%150 1$d	 ||\n %150 1$f	 ||\n %150 1$Lf	 ||\n 	 \n\n",  l1,  d1, ld1,  l2,  d2, ld2,  l3,  d3, ld3);
//	printf("%150 1$f	 ||\n %150 1$Lf	 ||\n %150 1$d 	\n\n%150 1$f	 ||\n %150 1$Lf	 ||\n %150 1$d 	 ||\n \n\n%150 1$f	 ||\n %150 1$Lf	 ||\n %150 1$d 	 ||\n 	 \n\n",  d1, ld1,  l2,  d1, ld2,  l2,  d3, ld3,  l3);
//	printf("%150 1$Lf	 ||\n %150 1$d	 ||\n %150 1$f 	\n\n%150 1$Lf	 ||\n %150 1$d	 ||\n %150 1$f 	 ||\n \n\n%150 1$Lf	 ||\n %150 1$d	 ||\n %150 1$f 	 ||\n 	 \n\n", ld1,  l1,  d2, ld1,  l2,  d2, ld3,  l3,  d3);
//printf("=============||==========||=========|========||==========||==========||=====|====||==========||==========||=====================================================================================================================\n");
//	printf("%150 1$d	 ||\n %150 1$f	 ||\n %150 1$Lf	\n\n%150 1$d	 ||\n %150 1$f	 ||\n %150 1$Lf	 ||\n \n\n%150 1$d	 ||\n %150 1$f	 ||\n %150 1$Lf	 ||\n 	 \n\n", ld1,  l1,  d1, ld2,  l2,  d2, ld3,  l3,  d3);
//	printf("%150 1$f	 ||\n %150 1$Lf	 ||\n %150 1$d 	\n\n%150 1$f	 ||\n %150 1$Lf	 ||\n %150 1$d 	 ||\n \n\n%150 1$f	 ||\n %150 1$Lf	 ||\n %150 1$d 	 ||\n 	 \n\n",  l1,  d1, ld2,  l1,  d2, ld2,  l3,  d3, ld3);
//	printf("%150 1$Lf	 ||\n %150 1$d	 ||\n %150 1$f 	\n\n%150 1$Lf	 ||\n %150 1$d	 ||\n %150 1$f 	 ||\n \n\n%150 1$Lf	 ||\n %150 1$d	 ||\n %150 1$f 	 ||\n 	 \n\n",  d1, ld1,  l2,  d1, ld2,  l2,  d3, ld3,  l3);
//printf("=============||==========||=========|========||==========||==========||=====|====||==========||==========||=====================================================================================================================\n");
//	printf("%150 1$d	 ||\n %150 1$f	 ||\n %150 1$Lf	\n\n%150 1$d	 ||\n %150 1$f	 ||\n %150 1$Lf	 ||\n \n\n%150 1$d	 ||\n %150 1$f	 ||\n %150 1$Lf	 ||\n 	 \n\n",  d1, ld1,  l1,  d2, ld2,  l2,  d3, ld3,  l3);
//	printf("%150 1$f	 ||\n %150 1$Lf	 ||\n %150 1$d 	\n\n%150 1$f	 ||\n %150 1$Lf	 ||\n %150 1$d 	 ||\n \n\n%150 1$f	 ||\n %150 1$Lf	 ||\n %150 1$d 	 ||\n 	 \n\n", ld1,  l1,  d2, ld1,  l2,  d2, ld3,  l3,  d3);
//	printf("%150 1$Lf	 ||\n %150 1$d	 ||\n %150 1$f 	\n\n%150 1$Lf	 ||\n %150 1$d	 ||\n %150 1$f 	 ||\n \n\n%150 1$Lf	 ||\n %150 1$d	 ||\n %150 1$f 	 ||\n 	 \n\n",  l1,  d1, ld2,  l1,  d2, ld2,  l3,  d3, ld3);

	printf("\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("            %1$d || %1$f  || %1$Lf \n\
            %2$f  || %2$Lf || %2$d  \n\
            %3$.8000Lf || %3$d  || %3$f  \n ", l1, ld1, d1);
printf("\n====================================\n\n");
	printf("            %1$d || %1$f  || %1$Lf \n\
            %2$f  || %2$Lf || %2$d  \n\
            %3$d  || %3$.8000Lf || %3$f  \n ", l1, ld1, d1 , 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,0.0 ,0.0,0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
printf("====================================\n");
printf("====================================\n");
printf("====================================\n");
printf("====================================\n");
	printf("            %1$f || %1$Lf || %1$d  \n\
            %2$Lf || %2$d || %2$f  \n\
            %3$d  ||> %3$f <|| %3$Lf \n ", l1, d1, ld1);
printf("\n====================================\n\n");
	printf("            %1$Lf || %1$d || %1$f  \n\
            %2$d  || %2$f  || %2$Lf \n\
            %3$f  || %3$Lf || %3$d  \n ", l1, ld1, d1);
printf("\n====================================\n\n");
 

	//	--> On a deux liste:
	//		Un tableau avec tout les argument.
	//		
	//		Une liste de type pour definir l'ordre des depope

//	printf("%20-1$d %20-1$f %20-1$Lf\n %20-2$d %20-2$f %20-2$Lf\n %20-3$d %20-3$f %20-3$Lf\n %20-4$d %20-4$f %20-4$Lf\n %20-5$d %20-5$f %20-5$Lf\n %20-6$d %20-6$f %20-6$Lf\n %20-7$d %20-7$f %20-7$Lf\n %20-8$d %20-8$f %20-8$Lf\n %20-9$d %20-9$f %20-9$Lf\n %20-10$d %20-10$f %20-10$Lf\n %20-11$d %20-11$f %20-11$Lf\n %20-12$d %20-12$f %20-12$Lf\n"
//			, l1 , d1 , ld1, l2 , d2 , ld2, l3 , d3 , ld3, l4 , d4 , ld4, l5 , d5 , ld5, l6 , d6 , ld6, l7 , d7 , ld7, l8 , d8 , ld8, l9 , d9 , ld9, l10, d10, ld10, l11, d11, ld11, l12, d12, ld12);
}

/*
 	structure de data: un tableau
	Normalement les 

	On conte les pourcent
*/	


int	main()
{
	
//	test_arg_witdth_and_prcision();
	
	test_id_colision_arg();
	return (0);
}



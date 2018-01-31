/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unite_test_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 23:01:15 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/28 10:06:57 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <limits.h>

#define BUFF_SMALL	32
#define BUFF_LARGE	1024


char	*write_bit_out(unsigned char *data, int size)
{
	static	char	buff[BUFF_LARGE];
	int	i;
	int	j;
	int	nb_char;
	int	id;

	nb_char = (size * 8);
	if (nb_char >= BUFF_LARGE)
	{
		dprintf(2, "buff too small\n");
		return (NULL);
	}
	buff[nb_char] = '\0';
	j = size - 1;
	while (j >= 0)
	{
		i = 7;
		while (i >= 0)
		{
			id = (7 - i) + ((size - 1 - j) * 8);
			buff[id] = (data[j] & (1 << i)) ? '1' : '0';
			i--;
		}
		j--;
	}
	return (buff);
}



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
	va_list		arg_beg;
	t_type		arg_addr[BUFF_SMALL];
	int			arg_nb;
}				t_arg;

//void	f1_light(char *buff_beg, char *buff, t_list *elem)

void	va_arg_basic(long tab_long[5], double tab_double[8], char *format, void (*f)(char *format, ...))		// function who staque the arg in va_list and exec the rest.
{
	f(format, tab_long[0], tab_long[1], tab_long[2], tab_long[3], tab_long[4], tab_double[0], tab_double[1], tab_double[2], tab_double[3], tab_double[4], tab_double[5], tab_double[6], tab_double[7]);
}

int		is_integer(char c);
int		is_floating_fd(char c);

/*
	Pour l'instant on reste dans la limite de la staque de chaque type
*/

//void	printf_testing(char *buff_beg, char *buff, t_list *elem)
//{
//	
//}
/*
	On genere des chaine de charactere
	On les connecte au fonction printf_like
	On controle la valeur des argument tant qu'on est inferieur aux regstre

	==> generation des chaine formater
	==> generation de la valeur a placer dans les arguments.
	==> teste de la fonction
*/


/*
 		On remplis chaque registre
		on ataque les va;eur sur la staque
 */

// depope un varaible en flnciton de l'id de la variable
//  On va simboliser les type par une lettre representant un nombre

// 13
//	char				c;
//	short				s;
//	int					i;
//	long				l;
//	unsigned	char	uc;
//	unsigned	short	us;
//	unsigned	int		ui;
//	unsigned	long	ul;
//	float				f;
//	double				d;
//	long	double		ld;
//	char				*t;	// text
//	void				*p;


void	print_char(t_type *arg)
{
	printf("%hhd", arg->val.c);
}


void	print_short(t_type *arg)
{
	printf("%hd", arg->val.s);
}


void	print_int(t_type *arg)
{
	printf("%d", arg->val.i);
}


void	print_long(t_type *arg)
{
	printf("%ld", arg->val.l);
}


void	print_unsigned_char(t_type *arg)
{
	printf("%hhu", arg->val.uc);
}


void	print_unsigned_short(t_type *arg)
{
	printf("%hu", arg->val.us);
}


void	print_unsigned_int(t_type *arg)
{
	printf("%u", arg->val.ui);
}


void	print_unsigned_long(t_type *arg)
{
	printf("%lu", arg->val.ul);
}


void	print_float(t_type *arg)
{
	printf("%30.15f", arg->val.f);
}


void	print_double(t_type *arg)
{
	printf("%30.15f", arg->val.d);
}


void	print_long_double(t_type *arg)
{
	printf("%30.15Lf", arg->val.ld);
}


void	print_char_ptr(t_type *arg)
{
	printf("%s", arg->val.t);
}


void	print_void_ptr(t_type *arg)
{
	printf("%p", arg->val.p);
}

				
				
				
#define NAME	(1 << 0)
#define ID      (1 << 1)
#define ID_VAL  (1 << 2)
#define ENDL    (1 << 3)

char	*ttype_name(int id_type)
{
	static	char	type_name[13][BUFF_SMALL];
	static	int init = 1;
	
	if (init)
	{
		init = 0;
		strcpy(&(type_name[e_char][0]),  "char");
		strcpy(&(type_name[e_short][0]),  "short");
		strcpy(&(type_name[e_int][0]),  "int");
		strcpy(&(type_name[e_long][0]),  "long");
		strcpy(&(type_name[e_unsigned_char][0]),  "unsigned char");
		strcpy(&(type_name[e_unsigned_short][0]),  "unsigned short");
		strcpy(&(type_name[e_unsigned_int][0]),  "unsigned int");
		strcpy(&(type_name[e_unsigned_long][0]),  "unsigned long");
		strcpy(&(type_name[e_float][0]),  "float");
		strcpy(&(type_name[e_double][0]),  "double");
		strcpy(&(type_name[e_long_double][0]),  "long double");
		strcpy(&(type_name[e_char_ptr][0]),  "char *");
		strcpy(&(type_name[e_void_ptr][0]),  "void *");
	}
	return ((char*)type_name + (id_type * BUFF_SMALL * sizeof(char)));
}

void	print_ttype(t_type *t, unsigned char mask)
{
	char	str[BUFF_SMALL];

	if (mask & (NAME | ID))
	{
	//			(str : )
		printf("(%s%s%s)", ((mask & NAME) ? ttype_name(t->id) : ""),
							((mask & (NAME | ID)) ? " : " : ""),
 							((mask & ID) ?  (sprintf(str, "%3d", t->id), str) : ""));
	}
}

t_type	depope_char(va_list *ap)
{
	t_type	arg;

	arg.id = e_char;
	arg.val.us = va_arg(*ap, char);
	return (arg);
}

t_type	depope_short(va_list *ap)
{
	t_type	arg;

	arg.id = e_short;
	arg.val.us = va_arg(*ap, short);
	return (arg);
}

t_type	depope_int(va_list *ap)
{
	t_type	arg;

	arg.id = e_int;
	arg.val.ui = va_arg(*ap, int);
	return (arg);
}

t_type	depope_long(va_list *ap)
{
	t_type	arg;

	arg.id = e_long;
	arg.val.ul = va_arg(*ap, long);
	return (arg);
}


t_type	depope_unsigned_char(va_list *ap)
{
	t_type	arg;

	arg.id = e_unsigned_char;
	arg.val.us = va_arg(*ap, unsigned char);
	return (arg);
}

t_type	depope_unsigned_short(va_list *ap)
{
	t_type	arg;

	arg.id = e_unsigned_short;
	arg.val.us = va_arg(*ap, unsigned short);
	return (arg);
}

t_type	depope_unsigned_int(va_list *ap)
{
	t_type	arg;

	arg.id = e_unsigned_int;
	arg.val.ui = va_arg(*ap, unsigned int);
	return (arg);
}

t_type	depope_unsigned_long(va_list *ap)
{
	t_type	arg;

	arg.id = e_unsigned_long;
	arg.val.ul = va_arg(*ap, unsigned long);
	return (arg);
}

t_type	depope_float(va_list *ap)
{
	t_type	arg;

	arg.id = e_float;
	arg.val.f = va_arg(*ap, float);
	return (arg);
}

t_type	depope_double(va_list *ap)
{
	t_type	arg;

	arg.id = e_double;
	arg.val.d = va_arg(*ap, double);
	return (arg);
}

t_type	depope_long_double(va_list *ap)
{
	t_type	arg;

	arg.id = e_long_double;
	arg.val.ld = va_arg(*ap, long double);
	return (arg);
}

t_type	depope_char_ptr(va_list *ap)
{
	t_type	arg;

	arg.id = e_char_ptr;
	arg.val.t = va_arg(*ap, char *);
	return (arg);
}

t_type	depope_void_ptr(va_list *ap)
{
	t_type	arg;

	arg.id = e_void_ptr;
	arg.val.p = va_arg(*ap, void *);
	return (arg);
}

t_type	depope_char(va_list *ap);
t_type	depope_short(va_list *ap);
t_type	depope_int(va_list *ap);
t_type	depope_long(va_list *ap);
t_type	depope_unsigned_char(va_list *ap);
t_type	depope_unsigned_short(va_list *ap);
t_type	depope_unsigned_int(va_list *ap);
t_type	depope_unsigned_long(va_list *ap);
t_type	depope_float(va_list *ap);
t_type	depope_double(va_list *ap);
t_type	depope_long_double(va_list *ap);
t_type	depope_char(va_list *ap);
t_type	depope_void_ptr(va_list *ap);



void	init_depope_function(t_type (***f)(va_list *ap))
{
	if (!(*f = malloc(sizeof(void*) * 13)))
		return ;
	(*f)[0] = depope_char;                     /* a */ 
	(*f)[1] = depope_short;                    /* b */
	(*f)[2] = depope_int;                      /* c */
	(*f)[3] = depope_long;                     /* d */
	(*f)[4] = depope_unsigned_char;            /* e */
	(*f)[5] = depope_unsigned_short;           /* f */
	(*f)[6] = depope_unsigned_int;             /* g */
	(*f)[7] = depope_unsigned_long;            /* h */
	(*f)[8] = depope_float;                    /* i */
	(*f)[9] = depope_double;                   /* j */
	(*f)[10] = depope_long_double;             /* k */
	(*f)[11] = depope_char;                    /* l */
	(*f)[12] = depope_void_ptr;                /* m */
}

void	print_char(t_type *arg);
void	print_short(t_type *arg);
void	print_int(t_type *arg);
void	print_long(t_type *arg);
void	print_unsigned_char(t_type *arg);
void	print_unsigned_short(t_type *arg);
void	print_unsigned_int(t_type *arg);
void	print_unsigned_long(t_type *arg);
void	print_float(t_type *arg);
void	print_double(t_type *arg);
void	print_long_double(t_type *arg);
void	print_char_prt(t_type *arg);
void	print_void_ptr(t_type *arg);

void	init_print_function(void (***f)(t_type *arg))
{
	if (!(*f = malloc(sizeof(void*) * 13)))
		return ;
	(*f)[0] = print_char;					   /* a */	
	(*f)[1] = print_short;               	   /* b */
	(*f)[2] = print_int;                      /* c */
	(*f)[3] = print_long;                     /* d */
	(*f)[4] = print_unsigned_char;            /* e */
	(*f)[5] = print_unsigned_short;           /* f */
	(*f)[6] = print_unsigned_int;             /* g */
	(*f)[7] = print_unsigned_long;            /* h */
	(*f)[8] = print_float;                    /* i */
	(*f)[9] = print_double;                   /* j */
	(*f)[10] = print_long_double;             /* k */
	(*f)[11] = print_char_ptr;                /* l */
	(*f)[12] = print_void_ptr;                /* m */
}


void	print_func(char *format, ...)
{
	va_list			ap;
	t_type			tab[256];
	size_t			tab_size;
	int				i;
	int				j;
	static	t_type	(**arg_depope)(va_list);
	static	void	(**arg_print)(t_type *arg);
	static	int		init = 1;
	char			c;

	if (init)
	{
		init = 0;
		init_depope_function(&arg_depope);
		init_print_function(&arg_print);
	}
	tab_size = sizeof(tab) / sizeof(t_type);
	va_start(ap, format);
printf("===\n");
	i = 0;
	j = 0;
	while ((c = format[i]) && j < tab_size)
	{
		if (c >= 'a' && c <= 'm')
		{
			tab[j].id = c - 'a';
			tab[j] = arg_depope[c - 'a'](&ap);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < j)
	{
		printf("[%2d]:id:%-2d %128s %14s -> ", i, tab[i].id, write_bit_out(&(tab[i].val), (tab[i].id == e_long_double) ? 16 : 8), ttype_name(tab[i].id));
		arg_print[tab[i].id](tab + i);
		printf("\n");
		i++;
	}
}

//	Comment tester si l'empilement infini fonctionne correctement
void	va_arg_256(t_type *tab, char *format, void (*f)(char *format, ...))
{
	printf("\n__256__\n\n");
	f(format, tab[0].val.ul, tab[1].val.ul, tab[2].val.ul, tab[3].val.ul, tab[4].val.ul, tab[5].val.d, tab[6].val.d, tab[7].val.d, tab[8].val.d, tab[9].val.d, tab[10].val.d, tab[11].val.d, tab[12].val.d,
	  	tab[13].val.ul, tab[14].val.ul, tab[15].val.ul, tab[16].val.ul, tab[17].val.ul, tab[18].val.ul, tab[19].val.ul, tab[20].val.ul, tab[21].val.ul, tab[22].val.ul, tab[23].val.ul, tab[24].val.ul, tab[25].val.ul, tab[26].val.ul,
	 	tab[27].val.ul, tab[28].val.ul, tab[29].val.ul, tab[30].val.ul, tab[31].val.ul, tab[32].val.ul, tab[33].val.ul, tab[34].val.ul, tab[35].val.ul, tab[36].val.ul, tab[37].val.ul, tab[38].val.ul, tab[39].val.ul, tab[40].val.ul,
	 	tab[41].val.ul, tab[42].val.ul, tab[43].val.ul, tab[44].val.ul, tab[45].val.ul, tab[46].val.ul, tab[47].val.ul, tab[48].val.ul, tab[49].val.ul, tab[50].val.ul, tab[51].val.ul, tab[52].val.ul, tab[53].val.ul, tab[54].val.ul,
	  	tab[55].val.ul, tab[56].val.ul, tab[57].val.ul, tab[58].val.ul, tab[59].val.ul, tab[60].val.ul, tab[61].val.ul, tab[62].val.ul, tab[63].val.ul, tab[64].val.ul, tab[65].val.ul, tab[66].val.ul, tab[67].val.ul, tab[68].val.ul,
	 	tab[55].val.ul, tab[56].val.ul, tab[57].val.ul, tab[58].val.ul, tab[59].val.ul, tab[60].val.ul, tab[61].val.ul, tab[62].val.ul, tab[63].val.ul, tab[64].val.ul, tab[65].val.ul, tab[66].val.ul, tab[67].val.ul, tab[68].val.ul,
	 	tab[69].val.ul, tab[70].val.ul, tab[71].val.ul, tab[72].val.ul, tab[73].val.ul, tab[74].val.ul, tab[75].val.ul, tab[76].val.ul, tab[77].val.ul, tab[78].val.ul, tab[79].val.ul, tab[80].val.ul, tab[81].val.ul, tab[82].val.ul,
	 	tab[83].val.ul, tab[84].val.ul, tab[85].val.ul, tab[86].val.ul, tab[87].val.ul, tab[88].val.ul, tab[89].val.ul, tab[90].val.ul, tab[91].val.ul, tab[92].val.ul, tab[93].val.ul, tab[94].val.ul, tab[95].val.ul, tab[96].val.ul,
	  	tab[96].val.ul, tab[97].val.ul, tab[98].val.ul, tab[99].val.ul, tab[100].val.ul,     tab[101].val.ul, tab[102].val.ul, tab[103].val.ul, tab[104].val.ul, tab[105].val.ul, tab[106].val.ul, tab[107].val.ul, tab[108].val.ul,
	 	tab[109].val.ul, tab[110].val.ul, tab[111].val.ul, tab[112].val.ul, tab[113].val.ul, tab[114].val.ul, tab[115].val.ul, tab[116].val.ul, tab[117].val.ul, tab[118].val.ul, tab[119].val.ul, tab[120].val.ul,
	 	tab[121].val.ul, tab[122].val.ul, tab[123].val.ul, tab[124].val.ul, tab[125].val.ul, tab[126].val.ul, tab[127].val.ul, tab[128].val.ul, tab[129].val.ul, tab[130].val.ul, tab[131].val.ul, tab[132].val.ul,
		tab[133].val.ul, tab[134].val.ul, tab[135].val.ul, tab[136].val.ul, tab[137].val.ul, tab[138].val.ul, tab[139].val.ul, tab[140].val.ul, tab[141].val.ul, tab[142].val.ul, tab[143].val.ul, tab[144].val.ul,
		tab[145].val.ul, tab[146].val.ul, tab[147].val.ul, tab[148].val.ul, tab[135].val.ul, tab[136].val.ul, tab[137].val.ul, tab[138].val.ul, tab[139].val.ul, tab[140].val.ul, tab[141].val.ul, tab[142].val.ul,
		tab[143].val.ul, tab[144].val.ul, tab[145].val.ul, tab[146].val.ul, tab[147].val.ul, tab[148].val.ul, tab[149].val.ul, tab[150].val.ul, tab[151].val.ul, tab[152].val.ul, tab[153].val.ul, tab[154].val.ul,
		tab[155].val.ul, tab[156].val.ul, tab[157].val.ul, tab[158].val.ul, tab[159].val.ul, tab[160].val.ul, tab[161].val.ul, tab[162].val.ul, tab[163].val.ul, tab[164].val.ul, tab[165].val.ul, tab[166].val.ul,
		tab[167].val.ul, tab[168].val.ul, tab[169].val.ul, tab[170].val.ul, tab[171].val.ul, tab[172].val.ul, tab[173].val.ul, tab[174].val.ul, tab[175].val.ul, tab[176].val.ul, tab[176].val.ul, tab[177].val.ul,
		tab[178].val.ul, tab[179].val.ul, tab[180].val.ul, tab[181].val.ul, tab[182].val.ul, tab[183].val.ul, tab[184].val.ul, tab[185].val.ul, tab[186].val.ul, tab[187].val.ul, tab[188].val.ul, tab[189].val.ul,
		tab[190].val.ul, tab[191].val.ul, tab[192].val.ul, tab[193].val.ul, tab[194].val.ul, tab[195].val.ul, tab[196].val.ul, tab[197].val.ul, tab[198].val.ul, tab[199].val.ul, tab[200].val.ul, tab[201].val.ul,
		tab[202].val.ul, tab[203].val.ul, tab[204].val.ul, tab[205].val.ul, tab[206].val.ul, tab[207].val.ul, tab[208].val.ul, tab[209].val.ul, tab[210].val.ul, tab[211].val.ul, tab[212].val.ul, tab[213].val.ul,
		tab[214].val.ul, tab[215].val.ul, tab[216].val.ul, tab[217].val.ul, tab[218].val.ul, tab[219].val.ul, tab[220].val.ul, tab[221].val.ul, tab[222].val.ul, tab[223].val.ul, tab[224].val.ul, tab[225].val.ul,
		tab[226].val.ul, tab[226].val.ul, tab[227].val.ul, tab[228].val.ul, tab[229].val.ul, tab[230].val.ul, tab[231].val.ul, tab[232].val.ul, tab[233].val.ul, tab[234].val.ul, tab[235].val.ul, tab[236].val.ul,
		tab[237].val.ul, tab[238].val.ul, tab[239].val.ul, tab[240].val.ul, tab[241].val.ul, tab[242].val.ul, tab[243].val.ul, tab[244].val.ul, tab[245].val.ul, tab[246].val.ul, tab[247].val.ul, tab[248].val.ul,
		tab[249].val.ul, tab[250].val.ul, tab[251].val.ul, tab[252].val.ul, tab[253].val.ul, tab[254].val.ul, tab[255].val.ul
		);
}

void	va_arg_64(t_type *tab, char *format, void (*f)(char *format, ...))
{
	printf("\n__64__\n\n");
	f(format, tab[0].val.ul, tab[1].val.ul, tab[2].val.ul, tab[3].val.ul, tab[4].val.ul, tab[5].val.d, tab[6].val.d, tab[7].val.d, tab[8].val.d, tab[9].val.d, tab[10].val.d, tab[11].val.d, tab[12].val.d,
	  	tab[13].val.ul, tab[14].val.ul, tab[15].val.ul, tab[16].val.ul, tab[17].val.ul, tab[18].val.ul, tab[19].val.ul, tab[20].val.ul, tab[21].val.ul, tab[22].val.ul, tab[23].val.ul, tab[24].val.ul, tab[25].val.ul, tab[26].val.ul,
	 	tab[27].val.ul, tab[28].val.ul, tab[29].val.ul, tab[30].val.ul, tab[31].val.ul, tab[32].val.ul, tab[33].val.ul, tab[34].val.ul, tab[35].val.ul, tab[36].val.ul, tab[37].val.ul, tab[38].val.ul, tab[39].val.ul, tab[40].val.ul,
	 	tab[41].val.ul, tab[42].val.ul, tab[43].val.ul, tab[44].val.ul, tab[45].val.ul, tab[46].val.ul, tab[47].val.ul, tab[48].val.ul, tab[49].val.ul, tab[50].val.ul, tab[51].val.ul, tab[52].val.ul, tab[53].val.ul, tab[54].val.ul,
	  	tab[55].val.ul, tab[56].val.ul, tab[57].val.ul, tab[58].val.ul, tab[59].val.ul, tab[60].val.ul, tab[61].val.ul, tab[62].val.ul, tab[63].val.ul, tab[64].val.ul, tab[65].val.ul, tab[66].val.ul, tab[67].val.ul, tab[68].val.ul,
	 	tab[55].val.ul, tab[56].val.ul, tab[57].val.ul, tab[58].val.ul, tab[59].val.ul, tab[60].val.ul, tab[61].val.ul, tab[62].val.ul, tab[63].val.ul
		);
}


void	va_arg_13(t_type *tab, char *format, void (*f)(char *format, ...))
{
	printf("\n__13__\n\n");
	f(format, tab[0].val.ul, tab[1].val.ul, tab[2].val.ul, tab[3].val.ul, tab[4].val.ul,
		tab[5].val.d, tab[6].val.d, tab[7].val.d, tab[8].val.d, tab[9].val.d, tab[10].val.d, tab[11].val.d, tab[12].val.d);
}


void		init_nb_arg(char *format, int *nb_int, int *nb_float)
{
	int		i;
	char	c;

	i = 0;
	while ((c = format[i]))
	{
		if (is_integer(c))
			(*nb_int)++;
		else if (is_floating_fd(c))
			(*nb_float)++;
		i++;
	}
}

void	va_arg_switch(int nb_arg, t_type *tab, char *format, void (*f)(char *format, ...))
{
	int	nb_float;
	int	nb_int;

	if (nb_arg <= 256)
	{
		init_nb_arg(format, &nb_int, &nb_float);
		if (nb_arg > 64 || nb_float > (64 - 5) || nb_int > (64 - 8))
			va_arg_256(tab, format, f);
		else if (nb_arg > 13 || nb_float > 8 || nb_int > 5)
			va_arg_64(tab, format, f);
		else
			va_arg_13(tab, format, f);
	}
	else
		dprintf(2, "file:%60s	line:%5d too much arg!\n", __FILE__, __LINE__);
}

int		is_integer(char c)
{
	return (((c >= 'a' && c <= 'h') || c == 'm') ? 1 : 0);
}

int		is_floating_fd(char c)
{
	return ((c == 'i' || c == 'j') ? 1 : 0);
}

/*

	f(format, tab[0].val.ul, tab[1].val.ul, tab[2].val.ul, tab[3].val.ul, tab[4].val.ul, tab[5].val.d, tab[6].val.d, tab[7].val.d, tab[8].val.d, tab[9].val.d, tab[10].val.d, tab[11].val.d, tab[12].val.d,
	  	tab[13].val.ul, tab[14].val.ul, tab[15].val.ul, tab[16].val.ul, tab[17].val.ul, tab[18].val.ul, tab[19].val.ul, tab[20].val.ul, tab[21].val.ul, tab[22].val.ul, tab[23].val.ul, tab[24].val.ul, tab[25].val.ul, tab[26].val.ul,

*/

//	il faut aussi checker la condition de l'empilement des truc...
int		init_tab_arg(char *format, double *tab_floating, unsigned long *tab_integer, t_type *arg)
{
	int	nbi;
	int	nbf;
	int	arg_id;
	int	i;
	int	c;

	int	id_arg;

	i = 0;
	nbi = 0;
	nbf = 0;
	arg_id = 13;
	while ((c = format[i]))
	{
		if (is_integer(c))
		{
			if (nbi < 5)
				id_arg = nbi;
			else
				id_arg = arg_id++;

			bzero(arg + id_arg, sizeof(t_type));
			arg[id_arg].val.ul = tab_integer[nbi];
			arg[id_arg].id = e_unsigned_long;
			nbi++;
		}
		else if (is_floating_fd(c))
		{
			if (nbf < 8)
				id_arg = nbf + 5;
			else
				id_arg = arg_id++;

			bzero(arg + id_arg, sizeof(t_type));
			arg[id_arg].val.d = tab_floating[nbf];
			arg[id_arg].id = e_double;
			nbf++;
		}
//		printf("id_arg:%d\n", id_arg);
		i++;
	}
	return (nbi + nbf);
}

void	test_empilage()
{
	double				tab_floating[8] = {0.001, 0.002, 0.003, 0.004,  0.005, 0.006, 0.007, 0.008};
	unsigned	long	tab_integer[8] = {1, 2, 3, 4,  5};
	t_type				tab_arg[256];
	char				format[] = "aaaaa iiiijjjj";
	int					len_arg;
	void				(**push_function)();

	len_arg = init_tab_arg(format, tab_floating, tab_integer, tab_arg);		
	va_arg_switch(len_arg, tab_arg, format, print_func);
}

void	describe_all()
{
	int	i;

	i = 0;
	while (i < 13)
	{
		printf("%17s: %c <-> %d\n", ttype_name(i), (i + 'a'), i);
		i++;
	}
	printf("==========================\n");

}

         /* a : char           */ 
         /* b : short          */
         /* c : int            */
         /* d : long           */
         /* e : unsigned_char  */
         /* f : unsigned_short */
         /* g : unsigned_int   */
         /* h : unsigned_long  */
         /* i : float          */
         /* j : double         */
         /* k : long_double    */
         /* l : char           */
         /* m : void_ptr       */


/*
 	Le truc des variable fantome sur la staque foncione bien
 */

void	test_stack_order()
{
	long	double		test = 42.1377000001992;	// pour tester un vrai il faudrait imprimer la data en binaire, avant et apres
	unsigned	long	l0, l1;

	l0 = *((unsigned long*)&(test));
	l1 = *((unsigned long*)&(test) + 1);

	printf("          |%s| test:%20.15Lf \n", write_bit_out(&test, sizeof(long double)), test);

//	l1 = l0;

	double				tab_floating[256] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0, 4.1, 4.2, 4.3, 4.4, 4.5, 4.6, 4.7, 4.8, 0};
//	unsigned	long	tab_integer[256] = {1, (long)(((unsigned long)(-1)) / 2) + 1, (long)(((unsigned long)(-1)) / 2) , (long)(((unsigned long)(-1)) / 2) + 1, (long)(((unsigned long)(-1)) / 2) , 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,  17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 28, 29, 30, 31, 32, 32, 33,  34};
	unsigned	long	tab_integer[256] = {1, 2, 3, 4, 5, l0, l1, 8, 9, 10, 11, 12, 13, 14, 15, 16,  17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 28, 29, 30, 31, 32, 32, 33,  34};
	t_type				tab_arg[256];

//	char				fmt[] = "dddddddddd\n\t jjjjjjjjjj\n\t dddddddddd\n\t jjjjjjjjjj\n";
	char				fmt_integer[] 					= "abcdefgh";
	char				fmt_pointer[]		 			= "lm";
	char				fmt_flotant[] 					= "ijk"; // il y a le longfouble en plus
	char				fmt_integer_extended[] 			= "abcdefgh lm";


	char				fmt_test_stack_arg_size_1[] 		= "\
       5 INTEGER:       [hhhhh]\n\
       1 LONG_DOUBLE    [k]\n\
       10 INTEGER:      [hhhhhhhhhh]\n\
		";

	char				fmt_test_stack_arg_size_2[] 		= "\
        5 INTEGER:      [hhhhh]\n\
        1 LONG_DOUBLE   [k]\n\
        2 INTEGER:      [hh]\n\
        8 FLOTAN[       jjjjjjjj]\n\
        2 DOULBE        [jj]\n\
		";






	char				fmt_int5_flo8_mix1[] 			= "abcde ijijijij";
	char				fmt_int5_flo8_mix2[] 			= "ijijijij abcde";
	char				fmt_int5_flo8_mix3[] 			= "i a j b i c j d i e jij";
	char				fmt_int5_flo8_mix4[] 			= "ab iji cde ij iji";
	char				fmt_int5_flo8_mix5[] 			= "ijij abcde ijij";

	char *format;

	int					len_arg;
	void				(**push_function)();
	
	format = fmt_test_stack_arg_size_2;

	len_arg = init_tab_arg(format, tab_floating, tab_integer, tab_arg);		
//	printf("\nformat:	[%s]\n\n", format);
	va_arg_switch(len_arg, tab_arg, format, print_func);
}



void	truc()
{
	unsigned	long	ul = 18446744073709551608;
	float				d = *((float*)&ul);

	printf("18446744073709551608 ==> %f\n", d);
}


int	main()
{
//	describe_all();

//	test_empilage();
	test_stack_order();

//	truc();

//	max_long_test();
	return (0);
}




/*
	- Il faut tester si on peu recuperer les typre flotant par supterfuge d'unsigned long
	- Tester le comportement des long double vis a vis de la palce prise dans la staque
		- Est-ce que balancer deux unsigned long peut reconstruire la data d'un long double
		- Est-ce qu'il va falloire utiliser d'autre batterie de teste
		- Developper une sorte de staque avec des variable jeutable et on en prend une sur 4
		- Est-ce que la vie
*/

/*
 	- generer une chaine formater
	- remplir un tableau de t_type
	- appeler la fonction
*/

/*
	- Il faut tester l'ordre dans la staque
*/


/*
   :::::::
   ::POC::
   :::::::
 	MAJ long double:
		- rajouter un tableau de long double     ||> pour les stoquer, pour le testeur modulaire    | test_side
		- adapter  la fonciton push_arg	         ||> avoir un conteur gllobale tout, caster en deux | test_side
		- adapter la fonction de depope_arg	     ||> prendre en conte la taille des varaiable       | print_side
	construction des ARG
		- regle de generation pour la chaine formater
		- regle de generation de la valeur des argument: TYPE, WIDTH, PRECISION
		- ordre de passage des argument: correspondance ordre argument et maniere d'acceder a une valeur: type, width, precision
		- regle de generation des valeur des argument en fontion d'un {paquaquet_argument || chaine formater}

   :::::::
   ::PRJ::
   :::::::
	Structure macro ?? (conceptualisante, generalisante), Quel distance d'un langage de scripte
	reception des ARG
		- creation de tout les paquet:/%/
		- construction de l'ordre des type ET adaptation en $ implicite de la position des %
		- recuperation de chaque type en fonction de son ordre, si pas preciser, c'est un 8oct
		- construction/ecriture de chaque bout de la chaine de chaactere

	Faire toute les fonction printf, elle decoule toute des mecanisme


	v, [a]s | s[n],
	
	printf		->	vprintf
	dprintf     ->	vdprintf
	asprintf    ->	vasprintf
	sprintf     ->	vsprintf
	snprintf    ->	vsnprintf



	input		-->	argument reel
				--> va_list
	-------------------------------
	output		--> sortie standar (fd == 1)	| on ecrit une/plusieurs chiane de charactere sur un fd
				--> file descriptor				|

				--> buffer a allouer
				--> buffer externe				
				--> buffer externe limite





v	-> on lui communique un va_list
s	-> on ecrit dans un buffer
a	-> on a une chaine de charactere que l'on aloue
n	-> au ecrit au plus n charactere
d	-> ecrit dans un file descriptor




 sprintf	->  on ecrit dans un buffer
 snprintf	->  on ecrit dans un buffer avec au plus n
 asprintf
 dprintf
 vsprintf
 vprintf
*/


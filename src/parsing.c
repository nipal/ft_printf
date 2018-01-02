/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatique.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:02:30 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/21 14:18:31 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef	enum	e_stament
{
	// parsing state
	e_valid_inside		= 1l << 0,
	e_end_prct			= 1l << 1,
	e_parse_error		= 1l << 2,
	e_end_parsing		= 1l << 3,

	// parsing 
	e_has_precision		= 1l << 3,	
	e_has_precision_ptr	= 1l << 4,		
	e_has_min_width_	= 1l << 5,	
	e_has_min_width_ptr	= 1l << 6,	
	e_is_casted			= 1l << 7,	

	// flag
	e_flag_plus		= 1l << 8,
	e_flag_minus	= 1l << 9,
	e_flag_space	= 1l << 10,
	e_flag_zero		= 1l << 11,
	e_flag_lang_nb	= 1l << 12,
	e_flag_sparate	= 1l << 13,
	e_flag_hash		= 1l <<	14,
}				t_state;



// init parsing
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

// data to proces arg
typedef	struct	s_fparam
{
	int		width;			// l'entier qui corespond a la taille minimum, neg si addr
	int		precision;		// l'entier qui corespond a la precision, neg si addr
	long	state;			// la ou toute les option sont determiner
	t_type	arg;			// la valeur de l'argument a traiter et sont type

}				t_fparam;

//typedef	struct	s_fparse
//{
//	char	**(*tabf)[256](char *prct, char *now, t_fparam *p);
//	int		val;
//}				t_fparse;

void	init_fparam(t_fparam *arg)
{
	bzero(arg, sizeof(t_fparam)); // on mettera eventuelement des valeur defni autre
}

char	*set_parse_error(char **prev_hard, char *now, t_fparam *p)
{
	(void)prev_hard;
	(void)now;
	(void)p;
	int	option = 2;
	// on [set une erreur] OU on [re_init + jump new prct [push normal txt_format]]
	
	if (option == 1)
	{
		p->state |= e_parse_error;
		return (now + 1);
	}
	else
	{
		init_fparam(p);
		while (*now && *now != '%')// find new prct
			now++;
		return (now + ((*now) ? 1: 0));
	}
}

void	init_func_table(char *(**tabf)(char **prct, char *now, t_fparam *p), int *first)
{
	(void)tabf;
	int	i;

	*first = 0;
	i = 0;
	while (i < 256)
	{
		tabf[i] = set_parse_error;
		i++;
	}
		tabf['\0'] = NULL; 	// print the last txt part
		tabf['+'] = NULL;	// condition,	action
		tabf['-'] = NULL;
		tabf[' '] = NULL;
		tabf['#'] = NULL;
		tabf['I'] = NULL;
	   tabf['\''] = NULL;
		tabf['0'] = NULL;

//variable
		tabf['*'] = NULL;
		tabf['.'] = NULL;
		tabf['$'] = NULL;
// number
		tabf['1'] = NULL;
		tabf['2'] = NULL;
		tabf['3'] = NULL;
		tabf['4'] = NULL;
		tabf['5'] = NULL;
		tabf['6'] = NULL;
		tabf['7'] = NULL;
		tabf['8'] = NULL;
		tabf['9'] = NULL;




// cast
		tabf['h'] = NULL;
		tabf['l'] = NULL;
		tabf['L'] = NULL;
		tabf['z'] = NULL;
		tabf['j'] = NULL;
		tabf['t'] = NULL;

// typefiled
		tabf['%'] = NULL;
		tabf['d'] = NULL;
		tabf['i'] = NULL;
		tabf['u'] = NULL;
		tabf['o'] = NULL;
		tabf['x'] = NULL;
		tabf['X'] = NULL;
		tabf['f'] = NULL;
		tabf['F'] = NULL;
		tabf['e'] = NULL;
		tabf['E'] = NULL;
		tabf['g'] = NULL;
		tabf['G'] = NULL;
		tabf['a'] = NULL;
		tabf['A'] = NULL;
		tabf['c'] = NULL;
		tabf['C'] = NULL;
		tabf['s'] = NULL;
		tabf['S'] = NULL;
		tabf['p'] = NULL;
		tabf['n'] = NULL;
		tabf['m'] = NULL;


}



//*f(char **, char *, t_fparam *)
void	main_parsing(char *format, va_list beg)
{
	va_list			current;
	static	int		first = 1;
	static	char	*(*tabf[256])(char **prct, char *now, t_fparam *p);
	char			*cursor;
	char			*prev_hard;		// la precedente chaine brute
	t_fparam		param_arg;
	(void)tabf;(void)format;(void)beg;(void)current;

//	va_copy(current, beg);
	if (first)
		init_func_table(tabf, &first);
	cursor = format;
	prev_hard = format;
	init_fparam(&param_arg);
	// wait for prct
	while (*cursor)
	{
		cursor = tabf[*((unsigned char*)cursor)](&prev_hard, cursor, &param_arg);
		// process the chain
			// all the type_convert option must find the next prct and print between
	}
	// if no error --> PRINT
}


//*f(char **, char *, t_fparam *)
//void	*get_action(unsigned char c)
//{
//	static	int		first = 1;
//	static	char	*(*tabf[256])(char **prct, char *now, t_fparam *p);
//	(void)c;
//	(void)tabf;
//
//	if (first)
//	{
//		tabf[256] = NULL;
//		init_func_table(tabf);
//		first = 0;
//	}
//	return (NULL);
////	return (tabf[c]);
//}

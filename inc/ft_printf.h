/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:09:11 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/07 05:38:18 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdio.h>	// oui pour l'instatn on a besoin de debug encore:
# include <stdarg.h>
# include "libft.h"
# include "bistromatique.h"

/////  integer //////////
# define SYM_ASK 0
# define SYM_MIN 1
# define SYM_MAJ 2
/////////////////////////

// /////////////////////////////////////
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
/////////////////////////////////////////////


/////////////////////////////////////////////
typedef	enum	e_stamen_id
{
	//	#0 parsing state
	e_id_parse_error = 0,
	e_id_long_double,

	e_id_has_precision = 8,
	e_id_has_min_width,
	e_id_has_value_arg,
	e_id_has_precision_arg,
	e_id_has_min_width_arg,
	e_id_has_precision_next_arg,
	e_id_has_min_width_next_arg,

	e_id_flag_plus	= 16,
	e_id_flag_minus,
	e_id_flag_space,
	e_id_flag_zero,
	e_id_flag_lang_nb,
	e_id_flag_sparate,
	e_id_flag_hash,

	e_id_has_base = 47,
	e_id_beg_base = 48,

	e_id_size_defined = 56,		// 57
	e_id_is_unsigned,			// permet de faire une focntion de chaque
	e_id_size_caste,			// 58

	e_id_end_enum =  63

}				t_state_id;

typedef	enum	e_stament
{
	//	#0 parsing state
	e_parse_error				= 1l << e_id_parse_error,
	e_cast_long_double 			= 1l << e_id_long_double,

	e_has_precision				= 1l << e_id_has_precision,
	e_has_min_width				= 1l << e_id_has_min_width,
	e_has_value_arg				= 1l << e_id_has_value_arg,
	e_has_precision_arg 		= 1l << e_id_has_precision_arg,
	e_has_min_width_arg 		= 1l << e_id_has_min_width_arg,
	e_has_precision_next_arg 	= 1l << e_id_has_precision_arg,
	e_has_min_width_next_arg 	= 1l << e_id_has_min_width_arg,
                        	                               
	e_flag_plus					= 1l << e_id_flag_plus,        
	e_flag_minus				= 1l << e_id_flag_minus,       
	e_flag_space				= 1l << e_id_flag_space,       
	e_flag_zero					= 1l << e_id_flag_zero,        
	e_flag_lang_nb				= 1l << e_id_flag_lang_nb,     
	e_flag_sparate				= 1l << e_id_flag_sparate,     
	e_flag_hash					= 1l <<	e_id_flag_hash,        

	e_has_base					= 1l << e_id_has_base,
	e_beg_base					= 1l << e_id_beg_base,

	e_size_define				= 1l << e_id_size_defined,
	e_is_unsigned 				= 1l << e_id_is_unsigned,
	e_size_caste  				= 1l << e_id_size_caste,
	 	//	#7 size cast		
	e_end_enum 					= 1l << e_id_end_enum
}				t_state;


// precision, min_siz, id_arg
// -------------------------------------------------------------------------
//					| ------------------ |
// 	nbr				|					 | is min_size
// 	*,				|-> define size min	 | next_arg is min_size		(int)
// 	*,(nbr,$)		| 					 | is id_arg minsize 		(int)
//					| ------------------ |

//					| ------------------ |
// 	nbr,$			|->    arg value     | is id_arg of value
//					| ------------------ |

//					| ------------------ |
// '.',nbr			|					 | is precision
// '.',*			|-> define size min	 | next_arg is precision	(int)
// '.',(*,nbr,$)	| 					 | is id_arg precisione 	(int)
//					| ------------------ |
// -------------------------------------------------------------------------
//
// data to proces arg
typedef	struct	s_fparam
{
	long	state;			// la ou toute les option sont determiner
	int		id_width;
	int		id_preci;
	int		id_arg;

	int		width;			// l'entier qui corespond a la taille minimum, neg si addr
	int		precision;		// l'entier qui corespond a la precision, neg si addr
	t_type	arg;			// la valeur de l'argument a traiter et sont type

}				t_fparam;

//typedef	struct	s_fparse
//{
//	char	**(*tabf)[256](char *prct, char *now, t_fparam *p);
//	int		val;
//}				t_fparse;



char	*flag_add_plus(char **prev_hard, char *now, t_fparam *p);
char	*flag_add_minus(char **prev_hard, char *now, t_fparam *p);
char	*flag_add_space(char **prev_hard, char *now, t_fparam *p);
char	*flag_add_zero(char **prev_hard, char *now, t_fparam *p);
char	*flag_add_lang_nb(char **prev_hard, char *now, t_fparam *p);
char	*flag_add_separate(char **prev_hard, char *now, t_fparam *p);
char	*flag_add_hash(char **prev_hard, char *now, t_fparam *p);


//	converter
#define F_TO_INT *(int*)&
#define INT_TO_F *(float*)&



int	ft_printf(const char *format, ...);

//void	count_arg(char *format, t_format_mem *mem);

/*
**	integer.c
*/

char	**symbole_base1(int flag);
int		put_integer_s(long val, int base, char *buff, int buff_len);
int		put_integer_u(unsigned long val, int base, char *buff, int buff_len);


/*
**	print_bit.c
*/

void	print_bit(unsigned char *data, int size);
void	print_bit_str(unsigned char *data, int size, char *s);

/*
**	print.c
*/
int		buffer(char *str, int size, int fd);	// si str est NULL on imprime le buffer et on libere la memoire

/*
**	floating_number.c
*/

void	print_float(float f, int precision);
void	float_get_value(float f, int *sign, int *expo, int *mantis);
int		calcul_bistro2(int expo, int mantis, t_bistro *res, int precision);
int		calcul_bistro(int expo, int mantis, t_bistro *res, int precision);

/*
**	precision_func.c
*/

char	*get_number(char *format, int *number);
char	*set_senario_nbr(char **prev_hard, char *now, t_fparam *p);
char	*set_senario_star(char **prev_hard, char *now, t_fparam *p);
char	*set_senario_point(char **prev_hard, char *now, t_fparam *p);

/*
**	pars_func.c
*/
char	*set_parse_error(char **prev_hard, char *now, t_fparam *p);
char	*flag_add_plus(char **prev_hard, char *now, t_fparam *p);
char	*flag_add_minus(char **prev_hard, char *now, t_fparam *p);
char	*flag_add_space(char **prev_hard, char *now, t_fparam *p);
char	*flag_add_zero(char **prev_hard, char *now, t_fparam *p);
char	*flag_add_lang_nb(char **prev_hard, char *now, t_fparam *p);
char	*flag_add_separate(char **prev_hard, char *now, t_fparam *p);
char	*flag_add_hash(char **prev_hard, char *now, t_fparam *p);

char	*flag_set_size_unsigned(char **prev_hard, char *now, t_fparam *p);
char	*flag_set_cast_s1(char **prev_hard, char *now, t_fparam *p);
char	*flag_set_cast_s2(char **prev_hard, char *now, t_fparam *p);
char	*flag_set_cast_s4(char **prev_hard, char *now, t_fparam *p);
char	*flag_set_cast_s8(char **prev_hard, char *now, t_fparam *p);
char	*flag_set_cast_u1(char **prev_hard, char *now, t_fparam *p);
char	*flag_set_cast_u2(char **prev_hard, char *now, t_fparam *p);
char	*flag_set_cast_u4(char **prev_hard, char *now, t_fparam *p);
char	*flag_set_cast_u8(char **prev_hard, char *now, t_fparam *p);
char	*flag_set_long_double(char **prev_hard, char *now, t_fparam *p);
#endif

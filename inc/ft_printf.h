/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:09:11 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/31 22:59:35 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdio.h>	// oui pour l'instatn on a besoin de debug encore:
# include <stdarg.h>
# include "libft.h"
# include "bistromatique.h"
# include <math.h>


# define BUFF_LARGE 4084 // (4096 - (sizeof(int) + sizeof(void*))) // pour que t_buf fasse lui 4096
//# define BUFF_LARGE 3
# define BUFF_SMALL 64

//  integer //////////
# define SYM_ASK 0
# define SYM_MIN 1
# define SYM_MAJ 2
/////////////////////////


// /////////////////////////////////////
typedef	struct	s_buf
{
	char	data[BUFF_LARGE];
	int		id;
	struct	s_buf	*next;
}				t_buf;

typedef	struct	s_buffer
{
	t_buf	beg;
	t_buf	*current;
	int		block_nb;
}				t_buffer;


// /////////////////////////////////////

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
	e_id_base_majuscule,

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
	e_base_majuscule			= 1l << e_id_base_majuscule,

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

	//	set the prinsing param
	int		width;			// l'entier qui corespond a la taille minimum, neg si addr
	int		precision;		// l'entier qui corespond a la precision, neg si addr
	t_type	arg;			// la valeur de l'argument a traiter et sont type
	char	*beg_sec;
	char	*prct;
	int		base;			// on staque la base

	// func to print the value
	char	dash[5];		//	--> the thing 
	char 	fill_before;	//	|	
	char 	signe;			// 	| if 0 -> do nothing nothing
	char	fill_after;		//	|
}				t_fparam;

//typedef	struct	s_fparse
//{
//	char	**(*tabf)[256](char *prct, char *now, t_fparam *p);
//	int		val;
//}				t_fparse;



char	*flag_add_plus(char *now, t_fparam *p);
char	*flag_add_minus(char *now, t_fparam *p);
char	*flag_add_space(char *now, t_fparam *p);
char	*flag_add_zero(char *now, t_fparam *p);
char	*flag_add_lang_nb(char *now, t_fparam *p);
char	*flag_add_separate(char *now, t_fparam *p);
char	*flag_add_hash(char *now, t_fparam *p);


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

void	buffer_init(t_buffer *b);
void	buffer_push_data(t_buffer *b, char *data, int size);
void	buffer_push_nchar(t_buffer *b, char c, int nb);
void	buffer_output_fd(t_buffer *b, int fd);
void	buffer_output_standar(t_buffer *b);
void	buffer_output_string_size(t_buffer *b, char *dest, int len);
void	buffer_output_string(t_buffer *b, char *dest);
;
/*
**	floating_number.c
*/

void	print_float_example(float f, int precision);
void	float_get_value(float f, int *sign, int *expo, int *mantis);
int		calcul_bistro2(int expo, int mantis, t_bistro *res, int precision);
int		calcul_bistro(int expo, int mantis, t_bistro *res, int precision);

/*
**	precision_func.c
*/

char	*get_number(char *format, int *number);
char	*set_senario_nbr(char *now, t_fparam *p);
char	*set_senario_star(char *now, t_fparam *p);
char	*set_senario_point(char *now, t_fparam *p);

/*
**	pars_func.c
*/
char	*set_parse_error(char *now, t_fparam *p);
char	*flag_add_plus(char *now, t_fparam *p);
char	*flag_add_minus(char *now, t_fparam *p);
char	*flag_add_space(char *now, t_fparam *p);
char	*flag_add_zero(char *now, t_fparam *p);
char	*flag_add_lang_nb(char *now, t_fparam *p);
char	*flag_add_separate(char *now, t_fparam *p);
char	*flag_add_hash(char *now, t_fparam *p);

char	*flag_set_size_unsigned(char *now, t_fparam *p);
char	*flag_set_cast_s1(char *now, t_fparam *p);
char	*flag_set_cast_s2(char *now, t_fparam *p);
char	*flag_set_cast_s4(char *now, t_fparam *p);
char	*flag_set_cast_s8(char *now, t_fparam *p);
char	*flag_set_cast_u1(char *now, t_fparam *p);
char	*flag_set_cast_u2(char *now, t_fparam *p);
char	*flag_set_cast_u4(char *now, t_fparam *p);
char	*flag_set_cast_u8(char *now, t_fparam *p);
char	*flag_set_long_double(char *now, t_fparam *p);

/*
**	type_function.c	
*/

char	*print_prct(char *buff, int *size, t_fparam *p);
char	*print_dec_signed(char *buff, int *size, t_fparam *p);
char	*print_dec_signed_cap(char *buff, int *size, t_fparam *p);
char	*print_dec_unsigned(char *buff, int *size, t_fparam *p);
char	*print_dec_unsigned_cap(char *buff, int *size, t_fparam *p);
char	*print_oct_unsigned(char *buff, int *size, t_fparam *p);
char	*print_oct_unsigned_cap(char *buff, int *size, t_fparam *p);
char	*print_exa_unsigned(char *buff, int *size, t_fparam *p);
char	*print_exa_unsigned_cap(char *buff, int *size, t_fparam *p);
char	*print_float(char *buff, int *size, t_fparam *p);
char	*print_float_cap(char *buff, int *size, t_fparam *p);
char	*print_expo_dec(char *buff, int *size, t_fparam *p);
char	*print_expo_dec_cap(char *buff, int *size, t_fparam *p);
char	*print_expo_dec_mixt(char *buff, int *size, t_fparam *p);
char	*print_expo_dec_mixt_cap(char *buff, int *size, t_fparam *p);
char	*print_expo_exa(char *buff, int *size, t_fparam *p);
char	*print_expo_exa_cap(char *buff, int *size, t_fparam *p);
char	*print_char(char *buff, int *size, t_fparam *p);
char	*print_char_unicode(char *buff, int *size, t_fparam *p);
char	*print_str(char *buff, int *size, t_fparam *p);
char	*print_str_unicode(char *buff, int *size, t_fparam *p);
char	*print_ptr(char *buff, int *size, t_fparam *p);
char	*print_nbc_print(char *buff, int *size, t_fparam *p);
char	*print_perror(char *buff, int *size, t_fparam *p);

/*
**	type_function.c	
*/

char	*parse_prct(char *now, t_fparam *p);
char	*parse_dec_signed(char *now, t_fparam *p);
char	*parse_dec_signed_cap(char *now, t_fparam *p);
char	*parse_dec_unsigned(char *now, t_fparam *p);
char	*parse_dec_unsigned_cap(char *now, t_fparam *p);
char	*parse_oct_unsigned(char *now, t_fparam *p);
char	*parse_oct_unsigned_cap(char *now, t_fparam *p);
char	*parse_exa_unsigned(char *now, t_fparam *p);
char	*parse_exa_unsigned_cap(char *now, t_fparam *p);
char	*parse_float(char *now, t_fparam *p);
char	*parse_float_cap(char *now, t_fparam *p);
char	*parse_expo_dec(char *now, t_fparam *p);
char	*parse_expo_dec_cap(char *now, t_fparam *p);
char	*parse_expo_dec_mixt(char *now, t_fparam *p);
char	*parse_expo_dec_mixt_cap(char *now, t_fparam *p);
char	*parse_expo_exa(char *now, t_fparam *p);
char	*parse_expo_exa_cap(char *now, t_fparam *p);
char	*parse_char(char *now, t_fparam *p);
char	*parse_char_unicode(char *now, t_fparam *p);
char	*parse_str(char *now, t_fparam *p);
char	*parse_str_unicode(char *now, t_fparam *p);
char	*parse_ptr(char *now, t_fparam *p);
char	*parse_nbc_parse(char *now, t_fparam *p);
char	*parse_perror(char *now, t_fparam *p);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:09:11 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/21 11:11:15 by fjanoty          ###   ########.fr       */
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



typedef	enum	e_stament
{
	// parsing state
	e_valid_inside		= 1l << 0,
	e_end_prct			= 1l << 1,
	e_parse_error		= 1l << 2,
	e_end_parsing		= 1l << 3,

	// parsing 
	e_has_precision		= 1l << 4,	
	e_has_precision_ptr	= 1l << 5,		
	e_has_min_width_	= 1l << 6,	
	e_has_min_width_ptr	= 1l << 7,	
	e_is_casted			= 1l << 8,	

	// flag
	e_flag_plus		= 1l << 9,
	e_flag_minus	= 1l << 10,
	e_flag_space	= 1l << 11,
	e_flag_zero		= 1l << 12,
	e_flag_lang_nb	= 1l << 13,
	e_flag_sparate	= 1l << 14,
	e_flag_hash		= 1l <<	15,
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

#endif

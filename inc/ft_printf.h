/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:09:11 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/10 08:59:08 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <stdio.h>	// oui pour l'instatn on a besoin de debug encore:
# include <stdarg.h>

typedef	struct	s_print_param
{
	int		integer;				//--> yes/no
	int		sign;					//--> the signe nust be present?
	int		left_justifier;			//--> push to left/right if shorter than min_size
	int		space_for_sign;			//--> have one space before number if positive but not apparant

	int		precision;				//--> number: [i]>>cast, [f]>>beforevirgule
	int		min_size;				//--> number: len_min
	char	empi_char;				//--> char to fill if shorter than min_size
	int		base;					//--> the base to print value
}				t_print_param;


typedef	struct	s_format_mem
{
	int				sc;			// segment_count
	int				ac;			// argument_count
	char			**qual;		// un pointeur sur la zone de texte qui qualifie la 
	char			**txt;		// un pointeur ver la zone de text brute
	char			*type;		// un tableau des type;
	char			*format;	// une copie de la chaine formater
	long			*data;		// le contenue des argument, a caster evidement
	int				*id_data;	// l'index de la data:: pour les bloque de %% associer a rien.. auttant que de segment
	t_print_param	*pram;		// toute les info relative au formatage du nombre
}				t_format_mem;

/*
Dans l'idee on a un genre de wraper/manageur qui va appeler
les fonction de parsing en fonction de la chaine de caractere. Et a chaque fois
on incremente le pointeur sur qual(ificateur).

que se passe-t-il si il y a plusieurs information contradictoire
*/


//	TODO: tolerrence aux espace

/*		[Info multiple]
(f)		.nb	:precision:				-->la dernier valeur


(d)		hh, h, l, ll :cast_type: 	-->le plus grand type
*/

/*			Parsing	>>>		*/
void	all_func(char *qual, int *id, t_format_mem *mem);
		is_integer				// >>> with type
		is_left_justified		// >>> ?
		is_sign					// >>> ?
		get_precision			// la precision peut etre une ref_data
		get_min_size			// >>> ?
		get_empi_char			// >>> ?
		get_base				// >>> with type
		get_value				// >>> ? si la zone memoir est une ref_data
	
		// exostiviter des senario
		is_one_shot				// les modifieur facile
		is_first_combo
		is_combo_valid			// celuila, plus chiant

/*		<<<	gnisraP			*/


/*			print	>>>		*/
//	convert base_min/maj 		(int)
//	convert base_min/maj 		(float)
//	push_str(char *str) 		// ==> str:push, NULL:print and flush
//		manage_fill_rest()			// remplis les case en plus
/*		<<<	tnirp			*/



typedef	enum	e_id_rule
{
	adapteur,
	type,
	number,
	mult_type,

}				t_id_rule;

typedef	struct	s_rules
{
	t_id_rule	id;
	char	*name;
	char	*init;
	char	tab[256];
}				t_rules;


int	ft_printf(char *format, ...);

void	count_arg(char *format, t_format_mem *mem);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatique.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:02:54 by fjanoty           #+#    #+#             */
/*   Updated: 2018/02/09 18:56:41 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTROMATIQUE_H
# define BISTROMATIQUE_H

# include <stdio.h>
# include <string.h>

#define BISTRO_LEN 30
#define BISTRO_UNITE 1000000
#define BISTRO_NB_DIGIT 6

#define BISTRO_DEBUG 0

//  integer
# define SYM_ASK 0
# define SYM_MIN 1
# define SYM_MAJ 2


# include "libft.h"

//	v2
//typedef struct	s_bistro
//{
//	int		sign;					// {-1, 1}
//	long	number[BISTRO_LEN];		// la data du nombre
//	long	*nbr;
//	int		is_maloc;
//	int		coma;					// la position relative de la virgule, peut etre {> 0, < 0, == 0}
//	int		block_max;				// le nombre de block utiliser
//}				t_bistro;

typedef struct	s_bistro
{
	long	number[BISTRO_LEN];		// la data du nombre
	long	*nbr;					// le poiteur au cas ou on le malloc
	int		is_malloc;				// if we need to free, au cas ou une liste chainer mixte
	int		sign;					// {-1, 1}
	int		coma;					// la position relative de la virgule, peut etre {> 0, < 0, == 0}
	int		block_max;				// le nombre de block utiliser
	int		state;					// un peu balencer des message d'erreur ??
}				t_bistro;

//	On fait quoi si les deux nombre n'on pas la meme position de virgule?
//		-> en dehore de son perimetre, un nombre est a 0,
//			donc si on est confronter a des valeur absurde ou peu remvoyer 0
//		-> Il faut tester si la plage de precision des deux tien dans un type
//			OUI: on place la virgule pour avoir le maximum d'imformation
//			NON: on alloue de la memoire

typedef	struct	s_bistro_sub_add
{
	t_bistro	*v1;
	t_bistro	*v2;
}				t_bistro_sa;


void	bistro_set_0_in(t_bistro *nb);
void	bistro_copie(t_bistro *from, t_bistro *to);
void	bistro_add_in(t_bistro *a, t_bistro *b, t_bistro *result);
void	bistro_mult_one_in(t_bistro *a, long nb, t_bistro *result);
void	bistro_pow_in(int nb, int pow, t_bistro *res);
void	bistro_pow_unite_in(t_bistro *a, int pow, t_bistro *result);

//void	bistro_sub_one_in(t_bistro *a, long nb, t_bistro *result);
void	bistro_sub_in(t_bistro *a, t_bistro *b, t_bistro *result);
//void	bistro_div_one_pow_in(t_bistro *a, long nb, t_bistro *result);
void	bistro_div_in(t_bistro *a, t_bistro *b, t_bistro *result);

int		bistro_is_inf_scal(t_bistro *a, long nb);
int		bistro_is_inf(t_bistro *a, t_bistro *b);
int		bistro_is_inf_eq_scal(t_bistro *a, long nb);
int		bistro_is_inf_eq(t_bistro *a, t_bistro *b);
int		bistro_is_sup_scal(t_bistro *a, long nb);
int		bistro_is_sup(t_bistro *a, t_bistro *b);
int		bistro_is_sup_eq_scal(t_bistro *a, long nb);
int		bistro_is_sup_eq(t_bistro *a, t_bistro *b);
int		bistro_is_eq_scal(t_bistro *a, long nb);
int		bistro_is_eq(t_bistro *a, t_bistro *b);

void	bistro_print(t_bistro *nb);
void	bistro_print_str(t_bistro *nb, char *str);
void	bistro_define_len(t_bistro *nb, int *nb_block, int *nb_digit);
int		bistro_to_str(t_bistro *nb, char *buff, int len_buff);

long	power(long val, int pow);
int		bistro_get_digit(t_bistro *nb, int pow, int base);
void	bistro_set_digit_in(long val, int pow, int base, t_bistro *nb);

/*
**	integer.c
*/

char	**symbole_base1(int flag);
int		put_integer_s(long val, int base, char *buff, int buff_len);
int		put_integer_u(unsigned long val, int base, char *buff, int buff_len);

#endif

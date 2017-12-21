/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatique.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:02:54 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/21 08:42:32 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTROMATIQUE_H
# define BISTROMATIQUE_H

# include <stdio.h>
# include <string.h>
# include "libft.h"

#define BISTRO_LEN 30
#define BISTRO_UNITE 1000000
#define BISTRO_NB_DIGIT 6

#define BISTRO_DEBUG 1

//  integer
# define SYM_ASK 0
# define SYM_MIN 1
# define SYM_MAJ 2



typedef struct	s_bistro
{
	int		sign;
	long	number[BISTRO_LEN];		// la data du nombre
	int		block_mult;				// le nombre de block qu'on multiplie // moins sur
	int		block_max;				// le nombre de block utiliser
}				t_bistro;


void	bistro_set_0_in(t_bistro *nb);
void	bistro_copie(t_bistro *from, t_bistro *to);
void	bistro_add_in(t_bistro *a, t_bistro *b, t_bistro *result);
void	bistro_mult_one_in(t_bistro *a, long nb, t_bistro *result);
void	bistro_pow_in(int nb, int pow, t_bistro *res);
void	bistro_pow_unite_in(t_bistro *a, int pow, t_bistro *result);

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

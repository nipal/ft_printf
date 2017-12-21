/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floating_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 05:43:49 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/21 08:47:01 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// get power digit
// set power digit

//	a and b are integer with a position for the coma
//	theoricaly they can't have a positive value,
//	a and b are supposed to be sort with coma positon:
//	a have the smallest
//			a		|		b
//--------------------------------
//		1234300.00 	+	0.000034545
//		 a * 10^2	+	b * 10^-9		|	a * 10^11 + b,	'.' --> len - 9
//		3233323		+	231.324
//		 a * 10^0	+	b * 10^-3		|	a * 10^3  + b,	'.' --> len - 3
//		3423.324	+	69.76576578
//		 a * 10^-2	+	b * 10^-8		|	a * 10^6  + b,	'.' --> len - 8
//----
//	 	 a * 10^m	+	b * 10^n		|	a * 10^(m - n), '.' --> len - n
//-------------------------------
//	to print the coma we move back all the char before the coma
//	or we move front all the char after and we save alle the char at the end -1
void	calcul_bistro(int expo, int mantis, t_bistro *res, int precision)
{
(void) precision;
	int			mult1;
	int			mult2;
	t_bistro	bmantis;
	t_bistro	bexpo;


	mult1 = 0;
	mult2 = 0;
	if ((expo - 23) > 0)
		bistro_pow_in(2, expo - 23, &bmantis);
	else
	{
		mult1 = (expo - ((expo == -127) ? 22 : 23));
		bistro_pow_in(5, -mult1, &bmantis);
	}
	if (expo > 0)
		bistro_pow_in(2, expo, &bexpo);
	else
	{
		mult2 = expo;
		(expo == -127) ? bistro_set_0_in(&bexpo) : bistro_pow_in(5, -mult2, &bexpo);
	}
	mult1 = mult2 - mult1;
	bistro_pow_unite_in(&bexpo, mult1 / 6, &bexpo);
	bistro_mult_one_in(&bexpo, power(10, (mult1 % 6)), &bexpo);
	bistro_mult_one_in(&bmantis, mantis, res);
	bistro_add_in(res, &bexpo, res);
	//	<<--	verification
}

//	on pourrai envoyer expo - 23 mais plus tard
//	on renvoie la positoion de la virgule
int		calcul_bistro2(int expo, int mantis, t_bistro *res, int precision)
{
	t_bistro	bmantis;
	t_bistro	add;
	int			id_coma;

	expo -= 23;
	mantis |= (expo > -150) << 23;
	id_coma =  (expo >= 0) ? 0 : -(expo + (expo == -150));
	if (expo > 0)
		bistro_pow_in(2, expo, &bmantis);
	else
		bistro_pow_in(5, id_coma, &bmantis);
	bistro_mult_one_in(&bmantis, mantis, res);
	//	<<--	verification d'arrondis
	if (precision > 0 && precision < id_coma
		&& (bistro_get_digit(&bmantis, id_coma - precision - 1, 10) >= 5))
	{
		bistro_set_digit_in(1, id_coma - precision, 10 , &add);
		bistro_add_in(&bmantis, &add, &bmantis);
	}
	// <<--		On a un nombre pret a etre imprimer a une certaine precision
	return (id_coma);
}

void	float_get_value(float f, int *sign, int *expo, int *mantis)
{
//	(void)f;
	*sign = !!((F_TO_INT f) & 1 << 31);	// 0-> '+'	1-> '-'
	*expo = ((F_TO_INT f) >> 23 & 0xFF) - 127;
	*mantis = (F_TO_INT f) & ((1 << 23) - 1);
}

# define BUFF_SIZE 256
//	apres on integrera cette fonction dans un truc qui construit la chaine de caractere a push
void	print_float(float f, int precision)
{
	char		buff[BUFF_SIZE];
	t_bistro	sum;
	int			sign;
	int			expo;
	int			mantis;
	int			id_coma;
	int			nb_digit;

	buff[BUFF_SIZE - 1] = '\0';
	float_get_value(f, &sign, &expo, &mantis);
	id_coma = calcul_bistro2(expo, mantis, &sum, precision);			// elle pourrais aussi directement appeler 
	nb_digit = bistro_to_str(&sum, buff, BUFF_SIZE);
	if (precision < id_coma)	// racourcir la chaine de charactere en fonction de la precision
	{
		memmove(buff + BUFF_SIZE - 1 - nb_digit + (id_coma - precision)
				, buff + BUFF_SIZE - 1 - nb_digit
				, (id_coma - precision));
		id_coma -= precision;
		nb_digit -= (id_coma - precision);
	}
	if (id_coma > 0)			// placer la virgule
		memmove(buff + BUFF_SIZE - 1 - nb_digit - 1
				, buff + BUFF_SIZE - 1 - nb_digit
				, nb_digit - id_coma);
	// On imprime
	printf("[%s]\n", (buff + BUFF_SIZE - 1 - nb_digit));
}

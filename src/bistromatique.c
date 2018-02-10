/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatique.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:02:30 by fjanoty           #+#    #+#             */
/*   Updated: 2018/02/09 19:28:45 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatique.h"

void	bistro_set_0_in(t_bistro *nb)
{
	bzero(nb, sizeof(t_bistro));
}




void	bistro_mult_one_in(t_bistro *a, long nb, t_bistro *result)
{
	(void)a;(void)nb;(void)result;
	int			i;
	long		tmp;
	long		ret;
	t_bistro	tmp_nb;

	i = 0;
	ret = 0;
	bzero(&tmp_nb, sizeof(tmp_nb));
	while (i < BISTRO_LEN)
	{
		tmp = a->number[i] * nb + ret;
		ret = tmp / BISTRO_UNITE;
		tmp_nb.number[i] = tmp % BISTRO_UNITE;
//		printf("-------------------------\n");
//		printf("a[%d] * nb:	%ld * %ld = %ld\n", i, a->number[i], nb, tmp_nb.number[i]);
		i++;
	}
	bistro_copie(&tmp_nb, result);
}

//	on decale tout les nombre, osef la perte d'info
void	bistro_pow_unite_in(t_bistro *a, int pow, t_bistro *result)
{
	(void)a;(void)pow;(void)result;
	int	i;

	if (pow > 0)
	{
		i = BISTRO_LEN - 1;
		while (i >= pow)
		{
			result->number[i] = a->number[i - pow];
			i--;
		}
		while (i >= 0)
		{
			result->number[i] = 0;
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < BISTRO_LEN - pow)
		{
			result->number[i] = a->number[i + pow];
			i++;
		}
		while (i < BISTRO_LEN)
		{
			result->number[i] = 0;
			i++;
		}	
	}
}

void	bistro_mult_in(t_bistro *a, t_bistro *b, t_bistro *result)
{
	(void)a;(void)b;(void)result;
	t_bistro	tmp;
	t_bistro	tmp_sum;
	int			i;

	bzero(&tmp, sizeof(tmp));
	bzero(&tmp_sum, sizeof(tmp_sum));
	i = 0;
	while (i < BISTRO_LEN)
	{
		bistro_mult_one_in(a, b->number[i], &tmp);
		bistro_pow_unite_in(&tmp, i, &tmp);
		bistro_add_in(&tmp, &tmp_sum, &tmp_sum);
		i++;
	}
	bistro_copie(&tmp_sum, result);
}

//	ne fonctionne bien qu'avec un nb < BISTRO_UNITE
void	bistro_pow_in(int nb, int pow, t_bistro *res)
{
	if (pow <= 0)
	{
		bzero(res, sizeof(t_bistro));
		res->number[0] = (pow < 0) ? 0: 1;
		return ;
	}
	else if (pow & 1)
	{
		bistro_pow_in(nb, pow - 1, res);
		bistro_mult_one_in(res, nb, res);
	}
	else
	{
		bistro_pow_in(nb, pow / 2, res);
		bistro_mult_in(res, res, res);
	}
}

void	bistro_print(t_bistro *nb)
{
	int	i;

	i = BISTRO_LEN - 1;
	while (i >= 0)
	{
		printf("%06ld ", nb->number[i]);
		i--;
	}
	printf("\n");
}

void	bistro_print_str(t_bistro *nb, char *str)
{
	int		i;

	i = BISTRO_LEN - 1;
	printf("%s", str);
	while (i >= 0)
	{
		if (BISTRO_DEBUG == 1)
  			printf("%06ld", nb->number[i]);
		else
			printf("%06ld ", nb->number[i]);
		i--;
	}
	printf("\n");
}



void	bistro_define_len(t_bistro *nb, int *nb_block, int *nb_digit)
{
	int		i;
	int		pow_10;
	
	i = BISTRO_LEN - 1;
	while (i >= 0 && !nb->number[i])
		i--;
	*nb_block = i + 1;
	*nb_digit = BISTRO_NB_DIGIT * i;
	pow_10 = 1;
	if (!*nb_block)
		*nb_digit = 0;
	else
		while (pow_10 < BISTRO_UNITE && nb->number[i] >= pow_10 && (pow_10 *= 10))
			(*nb_digit)++;
	if (!*nb_digit)
		*nb_digit = 1;
}

//	on pourrai aussi faire un truc comme pour les int
//int	put_integer_s(long val, int base, char *buff, int buff_len)
int		bistro_to_str(t_bistro *nb, char *buff, int len_buff)
{
	int		nb_digit;
	int		nb_block;
	int		i;
	int		j;

	buff[BISTRO_LEN * BISTRO_NB_DIGIT] = '\0';
	bistro_define_len(nb, &nb_block, &nb_digit);
	i = 0;
	j = len_buff - BISTRO_NB_DIGIT - 1;
//	if (nb->number[3] == 1000)
//		nb->number[3] = 1234;
//	bistro_print_str(nb, "number:	");
	while (i < nb_block - 1)
	{
		put_integer_s(nb->number[i] + BISTRO_UNITE, 10, buff + j - 1, 7); // il fut mettre combien??
		j -= BISTRO_NB_DIGIT;
		i++;
	}
	put_integer_s(nb->number[i], 10, buff + j, BISTRO_NB_DIGIT);
	return (nb_digit);
}

long	power(long val, int pow)
{
	long	tmp;

	if (pow <= 0)
		return (1);
	else if (pow & 1)
		return (val * power(val, pow - 1));
	tmp = power(val, pow / 2);
	return (tmp * tmp);
}

//	potentielement usilisable que dans une base 10
//	mais on pourrais eventuelement faire un truc generique
//	avec une vertion ameliorer de nistromatique
int		bistro_get_digit(t_bistro *nb, int pow, int base)
{
	int				id_nb;
	int				id_div;
	int				div;
	int				digit;

	id_nb = pow / BISTRO_NB_DIGIT;
	id_div = pow % BISTRO_NB_DIGIT;
	div = power(base, id_div);
	digit = (nb->number[id_nb] / div) % base;
//	printf("**********************************************\n");
//	printf("pow:%d	base:%d\n", pow, base);
//	printf("id_nb:%d	id_div:%d	div:%d\n", id_nb, id_div, div);
//	bistro_print_str(nb, "number:	");
//	printf("**********************************************\n");
	
	return (digit);
}

void	bistro_set_digit_in(long val, int pow, int base, t_bistro *nb)
{
	int				id_nb;
	int				mult;

	bzero(nb, sizeof(t_bistro));
	id_nb = pow / BISTRO_NB_DIGIT;
	mult = power(base, pow % BISTRO_NB_DIGIT);
	nb->number[id_nb] = mult * val;
}

/*
============================ ADD ============================
arg1_is_a:
	+, +
	-, -
	+, - && |a| >= |b|
	-, + && |a| >= |b|
--->  (a.sign * b.sign) > 0  || a > b

func_is_add:
	+, +
	-, -
--> (a.sign * b.sign) > 0
sign_is_pos:
	+, +
	+, - && a >= b
	-, + && !(a >= b)
--> [!same_sign  && ((a > 0) ^ (b >= a))] || [a > 0 && b > 0]		(A & B || ~A & ~B) <=> (A ^ ~B)

##	sign_is_neg:
##		+, - && |b| > |a|
##		-, + && |a| > |b|
##		-, -
##	--> [!same_sign  && {(a > 0) ^ (a > b)}] || [a < 0 && b < 0]


============================ SUB ============================


	+,+ && b > a	=  arg1_is_a && sign_eq
	-,- && a > b


arg1_is_a:
	+,- 
	-,+
	+,+ && b > a
	-,- && a > b
--> (a.sign * b.sign) < 0 || ((a > 0) ^ (a > b))

func_is_sub:
	+,+
	-,-
sign_is_neg:
	-,+
	+,+	&& b > a
	-,- && a > b
--> (a < 0 && b > 0) || ((a.sign * b.sign) > 0 && ((a > 0) ^ (a > b)))


	::::::::::::::::::::::::::::::::

	 a +  b		=>	  a + b, +
	 a + -b		=>	  a - b, +		si |a| >= |b|
	 			 ou:  b - a, -		-- sinon --
	-a +  b		=>	  b - a, -		si |a| >= |b|
	 			 ou:  a - b, +		-- sinon --
    -a + -b		=>	  a + b, -

-----------
+,+	 a -  b		=>	  a - b, +		si |a| >= |b|
+,+	 			 ou:  b - a, -		-- sinon --
+,-	 a - -b		=>	  a + b, +
-,+	-a -  b		=>	  a + b, -
-,- -a - -b		=>	  b - a, +		si |b| >= |a|
-,-	 			 ou:  a - b, -		-- sinon --

		a + b |=> (a * b) > 0
		a - b |=> a > b
	::::::::::::::::::::::::::::::::
	Il faudrait que les condition sur l'operation 
		On a un premier changement en d'oeration en fonction du signe
		Puis si c'est une soustraction et que l'un est plus grand que l'autre on inverse encore
	::::::::::::::::::::::::::::::::


	a - b => a + b*-1
	bistro - scal
	scal - bistro	=  (bistro * -1), + scal
	|
	|	Soit on gere la representation des nombre negatif dans les nombre et on
	| a pas a gerer la soustraction en tant que tel:
	|	a - b ==> a + b*-1
	|	b - a ==> b + a*-1
	|
	|	Soit .
*/


/*
	On part du principe que les valeur sont bonne,
	si non on aurra envoyer des parametre pour tomber dans un cas facile
*/
void	bistro_sub_one_in(t_bistro *a, long nb, t_bistro *result)
{
	(void)a;(void)nb;(void)result;
	//	normalement le nombre ne pourra attenindre que le trosieme block au maximum
}

//	7 -  3:	->	7 - 3
//	7 -  9:	->	9 - 7, *-1
//
//	7 + -3:	->	7 - 3
//	7 + -9:	->	9 - 7, *-1
//

/*
	int		i;
	long	tmp;
	long	ret;
	int		add;

	i = 0;
	ret = 0;
	while (i < BISTRO_LEN)
	{
		tmp = a->number[i] - (b->number[i] + ret);
		add = (((-tmp / BISTRO_UNITE) + 1) * BISTRO_UNIT);
		ret = (tmp < 0) ? add : 0;
		result->number[i] = (((tmp < 0) * add) + ) % BISTRO_UNITE;
		i++;
	}


	tmp
	
		



	--
	tmp = -BISTRO_UNITE
	result = 0
	ret = 1
	--
	tmp = -3 * BISTRO_UNITE
	result = tmp % BISTRO_UNITE * 
	ret = 1
	--
	tmp = -(BISTRO_UNITE ^ 2)
	ret = 
*/

/*
	+, +	|	0
	+, -	|	1
	-, +	|	2
	-, -	|	3
*/

/*
	c1 = (a.sign * b.sign) >= 0		(same_sign)
	c2 = (a > b)					(a_sup_b)
	c3 = c1 && c2 ^ (a.sign >=0)	(result_positive)

 	(f = '-'):
		+, +	0
		-, -	3
	-->  ((c1))

	(arg1 = a):
		+, +, a > b
		+, -
		-, +
		-, -, a > b
	-->  ( !c1 | ((c2 = (a > b))))

 	(inv = -1):
		+, +, b > a
		-, +
		-, -, a > b
	!(inv = -1)
		+, +, a > b
		-, -, b > a	|| -a > -b
	-->	((a >= 0 && b >= 0) && ((a >= 0) ^ (a > b)), avec: sign = (a < 0) ? -1 : 1; pck a et b sont du mem signe
	ou --> c1 && c2 ^ (a >=0)
		

	
*/

//	a >= b >= 0, 


//	on pourrait rajouter le reste
void	bistro_div_in(t_bistro *a, t_bistro *b, t_bistro *result)
{
	(void)a;(void)b;(void)result;
	//	on evalue 
}

//	/////////////////////////////////////////////////////////


int		bistro_is_inf_scal(t_bistro *a, long nb)
{
	(void)a;(void)nb;
	return (0);
}


int		bistro_is_inf(t_bistro *a, t_bistro *b)
{
	(void)a;(void)b;
	return (0);
}


int		bistro_is_inf_eq_scal(t_bistro *a, long nb)
{
	(void)a;(void)nb;
	return (0);
}


int		bistro_is_inf_eq(t_bistro *a, t_bistro *b)
{
	(void)a;(void)b;
	return (0);
}


int		bistro_is_sup_scal(t_bistro *a, long nb)
{
	(void)a;(void)nb;
	return (0);
}


int		bistro_is_sup(t_bistro *a, t_bistro *b)
{
	(void)a;(void)b;
	return (0);
}


int		bistro_is_sup_eq_scal(t_bistro *a, long nb)
{
	(void)a;(void)nb;
	return (0);
}


int		bistro_is_sup_eq(t_bistro *a, t_bistro *b)
{
	(void)a;(void)b;
	return (0);
}


int		bistro_is_eq_scal(t_bistro *a, long nb)
{
	(void)a;(void)nb;
	return (0);
}


int		bistro_is_eq(t_bistro *a, t_bistro *b)
{
	(void)a;(void)b;
	return (0);
}



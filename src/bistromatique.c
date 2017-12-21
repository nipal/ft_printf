/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatique.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:02:30 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/21 08:41:23 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatique.h"

void	bistro_set_0_in(t_bistro *nb)
{
	bzero(nb, sizeof(t_bistro));
}

void	bistro_copie(t_bistro *from, t_bistro *to)
{
	int	i;

	i = 0;
	while (i < BISTRO_LEN)
	{
		to->number[i] = from->number[i];
		i++;
	}
}

void	bistro_add_in(t_bistro *a, t_bistro *b, t_bistro *result)
{
	int		i;
	long	tmp;
	long	ret;

	i = 0;
	ret = 0;
	while (i < BISTRO_LEN)
	{
		tmp = a->number[i] + b->number[i] + ret;
		ret = tmp / BISTRO_UNITE;
		result->number[i] = tmp % BISTRO_UNITE;
		i++;
	}
}

void	bistro_mult_one_in(t_bistro *a, long nb, t_bistro *result)
{
	int			i;
	long		tmp;
	long		ret;
	long		ret_add;
	t_bistro	tmp_nb;

	i = 0;
	ret = 0;
	ret_add = 0;
	ft_bzero(&tmp_nb, sizeof(tmp_nb));
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
	int				div;
	int				digit;

	id_nb = pow / BISTRO_NB_DIGIT;
	div = power(base, pow % BISTRO_NB_DIGIT);
	digit = (nb->number[id_nb] / div) % base;
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

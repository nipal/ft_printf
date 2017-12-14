#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BISTRO_LEN 20
#define BISTRO_UNITE 1000000

typedef struct	s_bistro
{
	int		sign;
	long	number[BISTRO_LEN];		// la data du nombre
	int		block_mult;				// le nombre de block qu'on multiplie // moins sur
	int		block_max;				// le nombre de block utiliser
}				t_bistro;

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

void	bistro_mult_one(t_bistro *a, long nb, t_bistro *result)
{
	int			i;
	long		tmp;
	long		ret;
	long		ret_add;
	t_bistro	tmp_nb;

	i = 0;
	ret = 0;
	ret_add = 0;
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
		bistro_mult_one(a, b->number[i], &tmp);
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
		bistro_mult_one(res, nb, res);
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
	int	i;

	i = BISTRO_LEN - 1;
	printf("%s", str);
	while (i >= 0)
	{
		printf("%06ld", nb->number[i]);
		i--;
	}
	printf("\n");
}



void	test_bitro_print()
{
	t_bistro	a;

	bzero(&a, sizeof(a));
	a.number[0] = 42;
	a.number[1] = 1945;
	a.number[2] = 990099;
	a.number[3] = 3;
	bistro_print(&a);
}

void	test_bistro_all()
{
	t_bistro	a, b, c, d, e, f, g, h, j, k1, k2, k3;
	int			i;

	bzero(&a, sizeof(a));
	bzero(&b, sizeof(b));
	bzero(&c, sizeof(c));
	bzero(&d, sizeof(d));
	bzero(&e, sizeof(e));
	bzero(&f, sizeof(f));
	bzero(&g, sizeof(f));
	bzero(&h, sizeof(f));
	bzero(&j, sizeof(f));
	bzero(&k1, sizeof(f));
	bzero(&k2, sizeof(f));
	bzero(&k3, sizeof(f));
	i = 0;
	a.number[0] = 18;
	b.number[0] = 9;
	while (i < BISTRO_LEN - 2)
	{
		if (i < 4)
		{
			a.number[i + 1] = a.number[i] * 10 + a.number[0];
			b.number[i + 1] = b.number[i] * 10 + b.number[0];
		}
		else
		{
			a.number[i + 1] = a.number[i];
			b.number[i + 1] = b.number[i];
		}
		i++;
	}
	i = 0;
	d.number[0] = 1;
	e.number[0] = 2;
	g.number[0] = 3;
	h.number[0] = 4;
	j.number[0] = 5;
	k1.number[0] = 5;
	k2.number[0] = 5;
	while (i < (BISTRO_LEN / 2) - 1)
	{
		if (i < 5)
		{
			d.number[i + 1] = d.number[i] * 10 + d.number[0];
			e.number[i + 1] = e.number[i] * 10 + e.number[0];
			g.number[i + 1] = g.number[i] * 10 + g.number[0];
			h.number[i + 1] = h.number[i] * 10 + h.number[0];
			j.number[i + 1] = j.number[i] * 10 + j.number[0];
		}
		else
		{
			d.number[i + 1] = d.number[i];
			e.number[i + 1] = e.number[i];
			g.number[i + 1] = g.number[i];
			h.number[i + 1] = h.number[i];
			j.number[i + 1] = j.number[i];
		}
		i++;
	}
	bistro_print_str(&g, "\n\ng: 33.. * 3		");
	bistro_print_str(&h, "h: 44.. * 100		");
	bistro_print_str(&j, "j: 55.. * 100		");
	bistro_print_str(&k1, "k2:			");
	bistro_print_str(&k2, "k1:			");


	bistro_add_in(&a, &b, &c);
	bistro_mult_in(&d, &e, &f);
	bistro_mult_one(&g, 3, &g);
	bistro_mult_one(&h, 100, &h);
	bistro_mult_one(&j, 23455, &j);
	bistro_mult_in(&k1, &k2, &k3);

	bistro_print_str(&a, "\n\na:			");
	bistro_print_str(&b, "a:			");
	bistro_print_str(&c, "a + b:			");

	bistro_print_str(&d, "\nd:			");
	bistro_print_str(&e, "e:			");
	bistro_print_str(&f, "d * e:			");

	bistro_print_str(&g, "\ng: 33.. * 3		");
	bistro_print_str(&h, "h: 44.. * 100		");
	bistro_print_str(&j, "j: 55.. * 12455		");

	bistro_print_str(&k1, "\nk1:			");
	bistro_print_str(&k2, "k2:			");
	bistro_print_str(&k3, "k1 * k2:		");



}

void	debug_mult_one()
{
	int	i;
	t_bistro	a, b, c, d;

	bzero(&a, sizeof(t_bistro));
	bzero(&b, sizeof(t_bistro));
	bzero(&c, sizeof(t_bistro));
	bzero(&d, sizeof(t_bistro));
	i = 0;
	a.number[0] = 1;
	b.number[0] = 2;
	while (i < BISTRO_LEN - 2)
	{
		a.number[i + 1] = a.number[i];
		if (i < 5)
		{
			b.number[i + 1] = b.number[i] * 10 + b.number[0];
		}
		else
		{
			b.number[i + 1] = b.number[i];
		}
		i++;
	}

	bistro_mult_one(&b, 532654, &c);
	bistro_mult_one(&a, 532654, &d);

	bistro_print_str(&a, "a				");
	bistro_print_str(&b, "b				");
	bistro_print_str(&d, "\n\na * 532654			");
	bistro_print_str(&c, "b * 532654			");
}



void	test_bistromatique()
{
//	test print
//	test_bitro_print();
	test_bistro_all();
//	debug_mult_one();
//	test add
//	test mult one
//	test mult

//	test power		+ make power
//	test coma_print	+ make coma_print
}

int		main()
{
	test_bistromatique();
	return (0);
}

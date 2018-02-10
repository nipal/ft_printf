/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at_stack2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 07:53:51 by fjanoty           #+#    #+#             */
/*   Updated: 2018/02/09 09:14:38 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//	on veux push un argument et ensuite retrouver des baille

void	wait_key()
{
	char	c;

	printf("		====== PRES ANY KEY ======\n");
	read(1, &c, 1);
}

void	test_stack(unsigned long c1, unsigned long c2, unsigned long c3, unsigned long c4, void *father,
					unsigned long *cc1, unsigned long *cc2, unsigned long *cc3, unsigned long *cc4)
{
//	long	t0, t1, t2, t3, t4, t5, t6, t7;
	long	beg;
	long	beg_func;
	long	beg_var;
	long	delta;
	double	fact;
	double	fact_inv;
	int		i;
	unsigned	char	*stack;
	unsigned	long	tmp;

//	*cc1 = 0;
//	*cc2 = 0;
//	*cc3 = 0;
//	*cc4 = 0;
	tmp = *cc1;
	*cc1 = *cc2;
	*cc2 = *cc3;
	*cc3 = *cc4;
	*cc4 = tmp;
	stack = (unsigned char*)&beg;
	beg_func = (long)(&test_stack);
	beg_var = (long)(&beg);
	delta = beg_var - beg_func;
	fact = (double)beg_var / beg_func;
	fact_inv = (double)beg_func / beg_var;
	printf("beg_func:%ld	beg_var:%ld		-> delta:%20ld	fact:%f	fact_inv:%f\n", beg_func, beg_var, delta, fact, fact_inv);
	printf("beg_func:%lx	beg_var:%lx		-> delta:%20lx	fact:%f	fact_inv:%f\n", beg_func, beg_var, delta, fact, fact_inv);
//	exit(0);
//	wait_key();
	i = 0;
	while (i < 1500)
	{
		tmp = *((unsigned long*)(stack + i));
		if (tmp == c1 || tmp == c2 || tmp == c3 || tmp == c4)
			printf("[%d]:%lu\n", i, tmp);
		i++;
	}
}

int	main()
{
	unsigned long	c1 = 424242424242;
	unsigned long	c2 = 13377331;
	unsigned long	c3 = 11111111111;
	unsigned long	c4 = 101010101010101010;
	char			buff[512];
	int				i;

	i = 0;
	while (i < 512)
	{
		buff[i] = 0;
		i++;
	}
	test_stack(c1, c2, c3, c4, &main, &c1, &c2, &c3, &c4);

	return (0);
}


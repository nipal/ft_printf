/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_truc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 21:01:36 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/10 04:00:22 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

void	truc()
{
	unsigned	char		c;
	unsigned	short		s;
	unsigned	int			i;
	unsigned	long		l;
	unsigned	long	int	li;
	unsigned	long	int	ref;
	
	printf("%zu\n", sizeof(unsigned	char));
	printf("%zu\n", sizeof(unsigned	short));
	printf("%zu\n", sizeof(unsigned	int));
	printf("%zu\n", sizeof(unsigned	long));
	printf("%zu\n", sizeof(unsigned	long	int	));
	printf("%zu\n", sizeof(unsigned	long	int));
	// on load tout en long
	// si besoin on recaste magic en double


}

unsigned char	ud1(long val)
{
	return ((unsigned char)val);
}

unsigned short		ud2(long val)
{
	return ((unsigned short)val);
}

unsigned int		ud4(long val)
{
	return ((unsigned int)val);
}

unsigned int		ud8(long val)
{
	return ((unsigned long)val);
}

unsigned char	d1(long val)
{
	return ((unsigned char)val);
}

unsigned short		d2(long val)
{
	return ((unsigned short)val);
}

unsigned int		d4(long val)
{
	return ((unsigned int)val);
}

unsigned int		d8(long val)
{
	return ((unsigned long)val);
}



void	test_cast_transpose()
{
	long	val = -1231232131323 + 30;
	int		vi1, vi2, vi3;
	short	vs1, vs2, vs3;
	char	vc1, vc2, vc3;

	vi1 = ud4(val);
	vi2 = val & 0xFFFFFFFF;

	vs1 = ud2(val);
	vs2 = val & 0xFFFF;

	vc1 = ud1(val);
	vc2 = val & 0xFF;
	printf("%d:%d	%d:%d	%d:%d\n", vi1, vi2, vs1, vs2, vc1, vc2);
	printf("%d	%hd	%hhd\n", vi1, vs1, vc1);

	printf("A->>%1$d, %d, %d. %d\n", 4, 3, 2, 1); // on change juste celui qu'il prend
	printf("B->>%2$d, %d, %d. %d\n", 4, 3, 2, 1);
	printf("C->>%3$d, %d, %d. %d\n", 4, 3, 2, 1);
	printf("D->>%4$d, %d, %d. %d\n", 4, 3, 2, 1);

	printf("----------------\n");

	printf("A->>%d, %1$d, %d. %d\n", 4, 3, 2, 1); // on change juste celui qu'il prend
	printf("B->>%d, %2$d, %d. %d\n", 4, 3, 2, 1);
	printf("C->>%d, %3$d, %d. %d\n", 4, 3, 2, 1);
	printf("D->>%d, %4$d, %d. %d\n", 4, 3, 2, 1);

	printf("----------------\n");

	printf("A->>%d, %d, %1$d. %d\n", 4, 3, 2, 1); // on change juste celui qu'il prend
	printf("B->>%d, %d, %2$d. %d\n", 4, 3, 2, 1);
	printf("C->>%d, %d, %3$d. %d\n", 4, 3, 2, 1);
	printf("D->>%d, %d, %4$d. %d\n", 4, 3, 2, 1);

	printf("----------------\n");

	printf("A->>%d, %d, %d. %1$d\n", 4, 3, 2, 1); // on change juste celui qu'il prend
	printf("B->>%d, %d, %d. %2$d\n", 4, 3, 2, 1);
	printf("C->>%d, %d, %d. %3$d\n", 4, 3, 2, 1);
	printf("D->>%d, %d, %d. %4$d\n", 4, 3, 2, 1);

	printf("----------------\n");

	printf("A->>%1$d, %1$d, %1$d. %1$d\n", 4, 3, 2, 1); // on change juste celui qu'il prend
	printf("B->>%2$d, %2$d, %2$d. %2$d\n", 4, 3, 2, 1);
	printf("C->>%3$d, %3$d, %1$d. %3$d\n", 4, 3, 2, 1);
	printf("D->>%4$d, %1$d, %d. %d\n", 4, 3, 2, 1);

	printf("----------------\n");

	printf("A->>%1$d, %*1$d, %*1$d. %*1$d\n", 4, 3, 2, 1); // on change juste celui qu'il prend
	printf("B->>%2$d, %*1$d, %*2$d. %*3$d\n", 4, 3, 2, 1);
	printf("C->>%3$d, %*1$d, %d. %d\n", 4, 3, 2, 1);
	printf("D->>%4$d, %*1$d, %d. %d\n", 4, 3, 2, 1);

}

void	ptr_test()
{
	void	*pt;
	int	a, c, d, e, f, b;
	ptrdiff_t	pdiff;

	pdiff = &b - &a;

	pt = &a - &b;

	printf("%p	%tp\n", pt, pt);
	printf("%p	%tp\n", pdiff, pdiff);
}

void	perturb()
{
	int	val, v2, v3, v4, v5;

	val = 0;
	printf("coucou les gens.\n%n", &val);
	printf("---=>%n%n%n 		%n 		 %n\n", &val, &v2, &v3, &v4, &v5);
}


// apply_size_modifier
// Le n$ : on prend la nieme variable

int	main()
{//	truc();
//	test_cast_transpose();
//	perturb();
//	ptr_test();

	return (0);
}

/*
- indicateur convertion 	:: type
- modificateur de longeur	:: caste

*/

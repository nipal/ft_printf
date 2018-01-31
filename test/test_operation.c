/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 22:17:11 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/28 01:31:51 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define BUFF_SMALL 32
#define BUFF_LARGE 32

void	max_long_test();



long	val_add(long src, long val)
{
	return (src + val);
}

long	val_sub(long src, long val)
{
	return (src - val);
}

long	val_mult(long src, long val)
{
	return (src * val);
}

long	val_div(long src, long val)
{
	return (src / val);
}

long	val_mod(long src, long val)
{
	return (src % val);
}

long	val_void(long src, long val)
{
	(void)val;

	return (src);
}


//enum	e_test_type
//{
//	e_func_name;
//	e_func_ptr;
//};
//
//typedef	struct	s_test_operator
//{
//	char	name[BUFF_SMALL];
//	long	(*f)(long src, long val);
//}				t_test_operator;				
//
//void	*
//


/*
 	Le LONG_MIN s'utlise comme un nombre normale
 */


char	*func_name(int id_func)
{
	static	char	name_func[][BUFF_SMALL] = {"val_add", "val_sub", "val_mult", "val_div", "val_mod", "val_void"};
	size_t				nb_func;

	nb_func = sizeof(name_func) / sizeof(sizeof(char) * BUFF_SMALL);
	if (id_func >= 0 && id_func < nb_func)
		return ((char*)(&(name_func[id_func][0])));
	dprintf(2, "id_func error:	out of range\n");
	return (NULL);
}

//	L'idee c'est:
//		/*v1*/ /*operateur*/ /*v2*/
//

void	func_unite(long *dest, int operator, long val)
{
	static	long	(*f[])(long src, long val) = {val_add, val_sub, val_mult, val_div, val_mod, val_void};
	size_t				nb_func;
	long				tmp;


	nb_func = sizeof(f) / sizeof(long (*)(long, long));
	if (operator >= 0 && operator < nb_func)
	{
		printf("vvvvvvvvvvvvvvvvv 	%s:(%ld)\n", func_name(operator) + 4, val);
		printf("(0)A:% -21ld   [op:% d|%5s]  B:% -15ld	=>	%+-ld\n", *dest, operator, func_name(operator) + 4, val, *dest);
		tmp = f[operator](*dest, val);
//		printf("(1)A:% -21ld   [op:% d|%5s]  B:% -15ld	=>	%+-ld\n", *dest, operator, func_name(operator) + 4, val, *dest);
		*dest = tmp;
		printf("(~)A:% -21ld   [op:% d|%5s]  B:% -15ld	=>	%+-ld\n", *dest, operator, func_name(operator) + 4, val, *dest);
		printf("^^^^^^^^^^^^^^^^^\n");
	}
	else
		dprintf(2, "id_func error:	out of range\n");
}

typedef	enum	e_func
{
	e_func_add = 0,
	e_func_sub,
	e_func_mult,
	e_func_div,
	e_func_mod,
	e_func_void,
	e_func_end
}				t_efunc;

//	Dans notre cas la fonction (id % 2 == 0) ET (id % 2 ==1) sont les inverse a part pour modulo
typedef	struct	s_mlt
{
	t_efunc	id_func;
	long	arg;
}				t_mlt;

//	on a pas vraiment besoin de tester modulo pck il se coporte bcp comme ls division
//	
//	la batterie de test va avec le pointeur de focntion qui trqwite les truc
void	max_long_test_value(long val)
{
	size_t	i;
	size_t	nb_test;
	//	meintenant il faudraut faire des struc qui generer des entrer, ou qu'il execute la sectence d'action
	t_mlt	val_test[] = {
							{ e_func_add,  0 }		// do nothing
							,{e_func_sub,  0 }		// do nothing
							,{e_func_add,  1 }		// incr +
							,{e_func_sub,  1 }		// incr -
							,{e_func_add,  42}		// add
							,{e_func_sub,  42}		// sub

							,{e_func_mult, 1 }		// do nothing	
							,{e_func_div,  1 }		// do nothing
							,{e_func_mult, 42}		// mult
							,{e_func_div,  42}		// div
							};
	int		nb_mlt;
	int		id;
	long	result, arg2;

	nb_test = sizeof(val_test) / sizeof(t_mlt);
	i = 0;	
	while (i < nb_test)
	{
		id = val_test[i].id_func;
		arg2 = val_test[i].arg;
		result = val;
		func_unite(&result, id,	arg2);	// normale sensuu		func_unite(&result, id_inv,	val);	// revers  sens		les fonciton sont ranger pour que l'inverse soi bien placer, du coup c'est plus vraiment modulaire. mais caserra trop long a implementer
//		printf("% -5s: {%- 5ld , %2ld} => % ld\n", func_name(id) + 4, val, arg2, result);
		i++;
	}

}

void	max_long_test_v2()
{
	long	a, b;
	(void)a;(void)b;

	a = (long)(((unsigned long)-1) / 2);
	b = (long)(((unsigned long)-1) / 2) + 1l;
	b = (long)(((unsigned long)-1) / 2);
	max_long_test_value(a);
	printf("===\n===\n");
	max_long_test_value(b);
}


int	main()
{
	max_long_test_v2();
	return (0);
}



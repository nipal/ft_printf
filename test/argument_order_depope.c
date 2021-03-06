/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_order_depope.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Create--> 2018/01/12 05:08:20 by fjanoty           #+#    #+#             */
/*   Update--> 2018/01/12 05:45:12 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 256
#define MAX 10



void	print_bit_str(unsigned char *data, int size, char *s)
{
	int	i;
	int	j;
	int	nb_char;
	int	id;
	char	*str;

	nb_char = (size * 8);
	if (!(str = malloc(((nb_char) + 1) * sizeof(char))))
		return ;
	str[(size * 8)] = '\0';
	j = size - 1;
	while (j >= 0)
	{
		i = 7;
		while (i >= 0)
		{
			id = (7 - i) + ((size - 1 - j) * 8);
			str[id] = (data[j] & (1 << i)) ? '1' : '0';
			i--;
		}
		j--;
	}
	printf("%s%s\n", s, str);
	free(str);
}

void	print_bit_buffer(unsigned char *data, int size, char *buff)
{
	int	i;
	int	j;
	int	nb_char;
	int	id;

	nb_char = (size * 8);
	buff[(size * 8)] = '\0';
	j = size - 1;
	while (j >= 0)
	{
		i = 7;
		while (i >= 0)
		{
			id = (7 - i) + ((size - 1 - j) * 8);
			buff[id] = (data[j] & (1 << i)) ? '1' : '0';
//			printf("--i-->%d[%c]--	", id, buff[id]);
			i--;
		}
		j--;
	}
	buff[(size * 8)] = '\0';
//	printf("\n");
//	printf("%s%s\n", s, buff);
//	free(buff);
}



/*
 *	Le but sera de montrer qu'on a pas besoin  de connaitre les type a l'avence.
 *	Comme ca on fait tout au fure et a mesure, et puis o evite encore l'appele d'une fonction etc.
 *
 *	on fait un truc avec printf
 *	eventuelement on ele reproduit
*/

//	on peut aussi faire des tableau qui on leur taille dans la premiere case
void	func_print(int *id_int, int size_int, int *id_float, int size_float, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, size_float);
}

void	test_1_copy_val()
{
	
}

void	test_1()
{
	int		id_int[] 	= {4}; // 
	int		id_float[]	= {5};

	printf("dec(4):[%4$d]	float(1):%1$f,	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(4):[%4$d]	float(1):%1$f,	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("dec(4):[%4$d]	float(2):%2$f,	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(4):[%4$d]	float(2):%2$f,	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("dec(4):[%4$d]	float(3):%3$f,	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(4):[%4$d]	float(3):%3$f,	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("dec(4):[%4$d]	float(4):%4$f,	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(4):[%4$d]	float(3):%3$f,	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
printf("	-------------------																																\n");
	printf("dec(1):[%1$d]	float(1):%1$f,	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(1):[%1$d]	float(1):%1$f,	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("dec(2):[%2$d]	float(2):%2$f,	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(2):[%2$d]	float(2):%2$f,	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("dec(3):[%3$d]	float(3):%3$f,	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(3):[%3$d]	float(3):%3$f,	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("dec(4):[%4$d]	float(4):%4$f,	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(4):[%4$d]	float(4):%4$f,	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("dec(5):[%5$d]	float(4):%4$f,	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(5):[%5$d]	float(4):%4$f,	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
printf("	-------------------																																\n");
	printf("dec(1):[%1$d]	float(4):%4$f,	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(1):[%1$d]	float(4):%4$f,	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("dec(2):[%2$d]	float(4):%4$f,	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(2):[%2$d]	float(4):%4$f,	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("dec(3):[%3$d]	float(4):%4$f,	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(3):[%3$d]	float(4):%4$f,	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("dec(4):[%4$d]	float(4):%4$f,	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(4):[%4$d]	float(4):%4$f,	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
printf("	-------------------																																\n");

	printf("float(1):%1$f	dec(4):[%4$d]		1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("float(1):%1$f	dec(4):[%4$d]		1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("float(2):%2$f	dec(4):[%4$d]		1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("float(2):%2$f	dec(4):[%4$d]		1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("float(3):%3$f	dec(4):[%4$d]		1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("float(3):%3$f	dec(4):[%4$d]		1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("float(4):%4$f	dec(4):[%4$d]		1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("float(3):%3$f	dec(4):[%4$d]		1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
printf("	---			 	----------------  																												\n");
	printf("float(1):%1$f	dec(1):[%1$d]		1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("float(1):%1$f	dec(1):[%1$d]		1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("float(2):%2$f	dec(2):[%2$d]		1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("float(2):%2$f	dec(2):[%2$d]		1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("float(3):%3$f	dec(3):[%3$d]		1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("float(3):%3$f	dec(3):[%3$d]		1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("float(4):%4$f	dec(4):[%4$d]		1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("float(4):%4$f	dec(4):[%4$d]		1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("float(4):%4$f	dec(5):[%5$d]		1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("float(4):%4$f	dec(5):[%5$d]		1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
printf("	---			 	----------------  																												\n");
	printf("float(4):%4$f	dec(1):[%1$d]		1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("float(4):%4$f	dec(1):[%1$d]		1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("float(4):%4$f	dec(2):[%2$d]		1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("float(4):%4$f	dec(2):[%2$d]		1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("float(4):%4$f	dec(3):[%3$d]		1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("float(4):%4$f	dec(3):[%3$d]		1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("float(4):%4$f	dec(4):[%4$d]		1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("float(4):%4$f	dec(4):[%4$d]		1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
printf("	---				----------------																												\n");



}


void	test_2()
{
	int		id_int[] 	= {4}; // 
	int		id_float[]	= {5};

	printf("dec(4):[%4$d]	dec(3):[%3$d]	dec(2):[%2$d]	dec(1):[%1$d]	float(1):%2$f	float(3):%1$f	float(4):%3$f	float(3):%4$f	float(3):%3$f\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(4):[%4$d]	dec(3):[%3$d]	dec(2):[%2$d]	dec(1):[%1$d]	float(1):%2$f	float(1):%1$f	float(3):%3$f	float(4):%4$f	float(3):%3$f\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("dec(4):[%4$d]	dec(3):[%3$d]	dec(2):[%2$d]	dec(1):[%1$d]	float(2):%2$f	float(1):%1$f	float(1):%3$f	float(3):%4$f	float(4):%3$f\n",	1,		1.		2,		2.		2,		3.		4,		4.);
	printf("dec(4):[%4$d]	dec(3):[%3$d]	dec(2):[%2$d]	dec(1):[%1$d]	float(2):%2$f	float(2):%1$f	float(1):%3$f	float(1):%4$f	float(3):%3$f\n",		1.		1,		2.		2,		3.		3,		4.,	1);
	printf("dec(4):[%4$d]	dec(3):[%3$d]	dec(2):[%2$d]	dec(1):[%1$d]	float(3):%2$f	float(2):%1$f	float(2):%3$f	float(1):%4$f	float(1):%3$f\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(4):[%4$d]	dec(3):[%3$d]	dec(2):[%2$d]	dec(1):[%1$d]	float(3):%2$f	float(3):%1$f	float(2):%3$f	float(2):%4$f	float(1):%3$f\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);
	printf("dec(4):[%4$d]	dec(3):[%3$d]	dec(2):[%2$d]	dec(1):[%1$d]	float(4):%2$f	float(3):%1$f	float(3):%3$f	float(2):%4$f	float(2):%3$f\n",	1,		2,		3,		4,		1.0,	2.0,	3.0,	4.0);
	printf("dec(4):[%4$d]	dec(3):[%3$d]	dec(2):[%2$d]	dec(1):[%1$d]	float(3):%2$f	float(4):%1$f	float(3):%3$f	float(3):%4$f	float(2):%3$f\n",	1.0,	2.0,	3.0,	4.0,	1,		2,		3,		4);


}

int	main()
{
	test_2();
		return (0);
}


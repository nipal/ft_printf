/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_revers_ingenering.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:44:43 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/17 09:04:53 by fjanoty          ###   ########.fr       */
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
/**/}

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
//			printf("--id:%d[%c]--	", id, buff[id]);
			i--;
		}
		j--;
	}
	buff[(size * 8)] = '\0';
//	printf("\n");
//	printf("%s%s\n", s, buff);
//	free(buff);
/**/}




int	va_arg_id_card(int test, char *str, int fmt, ...)
{
	va_list	ap;					//	l10
	size_t	size;				//	l9
	char	buff[BUFF_SIZE];	//	l8
	size_t	i;					//	l7
	void	*p_func;			//	l6
	void	*p_var_func1;		//	l5
	void	*p_var_func2;		//	l4
	void	*p_var_arg;			//	l3

	size_t	size2;				//	l2

	long	tmp;				//	l1

	va_start(ap, str);
	size = sizeof(va_list);
	printf("size:%zu\n", size);
	
	//addr_func
	//addr_last_var
	

	printf("\n\n	==adresse argument==\n");
	print_bit_buffer(&test, sizeof(void*), buff);
	size2 = sizeof(test);
	printf("arg1[%zu]:	%s\n", size2, buff);
	print_bit_buffer(&str, sizeof(void*), buff);
	size2 = sizeof(str);
	printf("arg2[%zu]:	%s\n", size2, buff);
	print_bit_buffer(&fmt, sizeof(void*), buff);
	size2 = sizeof(fmt);
	printf("arg3[%zu]:	%s\n", size2, buff);

	printf("\n\n	==adresse variable==\n");
	print_bit_buffer(&tmp, sizeof(void*), buff);
	size2 = sizeof(tmp);
	printf("l1[%zu]:	%s\n", size2, buff);

	print_bit_buffer(&size2, sizeof(void*), buff);
	size2 = sizeof(size2);
	printf("l2[%zu]:	%s\n", size2, buff);

	print_bit_buffer(&p_var_arg, sizeof(void*), buff);
	size2 = sizeof(p_var_arg);
	printf("l3[%zu]:	%s\n", size2, buff);

	print_bit_buffer(&p_var_func2, sizeof(void*), buff);
	size2 = sizeof(p_var_func2);
	printf("l3[%zu]:	%s\n", size2, buff);

	print_bit_buffer(&p_var_func1, sizeof(void*), buff);
	size2 = sizeof(p_var_func1);
	printf("l4[%zu]:	%s\n", size2, buff);

	print_bit_buffer(&p_func, sizeof(void*), buff);
	size2 = sizeof(p_func);
	printf("l5[%zu]:	%s\n", size2, buff);

	print_bit_buffer(&i, sizeof(void*), buff);
	size2 = sizeof(i);
	printf("l6[%zu]:	%s\n", size2, buff);

	print_bit_buffer(&buff, sizeof(void*), buff);
	size2 = sizeof(buff);
	printf("l7[%zu]:	%s\n", size2, buff);

	print_bit_buffer(&size, sizeof(void*), buff);
	size2 = sizeof(size);
	printf("l8[%zu]:	%s\n", size2, buff);

	print_bit_buffer(&ap, sizeof(void*), buff);
	size2 = sizeof(ap);
	printf("l9[%zu]:	%s\n", size2, buff);


	printf("\n\n	==adresse variable==\n");
	printf("\n");
	i = 0;
	while (i < 185)
	{
//		if (0 % 2)
			tmp = va_arg(ap, char);
//		else
//			tmp = va_arg(ap, long);
		print_bit_buffer((unsigned char *)&ap, size, buff);
	//	if (i == 129020 || !i)
			printf("%s[%20d]:	|%s|\n", str, i, buff);
		i++;
	}
	return (0);
}
//////////////////////////////////////

void	truc_adique(int v, ...)
{
	int		a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16;
	double	b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16;
	va_list	ap;

printf("a1:%-11d	a2:%-11d	a3:%-11d	a4:%-11d	a5:%-11d	a6:%-11d	a7:%-11d	a8:%-11d	a9:%-11d	a10:%-11d	a11:%-11d	a12:%-11d	a13:%-11d	a14:%-11d	a15:%-11d	a16\nb1:%-11d	b2:%-11d	b3:%-11d	b4:%-11d	b5:%-11d	b6:%-11d	b7:%-11d	b8:%-11d	b9:%-11d	b10:%-11d	b11:%-11d	b12:%-11d	b13:%-11d	b14:%-11d	b15:%-11d	b16:%-11d\n\n", a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16);


	printf("=================================\n");

	va_start(ap, v);
	a1 = va_arg(ap, long);
	a2 = va_arg(ap, long);
	a3 = va_arg(ap, long);
	a4 = va_arg(ap, long);
	a5 = va_arg(ap, long);
	a6 = va_arg(ap, long);
	a7 = va_arg(ap, long);
	a8 = va_arg(ap, long);
	a9 = va_arg(ap, long);
	a10 = va_arg(ap, long);
	a11 = va_arg(ap, long);
	a12 = va_arg(ap, long);
	a13 = va_arg(ap, long);
	a14 = va_arg(ap, long);
	a15 = va_arg(ap, long);
	a16 = va_arg(ap, long);
	b1 = va_arg(ap, float);
	b2 = va_arg(ap, float);
	b3 = va_arg(ap, float);
	b4 = va_arg(ap, float);
	b5 = va_arg(ap, float);
	b6 = va_arg(ap, float);
	b7 = va_arg(ap, float);
	b8 = va_arg(ap, float);
	b9 = va_arg(ap, float);
	b10 = va_arg(ap, float);
	b11 = va_arg(ap, float);
	b12 = va_arg(ap, float);
	b13 = va_arg(ap, float);
	b14 = va_arg(ap, float);
	b15 = va_arg(ap, float);
	b16 = va_arg(ap, float);
	va_end(ap);

printf("a1:%-11d	a2:%-11d	a3:%-11d	a4:%-11d	a5:%-11d	a6:%-11d	a7:%-11d	a8:%-11d	a9:%-11d	a10:%-11d	a11:%-11d	a12:%-11d	a13:%-11d	a14:%-11d	a15:%-11d	a16\nb1:%-11d	b2:%-11d	b3:%-11d	b4:%-11d	b5:%-11d	b6:%-11d	b7:%-11d	b8:%-11d	b9:%-11d	b10:%-11d	b11:%-11d	b12:%-11d	b13:%-11d	b14:%-11d	b15:%-11d	b16:%-11d\n\n", a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16);

	va_start(ap, v);
	b1 = va_arg(ap, float);
	b2 = va_arg(ap, float);
	b6 = va_arg(ap, float);
	b4 = va_arg(ap, float);
	b5 = va_arg(ap, float);
	b6 = va_arg(ap, float);
	b7 = va_arg(ap, float);
	b8 = va_arg(ap, float);
	b9 = va_arg(ap, float);
	b10 = va_arg(ap, float);
	b11 = va_arg(ap, float);
	b12 = va_arg(ap, float);
	b13 = va_arg(ap, float);
	b14 = va_arg(ap, float);
	b15 = va_arg(ap, float);
	b16 = va_arg(ap, float);
	a1 = va_arg(ap, long);
	a2 = va_arg(ap, long);
	a3 = va_arg(ap, long);
	a4 = va_arg(ap, long);
	a5 = va_arg(ap, long);
	a6 = va_arg(ap, long);
	a7 = va_arg(ap, long);
	a8 = va_arg(ap, long);
	a9 = va_arg(ap, long);
	a10 = va_arg(ap, long);
	a14 = va_arg(ap, long);
	a12 = va_arg(ap, long);
	a13 = va_arg(ap, long);
	a14 = va_arg(ap, long);
	a15 = va_arg(ap, long);
	a16 = va_arg(ap, long);
	va_end(ap);

printf("a1:%-11d	a2:%-11d	a3:%-11d	a4:%-11d	a5:%-11d	a6:%-11d	a7:%-11d	a8:%-11d	a9:%-11d	a10:%-11d	a11:%-11d	a12:%-11d	a13:%-11d	a14:%-11d	a15:%-11d	a16\nb1:%-11d	b2:%-11d	b3:%-11d	b4:%-11d	b5:%-11d	b6:%-11d	b7:%-11d	b8:%-11d	b9:%-11d	b10:%-11d	b11:%-11d	b12:%-11d	b13:%-11d	b14:%-11d	b15:%-11d	b16:%-11d\n\n", a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16);

	va_start(ap, v);
	b1 = va_arg(ap, float);
	a1 = va_arg(ap, long);
	b2 = va_arg(ap, float);
	a2 = va_arg(ap, long);
	b3 = va_arg(ap, float);
	a3 = va_arg(ap, long);
	b4 = va_arg(ap, float);
	a4 = va_arg(ap, long);
	b5 = va_arg(ap, float);
	a5 = va_arg(ap, long);
	b6 = va_arg(ap, float);
	a6 = va_arg(ap, long);
	b7 = va_arg(ap, float);
	a7 = va_arg(ap, long);
	b8 = va_arg(ap, float);
	a8 = va_arg(ap, long);
	b9 = va_arg(ap, float);
	a9 = va_arg(ap, long);
	b10 = va_arg(ap, float);
	a10 = va_arg(ap, long);
	b11 = va_arg(ap, float);
	a11 = va_arg(ap, long);
	b12 = va_arg(ap, float);
	a12 = va_arg(ap, long);
	b13 = va_arg(ap, float);
	a13 = va_arg(ap, long);
	b14 = va_arg(ap, float);
	a14 = va_arg(ap, long);
	b15 = va_arg(ap, float);
	a15 = va_arg(ap, long);
	b16 = va_arg(ap, float);
	a16 = va_arg(ap, long);
	va_end(ap);


printf("a1:%-11d	a2:%-11d	a3:%-11d	a4:%-11d	a5:%-11d	a6:%-11d	a7:%-11d	a8:%-11d	a9:%-11d	a10:%-11d	a11:%-11d	a12:%-11d	a13:%-11d	a14:%-11d	a15:%-11d	a16\nb1:%-11d	b2:%-11d	b3:%-11d	b4:%-11d	b5:%-11d	b6:%-11d	b7:%-11d	b8:%-11d	b9:%-11d	b10:%-11d	b11:%-11d	b12:%-11d	b13:%-11d	b14:%-11d	b15:%-11d	b16:%-11d\n\n", a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16);

	va_start(ap, v);
	a1 = va_arg(ap, long);
	a2 = va_arg(ap, long);
	a3 = va_arg(ap, long);
	a4 = va_arg(ap, long);
	a5 = va_arg(ap, long);
	a6 = va_arg(ap, long);
	a7 = va_arg(ap, long);
	a8 = va_arg(ap, long);
	b1 = va_arg(ap, float);
	b2 = va_arg(ap, float);
	b3 = va_arg(ap, float);
	b4 = va_arg(ap, float);
	b5 = va_arg(ap, float);
	b6 = va_arg(ap, float);
	b7 = va_arg(ap, float);
	b8 = va_arg(ap, float);
	b9 = va_arg(ap, float);
	a9 = va_arg(ap, long);
	b10 = va_arg(ap, float);
	a10 = va_arg(ap, long);
	b11 = va_arg(ap, float);
	a11 = va_arg(ap, long);
	b12 = va_arg(ap, float);
	a12 = va_arg(ap, long);
	b13 = va_arg(ap, float);
	a13 = va_arg(ap, long);
	b14 = va_arg(ap, float);
	a14 = va_arg(ap, long);
	b15 = va_arg(ap, float);
	a15 = va_arg(ap, long);
	b16 = va_arg(ap, float);
	a16 = va_arg(ap, long);
	va_end(ap);

printf("a1:%-11d	a2:%-11d	a3:%-11d	a4:%-11d	a5:%-11d	a6:%-11d	a7:%-11d	a8:%-11d	a9:%-11d	a10:%-11d	a11:%-11d	a12:%-11d	a13:%-11d	a14:%-11d	a15:%-11d	a16\nb1:%-11d	b2:%-11d	b3:%-11d	b4:%-11d	b5:%-11d	b6:%-11d	b7:%-11d	b8:%-11d	b9:%-11d	b10:%-11d	b11:%-11d	b12:%-11d	b13:%-11d	b14:%-11d	b15:%-11d	b16:%-11d\n\n", a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16);
}

//	Il y a donc bien des pille differente pour les int et les float
//
void	twist_arg_fail_test()
{
	long	a1 = 1;
	long	a2 = 2;
	long	a3 = 3;
	long	a4 = 4;
	long	a5 = 5;
	long	a6 = 6;
	long	a7 = 7;
	long	a8 = 8;
	long	a9 = 9;
	long	a10 = 10;
	long	a11 = 11;
	long	a12 = 12;
	long	a13 = 13;
	long	a14 = 14;
	long	a15 = 15;
	long	a16 = 16;

	double	b1 =  .00001;
	double	b2 =  .00002;
	double	b3 =  .00003;
	double	b4 =  .00004;
	double	b5 =  .00005;
	double	b6 =  .00006;
	double	b7 =  .00007;
	double	b8 =  .00008;
	double	b9 =  .00009;
	double	b10 = .00010;
	double	b11 = .00011;
	double	b12 = .00012;
	double	b13 = .00013;
	double	b14 = .00014;
	double	b15 = .00015;
	double	b16 = .00016;

	truc_adique(16, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16);
   	truc_adique(16, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b1, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
  	truc_adique(16, a1, b1, a2, b2, a3, b3, a4, b4, a5, b5, a6, b6, a7, b7, a8, b8, a9, b9, a10, b10, a11, b11, a12, b12, a13, b13, a14, b14, a15, b15, a15, b16);
}

void	truc_adique_just(int v, ...)
{
	int		a1, a2, a3, a4;
	double	b1, b2, b3, b4, b5, b6, b7, b8;
	va_list	ap;

	//	in order
	va_start(ap, v);
	a1 = va_arg(ap, long);
	a2 = va_arg(ap, long);
	a3 = va_arg(ap, long);
	a4 = va_arg(ap, long);
	b1 = va_arg(ap, double);
	b2 = va_arg(ap, double);
	b3 = va_arg(ap, double);
	b4 = va_arg(ap, double);
	b5 = va_arg(ap, double);
	b6 = va_arg(ap, double);
	b7 = va_arg(ap, double);
	b8 = va_arg(ap, double);
	va_end(ap);
	printf("a1:%d	a2:%d	a3:%d	a4:%d	||	b1:%f	b2:%f	b3:%f	b4:%f	b5:%f	b6:%f	b7:%f	b8:%f\n", a1, a2, a3, a4, b1, b2, b3, b4, b5, b6, b6, b8);


	//	invert
	va_start(ap, v);
	b1 = va_arg(ap, double);
	b2 = va_arg(ap, double);
	b3 = va_arg(ap, double);
	b4 = va_arg(ap, double);
	b5 = va_arg(ap, double);
	b6 = va_arg(ap, double);
	b7 = va_arg(ap, double);
	b8 = va_arg(ap, double);
	a1 = va_arg(ap, long);
	a2 = va_arg(ap, long);
	a3 = va_arg(ap, long);
	a4 = va_arg(ap, long);
	va_end(ap);
	printf("a1:%d	a2:%d	a3:%d	a4:%d	||	b1:%f	b2:%f	b3:%f	b4:%f	b5:%f	b6:%f	b7:%f	b8:%f\n", a1, a2, a3, a4, b1, b2, b3, b4, b5, b6, b6, b8);

	//	shufful 1
	va_start(ap, v);
	b1 = va_arg(ap, double);
	b2 = va_arg(ap, double);
	a1 = va_arg(ap, long);
	b3 = va_arg(ap, double);
	b4 = va_arg(ap, double);
	a2 = va_arg(ap, long);
	b5 = va_arg(ap, double);
	b6 = va_arg(ap, double);
	a3 = va_arg(ap, long);
	b7 = va_arg(ap, double);
	b8 = va_arg(ap, double);
	a4 = va_arg(ap, long);
	va_end(ap);
	printf("a1:%d	a2:%d	a3:%d	a4:%d	||	b1:%f	b2:%f	b3:%f	b4:%f	b5:%f	b6:%f	b7:%f	b8:%f\n", a1, a2, a3, a4, b1, b2, b3, b4, b5, b6, b6, b8);

	//	insertion 1
	va_start(ap, v);
	b1 = va_arg(ap, double);
	b2 = va_arg(ap, double);
	b3 = va_arg(ap, double);
	b4 = va_arg(ap, double);
	a1 = va_arg(ap, long);
	a2 = va_arg(ap, long);
	a3 = va_arg(ap, long);
	a4 = va_arg(ap, long);
	b5 = va_arg(ap, double);
	b6 = va_arg(ap, double);
	b7 = va_arg(ap, double);
	b8 = va_arg(ap, double);
	va_end(ap);
	printf("a1:%d	a2:%d	a3:%d	a4:%d	||	b1:%f	b2:%f	b3:%f	b4:%f	b5:%f	b6:%f	b7:%f	b8:%f\n", a1, a2, a3, a4, b1, b2, b3, b4, b5, b6, b6, b8);

	//	insertion 2
	va_start(ap, v);
	a1 = va_arg(ap, long);
	a2 = va_arg(ap, long);
	b1 = va_arg(ap, double);
	b2 = va_arg(ap, double);
	b3 = va_arg(ap, double);
	b4 = va_arg(ap, double);
	b5 = va_arg(ap, double);
	b6 = va_arg(ap, double);
	b7 = va_arg(ap, double);
	b8 = va_arg(ap, double);
	a3 = va_arg(ap, long);
	a4 = va_arg(ap, long);
	va_end(ap);
	printf("a1:%d	a2:%d	a3:%d	a4:%d	||	b1:%f	b2:%f	b3:%f	b4:%f	b5:%f	b6:%f	b7:%f	b8:%f\n", a1, a2, a3, a4, b1, b2, b3, b4, b5, b6, b6, b8);
	printf("============================================================================================================================================================================\n\n");
}



void	twist_arg_succes_test()
{
	long	a1	= 1;
	long	a2	= 2;
	long	a3	= 3;
	long	a4	= 4;
	double	b1	= 0.000001;
	double	b2	= 0.000002;
	double	b3	= 0.000003;
	double	b4	= 0.000004;
	double	b5	= 0.000004;
	double	b6	= 0.000005;
	double	b7	= 0.000006;
	double	b8	= 0.000007;
	
	truc_adique_just(0, a1, a2, a3, a4, b1, b2, b3, b4, b5, b6, b7, b8);
	truc_adique_just(0, b1, b2, b3, b4, b5, b6, b7, b8, a1, a2, a3, a4);
	truc_adique_just(0, a1, b1, a2, b2, a3, b3, a4, b4, b5, b6, b7, b8);
	truc_adique_just(0, b1, b2, b3, b4, a1, b5, a2, b6, a3, b7, a4, b8);
}

///////////////////////////////////////////
void	truc_adique_one2much(int v, ...)
{
	int		a1, a2, a3, a4, a5, a6;
	double	b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;
	va_list	ap;

	//	in order
	va_start(ap, v);
	a1 = va_arg(ap, long);
	a2 = va_arg(ap, long);
	a3 = va_arg(ap, long);
	a4 = va_arg(ap, long);
	a5 = va_arg(ap, long);
	a6 = va_arg(ap, long);
	b1 = va_arg(ap, double);
	b2 = va_arg(ap, double);
	b3 = va_arg(ap, double);
	b4 = va_arg(ap, double);
	b5 = va_arg(ap, double);
	b6 = va_arg(ap, double);
	b7 = va_arg(ap, double);
	b8 = va_arg(ap, double);
	b9 = va_arg(ap, double);
	b10 = va_arg(ap, double);
	va_end(ap);
	printf("a1:%-11d	a2:%-11d	a3:%-11d	a4:%-11d	a5:%-11d	a6:%-11d	||	b1:%-11f	b2:%-11f	b3:%-11f	b4:%-11f	b5:%-11f	b6:%-11f	b7:%-11f	b8:%-11f	b9:%-11.10f	b10:%-11.10f\n", a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10);


	//	invert
	va_start(ap, v);
	b1 = va_arg(ap, double);
	b2 = va_arg(ap, double);
	b3 = va_arg(ap, double);
	b4 = va_arg(ap, double);
	b5 = va_arg(ap, double);
	b6 = va_arg(ap, double);
	b7 = va_arg(ap, double);
	b8 = va_arg(ap, double);
	b9 = va_arg(ap, double);
	b10 = va_arg(ap, double);
	a1 = va_arg(ap, long);
	a2 = va_arg(ap, long);
	a3 = va_arg(ap, long);
	a4 = va_arg(ap, long);
	a5 = va_arg(ap, long);
	a6 = va_arg(ap, long);
	va_end(ap);
	printf("a1:%-11d	a2:%-11d	a3:%-11d	a4:%-11d	a5:%-11d	a6:%-11d	||	b1:%-11f	b2:%-11f	b3:%-11f	b4:%-11f	b5:%-11f	b6:%-11f	b7:%-11f	b8:%-11f	b9:%-11.10f	b10:%-11.10f\n", a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10);

	//	shufful 1
	va_start(ap, v);
	b1 = va_arg(ap, double);
	b2 = va_arg(ap, double);
	a1 = va_arg(ap, long);
	b3 = va_arg(ap, double);
	b4 = va_arg(ap, double);
	a2 = va_arg(ap, long);
	b5 = va_arg(ap, double);
	b6 = va_arg(ap, double);
	a3 = va_arg(ap, long);
	b7 = va_arg(ap, double);
	b8 = va_arg(ap, double);
	a4 = va_arg(ap, long);
	b9 = va_arg(ap, double);
	b10 = va_arg(ap, double);
	a5 = va_arg(ap, long);
	a6 = va_arg(ap, long);
	va_end(ap);
	printf("a1:%-11d	a2:%-11d	a3:%-11d	a4:%-11d	a5:%-11d	a6:%-11d	||	b1:%-11f	b2:%-11f	b3:%-11f	b4:%-11f	b5:%-11f	b6:%-11f	b7:%-11f	b8:%-11f	b9:%-11.10f	b10:%-11.10f\n", a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10);

	//	insertion 1
	va_start(ap, v);
	b1 = va_arg(ap, double);
	b2 = va_arg(ap, double);
	b3 = va_arg(ap, double);
	b4 = va_arg(ap, double);
	b5 = va_arg(ap, double);
	a1 = va_arg(ap, long);
	a2 = va_arg(ap, long);
	a3 = va_arg(ap, long);
	a4 = va_arg(ap, long);
	a5 = va_arg(ap, long);
	a6 = va_arg(ap, long);
	b6 = va_arg(ap, double);
	b7 = va_arg(ap, double);
	b8 = va_arg(ap, double);
	b9 = va_arg(ap, double);
	b10 = va_arg(ap, double);
	va_end(ap);
	printf("a1:%-11d	a2:%-11d	a3:%-11d	a4:%-11d	a5:%-11d	a6:%-11d	||	b1:%-11f	b2:%-11f	b3:%-11f	b4:%-11f	b5:%-11f	b6:%-11f	b7:%-11f	b8:%-11f	b9:%-11.10f	b10:%-11.10f\n", a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10);

	//	insertion 2
	va_start(ap, v);
	a1 = va_arg(ap, long);
	a2 = va_arg(ap, long);
	b1 = va_arg(ap, double);
	b2 = va_arg(ap, double);
	b3 = va_arg(ap, double);
	b4 = va_arg(ap, double);
	b5 = va_arg(ap, double);
	b6 = va_arg(ap, double);
	b7 = va_arg(ap, double);
	b8 = va_arg(ap, double);
	b9 = va_arg(ap, double);
	b10 = va_arg(ap, double);
	a3 = va_arg(ap, long);
	a4 = va_arg(ap, long);
	a5 = va_arg(ap, long);
	a6 = va_arg(ap, long);
	va_end(ap);
	printf("a1:%-11d	a2:%-11d	a3:%-11d	a4:%-11d	a5:%-11d	a6:%-11d	||	b1:%-11f	b2:%-11f	b3:%-11f	b4:%-11f	b5:%-11f	b6:%-11f	b7:%-11f	b8:%-11f	b9:%-11.10f	b10:%-11.10f\n", a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10);
	printf("==============================================================================================================================================================================================================================================================================\n\n");
}

//	pour mieux determiner la limite des zone de chacun
void	twist_arg_one2much__test()
{
	long	a1	= 1;
	long	a2	= 2;
	long	a3	= 3;
	long	a4	= 4;
	long	a5	= 5;
	long	a6	= 6;
	double	b1	= 0.000001;
	double	b2	= 0.000002;
	double	b3	= 0.000003;
	double	b4	= 0.000004;
	double	b5	= 0.000005;
	double	b6	= 0.000006;
	double	b7	= 0.000007;
	double	b8	= 0.000008;
	double	b9	= 0.000009;
	double	b10	= 0.000010;
	
	truc_adique_one2much(0, a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b10);
	truc_adique_one2much(0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b10, a1, a2, a3, a4, a5, a6);
	truc_adique_one2much(0, a1, b1, a2, b2, a3, b3, a4, b4, a5, b5, a6, b6, b7, b8, b9, b10, b10);
	truc_adique_one2much(0, b1, b2, b3, b4, a1, b5, a2, b6, a3, b7, a4, b8, b9, b10, a5, a6);

	truc_adique_one2much(0, a1, a2, a3, a4, a5, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b10, a6);
	truc_adique_one2much(0, a1, a2, a3, a4, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b10, a5, a6);
}


/*
	On va faire des testes sur les va_arg:	taille,	structure, evolution, binary_value etc
	---
	type:	intger, double, long double
		- SECFAULT: 3x one,  3x versus, tiro
		- melange parfait
		- melange limite

void	print_bit_buffer(unsigned char *data, int size, char *buff)
*/

void	va_list_value(int v, ...)
{
	int		i;
	va_list	ap;
	char	buff[BUFF_SIZE];

	long			a1;
	double			b1;
	long	double	c1;


	//	long BCL
	va_start(ap, v);
	i = 0;
	while (i < MAX)
	{
		a1 = va_arg(ap, long);
		print_bit_buffer(&ap, sizeof(va_list), buff);
		printf("{%d}	[%s]\n", i, buff);
		i++;
	}
	va_end(ap);

	printf("==============================================================================\n");

	//	double BCL
	va_start(ap, v);
	i = 0;
	while (i < MAX)
	{
		b1 = va_arg(ap, double);
		print_bit_buffer(&ap, sizeof(va_list), buff);
		printf("{%d}	[%s]\n", i, buff);
		i++;
	}
	va_end(ap);
	printf("==============================================================================\n");

	//	long double BCL
	va_start(ap, v);
	i = 0;
	while (i < MAX)
	{
		c1 = va_arg(ap, long double);
		print_bit_buffer(&ap, sizeof(va_list), buff);
		printf("{%d}	[%s]\n", i, buff);
		i++;
	}
	va_end(ap);
}



int	main()
{
//	twist_arg_fail_test();// more than integer buffer AND flotaing buffer
//	twist_arg_succes_test();
//	twist_arg_one2much__test();

	va_list_value(0);
		return (0);
}


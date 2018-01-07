/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precison_def_prior.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 00:19:10 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/07 02:25:26 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precison_def_prior.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:57:30 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/07 00:18:27 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// trigger --> [value | arg_id]
// stack arg

void	so_long_line()
{
	double	f = 0;
//	printf(".*2$		|%f|	|%.*2$f|\n", f, 0);
//	printf(".*2$		|%f|	|%.*2$f|\n", f, 0, 0);
//	printf(".*2$		|%f|	|%.*2$f|\n", f, 0, 0, 0);
	printf(".*2$		|%f|	|%.*2$f|\n", f, 0, 0, 0, 0);
}

void	test_trigger(double f)
{
	dprintf(2, "\n====================================\n\n");
	printf("f			|%f|\n", f);
	printf("10			|%10f|\n", f);
	printf(".10			|%.10f|\n", f);
	printf("10.9		|%10.10f|\n", f);
	printf(".*			|%.*f|\n", f, 8);
	printf(".*2			|%.*2f|\n", f, 7);
//	printf(".*2$		|%.*2$f|\n", f, 0);
	printf(".2$			|%.2$f|\n", f, 5);


	dprintf(2, "\n====================================\n\n");

	printf("10f			|%10f|\n", f);
	printf("10			|%10f|\n", f);
	printf("10.10		|%10.10f|\n", f);
	printf("10.9		|%10.10f|\n", f);
	printf("10.*		|%10.*f|\n", f, 8);
	printf("10.*2		|%10.*2f|\n", f, 7);
	printf("10.*2$		|%10.*2$f|\n", f, 6);
	printf("10.2$		|%10.2$f|\n", f, 5);


	dprintf(2, "\n====================================\n\n");

	printf("f			|%10f|		\n", f);
	printf("10f			|%10f|		\n", f);
	printf("10.0f 		|%10.0f|		\n", f);
	printf("10.1f 		|%10.1f|		\n", f);
	printf("10.2f 		|%10.2f|		\n", f);
	printf("10.3f 		|%10.3f|		\n", f);
	printf("10.4f 		|%10.4f|		\n", f);
	printf("10.5f 		|%10.5f|		\n", f);
	printf("10.6f 		|%10.6f|		\n", f);
	printf("10.7f 		|%10.7f|		\n", f);
	printf("10.8f 		|%10.8f|		\n", f);
	printf("10.9f 		|%10.9f|		\n", f);
	printf("10.10f		|%10.10f|		\n", f);

	dprintf(2, "\n====================================\n\n");

	printf("f			|%10f|		\n", f);
	printf("10f			|%10f|		\n", f);
	printf("10.10f 		|%10.10f|		\n", f);
	printf("10.11f 		|%10.11f|		\n", f);
	printf("10.12f 		|%10.12f|		\n", f);
	printf("10.13f 		|%10.13f|		\n", f);
	printf("10.14f 		|%10.14f|		\n", f);
	printf("10.15f 		|%10.15f|		\n", f);
	printf("10.16f 		|%10.16f|		\n", f);
	printf("10.17f 		|%10.17f|		\n", f);
	printf("10.18f 		|%10.18f|		\n", f);
	printf("10.19f 		|%10.19f|		\n", f);
	printf("10.20f		|%10.20f|		\n", f);
	printf(".150f		|%.150f|		\n", f);

	dprintf(2, "\n################################################################\n################################################################\n################################################################\n\n");

}



void	test_trigger_precision()
{
	double	f = 0.1337999000000000000000000000000000000000000000000;
	double	f2 = 0.133799899999999999389288518614193890243768692016601562500000000; 
	double	f3 = 0.133799899999999999389288518614193890243768692016601562500000000154354; 
	double	f4 = 0.1337998999999999993892885186141938902437686920166015625000000009543543; 
	int		a = 42;

//	test_trigger(f);
//	test_trigger(f2);
//	test_trigger(f3);
//	test_trigger(f4);
	so_long_line();
}

void	test_struct_star()
{
	double	f = 42.1337;

	printf("\n\n");
	printf("|%%f|  		|%f|		\n", f);
	printf("|%%42f|		|%42f|		\n", f);
	printf("|========================== * ==========================\n");
	printf("|%%*f| 		|%*f|		\n", f, 42 );
	printf("|%%*0f|		|%*0f|		\n", f, 42);
	printf("|%%*1f|		|%*1f|		\n", f, 42);
	printf("|%%*2f|		|%*2f|		\n", f, 42);
	printf("-\n");
	printf("|%%*10f|		|%*10f|	\n", f, 42, 20, 10, 7, 0);
	printf("|%%*11f|		|%*11f|	\n", f, 42, 20, 10, 7, 0);
	printf("|%%*12f|		|%*12f|	\n", f, 42, 20, 10, 7, 0);
	printf("-\n");
	printf("|%%0*f|		|%0*f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%1*f|		|%1*f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%2*f|		|%2*f|		\n", f, 42, 20, 10, 7, 0);
	printf("-\n");
	printf("|%%*0$f|		|%*0$f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%*2$f|		|%*2$f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%*3$f|		|%*3$f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%*4$f|		|%*4$f|		\n", f, 42, 20, 10, 7, 0);
	printf("-\n");
	printf("|%%*1$2$f|	|%*1$2$f|		\n", 42, f, 20, 10, 7, 0);
	printf("|%%*1$0$f|	|%*1$0$f|		\n", 42, f, 20, 10, 7, 0);
}

void	test_struc_point()
{
	double	f = 42.1337;

	printf("\n\n");
	printf("|%%f|  		|%f|		\n", f);
	printf("|%%.42f|		|%.42f|		\n", f);
	printf("|========================== * ==========================\n");
	printf("|%%.f| 		|%.f|		\n", f, 42 );
	printf("|%%.0f|		|%.0f|		\n", f, 42);
	printf("|%%.001f|	|%.001f|		\n", f, 42);
	printf("|%%.00001f|	|%.00001f|		\n", f, 42);
	printf("|%%.00000000000000000000000000000000000000000000000000000000000000000000000001f|	|%.00000000000000000000000000000000000000000000000000000000000000000000000001f|		\n", f, 42);
	printf("|%%.1f|		|%.1f|		\n", f, 42);
	printf("|%%.2f|		|%.2f|		\n", f, 42);
	printf("-\n");
	printf("|%%.10f|		|%.10f|	\n", f, 42, 20, 10, 7, 0);
	printf("|%%.11f|		|%.11f|	\n", f, 42, 20, 10, 7, 0);
	printf("|%%.12f|		|%.12f|	\n", f, 42, 20, 10, 7, 0);
	printf("-\n");
	printf("|%%0.f|		|%0.f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%1.f|		|%1.f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%2.f|		|%2.f|		\n", f, 42, 20, 10, 7, 0);
	printf("-\n");
	printf("|%%.0$f|		|%.0$f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%.2$f|		|%.2$f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%.3$f|		|%.3$f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%.4$f|		|%.4$f|		\n", f, 42, 20, 10, 7, 0);
	printf("-\n");
	printf("|%%.*0$f|	|%.*0$f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%.*2$f|	|%.*2$f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%.*3$f|	|%.*3$f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%.*4$f|	|%.*4$f|		\n", f, 42, 20, 10, 7, 0);
	printf("-\n");
	printf("|%%.*f|		|%.*f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%.*.0f|	|%.*.0f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%.*.2f|	|%.*.2f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%.*.3f|	|%.*.3f|		\n", f, 42, 20, 10, 7, 0);
	printf("|%%.*.4f|	|%.*.4f|		\n", f, 42, 20, 10, 7, 0);
	printf("-\n");
	printf("|%%.1$2$f|	|%.1$2$f|		\n", 42, f, 20, 10, 7, 0);
	printf("|%%.1$0$f|	|%.1$0$f|		\n", 42, f, 20, 10, 7, 0);

}

//void	test_secfault()
//{
//	double	f = 42.1337;
//	int		i;
//	char	*str;
//	int		len;
//	char	format[100] = "jrhghr";
//	int	a, b, c, d, e, g, h, j, k, l, m;
//
//	if (!(str = malloc(100000000)))
//	{
//		printf("Oh  damned\n");
//		exit(0);
//	}
////	printf("%*1$f\n");
////	printf("%*400$f\n");
////	printf("%*400$+*1$f\n");
//	len = 0;
//	i = 0;
//	while (++i)
//	{
//	//	printf("\nyo\n");
//	//	len = sprintf(str  + len, "	%% %d \$d\n", i, 2, 3, 4, 5);
//	//
//	//
////		len += sprintf(str  + len, " {%%%d$hhu[%d]}	", i, i, 	((!(i % 6)) ? '\\t' : '\\n' ) );
// //		len += sprintf(str + len, " {%%%lx$hu[%d]}	%c", i, i, 	((!((i % 13) == 0)) ? '\t' : '\n' ) );
////		len += sprintf(str  + len, " {%%%d$u[%d]}	", i, i, 	((!(i % 6)) ? '\\t' : '\\n' ) );
////		len += sprintf(str  + len, " {%%%d$lu[%d]}	", i, i, 	((!(i % 6)) ? '\\t' : '\\n' ) );
//
//
//
//		len += sprintf(str + len, "%%%lx$h50u%c", i, i, 	((!((i % 4) == 0)) ? ' ' : '\n' ) );
//
////		int j = 0;
////		while (j < (1 << 1))
////			j++;
//		str[len] = 0;
//	//	printf("[%d]	%s", i, str);
//		printf(str);
//	//	printf("%s", str);
////		memmove();
//		printf("\n");
//	}
//}


void	test_secfault()                                                                               
 {
 	double	f = 42.1337;
 	int		i;
 	char	*str;
 	int		len;
 	char	format[100] = "jrhghr";
 	int	a, b, c, d, e, g, h, j, k, l, m;
 
 	if (!(str = malloc(100000000)))
 	{
 		printf("Oh  damned\n");
 		exit(0);
 	}
 	len = 0;
 	i = 0;
 	while (++i)
 	{
 		len = sprintf(str, "\n{%% %13d$u \0}%%2$c", i, i , '\n');	
  		str[len] = 0;
	//	(0) ? printf(str) : printf("%s", str);
//		(0) ? printf(str) : printf("%s%c", str, ((((i % 5) == 0)) ? '\n' : ' ' ));
		printf("%s%c", str, ((((i % 5) == 0)) ? '\n' : ' ' ));
		printf(str);
		str += len;
 	}
 }

void	test_number_end()
{
	double	f = 42.13370001;

	printf("	%f\n", f);
	printf("	%.0f\n", f);
	printf("	%.10f\n", f);
	printf("	%.20f\n", f);
	printf("	%.1f\n", f);
	printf("--	%.1$f\n", f);
}

int	main()
{
//	test_trigger_precision();
//	test_struct_star();
//	test_struc_point();
//	test_secfault();
	test_number_end();
	return (0);
}


// precision, min_siz, id_arg
// -------------------------------------------------------------------------
//					| ------------------ |
// 	nbr				|					 | is min_size
// 	*,				|-> define size min	 | next_arg is min_size		(int)
// 	*,(nbr,$)		| 					 | is id_arg minsize 		(int)
//					| ------------------ |

//					| ------------------ |
// 	nbr,$			|->    arg value     | is id_arg of value
//					| ------------------ |

//					| ------------------ |
// '.',nbr			|					 | is precision
// '.',*			|-> define size min	 | next_arg is precision	(int)
// '.',(*,nbr,$)	| 					 | is id_arg precisione 	(int)
//					| ------------------ |
// -------------------------------------------------------------------------

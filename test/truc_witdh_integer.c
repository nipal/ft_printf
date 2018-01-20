/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc_witdh_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:37:07 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/17 16:43:28 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

void	test_one_int(long l)
{
printf("############################################################################################\n", l);
printf("#########################    %21ld    ######################################\n", l);
printf("############################################################################################\n", l);
	printf("%%l         |%ld|\n", l);
	printf("%%1.1l      |%1.1ld|\n", l);
	printf("%%10.10l    |%10.10ld|\n", l);
	printf("%%20.20l    |%20.20ld|\n", l);
	printf("%%30.20l    |%30.20ld|\n", l);
	printf("%%20.30l    |%20.30ld|\n", l);
printf("====================\n");
	printf("%%0         |%0ld|\n", l);
	printf("%%01.1l     |%01.1ld|\n", l);
	printf("%%010.10l   |%010.10ld|\n", l);
	printf("%%020.20l   |%020.20ld|\n", l);
	printf("%%030.20l   |%030.20ld|\n", l);
	printf("%%020.30l   |%020.30ld|\n", l);
printf("====================\n");
	printf("%%+l        |%+ld|\n", l);
	printf("%%+1.1l     |%+1.1ld|\n", l);
	printf("%%+10.10l   |%+10.10ld|\n", l);
	printf("%%+20.20l   |%+20.20ld|\n", l);
	printf("%%+30.20l   |%+30.20ld|\n", l);
	printf("%%+20.30l   |%+20.30ld|\n", l);
printf("====================\n");
	printf("%%-l        |%-ld|\n", l);
	printf("%%-1.1l     |%-1.1ld|\n", l);
	printf("%%-10.10l   |%-10.10ld|\n", l);
	printf("%%-20.20l   |%-20.20ld|\n", l);
	printf("%%-30.20l   |%-30.20ld|\n", l);
	printf("%%-20.30l   |%-20.30ld|\n", l);
printf("====================\n");
	printf("%% l        |% ld|\n", l);
	printf("%% 1.1l     |% 1.1ld|\n", l);
	printf("%% 10.10l   |% 10.10ld|\n", l);
	printf("%% 20.20l   |% 20.20ld|\n", l);
	printf("%% 30.20l   |% 30.20ld|\n", l);
	printf("%% 20.30l   |% 20.30ld|\n", l);
printf("====================\n");
	printf("%%+ l       |%+ ld|\n", l);
	printf("%%+ 1.1l    |%+ 1.1ld|\n", l);
	printf("%%+ 10.10l  |%+ 10.10ld|\n", l);
	printf("%%+ 20.20l  |%+ 20.20ld|\n", l);
	printf("%%+ 30.20l  |%+ 30.20ld|\n", l);
	printf("%%+ 20.30l  |%+ 20.30ld|\n", l);
printf("====================\n");
	printf("%%0 l       |%0 1.1ld|\n", l);
	printf("%%0 1.1l    |%0 1.1ld|\n", l);
	printf("%%0 10.10l  |%0 10.10ld|\n", l);
	printf("%%0 20.20l  |%0 20.20ld|\n", l);
	printf("%%0 30.20l  |%0 30.20ld|\n", l);
	printf("%%0 20.30l  |%0 20.30ld|\n", l);
printf("====================\n");
	printf("%% 0l       |% 0ld|\n", l);
	printf("%% 01.1l    |% 01.1ld|\n", l);
	printf("%% 010.10l  |% 010.10ld|\n", l);
	printf("%% 020.20l  |% 020.20ld|\n", l);
	printf("%% 030.20l  |% 030.20ld|\n", l);
	printf("%% 020.30l  |% 020.30ld|\n", l);
printf("====================\n");
	printf("%%0l        |% 0ld|\n", l);
	printf("%%0.1l      |% 0.1ld|\n", l);
	printf("%%0.10l     |% 0.10ld|\n", l);
	printf("%%0.20l     |% 0.20ld|\n", l);
	printf("%%0.20l     |% 0.20ld|\n", l);
	printf("%%0.30l     |% 0.30ld|\n", l);
	printf("%%0+35l     |%0+35ld|\n", l);
	printf("%%0+35.40l  |%0+35.40lld|\n", l);
	printf("%%035.40l   |%035.40lld|\n", l);


	printf("%%-l         |%-ld|\n", l);
	printf("%%-1.1l      |%-1.1ld|\n", l);
	printf("%%-10.10l    |%-10.10ld|\n", l);
	printf("%%-20.20l    |%-20.20ld|\n", l);
	printf("%%-30.20l    |%-30.20ld|\n", l);
	printf("%%-20.30l    |%-20.30ld|\n", l);
printf("====================\n");
	printf("%%-0         |%-0ld|\n", l);
	printf("%%-01.1l     |%-01.1ld|\n", l);
	printf("%%-010.10l   |%-010.10ld|\n", l);
	printf("%%-020.20l   |%-020.20ld|\n", l);
	printf("%%-030.20l   |%-030.20ld|\n", l);
	printf("%%-020.30l   |%-020.30ld|\n", l);
printf("====================\n");
	printf("%%-+l        |%-+ld|\n", l);
	printf("%%-+1.1l     |%-+1.1ld|\n", l);
	printf("%%-+10.10l   |%-+10.10ld|\n", l);
	printf("%%-+20.20l   |%-+20.20ld|\n", l);
	printf("%%-+30.20l   |%-+30.20ld|\n", l);
	printf("%%-+20.30l   |%-+20.30ld|\n", l);
printf("====================\n");
	printf("%%--l        |%--ld|\n", l);
	printf("%%--1.1l     |%--1.1ld|\n", l);
	printf("%%--10.10l   |%--10.10ld|\n", l);
	printf("%%--20.20l   |%--20.20ld|\n", l);
	printf("%%--30.20l   |%--30.20ld|\n", l);
	printf("%%--20.30l   |%--20.30ld|\n", l);
printf("====================\n");
	printf("%%- l        |%- ld|\n", l);
	printf("%%- 1.1l     |%- 1.1ld|\n", l);
	printf("%%- 10.10l   |%- 10.10ld|\n", l);
	printf("%%- 20.20l   |%- 20.20ld|\n", l);
	printf("%%- 30.20l   |%- 30.20ld|\n", l);
	printf("%%- 20.30l   |%- 20.30ld|\n", l);
printf("====================\n");
	printf("%%-+ l       |%-+ ld|\n", l);
	printf("%%-+ 1.1l    |%-+ 1.1ld|\n", l);
	printf("%%-+ 10.10l  |%-+ 10.10ld|\n", l);
	printf("%%-+ 20.20l  |%-+ 20.20ld|\n", l);
	printf("%%-+ 30.20l  |%-+ 30.20ld|\n", l);
	printf("%%-+ 20.30l  |%-+ 20.30ld|\n", l);
printf("====================\n");
	printf("%%-0 l       |%-0 1.1ld|\n", l);
	printf("%%-0 1.1l    |%-0 1.1ld|\n", l);
	printf("%%-0 10.10l  |%-0 10.10ld|\n", l);
	printf("%%-0 20.20l  |%-0 20.20ld|\n", l);
	printf("%%-0 30.20l  |%-0 30.20ld|\n", l);
	printf("%%-0 20.30l  |%-0 20.30ld|\n", l);
printf("====================\n");
	printf("%%- 0l       |%- 0ld|\n", l);
	printf("%%- 01.1l    |%- 01.1ld|\n", l);
	printf("%%- 010.10l  |%- 010.10ld|\n", l);
	printf("%%- 020.20l  |%- 020.20ld|\n", l);
	printf("%%- 030.20l  |%- 030.20ld|\n", l);
	printf("%%- 020.30l  |%- 020.30ld|\n", l);
printf("====================\n");
	printf("%%-0l        |%- 0ld|\n", l);
	printf("%%-0.1l      |%- 0.1ld|\n", l);
	printf("%%-0.10l     |%- 0.10ld|\n", l);
	printf("%%-0.20l     |%- 0.20ld|\n", l);
	printf("%%-0.20l     |%- 0.20ld|\n", l);
	printf("%%-0.30l     |%- 0.30ld|\n", l);
	printf("%%-0+35l     |%-0+35ld|\n", l);
	printf("%%-0+35.40l  |%-0+35.40lld|\n", l);
	printf("%%-035.40l   |%-035.40lld|\n", l);
}

void	test_flag()
{
	test_one_int(0);
	test_one_int(-1);
	test_one_int(1);
	test_one_int(INT_MAX);
	test_one_int(INT_MIN);
	test_one_int(LONG_MIN);
	test_one_int(LONG_MAX);

}

void	test_zero_one(long l)
{
	int	w, p;
	
	
	w =   0; p =    0; printf("%%ld      %ld", w, p, l);	
	w =  10; p =    0; printf("%%0ld      %ld", w, p, l);	
	w =  20; p =    0; printf("%%0-ld      %ld", w, p, l);	
	w =  30; p =    0; printf("%%0+ld      %ld", w, p, l);	
                  
	w =  30; p =    0; printf("%%0 ld      %ld", w, p, l);	
	w =  30; p =    0; printf("%%0*.*ld      %ld", w, p, l);	
}        

void	test_zero()
{
	test_zero_one(0);
	test_zero_one(-1);
	test_zero_one(1);
	test_zero_one(INT_MAX);
	test_zero_one(INT_MIN);
	test_zero_one(LONG_MIN);
	test_zero_one(LONG_MAX);
}

void	test_integer()
{
//	test_flag();
	test_zero();
}

//1659483736897

int	main()
{
	test_integer();
	return (0);
}

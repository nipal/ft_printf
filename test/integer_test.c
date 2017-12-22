/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:00:50 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/22 01:07:11 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	precision_check(int a)
{
	int	precision;

	printf("-------- %d ----------\n", a);
	printf("%%.0d	[%.0d]\n", a);
	printf("%%.1d	[%.1d]\n", a);
	printf("%%.2d	[%.2d]\n", a);
	printf("%%.3d	[%.3d]\n", a);
	printf("%%.4d	[%.4d]\n", a);
	printf("%%.5d	[%.5d]\n", a);
	printf("---\n");
	printf("%%0.0d	[%0.0d]\n", a);
	printf("%%1.1d	[%1.1d]\n", a);
	printf("%%2.2d	[%2.2d]\n", a);
	printf("%%3.3d	[%3.3d]\n", a);
	printf("%%4.4d	[%4.4d]\n", a);
	printf("%%5.5d	[%5.5d]\n", a);
	printf("---\n");
	printf("%%0d	[%0d]\n", a);
	printf("%%1d	[%1d]\n", a);
	printf("%%2d	[%2d]\n", a);
	printf("%%3d	[%3d]\n", a);
	printf("%%4d	[%4d]\n", a);
	printf("%%5d	[%5d]\n", a);


	printf("---\n");
	printf("%%.0d	[%+.0d]\n", a);
	printf("%%.1d	[%+.1d]\n", a);
	printf("%%.2d	[%+.2d]\n", a);
	printf("%%.3d	[%+.3d]\n", a);
	printf("%%.4d	[%+.4d]\n", a);
	printf("%%.5d	[%+.5d]\n", a);
	printf("---\n");
	printf("%%0d	[%+0d]\n", a);
	printf("%%1d	[%+1d]\n", a);
	printf("%%2d	[%+2d]\n", a);
	printf("%%3d	[%+3d]\n", a);
	printf("%%4d	[%+4d]\n", a);
	printf("%%5d	[%+5d]\n", a);
	printf("---\n");

	printf("---\n");
	printf("%%.0d	[%-.0d]\n", a);
	printf("%%.1d	[%-.1d]\n", a);
	printf("%%.2d	[%-.2d]\n", a);
	printf("%%.3d	[%-.3d]\n", a);
	printf("%%.4d	[%-.4d]\n", a);
	printf("%%.5d	[%-.5d]\n", a);
	printf("---\n");
	printf("%%0d	[%-d]\n", a);
	printf("%%1d	[%-1d]\n", a);
	printf("%%2d	[%-2d]\n", a);
	printf("%%3d	[%-3d]\n", a);
	printf("%%4d	[%-4d]\n", a);
	printf("%%5d	[%-5d]\n", a);
	printf("---\n");

	printf("---\n");
	printf("%%.0d	[% .0d]\n", a);
	printf("%%.1d	[% .1d]\n", a);
	printf("%%.2d	[% .2d]\n", a);
	printf("%%.3d	[% .3d]\n", a);
	printf("%%.4d	[% .4d]\n", a);
	printf("%%.5d	[% .5d]\n", a);
	printf("   \n");
	printf("%%0d	[% 0d]\n", a);
	printf("%%1d	[% 1d]\n", a);
	printf("%%2d	[% 2d]\n", a);
	printf("%%3d	[% 3d]\n", a);
	printf("%%4d	[% 4d]\n", a);
	printf("%%4d	[% 5d]\n", a);
	printf("---\n");







}

void	precizion_integer()
{
	precision_check(0);	
	precision_check(1);	
	precision_check(2);	
	precision_check(113);	

	precision_check(-0);	
	precision_check(-1);	
	precision_check(-2);	
	precision_check(-113);	
}

int	main()
{
	precizion_integer();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:10:43 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/21 16:02:20 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	test_print_float()
{
	float	precision = 4;

	print_float(4242.42, precision);
	print_float(110, precision);
	print_float(10, precision);
	print_float(1, precision);
	print_float(11, precision);
	print_float(111, precision);
	print_float(13345345, precision);
	print_float(0.1337, precision);
	print_float(0.0, precision);
	print_float(42.42, precision);
	print_float(0.9999, precision);
	print_float(0.0999, precision);
	print_float(0.0009, precision);
	print_float(0.0000123, precision);
}

void	test_print_float_precision()
{
	float	precision = 5;

	print_float(0.1234567890123456, precision);
	print_float(0.11111, precision);
	print_float(0.22222, precision);
	print_float(0.33333, precision);
	print_float(0.44444, precision);
	print_float(0.55555, precision);
	print_float(0.66666, precision);
	print_float(0.77777, precision);
	print_float(0.88888, precision);
	print_float(0.99999, precision);
	print_float(9.99999, precision);
}

int	main(void)
{
//	test_print_float();
	test_print_float_precision();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:10:43 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/21 09:33:12 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	test_print_float()
{
	print_float(0.0, -1);
	print_float(0.1337, -1);
	print_float(-42.42, -1);
	print_float(0.9999, -1);
}

int	main(void)
{
	test_print_float();
	return (0);
}

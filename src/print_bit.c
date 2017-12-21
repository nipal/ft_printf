/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 01:26:23 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/21 01:27:58 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_bit(unsigned char *data, int size)
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
	printf("%s\n", str);
	free(str);
/**/}

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



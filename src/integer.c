/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 01:21:33 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/21 08:25:13 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**symbole_base1(int flag)
{
	static	char	symbole_min[17] = "0123456789abcdef";
	static	char	symbole_maj[17] = "0123456789ABCDEF";
	static	char	*now = NULL;
	
	if (!now)
		now = symbole_min;
	if (flag == SYM_MIN)
		now = symbole_min;
	else if (flag == SYM_MAJ)
		now = symbole_maj;
	return (&now);
}

int	put_integer_s(long val, int base, char *buff, int buff_len)
{
	int				i;
	int				s;
	static	char	**ptr = NULL;
	char			*symbol;
	
	if (!ptr)
		ptr = symbole_base1(SYM_ASK);
	symbol = *ptr;
	s = val < 0;
	val = (val > 0) ? val : -val;
	i = 0;
	if (!val)
		return (!!(buff[buff_len - 1] = '0'));
	while (val)
	{
		buff[buff_len - i - 1] = symbol[(val % base)];
		val /= base;
		i++;
	}
	if (!s)
		return (i);
	buff[buff_len - i - 1] = '-';
	return (++i);
}

int	put_integer_u(unsigned long val, int base, char *buff, int buff_len)
{
	int				i;
	static	char	**ptr = NULL;
	char			*symbol;
	
	if (!ptr)
		ptr = symbole_base1(SYM_ASK);
	symbol = *ptr;
	i = 0;
	if (!val)
		return (!!(buff[buff_len] = '0'));
	while (val)
	{
		buff[buff_len - i] = symbol[(val % base)];
		val /= base;
		i++;
	}
		return (i);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatique.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:02:30 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/12 05:07:55 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	init_fparam(t_fparam *arg, char *now)
{
	char *prct;
	char *beg_sec;

	prct = now;
	beg_sec = arg->beg_sec;
	bzero(arg, sizeof(t_fparam)); // on mettera eventuelement des valeur defni autre
	arg->prct = prct;
	arg->beg_sec = beg_sec;
}

char	*get_char_toend(char *str, char target)
{
	while (*str && *str != target)
		str++;
	return (str);
}

char	*set_parse_error(char *now, t_fparam *p)
{
	now = get_char_toend(now, '%');
	init_fparam(p, now);
	return (now + ((*now) ? 1: 0));
}

void	init_func_table(char *(**tabf)(char *now, t_fparam *p), int *first)
{
	(void)tabf;
	int	i;

	*first = 0;
	i = 0;
	while (i < 256)
	{
		tabf[i] = set_parse_error;
		i++;
	}
		tabf['\0'] = NULL; 	// print the last txt part
		tabf['+'] = flag_add_plus;
		tabf['-'] = flag_add_minus;
		tabf[' '] = flag_add_space;
		tabf['#'] = flag_add_hash;
		tabf['I'] = flag_add_lang_nb;
	   tabf['\''] = flag_add_separate;
		tabf['0'] = flag_add_zero;

//variable
		tabf['*'] = set_senario_star;
		tabf['.'] = set_senario_point;
		tabf['1'] = set_senario_nbr;
		tabf['2'] = set_senario_nbr;
		tabf['3'] = set_senario_nbr;
		tabf['4'] = set_senario_nbr;
		tabf['5'] = set_senario_nbr;
		tabf['6'] = set_senario_nbr;
		tabf['7'] = set_senario_nbr;
		tabf['8'] = set_senario_nbr;
		tabf['9'] = set_senario_nbr;




// cast
		tabf['h'] = flag_set_cast_s2;
		tabf['l'] = flag_set_cast_s8;
		tabf['z'] = flag_set_cast_u8;
		tabf['j'] = flag_set_cast_u8;
		tabf['t'] = flag_set_cast_u8; 
		tabf['L'] = flag_set_long_double;	// long double


// typefiled
		tabf['i'] = parse_dec_signed;
		tabf['d'] = parse_dec_signed;
		tabf['D'] = parse_dec_signed_cap;
		tabf['u'] = parse_dec_unsigned;
		tabf['U'] = parse_dec_unsigned_cap;
		tabf['o'] = parse_oct_unsigned;
		tabf['O'] = parse_oct_unsigned_cap;
		tabf['x'] = parse_exa_unsigned;
		tabf['X'] = parse_exa_unsigned_cap;
		tabf['f'] = parse_float;
		tabf['F'] = parse_float_cap;
		tabf['e'] = parse_expo_dec;
		tabf['E'] = parse_expo_dec_cap;
		tabf['g'] = parse_expo_dec_mixt;
		tabf['G'] = parse_expo_dec_mixt_cap;
		tabf['a'] = parse_expo_exa;
		tabf['A'] = parse_expo_exa_cap;
		tabf['c'] = parse_char;
		tabf['C'] = parse_char_unicode;
		tabf['s'] = parse_str;
		tabf['S'] = parse_str_unicode;
		tabf['p'] = parse_ptr;
		tabf['n'] = parse_nbc_print;
		tabf['m'] = parse_perror;
		tabf['%'] = parse_prct;
}

void	push_param(t_list **beg, t_list *node)
{
	static	t_list *beg_lst = NULL;

	if (beg && *beg)
		beg_lst = *beg;
	if (node)
	{
		node->next = *beg;;
		*beg = node;
	}
}

void	del_param(void *param, size_t size)
{
	(void)size;
	free(param);
}

/*
**	print the param
*/


//*f(char **, char *, t_fparam *)
void	main_parsing(const char *format, va_list beg)
{
	t_list			*beg_param;
	va_list			current;
	static	int		first = 1;
	static	char	*(*tabf[256])(char *now, t_fparam *p);
	char		*cursor;
	t_fparam		param_arg;
	(void)tabf;(void)format;(void)beg;(void)current;

//	va_copy(current, beg);
	if (first)
		init_func_table(tabf, &first);
	beg_param = NULL;

	push_param(&beg_param, NULL);
	param_arg.beg_sec = (char *)format;
	param_arg.prct = get_char_toend((char*)format, '%');

	//	stack the param
	cursor = param_arg.prct;
	init_fparam(&param_arg, cursor);
	while (*cursor)
	{
		cursor = tabf[*((unsigned char*)cursor)](cursor, &param_arg);
		ft_lstadd(&beg_param, ft_lstnew(&param_arg, sizeof(t_fparam)));
	}
	//	count the arg, get the arg
	//		on scan les type [d'argument] et de [valeur] qui accedent aux arguemnt
	//		on depope tout gentillement
	//	push into the buffer
	//	print all
	ft_lstdel(&beg_param, del_param);
	// TODO: if no error --> PRINT
}


//*f(char **, char *, t_fparam *)
//void	*get_action(unsigned char c)
//{
//	static	int		first = 1;
//	static	char	*(*tabf[256])(char **prct, char *now, t_fparam *p);
//	(void)c;
//	(void)tabf;
//
//	if (first)
//	{
//		tabf[256] = NULL;
//		init_func_table(tabf);
//		first = 0;
//	}
//	return (NULL);
////	return (tabf[c]);
//}

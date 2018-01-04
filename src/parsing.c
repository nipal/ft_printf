/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatique.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:02:30 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/21 14:18:31 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	init_fparam(t_fparam *arg)
{
	bzero(arg, sizeof(t_fparam)); // on mettera eventuelement des valeur defni autre
}

char	*set_parse_error(char **prev_hard, char *now, t_fparam *p)
{
	(void)prev_hard;
	(void)now;
	(void)p;
	int	option = 2;
	// on [set une erreur] OU on [re_init + jump new prct [push normal txt_format]]
	
	if (option == 1)
	{
		p->state |= e_parse_error;
		return (now + 1);
	}
	else
	{
		init_fparam(p);
		while (*now && *now != '%')// find new prct
			now++;
		return (now + ((*now) ? 1: 0));
	}
}
void	init_func_table(char *(**tabf)(char **prct, char *now, t_fparam *p), int *first)
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
		tabf['+'] = flag_add_plus;	// condition,	action
		tabf['-'] = flag_add_minus;
		tabf[' '] = flag_add_space;
		tabf['#'] = flag_add_hash;
		tabf['I'] = flag_add_lang_nb;
	   tabf['\''] = flag_add_separate;
		tabf['0'] = flag_add_zero;

//variable
		tabf['*'] = NULL;
		tabf['.'] = NULL;
		tabf['$'] = NULL;
// number
		tabf['1'] = NULL;
		tabf['2'] = NULL;
		tabf['3'] = NULL;
		tabf['4'] = NULL;
		tabf['5'] = NULL;
		tabf['6'] = NULL;
		tabf['7'] = NULL;
		tabf['8'] = NULL;
		tabf['9'] = NULL;




// cast
		tabf['h'] = NULL;
		tabf['l'] = NULL;
		tabf['L'] = NULL;
		tabf['z'] = NULL;
		tabf['j'] = NULL;
		tabf['t'] = NULL;

// typefiled
		tabf['%'] = NULL;
		tabf['d'] = NULL;
		tabf['i'] = NULL;
		tabf['u'] = NULL;
		tabf['o'] = NULL;
		tabf['x'] = NULL;
		tabf['X'] = NULL;
		tabf['f'] = NULL;
		tabf['F'] = NULL;
		tabf['e'] = NULL;
		tabf['E'] = NULL;
		tabf['g'] = NULL;
		tabf['G'] = NULL;
		tabf['a'] = NULL;
		tabf['A'] = NULL;
		tabf['c'] = NULL;
		tabf['C'] = NULL;
		tabf['s'] = NULL;
		tabf['S'] = NULL;
		tabf['p'] = NULL;
		tabf['n'] = NULL;
		tabf['m'] = NULL;


}



//*f(char **, char *, t_fparam *)
void	main_parsing(const char *format, va_list beg)
{
	va_list			current;
	static	int		first = 1;
	static	char	*(*tabf[256])(char **prct, char *now, t_fparam *p);
	char		*cursor;
	char		*prev_hard;		// la precedente chaine brute
	t_fparam		param_arg;
	(void)tabf;(void)format;(void)beg;(void)current;

//	va_copy(current, beg);
	if (first)
		init_func_table(tabf, &first);
	cursor = (char *)format;
	prev_hard = (char *)format;
	init_fparam(&param_arg);
	// TODO: wait for prct
	while (*cursor)
	{
		cursor = tabf[*((unsigned char*)cursor)](&prev_hard, cursor, &param_arg);
		// process the chain
			// all the type_convert option must find the next prct and print between
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unite_test_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 22:23:24 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/18 01:43:25 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#include "libft.h"

#define BUFF_SMALL	32
#define BUFF_LARGE	1024

void	init_word_size(int *word_size, char *tab, int nb_word)
{
	int	i;

	i = 0;
	while (i < nb_word)
	{
		word_size[i] = strlen(tab + (i * BUFF_SMALL * sizeof(char)));
		i++;
	}
}

void	print_tab_word(char *tab, int nb_word)
{
	int	i;

	i = 0;
	while (i < nb_word)
	{
		printf("%s\n", tab + (i * BUFF_SMALL * sizeof(char)));
		i++;
	}
}

void	print_word_size(int *word_size, int nb_word)
{
	int	i;

	i = 0;
	while (i < nb_word)
	{
		printf("%d\n", word_size[i]);
		i++;
	}
}

void	print_word_and_size(int *word_size, char *tab, int nb_word)
{
	int	i;

	i = 0;
	while (i < nb_word)
	{
		printf("[%6d]:{%s}\n", word_size[i], tab + (i * BUFF_SMALL * sizeof(char)));
		i++;
	}
}

#define WORD_MAX 32
typedef	struct	s_pars
{
	unsigned	long	mask;
	char				word_tab[WORD_MAX][BUFF_SMALL];
	int					word_nb;
	void				(*f)(char *beg_str, char *buff, t_list *beg_pars);
}				t_pars;


void	f1_light(char *buff_beg, char *buff, t_list *elem)
{
	int				i;
	int				len;
	t_pars	p;

	p = *((t_pars*)elem->content);
	i = 0;
	while (i < p.word_nb)
	{
		strncpy(buff, &(p.word_tab[i][0]), (len = strlen(&(p.word_tab[i][0]))));
		p.f(buff_beg, buff + len, elem->next);
		i++;
	}
}


void	f2_light(char *buff_beg, char *buff, t_list *elem)
{
	int				i;
	int				len;
	t_pars	p;

	p = *((t_pars*)elem->content);
	i = 0;
	while (i < p.word_nb)
	{
		strncpy(buff, &(p.word_tab[i][0]), (len = strlen(&(p.word_tab[i][0]))));
		p.f(buff_beg, buff + len, elem->next);
		i++;
	}
}

void	print_func(char *buff_beg, char *buff, t_list *elem)
{
	(void)buff;
	(void)elem;
	printf("%s\n", buff_beg);
}


void	func_nbr_precision(char *buff_beg, char *buff, t_list *elem)
{
	(void)buff_beg;
	(void)buff;
	(void)elem;
}

t_list	*creat_parsing_chain()
{
	int	i;
	t_pars	p;
	t_list	*beg;
	t_pars	chain[] = {
		{((1l << 6) - 1), {"", " ", "+", "-", "0","#"}, 6, f1_light}, // on me la fontion du maillon d'apres
		{((1l << 6) - 1), {"", "hh", "h", "l", "ll", "L", "j", "q", "z"}, 9, f1_light},
		{((1l << 6) - 1), {"", "*"}, 2, f1_light},
		{((1l << 6) - 1), {"", " ", "-10", "0", "1", "2", "3", "4", "15", "20", "30", "100"}, 12, f1_light},
		{((1l << 6) - 1), {"", "$"}, 2, f1_light},
		{((1l << 6) - 1), {"", ".", ".*"}, 3, f1_light},
		{((1l << 6) - 1), {"", " ", "0", "0", "1", "2", "3", "4", "15", "20", "30", "100"}, 12, f1_light},
		{((1l << 6) - 1), {"", "$"}, 2, f1_light},
		{((1l << 6) - 1), {"d", "i", "o", "u", "x", "X", "e", "E", "f", "F", "g", "G", "a", "A", "c", "C", "s", "S", "p", "n", "m", "%"}, 22, print_func},
		{((1l << 6) - 1), {""}, 0, print_func}
	};
	int		chain_len = sizeof(chain) / sizeof(t_pars);

	beg = NULL;
	i = 0;
	while (i < chain_len)
	{
		ft_lstadd_back(&beg, ft_lstnew(chain + i, sizeof(t_pars)));
		i++;
	}
	return (beg);
}

void	pars_chain_del(void *content, size_t size)
{
	if (content)
	{
		bzero(content, size);
		free(content);
	}
}

void	unite_test_all()
{
	char	buff[BUFF_LARGE];
	t_list	*beg;

	if (!(beg = creat_parsing_chain()))
		return ;	
	f2_light(buff, buff, beg); // on initie le lancement ici et tout le reste a'enchai tout seul

	//---

	ft_lstdel(&beg, pars_chain_del);
}


/////////////////////


int	main()
{
	unite_test_all();
		return (0);
}


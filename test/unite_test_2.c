/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unite_test_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 22:23:24 by fjanoty           #+#    #+#             */
/*   Updated: 2018/02/01 06:49:26 by fjanoty          ###   ########.fr       */
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

////////////////////////////
void	wait_4_input_trace(char *file, int line)
{
	char	key;

	printf("\nfile:%20s line:%d\t\t-- presse any key --\n", file, line);
	read(0, &key, 1);
}
////////////////////////////


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

//============================= vv debug function vv =================================================

void	print_line_limit(char limit, char mid, int l1, int l2)
{
	int	i;

	printf("%c", limit);
	for (i = 0; i < (l1); i++)
		printf("%c", mid);
	printf("%c", limit);
	for (i = 0; i < (l2); i++)
		printf("%c", mid);
	printf("%c\n", limit);
		
}

void	pars_node_describe(t_pars *p, int nb_pars)
{
	int		i;
	int		j;
	char	buff[BUFF_SMALL];

	for (j = 0; j < nb_pars; j++)	
	{
		printf("\n\n             arg staked {%d}   \n", j);
		print_line_limit('|', '-', 10, 32);
		print_line_limit('|', '-', 10, 32);
		printf("|%10s|%10lx%*.*d|\n", "mask ", p[j].mask, 22, 0, 0);
		print_line_limit('|', '-', 10, 32);
		print_line_limit('|', '-', 10, 32);
		printf("|%10s|%10d%*.*d|\n", "word_nb ", p[j].word_nb, 22, 0, 0);
		print_line_limit('|', '-', 10, 32);
		print_line_limit('|', '-', 10, 32);
		for (i = 0; i < p[j].word_nb; i++)
		{
			sprintf(buff, "word[%d]", i);
			printf("|%10s|%32s|\n", buff, &(p[j].word_tab[i][0]));
			print_line_limit('|', '-', 10, 32);
		}
		if (i)
			print_line_limit('|', '-', 10, 32);
	}
}

//============================= vv Recurtion vv ======================================================

/*
	il faut qu'on remplace la chaine de charactere en tableau d'indice
	il faudra aussi changer la fonciton d'impression

	char *id_used/free  --> int *id_used/free 
*/


int		recurs_char_is_free(int *id_used, int curs, int value)
{
	while (--curs >= 0)
		if (id_used[curs] == value)
			return (0);
	return (1);
}

void	recurs_set_char_free(int *id_used, int *id_free, int curs, int len)
{
	int	i;	
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (recurs_char_is_free(id_used, curs, i))
		{
			id_free[j] = i;
			j++;
		}
		i++;
	}
}

/*
	char *org			: chaine originale							->	tableau de mots						
	char *tmp			: chaine re assembler						->	liste des indice deja assembler
	int len				: nb char in originale						->	nombre de mots dans le tableau de mots
	int stape_end		: nb char combined -> stop condition		->	nombre de mots a assembler

	int stape			: actual stape								->	l'etape dans la recurtion
	int *sum			: sum of all combined char					->	une somme de tout les assembage possible
	int (*f)(char *s)	: print fuction or what ever callback		->	la fonciton d'impression/callback
*/

void	f2_light(char *buff_beg, char *buff, t_list *elem);

//void	test_combin_recurs(char *tmp, int len, int stape_end, int stape, int *sum, void (*f)(char *beg, char *buff, t_list *elem))
void	test_combin_recurs(int *id_used, int stape, int stape_max,
			char *buff_beg, char *buff, t_list *elem)
{
	int 	i;
	int		id_free[BUFF_SMALL];
	t_pars	*p;
	char	*word;
	int		word_len;

	if (stape < stape_max) // construction part (recusrtion)
	{
		//				int *id_used	->	
		//				int *id_free    ->	
		//				int curs		->	stape
		//				int len			->	nbr char to combine
		p = (t_pars*)elem->content;
		recurs_set_char_free(id_used, id_free, stape, p->word_nb);									// construction des cas possible
		i = 0;
		while (i < p->word_nb - stape)																// pour chaque cas possible
		{
			if (p->mask & (1l << id_free[i]))	// si le mots est conserner
			{
				id_used[stape] = id_free[i];															// on set l'id utiliser
				// inserer ici les truc en plus
				word = ((char*)p->word_tab) + (sizeof(char) * BUFF_SMALL * id_free[i]);					// le mot a ajouter en fonciton de l'indice et tout sa mere. tmtc wesh!
				strncpy(buff, word, (word_len = strlen(word)));
				test_combin_recurs(id_used, stape + 1, stape_max, buff_beg, buff + word_len, elem);		// on lance la recurtion d'apres
			}
			i++;
		}
	}
	else if (elem->next)// printf part
	{
		p = (t_pars*)elem->next->content;
		p->f(buff_beg, buff, elem->next);
	}
}
////////////////////////////////////////////

/*
	Ici on prend une chaine de charactere et on fait toute les combinaison possible
	entre ces caratere puis on les imprime.
	-
	On fera la meme chose avec un tableau de chaine de charactere

	On construit chaque etape par recusrtion.
	Il y a un buffer qui lui permet de construire les possibilite en fonction des charatere qui ne sont pas encore present.
	Puis de les imprimer.
	-
	Pour le tableau de chaine de charactere il faudrait faire la meme chose avec des tableau d'indice de chaine de charactere

*/
//	declanche un teste de toute les combinaison
void	f2_light(char *buff_beg, char *buff, t_list *elem)
{
	int		i;
	int		id_used[BUFF_SMALL];
	int		max;

	bzero(id_used ,sizeof(id_used));
	max = ((t_pars*)elem->content)->word_nb;
	i = 0;
	while (i <= max)
	{
		test_combin_recurs(id_used, 0, i, buff_beg, buff, elem);
		i++;
	}
}

//============================= ^^ Recurtion ^^ ======================================================


//	on ajoute chaque mot bout a bout
void	f1_light(char *buff_beg, char *buff, t_list *elem)
{
	int				i;
	int				len;
	t_pars	p;

	p = *((t_pars*)elem->content);
	i = 0;
	while (i < p.word_nb)
	{
		if (p.mask & (1l << i))
		{
			strncpy(buff, &(p.word_tab[i][0]), (len = strlen(&(p.word_tab[i][0]))));
			buff[len] = '\0';
			p.f(buff_beg, buff + len, elem->next);
		}
		i++;
	}
//	printf("	=%2d=\n", i);
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

// bit actif pour chaque chaine

//		0b00000000000000000111111
//		0b00000000000000111111111
//		0b00000000000000000000011
//		0b00000000000000111111111
//		0b00000000000000000000011
//		0b00000000000000000000111
//		0b00000000000000111111111
//		0b00000000000000000000011
//		0b11111111111111111111111
//		0b00000000000000000000001

//		0b00000000000000000000001
//		0b00000000000000000000001
//		0b00000000000000000000001
//		0b00000000000000000000001
//		0b00000000000000000000001
//		0b00000000000000000000001
//		0b00000000000000000000001
//		0b00000000000000000000001
//		0b00000000000000000000001
//		0b00000000000000000000001

/*
	liste simple
	combinaison	longeur finale
	combinaison toute longeur
	combinaision brute force n^n
*/

void	init_chain_param_all(t_pars *chain_input, int *chain_len)
{
	int		i;
	t_pars	chain[] = {
		{0b00000000000000000000001, {"%"}          			                                                                                           , 1, f1_light},	// debut de la chaine
		{0b00000000000000001111110, {"", " ", "+"}                                                                                                     , 3, f1_light},	// flag signe
		{0b00000000000000001111110, {"", "-", "0","#"}                                                                                                 , 4, f1_light},	// flag autre
		{0b00000000000000000000001, {"", "hh", "h", "l", "ll", "L", "j", "q", "z"}                                                                     , 9, f1_light},	// taille
		{0b00000000000000001111101, {"", "*"}                                                                                                          , 2, f1_light},
		{0b00000000000000000000001, {"", "0", "1", "2", "3", "4", "15", "20", "30"}                                                                    , 12,f1_light},
		{0b00000000000000000000001, {"", "$"}                                                                                                          , 2, f1_light},		// achtoung le dolard tout seul
		{0b00000000000000000000001, {"", ".", ".*"}                                                                                                    , 3, f1_light},
		{0b00000000000000000000001, {"", " ", "0", "1", "2", "3", "4", "15", "20", "30"}                                                               , 12,f1_light},
		{0b00000000000000000000001, {"", "$"}                                                                                                          , 2, f1_light},		// achtoung le dolard tout seul
		{0b00000000000000000000001, {"", "d", "i", "o", "u", "x", "X", "e", "E", "f", "F", "g", "G", "a", "A", "c", "C", "s", "S", "p", "n", "m", "%"} , 23,f1_light},
		{0b00000000000000000000001, {""}                                                                                                               , 1, print_func}
	};

	*chain_len = sizeof(chain) / sizeof(t_pars);
	printf("chain_len:%d	<= (%zu) / (%zu)\n", *chain_len, sizeof(chain), sizeof(t_pars));
	memmove(chain_input + i, chain, sizeof(chain));
	memmove(chain_input + i, chain, sizeof(chain));
	pars_node_describe(chain, chain_len);


}


void	init_chain_custom(t_pars *chain_input, int *chain_len)
{
	(void)chain_input; (void)chain_len; 
	//
	//	FLAG --> all
	//  CAST --> intger : hh, h, l, ll, j, q, z
	//  CAST --> float  : L 
	//
	//---------------|---------------|---------------|---------------|||---------------|---------------|---------------|
	//                                                               |||   TYPE CONV   |     FLAG      |    CAST       |
	//---------------|---------------|---------------|---------------|||---------------|---------------|---------------|
	// number        | integer       | base16        | unsigned      |||     x, X, (p) |               |               |
	//               |               |---------------|---------------|||---------------|---------------|---------------|
	//               |               | base8         | unsigned      |||     o         |               |               |
	//               |               |---------------|---------------|||---------------|---------------|---------------|
	//               |               | base2         | unsigned      |||     b         |               |               |
	//               |               |---------------|---------------|||---------------|---------------|---------------|
	//               |               | base10        | unsigned      |||     u         |               |               |
	//               |               |---------------|---------------|||---------------|---------------|---------------|
	//               |               |               | signed        |||     d, i      |               |               |
	//               |---------------|---------------|---------------|||---------------|---------------|---------------|
	//               | floating      | base16        | signed        ||| a, A, g, G    |               |               |
	//               |               |---------------|---------------|||---------------|---------------|---------------|
	//               |               | base10        | signed        ||| e, E, f, F    |               |               |
	//---------------|---------------|---------------|---------------|||---------------|---------------|---------------|
	//  char         | one           | ascii         |               |||      c        |               |               |
	//               |               |---------------|---------------|||---------------|---------------|---------------|
	//               |               | unicode       |               |||      C        |               |               |
	//               |---------------|---------------|---------------|||---------------|---------------|---------------|
	//               | chaine        | ascii         |               |||      s        |               |               |
	//               |               |---------------|---------------|||---------------|---------------|---------------|
	//               |               | unicode       |               |||      S        |               |               |
	//---------------|---------------|---------------|---------------|||---------------|---------------|---------------|
	//  prct         |               |               |               |||      %        |               |               |
	//---------------|---------------|---------------|---------------|||---------------|---------------|---------------|
	// nb print char |               |               |               |||      n        |               |               | 
	//---------------|---------------|---------------|---------------|||---------------|---------------|---------------|
	// err msg       |               |               |               |||      m        |               |               |
	//---------------|---------------|---------------|---------------|||---------------|---------------|---------------|
	//
	// when '#' is active?
	//	CAST --> not a number ?? 
	//	#    --> not a number ?? 
                                                                                 
    //
	//	differente maniere de gerer les [width] et [.precision]
	//	gere le n$
	
	//	juste one time
	//	combine max_len
	//	combine all_len
	//	all^(all)
}                                                                                

//	
t_list	*creat_parsing_chain(int *chain_len)                                                   
{
	int	i;
	t_pars	p;
	t_list	*beg;
//#define TRUC 1 // ==> '|'

	t_pars	chain[BUFF_SMALL];

	init_chain_param_all(chain, chain_len);
	beg = NULL;
	i = 0;
	while (i < *chain_len)
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

void	launch_production(t_list *beg)
{
	char	buff[BUFF_LARGE];
	t_pars	*p;

//	((t_pars*)beg->content)->f(buff, buff, beg);
	p = (t_pars*)beg->content;
	p->f(buff, buff, beg);
}

void	unite_test_all()
{
	t_list	*beg;
	int	chain_len;
int	to_rm;	

to_rm = 0;
	if (!(beg = creat_parsing_chain(&chain_len)))
		return ;	
//	pars_node_describe((t_pars*)beg->content, chain_len);
	launch_production(beg);
	ft_lstdel(&beg, pars_chain_del);
}


/////////////////////


int	main()
{
	unite_test_all();
		return (0);
}


///////////////////
//	(a) --> automatiser la creation des noeud + fonciton + permition
//	(b) --> definir des niveau compatibiliter... en gros savoir ce qui est correcte ou non pour pouvoir lancer eventuelement des jeux de test sur des test non valide


/*	
(a)
	permision: definir des ensemble de compatibiliter: ==> parametrage plus simple 
	fonciton:  definir des type de senario pour reartir le nombre de cas a generer sur les noeud)


(b)	
	englober le resulta dans des chaine avec plusieurs argument recuperer

(c)
	cree les fonction de reception (print_func LVL UP) 
*/

/*
                                |                                 |                                |                                | On configure les different     | On lance toute les combinaison |
                                |                                 |                                |                                | maillont de staque avec une    | avec les mallion de stack      |
                                |                                 |                                |                                | logique de combinaison de      | genere comme il faut           |
                                |                                 |                                |                                | parametre,                     |                                |
                                |                                 |                                |                                | ==> senario parametrable       |                                |
                                |                                 |                                |                                |                                |                                |
					

*/

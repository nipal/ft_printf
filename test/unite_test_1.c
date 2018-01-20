/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_unite_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:43:56 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/17 22:22:25 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Le but serra de faire des fonction en 'cascade' ou 'callback' pour faire une
	sorte de combinaision totale.
	En suite on peut definir de relation de compatibilite:
		1- une seul globale a tout le monde:            si A -> dof 
		2- multi relationel                             si X -> dof puis Y
		2- multiple heritage                             
		2- multiple heritage                            si (A && A && ...) alors k                  les lettre son une famille de compatibilite
		---------------
		

	On va juste faire des fonction en 'cascade' ou 'callback' pour obtenir toute
	les combinaison.
	En suite on peu aussi faire une sorte d'activation de generation en fonction d'un parametre d'activation

*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define BUFF_SMALL	32
#define BUFF_LARGE	512

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

void	f4(char *buff_beg, char *buff)
{
	char			tab[][BUFF_SMALL] = {
											"|>>>>",
											"|<<<<",
											"|===="
											};
	int				word_nb = sizeof(tab) / (BUFF_SMALL * sizeof(char));
	int				i, len;
	static	int		word_size[BUFF_SMALL];
	static	int		init = 1;

	if (init && !(init = 0))
		init_word_size(word_size, tab, word_nb);
	i = 0;
	while (i < word_nb)
	{
//		printf("%s", &(tab[i][0]));
		strncpy(buff, &(tab[i][0]), word_size[i]);
		printf("%s\n", buff_beg);
		i++;
	}
}

void	f3(char *buff_beg, char *buff)
{
	char			tab[][BUFF_SMALL] = {
											"|00",
											"|11",
											"|22"
											};
	int				word_nb = sizeof(tab) / (BUFF_SMALL * sizeof(char));
	int				i, len;
	static	int		word_size[BUFF_SMALL];
	static	int		init = 1;

	if (init && !(init = 0))
		init_word_size(word_size, tab, word_nb);
	i = 0;
	while (i < word_nb)
	{
//		printf("%s", &(tab[i][0]));
		strncpy(buff, &(tab[i][0]), word_size[i]);
		f4(buff_beg, buff + word_size[i]);
		i++;
	}
}

void	f2(char *buff_beg, char *buff)
{
	char			tab[][BUFF_SMALL] = {
											"|--_--",
											"|-___-",
											"|_____",
											"|__-__",
											"|_---_",
											"|-----"
											};
	int				word_nb = sizeof(tab) / (BUFF_SMALL * sizeof(char));
	int				i, len;
	static	int		word_size[BUFF_SMALL];
	static	int		init = 1;

	if (init && !(init = 0))
		init_word_size(word_size, tab, word_nb);
	i = 0;
	while (i < word_nb)
	{
//		printf("%s", &(tab[i][0]));
		strncpy(buff, &(tab[i][0]), word_size[i]);
		f3(buff_beg, buff + word_size[i]);
		i++;
	}
}


void	f1(char *buff_beg, char *buff)
{
	char			tab[][BUFF_SMALL] = {
											"|a",
											"|b",
											"|k",
											"|g",
											"|l",
											"|c"
											};
	int				word_nb = sizeof(tab) / (BUFF_SMALL * sizeof(char));
	int				i, len;
	static	int		word_size[BUFF_SMALL];
	static	int		init = 1;

	if (init && !(init = 0))
		init_word_size(word_size, tab, word_nb);
	i = 0;
	print_word_and_size(word_size, tab, word_nb);
	while (i < word_nb)
	{
//		printf("%s", &(tab[i][0]));
		strncpy(buff, &(tab[i][0]), word_size[i]);
		f2(buff_beg, buff + word_size[i]);
		i++;
	}
}




void	first_try()
{
	char	buff[BUFF_LARGE + 1];

	bzero(buff, sizeof(buff));
	f1(buff, buff);
}



int	main()
{
	first_try();
	return (0);
}


//	le rendre plus modulaire
//		{fonction_end, data}

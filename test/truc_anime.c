/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc_anime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:33:35 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/17 18:10:10 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define BUFF_SMALL 32
#define BUFF_LARGE 1024

void	nope(void *nothing)
{
	printf(" 	%p", nothing);
	(void)nothing;
}

int	main()
{
	int		i, j, k;
	int		tab_len;
	char	tab[][BUFF_SMALL] = {
		"------",
		"--__--",
		"-____-",
		"______",
		"______",
		"__--__",
//		"_----_",
		"_----_",
		"------"
		};

	tab_len = sizeof(tab) / (sizeof(char) * BUFF_SMALL);
	printf("fwdfwefwef  tab_len:%d\n", tab_len);
	int	l = 0;
	while (42)
	{
		i = 0;
		while (i < tab_len)
		{
			printf("\r%s", &(tab[i][0]));
			j = 0;
			while (j < 300000)
			{
				k += j;
				j++;
			}
			i++;

		char tab_char[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int		tab_char_len = sizeof(tab_char) / (sizeof(char));
		int		id = l % tab_char_len;
		printf("%c", tab_char[id]);

	//		nope(&k);		
		}
		l++;
	}

	return (0);
}


//	comment retro ingenere la taille du buffer de printf

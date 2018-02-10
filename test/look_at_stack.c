/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 06:51:14 by fjanoty           #+#    #+#             */
/*   Updated: 2018/02/01 14:06:18 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define BUFF_SMALL 64
#define BUFF_LARGE 4096

void	test_segv_read(char *str)
{
	int	i;
	int	c;

	i = 0;
	while (i > -1)
	{
		printf("%d\n", i);
		c = str[i];
		i++;
	}
}

void	test_segv_read_revers(char *str, int *anti_offset)
{
	int	i;
	int	c;
	int	last_non_null;

	i = 0;
	last_non_null = i;
	while (i > -7000000)
	{
		if (str[i])
		{
			last_non_null = i;
			printf("last_non_null:[%d] => %d\n", last_non_null, str[i]);
		}
		else if ((i % 4096) == 0)
			printf("last_non_null:[%d] => now:{%d}\n", last_non_null, i);
		c = str[i];
		i--;
	}
	*anti_offset = -last_non_null;
}

void	test_segv_write(char *str)
{
	int	i;
	int	c;
	int	len_truc = 1472;

	i = 0;
	while (i > -1)
	{
		printf("%d\n", i);
		str[i] = 42;
		i++;
	}
}


void	*ft_membchr(void *buf_large, void *buf_small, int size_large, int size_small)
{
	char	*blarge, *bsmall;
	int	i;
	int	j;
	int	tmp;

	blarge = buf_large;
	bsmall = buf_small;
	i = 0;
	while (i < size_large)
	{
//		printf("i:%d\n", i);
		tmp = bsmall[0];
		tmp = blarge[i];
		if (blarge[i] == bsmall[0]) 
		{
			j = 0;
			while ((i +j) < size_large && j < size_small && blarge[i + j] == bsmall[j])
				j++;
			if (j == size_small)
				return (blarge + i);
		}
		i++;
	}
	return (NULL);
}

char	*get_rand_str()
{
	int				i;
	int				len;
	static	char	buff[BUFF_SMALL];

	len = sizeof(buff) / sizeof(char);
	sranddev();
	i = 0;
	while (i < (len - 1))
	{
	//	buff[i] = (rand() % 96) + 32; // pour n'avoir que des caractere imprimable
		buff[i] = ((unsigned long)rand() % 96) + 32; // pour n'avoir que des caractere imprimable
	//	printf("%c\n", buff[i]);
		i++;
	}
	memset(buff, '=', 3);
	memset(buff + (BUFF_SMALL - 4), '=', 3);
	buff[len] = '\0';
	return (buff);
}

void	f3(char *str)
{
	long 	c, i, j;
	char	*b1, *b2, *bb1;
	long	bb1_len;
	long	len_read = 9967;
	char	trg1[32] = "executable";
	char	trg2[32] = "path";
	char	*tmp;
	char	target[BUFF_LARGE];
	long	befor = 0;
	long	z;
	int		anti_offset;
	long	toto;

	bzero(target, sizeof(target));
	tmp = str;
	b1 = &z;
	memmove(target, tmp, strlen(tmp));
	test_segv_read_revers(b1, &anti_offset);

	anti_offset /= 4;

	bb1 = b1 - anti_offset + 1;
	bb1_len = len_read + anti_offset - 1;
	

//	test_segv_read(b1);
//	exit(0);
	
	char	line[BUFF_LARGE];
	long	line_len;
	i = 0;
	sprintf(line, "\n\n\n                                  ====================  PRESS ANY KEY [%2d] ======================\n\n\n\n", i);
	line_len = strlen(line);
	while (i < 16)
	{
		write(1, bb1, bb1_len);
		sprintf(line, "\n\n\n                                  ====================  PRESS ANY KEY [%2d] ======================\n\n\n\n", i);
		write(1, line, line_len);
		read(0, &toto, 1);
		i++;
	}


//	test_segv_read(b1);
//	test_segv_write(b1);
	b2 = ft_membchr(b1, tmp, len_read, strlen(tmp));
	printf("\n\n-------------------->%d\n\n\n", anti_offset);
	write(1, b1 - anti_offset, len_read + anti_offset);
	printf("\n==============================================================================================\n");
	printf(" len_read:%ld  looking for:  -->%s<---\n", len_read, tmp);
	printf("==============================================================================================\n");
	if (b2)
		write(1, b2, (len_read - (b2 - b1)));
	
}

void	f2(char *str)
{
	f3(str);
}

void	f1(char *str)
{
	char	*truc1;
	int		ouii;
	char	buff1[BUFF_SMALL];

	f2(str);
	bzero(buff1, sizeof(buff1));
}

int	main()
{
	char	buff[BUFF_SMALL + 1];

	f1(get_rand_str());
//	f3("executable");
	return (0);
}


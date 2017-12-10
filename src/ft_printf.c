/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:14:45 by fjanoty           #+#    #+#             */
/*   Updated: 2017/12/10 08:42:36 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid_percent(char *format, int *indice)
{
	// next_type = (rien, qulifieur, pourcent)
}

/*
d, i ,o, u,
x, X,
e, E,
f, F,
g, G,
a, A,
c,
s,
C,
S,
p,
n,
m,
%

================
d, i ,o, u, x, X, e, E, f, F, g, G, a, A, c, s, C, S, p, n, m, %

*/

//  key, name,{values, ...}


int		is_adapteur(unsigned char c)
{
	static	int		begin = 1;
	static	char	init[] = "0123456789hlLqjzt+-. *$#";
	static	char 	tab[256];
	int	i;

	if (begin)
	{
		begin = 0;
		ft_bzero(init, sizeof(init))
		i = 0;
		while (init[i])
		{
			tab[init[i]] = 1;
			i++;
		}
	}
	return (tab[c]);
}

//int		is_adapteur(unsigned char c)
int		is_type(unsigned char c)
{
	static	int		begin = 1;
	static	char	init[] = "diouxXeEfFgGaAcsCSpnm%";
	static	char 	tab[256];
	int	i;

	if (begin)
	{
		begin = 0;
		ft_bzero(init, sizeof(init))
		i = 0;
		while (init[i])
		{
			tab[init[i]] = 1;
			i++;
		}
	}
	return (tab[c]);
}

int		next_prct(char *format, int beg)
{
	int	i;

	i = beg;
	while (format[i] && format[i] != '%')
		i++;
	if (!format[i])
		return (0);
	return (i);
}

int		next_type(char *format, int beg)
{
	int	i;

	i = beg;
	while (format[i] && is_adapteur(format[i]))
		i++;
	if (!format[i])
		return (0);
	return (i);
}

void	count_arg(char *format, t_format_mem *mem)
{
	int	i;
	int	j;

	i = 0;
	mem->ac = 0;
	mem->sc = 0;
	while (format[i])
	{
		if (format[i] == '%') // quand on trouve un indicateur d'insertion
		{
			j = i + 1;
			while (!is_converteur(format[j])) // tan qu'on est pas un truc, mais qu'on a des carater modifieur
				j++;
			if (format[j])	// si on a un type
			{
				if (format[j] != '%') // si c'est pas rien
					mem->ac++;
				mem->sc++;		// on a quand meme un segment de truc
				i = j + 1;
			}
			// si il n'y a rien, on fait rien, mais ca sera uen chaine quand meme
		}
		i++;
	}
}

int	set_str_qualifier(char *format, char **qualifier, int ac)
{
	int	i;
	int	j;
	int	sum;

	i = 0;
	sum = 0;
	while (format[i])
	{
		if (format[i] == '%') // quand on trouve un indicateur d'insertion
		{
			j = i + 1;
			while (!is_converteur(format[j])) // tan qu'on est pas un truc, mais qu'on a des carater modifieur
				j++;
			if (format[j])	// si on a un type
			{
				if (format[j] != '%') // si c'est pas rien
				{
					qualifier
				}
				i = j + 1;
			}
		}
		i++;
	}
}

void	get_value(va_list ap, t_format_mem *mem)
{
	int		i;

	i = 0;
	while (i < mem->ac)
	{
		mem->data[i] = va_arg(ap, long);
		i++;
	}
	return (arg_data);
}


//	nb_segment_formate	:: %%	inclue
//	nb_argumen	t		:: %%	EXCLUT
//	
//	Les segment formater %% 

//	==	type | quantifieur/precision | minimum_size | char_empti | left_justified | base
//---------------------------------------------------------------------------------
//	::	[d, f]  | (d):cast / (f):.nb | 		nb		|	['0', ' ']		 | 		[0, 1]		  |  nb[2, 8, 10, 16, e]?

void	set_statment(t_format_mem *mem, int i, int type, int prct)
{
	mem->txt[i + 1] = mem->format + type + 1;		// on enregistre le debut de la chaine en brute suivante
	mem->qual[i] = mem->format + prct + 1;			// debut du qualifier
	mem->type[i] = mem->format[type]; 					// could be %
	mem->format[type] = '\0';
	mem->format[prct] = '\0';
}

int		set_mem(t_format_mem *mem)
{
	int	i;
	int	prct;
	int	type;
	int	id_data;

	if (!(mem->qual = malloc(sizeof(char*) * (mem->sc + 1)))
		|| !(mem->txt = malloc(sizeof(char*) * (mem->sc + 2)))
		|| !(mem->type = malloc(sizeof(char) * (mem->sc + 1)))
		|| !(mem->data = malloc(sizeof(long) * (mem->ac + 1))))
		return (0);
// TODO:	il faudrait sois metre toute les derniere valeur a 0
// soit allouer un de moins, soit... la vie
	i = 0;
	type = -1;
	id_data	= 0;
	mem->txt[0] = mem->format;
	while (i < mem->as)
	{
		if (!(prct = next_prct(mem->format, type + 1))
			|| !(type = next_type(mem->format prct + 1)))
			break ; // on aurra peuetre rien a faire				// if !type --> end of truc... possible
		set_statment(mem, i, type, prct); 							// on delocalise de l'initialisation
		mem->id_data[i] = (mem->type[i] != '%') ? id_data++ : -1; 	// -1 equal to no variable is linked
		i++;
	}
	return (1);
}

// text
// type
// 

int	ft_printf_end(t_format_mem *mem)
{
	free(mem->qual);
	free(mem->txt);
	free(mem->type);
	free(mem->format);
	free(mem->data);
	free(mem->id_data);
	free(mem->param);
}

int		is_adapteur(unsigned char c);
int		is_type(unsigned char c);

int	ft_printf(const char *format, ...)
{
	va_list			ap;				// variable variadique
	t_format_mem	mem;

	if (!(mem.format = ft_strdup(format)))
			return (-1);
	count_arg(mem.format, &mem);		// on conte le nombre de segment et argc
	set_mem(&mem);								// on alloue la memoir et on initialise les tableau et tout et tout`
///		----------------------------	
	ap = va_start(ap, format);
	get_value(ap, &mem);					// on recupere les valeur et on les met dans les index coresspondant au argument
	va_end(ap);
///		----------------------------	
		/* on parse chaque qualfieur*/	
///		----------------------------	
		/* on construit tout les bout de chaine*/
///		----------------------------	
		/* on push alterniativement: brute/genere/brute/genere...*/
///		----------------------------	
	ft_printf_end(mem);
	return (0);
}

//	va_list		ap_copy = va_copy(ap, ap_copy);
//	va_end(ap_copy);

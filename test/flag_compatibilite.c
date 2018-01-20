/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_compatibilite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:39:13 by fjanoty           #+#    #+#             */
/*   Updated: 2018/01/17 20:45:28 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


void	test_flag_compatibiliti()
{
	int					i ;
	long				l ;
	unsigned	int		ui;
	unsigned	long	ul;

	printf("%d", i );
	printf("%d", l );
	printf("%d", ui);
	printf("%d", ul);
printf("-\n");
	printf("%qd", i );
	printf("%qd", l );
	printf("%qd", ui);
	printf("%qd", ul);
printf("-\n");
	printf("%jd", i );
	printf("%jd", l );
	printf("%jd", ui);
	printf("%jd", ul);
printf("-\n");
	printf("%zd", i );
	printf("%zd", l );
	printf("%zd", ui);
	printf("%zd", ul);
printf("-\n");
printf("-\n");
	printf("%qld", i );
	printf("%qld", l );
	printf("%qld", ui);
	printf("%qld", ul);
printf("-\n");
	printf("%jld", i );
	printf("%jld", l );
	printf("%jld", ui);
	printf("%jld", ul);
printf("-\n");
	printf("%zld", i );
	printf("%zld", l );
	printf("%zld", ui);
	printf("%zld", ul);
printf("-\n");
}

int	main()
{
	return (0);
}


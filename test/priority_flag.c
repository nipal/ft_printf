#include <stdio.h>


void	flag_priority()
{
	int	a = 4242;

	printf("%d\n", a);
	printf("%+d\n", a);
	printf("% d\n", a);
	printf("%+ d\n", a);
	printf("% +d\n", a);
}

int	main()
{
	flag_priority();
	return (0);
}

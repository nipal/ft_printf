#include <stdio.h>

void	parse_error()
{
	int	nb = 42;

	printf("----% d____%d\n", nb);
	printf("----%+-0 d____%d\n", nb);
	printf("----%l+-0 d____%d\n", nb);
	printf("----%+-0k d____%d\n", nb);
	printf("----%l,+-0 d____%d\n", nb);
	printf("===========\n");
	printf("----% %d____%d\n", nb);
	printf("----%+-0 d_%___%d\n", nb);
	printf("----%l+-0 d____%d\n", nb);
	printf("->--%+- 0k% d____%d\n", nb);
	printf("->--%+- 0kk% d____%d\n", nb);
	printf("->--%,+- 0k% d____%d\n", nb);
	printf("->--%.+- 0kk% d____%d\n", nb);
	printf("----%l,+-0 d____%d\n", nb);

	
}

// il y a plusieurs comportement different entre linux et mac

int	main()
{
	parse_error();
	return (0);
}

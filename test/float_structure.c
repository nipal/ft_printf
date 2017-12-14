#include <stdio.h>
#define F_TO_INT *(int*)&
#define INT_TO_F *(float*)&


void	print_bit(unsigned char *data, int size)
{
	int	i;
	int	j;
	int	nb_char;
	int	id;
	char	*str;

	nb_char = (size * 8);
	if (!(str = malloc(((nb_char) + 1) * sizeof(char))))
		return ;
	str[(size * 8)] = '\0';
	j = size - 1;
	while (j >= 0)
	{
		i = 7;
		while (i >= 0)
		{
			id = (7 - i) + ((size - 1 - j) * 8);
			str[id] = (data[j] & (1 << i)) ? '1' : '0';
			i--;
		}
		j--;
	}
	printf("%s\n", str);
	free(str);
/**/}

void	print_bit_str(unsigned char *data, int size, char *s)
{
	int	i;
	int	j;
	int	nb_char;
	int	id;
	char	*str;

	nb_char = (size * 8);
	if (!(str = malloc(((nb_char) + 1) * sizeof(char))))
		return ;
	str[(size * 8)] = '\0';
	j = size - 1;
	while (j >= 0)
	{
		i = 7;
		while (i >= 0)
		{
			id = (7 - i) + ((size - 1 - j) * 8);
			str[id] = (data[j] & (1 << i)) ? '1' : '0';
			i--;
		}
		j--;
	}
	printf("%s%s\n", s, str);
	free(str);
/**/}

void	print_float_str(float f, char *s)
{
	int	i;
	int	j;
	int	data;
	int	nb_char;
	int	id;
	int	a, b, c;
	char	*str;

	data = *(int*)(&f);
	if (!(str = malloc((35) * sizeof(char))))
		return ;
	str[34] = '\0';
	i = 31;
	id = 0;
	while (i >= 0)
	{
		str[id] = (data & (1 << i)) ? '1' : '0';
		if (id == 0 || id == 9)
			str[++id] = '|';
		id++;
		i--;
	}
	printf("%s%s|%10.60f\n", s, str, f);// 									   v0x8FFFFFFF
	c = (data & (1 << 31))? '-' : '+';
	a = ((data & (((1 << 31) - 1))) >> 23);
	a = ((a) % 256) - 127;
	b = (data & ((1 << 23) - 1));
	printf("%s%c|% 8hhd|% 23d|\n", "\t", c, a, b);
	free(str);
}

void	float_structure()
{
	float	inf, f, f0, f1, f2, f3, fa, fb, fc, ff1, ff2, ff3;
	
	ff1 = 1.0 / (float)(1 << 1);
	ff2 = 1.0 / (float)(1 << 2);
	ff3 = 1.0 / (float)(1 << 3);
	inf = 1.0 / 0.0 ;// set +inf value 
	f0 = 0.0;
	f1 = 1.0;
	f2 = 2.0;
	f3 = 4.0;
	*(int*)&fa = (100) << 23;
	*(int*)&fb = (127 + 23) << 23;
	*(int*)&fc = (127 + 24) << 23;

	*(int*)&f = ((*(int*)&f0) | 1);

	// 2 ^ (a - 127) + (b * 2 ^ ((a - 127) - 23))

//	1 + 8 + 23:
//	print_bit_str(&inf, 4, "inf:	");
//	print_bit_str(&f1, 4, "f1:	");
//	print_bit_str(&f2, 4, "f2:	");
//	print_bit_str(&f3, 4, "f3:	");
//	print_float_str(inf, "inf:	");
	print_float_str(f0, "f0:	");
	print_float_str(f, "f0*:	");

	print_float_str(f1, "f1:	");
	*(int*)&f = ((*(int*)&f1) | 1);
	print_float_str(f, "f1*:	");

	print_float_str(f2, "f2:	");
	*(int*)&f = ((*(int*)&f2) | 1);
	print_float_str(f, "f2*:	");

	print_float_str(f3, "f3:	");
	*(int*)&f = ((*(int*)&f3) | 1);
	print_float_str(f, "f3*:	");

	print_float_str(fa, "fa:	");
	*(int*)&f = ((*(int*)&fa) | 1);
	print_float_str(f, "fa*:	");

	print_float_str(fb, "fb:	");
	*(int*)&f = ((*(int*)&fb) | 1);
	print_float_str(f, "fb*:	");

	print_float_str(fc, "fc:	");
	*(int*)&f = ((*(int*)&fc) | 1);
	print_float_str(f, "fc*:	");

	print_float_str(ff1, "ff1:	");
	*(int*)&f = ((*(int*)&ff1) | 1);
	print_float_str(f, "ff1*:	");

	print_float_str(ff2, "ff2:	");
	*(int*)&f = ((*(int*)&ff2) | 1);
	print_float_str(f, "ff2*:	");

	print_float_str(ff3, "ff3:	");
	*(int*)&f = ((*(int*)&ff3) | 1);
	print_float_str(f, "ff3*:	");


}

//	x * (2^b) = x * 10^b / 5^b
//	x / (2^b) = x * 5^b  / 10^b
__int128	pow_5(int pow)
{
	__int128	val;

	if (pow & 1)
		return (5 * pow_5(pow - 1));
	if (!pow)
		return (1);
	val = pow_5(pow / 2);
	return (val * val);
}

void	all_pow_5()
{
	int	i;
	__int128	val;

	i = 0;
	while (i < 30)
	{
		val = pow_5(i);
		printf("%ld		%.15f\n", val, 1.0 / (float)(1 << i));
		i++;
	}
}

__int128	pow_conv(__int128 val, int pow)
{
	__int128	a, b;
	
	//		

	if (pow > 0)
		b = (__int128)val << pow; //
	else
	{
//		printf(".......pow..>%d\n", pow);
//		printf("\n%ld	pow:%d\n", (long)pow_5(-pow), -pow);
		return (val * pow_5(-pow));	// * 1/2^-pow
	}
}



void	copie_float(float f)
{
	char		buff[255];
	int			ret;
	int			value;
	int			a;
	int			b;
	int			sign;
	char		sign_c;
	__int128	val;
	
	int			pow;
	__int128	data, d1, d2;


	printf("---------------------------\n");

	value = F_TO_INT f;
	a = (value >> 23) & 0xFF;
	b = value & ((1 << 23) - 1);
	sign = (f > 0.0) ? 1: -1;
	sign_c = (f > 0.0) ? '+': '-';
	
	pow = a - 127;
	val =  pow_conv(b, pow - 23);
	int	space = -(pow - 23);
	printf("%10d::\r%0*1$lld----<<\n", space + 20, val);

	val = pow_conv(1, pow);
	printf("%d\r%0*1$lld\n", 20 + ((pow < 0) ? -pow: 0), val);

//	------------------------------
	printf("sign:% 4c| a:% 5d| b:% 20d|val:%58d	\n",sign_c, a, b, value);
	print_float_str(f, "->	");
	// 2 ^ (a - 127) + (b * 2 ^ ((a - 127) - 23))
	// 2 ^ (pow) + (b * 2 ^ (pow - 23))

//	d1 = ;
//	data = 
}

float	float_add_mantis(float val, int add)
{
	int	value;

	value = F_TO_INT val;
	value += add;
	return (INT_TO_F value);
}

float	construct_float(int sign, int a, int b)
{
	int	val;

	val = (!!(sign) << 31) | ((a & ((1 << 8) - 1)) << 23) | (b & ((1 << 23) - 1));
	return (INT_TO_F val);
}



void	copie_float_test()
{
//	copie_float(float_add_mantis(1.000, 10));
//	copie_float(float_add_mantis(1.000, 9));
//	copie_float(float_add_mantis(1.000, 8));
//	copie_float(float_add_mantis(2.0, 1));
//	copie_float(float_add_mantis(4096.0, 1));
//	copie_float(float_add_mantis(4096.0 * 2, 1));
//	copie_float(float_add_mantis(1., 1));

//	copie_float(float_add_mantis(0.0, 1));
//	copie_float(float_add_mantis(0.125, 1));
//	copie_float(float_add_mantis(0.5, 0));
//	copie_float(float_add_mantis(1024., 13));

	copie_float(construct_float(0, 121, 6));
	copie_float(construct_float(0, 121, 5));
	copie_float(construct_float(0, 121, 4));
	copie_float(construct_float(0, 121, 3));
	copie_float(construct_float(0, 121, 2));
	copie_float(construct_float(0, 121, 1));
//	copie_float(construct_float(0, 126, 1));
//	copie_float(construct_float(0, 127, 1));
//	copie_float(construct_float(0, 128, 1));
//	copie_float(construct_float(0, 128, 13));
}

int	main()
{
	//float_structure();
	copie_float_test();
//	all_pow_5();
	return (0);
}

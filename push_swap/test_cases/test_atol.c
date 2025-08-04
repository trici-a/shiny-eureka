#include "push_swap.h"
#include "libft.h"
#include <stdio.h>
#include <limits.h>

//Comment out Int main in header file
/*
Compile:
	ccc -Iinclude -Ilibft srcs/utils.c srcs/free.c test_cases/test_atol.c -o test
	*/
int main()
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;

	char	str[13] = "Hello World!";
	char	str2[11] = "    	1234";
	char	str3[11] = "    	+1234";
	char	str4[11] = "    	-1234";
	char	str5[12] = "-2147483648";
	char	str6[12] = "2147483647";
	char	str7[12] = "-2147483649";
	char	str8[12] = "2147483649";

	printf("%d\n", INT_MIN);
	printf("%d\n", INT_MAX);

	printf("Hello World!\t: %ld\n", ft_atol(str, &stack));
	printf("    	1234\t: %ld\n", ft_atol(str2, &stack));
	printf("    	+1234\t: %ld\n", ft_atol(str3, &stack));
	printf("    	-1234\t: %ld\n", ft_atol(str4, &stack));
	printf("INT_MIN\t\t: %ld\n", ft_atol(str5, &stack));
	printf("INT_MAX\t\t: %ld\n", ft_atol(str6, &stack));
	printf("<INT_MIN\t:");
	printf("%ld\n", ft_atol(str7, &stack));
	printf("<INT_MAX\t:");
	printf("%ld\n", ft_atol(str8, &stack));
	return (0);
}
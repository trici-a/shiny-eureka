#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

//Comment out the other functions in utils.c and int main in header file
/* ccc -Iinclude -Ilibft srcs/utils.c test_cases/test_isnum.c -o test */
int main()
{
	char	str[20] = "Hello World1234";
	char	str2[20] = "1234";
	char	str3[20] = "-1234";
	char	str4[20] = "1234Hello World";
	char	str5[20] = "12 34";
	char	str6[20] = "12+34";
	char	str7[20] = "Hello World";

	printf("%d\n", is_number(str));
	printf("%d\n", is_number(str2));
	printf("%d\n", is_number(str3));
	printf("%d\n", is_number(str4));
	printf("%d\n", is_number(str5));
	printf("%d\n", is_number(str6));
	printf("%d\n", is_number(str7));
}
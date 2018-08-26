#include "ft_printf.h"

int main()
{
	ft_printf("%14o\n", 45);
	printf("%14o\n", 45);
	ft_printf("%014o\n", 45);
	printf("%014o\n", 45);
	ft_printf("%#14o\n", 45);
	printf("%#14o\n", 45);
	ft_printf("%#014o\n", 45);
	printf("%#014o\n", 45);
	ft_printf("%-14o\n", 45);
	printf("%-14o\n", 45);
	ft_printf("%-#14o\n", 45);
	printf("%-#14o\n\n", 45);

	ft_printf("%14o\n", -45);
	printf("%14o\n", -45);
	ft_printf("%014o\n", -45);
	printf("%014o\n", -45);
	ft_printf("%#14o\n", -45);
	printf("%#14o\n", -45);
	ft_printf("%#014o\n", -45);
	printf("%#014o\n", -45);
	ft_printf("%-14o\n", -45);
	printf("%-14o\n", -45);
	ft_printf("%-#14o\n", -45);
	printf("%-#14o\n\n", -45);;

	ft_printf("%o\n", 45);
	printf("%o\n", 45);
    ft_printf("%12.o\n", 45);
	printf("%12.o\n", 45);
	ft_printf("%12.1o\n", -45);
	printf("%12.1o\n", -45);
	ft_printf("%1.3o\n", 45);
	printf("%1.3o\n", 45);
	ft_printf("%1.3o\n", -45);
	printf("%1.3o\n", -45);
	return (0);
}
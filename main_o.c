#include "ft_printf.h"

int main()
{
	foo("%14o\n", 45);
	printf("%14o\n", 45);
	foo("%014o\n", 45);
	printf("%014o\n", 45);
	foo("%#14o\n", 45);
	printf("%#14o\n", 45);
	foo("%#014o\n", 45);
	printf("%#014o\n", 45);
	foo("%-14o\n", 45);
	printf("%-14o\n", 45);
	foo("%-#14o\n", 45);
	printf("%-#14o\n\n", 45);

	foo("%14o\n", -45);
	printf("%14o\n", -45);
	foo("%014o\n", -45);
	printf("%014o\n", -45);
	foo("%#14o\n", -45);
	printf("%#14o\n", -45);
	foo("%#014o\n", -45);
	printf("%#014o\n", -45);
	foo("%-14o\n", -45);
	printf("%-14o\n", -45);
	foo("%-#14o\n", -45);
	printf("%-#14o\n\n", -45);

	foo("%o\n", 45);
	printf("%o\n", 45);
    foo("%12.o\n", 45);
	printf("%12.o\n", 45);
	foo("%12.1o\n", -45);
	printf("%12.1o\n", -45);
	foo("%1.3o\n", 45);
	printf("%1.3o\n", 45);
	foo("%1.3o\n", -45);
	printf("%1.3o\n", -45);
	return (0);
}
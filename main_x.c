#include "ft_printf.h"

int main()
{
	foo("%14X\n", 45);
	printf("%14X\n", 45);
	foo("%014X\n", 45);
	printf("%014X\n", 45);
	foo("%#14X\n", 45);
	printf("%#14X\n", 45);
	foo("%#014X\n", 45);
	printf("%#014X\n", 45);
	foo("%-14X\n", 45);
	printf("%-14X\n", 45);
	foo("%-#14X\n", 45);
	printf("%-#14X\n\n", 45);

	foo("%14X\n", -45);
	printf("%14X\n", -45);
	foo("%014X\n", -45);
	printf("%014X\n", -45);
	foo("%#14X\n", -45);
	printf("%#14X\n", -45);
	foo("%#014X\n", -45);
	printf("%#014X\n", -45);
	foo("%-14X\n", -45);
	printf("%-14X\n", -45);
	foo("%-#14X\n", -45);
	printf("%-#14X\n\n", -45);


	foo("%X\n", 45);
	printf("%X\n", 45);
    foo("%12.X\n", 45);
	printf("%12.X\n", 45);
	foo("%12.1X\n", -45);
	printf("%12.1X\n", -45);
	foo("%1.3X\n", 45);
	printf("%1.3X\n", 45);
	foo("%1.3X\n", -45);
	printf("%1.3X\n", -45);
	return (0);
}
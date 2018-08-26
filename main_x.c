#include "ft_printf.h"

int main()
{
	foo("%14lx\n", 45);
	printf("%14lx\n", 45);
	foo("%014lx\n", 45);
	printf("%014lx\n", 45);
	foo("%#14lx\n", 45);
	printf("%#14lx\n", 45);
	foo("%#014lx\n", 45);
	printf("%#014lx\n", 45);
	foo("%-14lx\n", 45);
	printf("%-14lx\n", 45);
	foo("%-#14lx\n", 45);
	printf("%-#14lx\n\n", 45);

	foo("%14lx\n", -45);
	printf("%14lx\n", -45);
	foo("%014lx\n", -45);
	printf("%014lx\n", -45);
	foo("%#14lx\n", -45);
	printf("%#14lx\n", -45);
	foo("%#014lx\n", -45);
	printf("%#014lx\n", -45);
	foo("%-14lx\n", -45);
	printf("%-14lx\n", -45);
	foo("%-#14lx\n", -45);
	printf("%-#14lx\n\n", -45);


	foo("%lx\n", 45);
	printf("%lx\n", 45);
    foo("%12.lx\n", 45);
	printf("%12.lx\n", 45);
	foo("%12.1lx\n", -45);
	printf("%12.1lx\n", -45);
	foo("%1.3lx\n", 45);
	printf("%1.3lx\n", 45);
	foo("%1.3lx\n", -45);
	printf("%1.3lx\n", -45);
	return (0);
}
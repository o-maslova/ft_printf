#include "ft_printf.h"

int main()
{
	foo("%14u\n", 45);
	printf("%14u\n", 45);
	foo("%014u\n", 45);
	printf("%014u\n", 45);
	foo("%-14u\n", 45);
	printf("%-14u\n\n", 45);

	foo("%14u\n", -45);
	printf("%14u\n", -45);
	foo("%014u\n", -45);
	printf("%014u\n", -45);
	foo("%-14u\n", -45);
	printf("%-14u\n\n", -45);

	foo("%u\n", 45);
	printf("%u\n", 45);
	foo("%u\n", -45);
	printf("%u\n", -45);
	foo("%-14.4u\n", 45);
	printf("%-14.4u\n", 45);
	foo("%18.4u\n", -45);
	printf("%18.4u\n", -45);
	foo("%1.3u\n", 45);
	printf("%1.3u\n", 45);
	foo("%1.3u\n", -45);
	printf("%1.3u\n", -45);
	return (0);
}
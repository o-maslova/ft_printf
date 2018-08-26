#include "ft_printf.h"

int main()
{
	foo("%14U\n", 45);
	printf("%14U\n", 45);
	foo("%014U\n", 45);
	printf("%014U\n", 45);
	foo("%-14U\n", 45);
	printf("%-14U\n\n", 45);

	foo("%14U\n", -45);
	printf("%14U\n", -45);
	foo("%014U\n", -45);
	printf("%014U\n", -45);
	foo("%-14U\n", -45);
	printf("%-14U\n\n", -45);

	foo("%U\n", 45);
	printf("%U\n", 45);
	foo("%U\n", -45);
	printf("%U\n", -45);
	foo("%-14.4U\n", 45);
	printf("%-14.4U\n", 45);
	foo("%18.4U\n", -45);
	printf("%18.4U\n", -45);
	foo("%1.3U\n", 45);
	printf("%1.3U\n", 45);
	foo("%1.3U\n", -45);
	printf("%1.3U\n", -45);
	return (0);
}

#include "ft_printf.h"

int main()
{
	foo("%14c\n", 's');
	printf("%14c\n", 's');
	// foo("%014c\n", 's');
	// printf("%014c\n", 's');
	foo("%-14c\n", 's');
	printf("%-14c\n\n", 's');

	// foo("%014c\n", 's');
	// printf("%014c\n", 's');
	foo("%-14c\n", 's');
	printf("%-14c\n\n", 's');

	foo("%c\n", 's');
	printf("%c\n", 's');
	// foo("%-14.4c\n", 's');
	// printf("%-14.4c\n", 's');
	// foo("%18.4c\n", 's');
	// printf("%18.4c\n", 's');
	// foo("%1.3c\n", 's');
	// printf("%1.3c\n", 's');
	// foo("%1.3c\n", 's');
	// printf("%1.3c\n", 's');
	return (0);
}

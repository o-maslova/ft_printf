#include "ft_printf.h"

int main()
{
    int ptr;

    // ptr = NULL;
    ptr = -45;

    foo("%12p\n",&ptr);
	printf("%12p\n", &ptr);
	foo("%12p\n", &ptr);
	printf("%12p\n", &ptr);
	foo("%12p\n", &ptr);
	printf("%12p\n", &ptr);
	foo("%12p\n", &ptr);
	printf("%12p\n", &ptr);
	foo("%12p\n", &ptr);
	printf("%12p\n", &ptr);
	foo("%-12p\n", &ptr);
	printf("%-12p\n", &ptr);
	foo("%-12p\n", &ptr);
	printf("%-12p\n", &ptr);
	foo("%-12p\n", &ptr);
	printf("%-12p\n\n", &ptr);

	foo("%*.p\n", 12, &ptr);
    printf("%*.p\n", 12, &ptr);

	foo("U Mashi %-12p yabllok, a u Sashi %018p yablok\n", 4556, 98);
	printf("U Mashi %-12p yablok, a u Sashi %018p yablok\n", 4556, 98);

    return (0);
}
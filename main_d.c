#include "ft_printf.h"

int main()
{
	foo("%12d\n", 567);
	printf("%12d\n", 567);
	foo("%012d\n", 567);
	printf("%012d\n", 567);
	foo("% 012d\n", 567);
	printf("% 012d\n", 567);
	foo("%+12d\n", 567);
	printf("%+12d\n", 567);
	foo("%+012d\n", 567);
	printf("%+012d\n", 567);
	foo("%-12d\n", 567);
	printf("%-12d\n", 567);
	foo("%- 12d\n", 567);
	printf("%- 12d\n", 567);
	foo("%-+12d\n", 567);
	printf("%-+12d\n\n", 567);

	foo("%12d\n", -45);
	printf("%12d\n", -45);
	foo("%012d\n", -45);
	printf("%012d\n", -45);
	foo("% 012d\n", -45);
	printf("% 012d\n", -45);
	foo("%+12d\n", -45);
	printf("%+12d\n", -45);
	foo("%+012d\n", -45);
	printf("%+012d\n", -45);
	foo("%-12d\n", -45);
	printf("%-12d\n", -45);
	foo("%- 12d\n", -45);
	printf("%- 12d\n", -45);
	foo("%-+12d\n", -45);
	printf("%-+12d\n\n\n", -45);

	foo("%12ld\n", -45);
	printf("%12ld\n", -45);
	foo("%012ld\n", -45);
	printf("%012ld\n", -45);
	foo("% 012ld\n", -45);
	printf("% 012ld\n", -45);
	foo("%+12ld\n", -45);
	printf("%+12ld\n", -45);                                                                                                                                                                                                                                                                   
	foo("%+012ld\n", -45);
	printf("%+012ld\n", -45);
	foo("%-12ld\n", -45);
	printf("%-12ld\n", -45);
	foo("%- 12ld\n", -45);
	printf("%- 12ld\n", -45);
	foo("%-+12ld\n", -45);
	printf("%-+12ld\n\n\n", -45);

	// foo("%d\n", 45);
	// printf("%d\n", 45);
	// foo("%-12.4d\n", -45);
	// printf("%-12.4d\n", -45);
	// foo("%1.3d\n", 45);
	// printf("%1.3d\n", 45);
	// foo("%1.3d\n", -45);
	// printf("%1.3d\n\n", -45);

	// foo("%*.d\n", 12, -45);
    // printf("%*.d\n", 12, -45);

	// foo("U Mashi %-12d yabllok, a u Sashi %018d yablok\n", 4556, 98);
	// printf("U Mashi %-12d yablok, a u Sashi %018d yablok\n", 4556, 98);
	return (0);
}
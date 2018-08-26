#include "ft_printf.h"

int main()
{
	foo("%25s\n", "zlobniy gnom");
	printf("%25s\n", "zlobniy gnom");
	foo("%025s\n", "zlobniy gnom");
	printf("%025s\n", "zlobniy gnom");
	foo("%-25s\n", "zlobniy gnom");
	printf("%-25s\n", "zlobniy gnom");
	foo("% 25s\n", "zlobniy gnom");
	printf("% 25s\n", "zlobniy gnom");
	foo("%25.6s\n", "zlobniy gnom");
	printf("%25.6s\n", "zlobniy gnom");
	foo("%25s\n", "zlobniy gnom");
	printf("%25s\n", "zlobniy gnom");
	foo("%*.*s -\n", 14, 4, "zlobniy gnom");
	printf("%*.*s -\n", 14, 4, "zlobniy gnom");
	return (0);
}

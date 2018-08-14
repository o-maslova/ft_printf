/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:15:50 by omaslova          #+#    #+#             */
/*   Updated: 2018/08/14 11:15:54 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	foo(char *fmt, ...)
{
	va_list ap;
	int d;
	char c, *s;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 's')
			{
				s = va_arg(ap, char *);
				printf("%s", s);
			}
			if (*fmt == 'd')
			{
				d = va_arg(ap, int);
				printf("%d", d);
			}
			if (*fmt == 'c')
			{
				c = va_arg(ap, int);
				printf("%c", c);
			}
		}
		else if (*fmt != '%')
			printf("%c", *fmt);
		fmt++;
	}
	printf("\n");
	va_end(ap);
}

int main(int argc, char **argv)
{
	int i;
	char *str;
	char *str2;

	(void)argc;
	i = 1;
	str = argv[1];
	str2 = argv[2];
	foo(str, str2);
	// while (i < argc)
	// 	foo(argv[i++]);
	return (0);
}
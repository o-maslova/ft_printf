/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalch, okosiako                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 12:24:07 by dkovalch          #+#    #+#             */
/*   Updated: 2017/03/08 15:44:12 by dkovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <locale.h>
#include <limits.h>
#include <errno.h>

#define RED "\x1b[31m"
#define NORM "\x1b[0m"

//Testing macro - dont change!
#define PRINTF(...){\
		int ret = 0,ret2 = 0;\
		printf("Args:\t%s\n", #__VA_ARGS__);\
		printf("Origin:\t");ret = printf(__VA_ARGS__);\
		printf("\tret: %d\n",ret);fflush(stdout);\
		ft_printf("    Ft:\t");ret2 = ft_printf(__VA_ARGS__);\
		printf("\t%sret: %d"NORM"\n",(ret == ret2) ? NORM : RED, ret2);\
		printf("\n");fflush(stdout);\
}
#define TITLE(...){printf("\033[1m\n");printf(__VA_ARGS__);printf("\n\033[0m");}

//Include your printf here!
#include "printf.h"

//Test switchers - comment some of then to turn the tests off
#define	CHAR		//aka chars
#define	PER			//aka percent(%)
#define	NUM			//aka numbers
#define	PTR			//aka pointers
#define	STRANGE		//aka undefined tests
#define STR			//aka strings
#define WSTR		//aka wide strings
#define	LENGTH		//aka hh, h, l ,ll , z, j

int	main(void)
{
	setlocale(LC_CTYPE, "");
#ifdef CHAR
	TITLE("Char options:\n");
	{
	char a = ' ';
	for (a = ' '; a <' ' + 60 ; a+=15)
	PRINTF("|%-2c|(%3d)\t|%-2c|(%3d)\t|%-2c|(%3d)", a, a, a+5,a+5,a+10,a+10);
	PRINTF("|%-2.3c|(%3d)\t|%-2.5c|(%3d)\t|%-2.0c|(%3d)", a, a, a+5,a+5,a+10,a+10);
	PRINTF("|%+3c|(%3d)\t|%+3c|(%3d)\t|%+c|(%3d)", a, a, a+5, a+5, a+10, a+10);
	PRINTF("|%3.4c|(%3d)\t|%+3.4c|(%3d)\t|%.4c|(%3d)", a, a, a+5, a+5, a+10, a+10);
	PRINTF("|%-3w|(%3w)\t|%3Z|(%3Z)\t|%Q|(%3Q)");
	PRINTF("|%3h|\t|%3l|\t|%3hhll|\t|%3llhhllQ|\t|%3z|\t|%3j|\t|%3J|");
	PRINTF("|%-3c|\t|%3c|\t|%c|\t|%-03c|\t|%03c|\t|%.c|\t|%.5c|\t|%.C|\t|%.5C|", 0,0,0,0,0,0,0,0,0);
	}
#endif

#ifdef PER
	TITLE("Percent options:\n");
	PRINTF("|%-6%|   |%6%|   |%6.2%|   |%-06%|   |%-06.3%|");
#endif
	
#ifdef STR
	TITLE("Strings:\n");
	PRINTF("|%s|", NULL);
	PRINTF("|%s|", "ПрэвЭд!");
	PRINTF("|%s|\t","ç±³");
	TITLE("String options(field width, presicion and justification):\n");
	{
	const char A[] = "this is tEEEEst!";
	PRINTF("|%5.3s|\t\t|%3.5s|\t|%7s|\t|%7.3s|",A, A,A,NULL);
	PRINTF("|%07.5s|\t|%02.5s|\t|%.10s|\t\t|%.5s|\t",A,A,A, "");
	PRINTF("|%-7.5s|\t|%-2.5s|\t|%-.10s|\t\t|%-.5s|\t",A,A,A, "");
	PRINTF("|%-07.5s|\t|%-02.5s|\t|%-020s|\t|%-0.5s|\t",A,A,A, "");
	}
#endif

#ifdef WSTR
	TITLE("Wide string options:\n");
	PRINTF("|%S|\t|%S|\t|%C|\t|%S|",L"Wide sample string..",L"米",L'米',L"");
	PRINTF("|%S|  |%S|\t|%S|",L"বিড়াল এবং খাওয়া তিমি ঘুঘু", L"合気道",L"ድመቶች ሰዎች አልወደውም.");

//Presicions for wide strings	
	TITLE("Wide string options(field width, presicion and justification):\n");fflush(stdout);
	{
	const wchar_t B[] = L"ድመቶች ሰዎች አልወደውም.";
	PRINTF("|%5.3S|\t\t|%3.5S|\t|%7S|\t|%7.3S|",B, B,B,L"");
	PRINTF("|%.3S|\t|%2.5S|\t|%.10S|\t\t|%.5S|",B,B,B, L"");
	PRINTF("|%-7.5S|\t|%-2.5S|\t|%-.10S|\t\t|%-.5S|",B,B,B, L"");
	PRINTF("|%-07.5S|\t|%-02.5S|\t|%-020S|\t|%-0.5S|",B,B,B, L"");
	}
#endif

#ifdef PTR
	TITLE("Pointer options(field width, presicioin and justification):\n");
	{
	char *ptr_c = (char*)malloc(sizeof(char));
	int ptr_i = 43;
	long ptr_l = 874748;
	PRINTF("|%.0p|\t\t|%6p|\t\t|%6.p|\t|%10.6p|", NULL,NULL,NULL,NULL);
	PRINTF("|%12p||%17p|\t|%-22p|", ptr_c, &ptr_i, &ptr_l);
	PRINTF("|%.0p||%6p|\t|%6.p||%.20p|", &ptr_l, &ptr_l, &ptr_l,&ptr_l);
	free(ptr_c);
	}
#endif

#ifdef NUM
	TITLE("Number options(field width and justification):\n");
	printf("   |i|:\n");
	PRINTF("\t|%12i|\t|%12i|\t|%12i|", INT_MIN, INT_MAX,0);
	PRINTF("\t|%012i|\t|%-12i|\t|%012i|",-42,42,42);
	printf("\n   |d|:\n");
	PRINTF("\t|%12d|\t|%12d|\t|%12d|", INT_MIN, INT_MAX,0);
	PRINTF("\t|%012d|\t|%-12d|\t|%012d|",-42,42,42);
	printf("\n   |D|:\n");
	PRINTF("\t|%12D|\t|%12D|\t|%12D|", INT_MIN, INT_MAX,0);
	PRINTF("\t|%012D|\t|%-12D|\t|%012D|",-42,42,42);
	printf("\n   |u|:\n");
	PRINTF("\t|%12u|\t|%12u|\t|%12u|", INT_MIN, INT_MAX,0);
	PRINTF("\t|%012u|\t|%-12u|\t|%012u|",-42,42,42);
	printf("\n   |U|:\n");
	PRINTF("\t|%12U|\t|%12U|\t|%12U|", INT_MIN, INT_MAX,0);
	PRINTF("\t|%012U|\t|%-12U|\t|%012U|",-42,42,42);
	printf("\n   |o|:\n");
	PRINTF("\t|%12o|\t|%12o|\t|%12o|", INT_MIN, INT_MAX,0);
	PRINTF("\t|%012o|\t|%-12o|\t|%012o|",-42,42,42);
	printf("\n   |O|:\n");
	PRINTF("\t|%12O|\t|%12O|\t|%12O|", INT_MIN, INT_MAX,0);
	PRINTF("\t|%012O|\t|%-12O|\t|%012O|",-42,42,42);
	printf("\n   |x|:\n");
	PRINTF("\t|%12x|\t|%12x|\t|%12x|", INT_MIN, INT_MAX,0);
	PRINTF("\t|%012x|\t|%-12x|\t|%012x|",-42,42,42);
	printf("\n   |X|:\n");
	PRINTF("\t|%12X|\t|%12X|\t|%12X|", INT_MIN, INT_MAX,0);
	PRINTF("\t|%012X|\t|%-12X|\t|%012X|",-42,42,42);
	TITLE("Number options(field width, presicion and -):\n");
	{
		int nmb = 4235;
		#define CNV "i"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
	}
	{
		int nmb = 4235;
		#define CNV "d"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
	}
	{
		int nmb = 4235;
		#define CNV "D"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
		PRINTF("|%1.1"CNV"|\t|%5.1"CNV"|\t|%5.3"CNV"|\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t",0,0,0,0,0,0,0,0);
	}
	{
		int nmb = 4235;
		#define CNV "u"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
		PRINTF("|%1.1"CNV"|\t|%5.1"CNV"|\t|%5.3"CNV"|\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
	}
	{
		int nmb = 4235;
		#define CNV "U"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
		PRINTF("|%1.1"CNV"|\t|%5.1"CNV"|\t|%5.3"CNV"|\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t",0,0,0,0,0,0,0,0);
	}
	{
		int nmb = 4235;
		#define CNV "o"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
		PRINTF("|%1.1"CNV"|\t|%5.1"CNV"|\t|%5.3"CNV"|\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
	}
	{
		int nmb = 4235;
		#define CNV "O"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
		PRINTF("|%1.1"CNV"|\t|%5.1"CNV"|\t|%5.3"CNV"|\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|",0,0,0,0,0,0,0,0);
	}
	{
		int nmb = 4235;
		#define CNV "x"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
		PRINTF("|%1.1"CNV"|\t|%5.1"CNV"|\t|%5.3"CNV"|\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
	}
	{
		int nmb = 4235;
		#define CNV "X"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
		PRINTF("|%1.1"CNV"|\t|%5.1"CNV"|\t|%5.3"CNV"|\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
	}
//Flag + - 0 and space
	TITLE("Number options(field width, justification, +, space and 0):\n");	
	{
		int nmb = 42;
		#define CNV "i"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
	}
	{
		int nmb = 42;
		#define CNV "d"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
	}
	{
		int nmb = 42;
		#define CNV "D"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|\t",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
	}
	{
		int nmb = 42;
		#define CNV "u"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|\t",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
	}
	{
		int nmb = 42;
		#define CNV "U"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|\t",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
	}
	{
		int nmb = 42;
		#define CNV "o"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|\t",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
	}
	{
		int nmb = 42;
		#define CNV "O"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|\t",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
	}
	{
		int nmb = 42;
		#define CNV "x"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|\t",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
	}
	{
		int nmb = 42;
		#define CNV "X"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|\t",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
	}
//Flag # for X x and o and O and i
	TITLE("Number options(field width, presicion, justification and #):\n");
	{
		# define CNV "o"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t\t", 25,25,25,25);
	}
	{
		# define CNV "O"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t\t", 25,25,25,25);
	}
	{
		# define CNV "x"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t\t", 25,25,25,25);
	}
	{
		# define CNV "X"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t\t", 25,25,25,25);
	}
	{
		# define CNV "i"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|\t", 8400,8400,0,8400,8400);
		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|\t", 8400,8400,0,8400,8400);
		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t\t", 25,25,25,25);
	}
	{
		# define CNV "d"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|\t", 8400,8400,0,8400,8400);
		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|\t", 8400,8400,0,8400,8400);
		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t\t", 25,25,25,25);
	}
	{
		# define CNV "D"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|\t", 8400,8400,0,8400,8400);
		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|\t", 8400,8400,0,8400,8400);
		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t\t", 25,25,25,25);
	}
	{
		# define CNV "u"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|\t", 8400,8400,0,8400,8400);
		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|\t", 8400,8400,0,8400,8400);
		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t\t", 25,25,25,25);
	}
	{
		# define CNV "u"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|\t", 8400,8400,0,8400,8400);
		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|\t", 8400,8400,0,8400,8400);
		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t\t", 25,25,25,25);
	}
#endif
#ifdef LENGTH
	TITLE("Number options(field width and length modifiers):\n");
	printf("\t|%5s|\t|%5s|\t|%20s|\t|%20s|\t|%20s|\t|%10s|\t|%10s|\n", "hh", "h", "l", "ll","j", "z", "nothing" );
	{
		# define CNV "i"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,-2,LONG_MAX);
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,-2,LONG_MIN);
	}
	{
		# define CNV "d"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,-2,LONG_MAX);
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,-2,LONG_MIN);
	}
	{
		# define CNV "D"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,-2,LONG_MAX);
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,-2,LONG_MIN);
	}
	{
		# define CNV "u"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,-2,LONG_MAX);
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,-2,LONG_MIN);
	}
	{
		# define CNV "U"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,-2,LONG_MAX);
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,-2,LONG_MIN);
	}
	{
		# define CNV "o"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,-2,LONG_MAX);
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,-2,LONG_MIN);
	}
	{
		# define CNV "O"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,-2,LONG_MAX);
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,-2,LONG_MIN);
	}
	{
		# define CNV "x"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,-2,LONG_MAX);
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,-2,LONG_MIN);
	}
	{
		# define CNV "X"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,-2,LONG_MAX);
		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,-2,LONG_MIN);
	}

	TITLE("Another test\n");
	{
		# define CNV "i"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
	}
	{
		# define CNV "d"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
	}
	{
		# define CNV "d"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
	}
	{
		# define CNV "u"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
	}
	{
		# define CNV "U"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
	}	
	{
		# define CNV "x"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
	}
	{
		# define CNV "X"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
	}
	{
		# define CNV "o"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
	}
	{
		# define CNV "O"
		printf("\n   |"CNV"|:\n");
		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
	}
	TITLE("Very big number options(field width and length modifiers):\n");
	printf("\n\t\t|%22s|\t|%22s|\t|%22s|\t|%22s|\n", "ll + small letter", "ll + BIG letter","hh + small letter", "hh + BIG letter");
	PRINTF("|d/D|\t|%22lld|\t|%22llD|\t|%22hhd|\t|%22hhD|", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
	PRINTF("|u/U|\t|%22llu|\t|%22llU|\t|%22hhu|\t|%22hhU|", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
	PRINTF("|o/O|\t|%22llo|\t|%22llO|\t|%22hho|\t|%22hhO|", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
	PRINTF("|x/X|\t|%22llx|\t|%22llX|\t|%22hhx|\t|%22hhX|", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
	printf("\n\t\t|%22s|\t|%22s|\t|%22s|\t|%22s|\n", "z + small letter", "z + BIG letter","j + small letter", "j + BIG letter");
	PRINTF("|d/D|\t|%22zd|\t|%22zD|\t|%22jd|\t|%22jD|", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
	PRINTF("|u/U|\t|%22zu|\t|%22zU|\t|%22ju|\t|%22jU|", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
	PRINTF("|o/O|\t|%22zo|\t|%22zO|\t|%22jO|\t|%22jO|", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
	PRINTF("|x/X|\t|%22zx|\t|%22zX|\t|%22jx|\t|%22jX|", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
//Not number options
	TITLE("Not number number options(field width and length modifiers):");
	{
		# define CNV "i"
		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
	}
	{
		# define CNV "d"
		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
	}
	{
		# define CNV "D"
		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
	}
	{
		# define CNV "u"
		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
	}
	{
		# define CNV "U"
		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
	}
	{
		# define CNV "x"
		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
	}
	{
		# define CNV "X"
		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
	}
	{
		# define CNV "o"
		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
	}
	{
		# define CNV "O"
		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
	}
#endif

#ifdef STRANGE
//Strange undefined tests to test the atoi of the field width and presicion
	TITLE("Very undefined tests(field width, presicion and all flags) only 'd':\n");
	printf("Round 1:|-5.#3| |-5.#6.5| |-5.#6| |-5.#6.| |-5.#6#4| |-5.#6#.4| |-5.#6.#0| |-5.#6.#0#7|\n");
	PRINTF("|%-5.3d| |%-5.#6.5d| |%-5.#6d| |%-5.#6.d| |%-5.#6#4d| |%-5.#6#.4d| |%-5.#6.#0d| |%-5.#6.#0#7d|", -42,42,42,42,42,42,42,42);
	printf("\nRound 2:|.7.3|\t|07.3|\t|. 7.3|\t|.07.03| |.#7.3|  |.+7.3|\n");
	PRINTF("|%.7.3d| |%07.3d| |%. 7.3d| |%.07.03d| |%.#7.3d| |%.+7.3d|",42,42,42,42,42,42);
	printf("\nRound 3:|.07.+6.3| |+5 +4.3| |+0+7+5| |+0+7+5.3| |+.07.3|\n");
	PRINTF("|%.07.+6.3d| |%+5 +4.3d| |%+0+7+5d| |%+0+7+5.3d| |%+.07.3d|", 42,42,42,42,42);
	printf("\nRound 4:|ll.15.12|\t|.ll 15.12|\t\t|.015ll.12|\t|.ll#15.12|\t\t|.ll#15.12x|\n");
	PRINTF("|%ll.15.12d|\t|%.ll 15.12d|\t|%.015ll.12d|\t|%.ll#15.12d|\t|%.ll#15.12x|",-42,-42,-42,-42,-42);
#endif
	
/*
**	Put new stuff here like:

#ifdef <test_name>
	TITLE("<test name>\n");
	PRINTF("test without \n in the end!");
#endif

*/

//Don't remove!
	if (errno)
		printf(RED"\n\n\tSome error has been found:\t%s\n"NORM, strerror(errno));

//LEAKS test (just make <gcc -D LEAKS> and it will work)
#ifdef LEAKS
	while (1) sleep(120);
#endif
	return (0);
}

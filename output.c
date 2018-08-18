#include "ft_printf.h"

void    ft_strpad(int width, char c, t_flags *flags)
{
    int i;

    i = -1;
    if (flags->plus == 1 && flags->nul == 1)
        ft_putchar('+');
    if (flags->space == 1)
    {
        ft_putchar(' ');
        i++;
    }
    while (++i < width)
        ft_putchar(c);
}

void    print_str(t_arg *var, t_flags *flags)
{
    int len;

    len = ft_strlen(var->str);
    if (var->width > 0 && var->width > len && flags->minus != 1)
        ft_strpad(var->width - len, ' ', flags);
    ft_putstr(var->str);
}

void    print_d(t_arg *var, t_flags *flags)
{
    char *str;
    int len;

    if (flags->nul == 1 && var->d < 0)
        var->d = -var->d;
    str = ft_itoa(var->d);
    len = ft_strlen(str);
    if (flags->plus == 1)
        len++;
    if (var->width > 0 && var->width > len && flags->minus != 1)
    {
        if (flags->nul == 1)
            ft_strpad(var->width - len, '0', flags);
        else
            ft_strpad(var->width - len, ' ', flags);
    }
    else if (flags->space == 1 && flags->plus != 1)
        ft_putchar(' ');
    if (flags->plus == 1 && *str != '-' && flags->nul != 1)
        ft_putchar('+');
    ft_putstr(str);
}
#include "ft_printf.h"

char    *print_str(t_arg *var, t_flags *fl)
{
    char    *buff;
    int     len;
  
    if (fl->plus == 1 || fl->space == 1 || fl->hash ==  1 || fl->nul == 1)
    {
        undef_beh(fl, var->type);
        return (NULL);
    }
    len = ft_strlen(var->str);
    if (fl->prsn >= 0 && fl->prsn < len)
        var->str = ft_strsub(var->str, 0, fl->prsn);
    len = ft_strlen(var->str);
    var->width = var->width > len ? var->width - len : 0;
    buff = (char *)malloc(sizeof(char) * (var->width + 1));
    buff = set_pad(var->width, buff, fl);
    if (fl->minus == 1)
        buff = ft_strjoin(var->str, buff);
    else
        buff = ft_strjoin(buff, var->str);
    return (buff);
}

char    *print_c(t_arg *var, t_flags *fl)
{
    char    *buff;
    char    str[2];
    int     len;
  
    if (fl->plus || fl->space|| fl->hash || fl->nul)
    {
        undef_beh(fl, var->type);
        return (NULL);
    }
    str[0] = var->d;
    str[1] = '\0';
    buff = (char *)malloc(sizeof(char) * (var->width + 1));
    buff = set_pad(var->width - 1, buff, fl);
    if (fl->minus == 1)
        buff = ft_strjoin(str, buff);
    else
        buff = ft_strjoin(buff, str);
    return (buff);
}
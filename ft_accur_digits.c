#include "ft_printf.h"

char    *ft_accur_digits(char *str, t_struct *lst)
{
    char *src;

    if (lst->accur != 0)
    {
        if ((int) ft_strlen(str) < lst->accur)
        {
            if ((src = ft_strnew((size_t) lst->width)) == NULL)
                return (NULL);
            if (lst->zero_or_minus == '1')
            {
                lst->zero_or_minus = '0';
                lst->space = ' ';
            }
            return (ft_strcpy_rev(src, str, '0', lst->accur));
        }
    }
    return (str);
}

char    *strhesh(char *str, t_struct *lst)
{
    char    *src;
    int     i;
    int     j;

    i = 0;
    j = 0;
    if ((lst->hesh == 1) && (lst->letar == 'x'))
    {
        src = ft_strnew(ft_strlen(str) + 2);
        src[i++] = '0';
        src[i++] = 'x';
        while (str[j])
        {
            src[i] = str[j];
            i++;
            j++;
        }
        ft_strdel(&str);
        return (src);
    }
    else if (lst->hesh == 1 && (lst->letar == 'o' || lst->letar == 'O'))
            return (ft_strcpy_rev(src, str, '0', ((int)ft_strlen(str) + 1)));
    return (str);
}
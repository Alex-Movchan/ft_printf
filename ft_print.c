#include "ft_printf.h"

void ft_argdolar(va_list *ap, va_list *tmp, int len)
{
	va_copy(*ap, *tmp);
	while (--len)
		va_arg(*ap, int);
}

char *ft_getchar(t_srt *lst)
{
	char *str;

	if (lst->chr != '0')
	{
		str = ft_strnew(1);
		str[0] = lst->chr;
		str[1] = '\0';
		str = ft_width(str, lst);
		return (str);
	}
	return (NULL);
}

int ft_print(t_srt *lst, va_list *ap, va_list *tmp)
{
	char *str;


	if (lst->dolar != 0)
		ft_argdolar(ap, tmp, lst->dolar);
	else if ((str = get_str(ap, lst)) != NULL || (str = ft_getchar(lst)) != NULL)
	{
		ft_putstr_fd(str, lst->fd);
		return ((int) ft_strlen(str));
	}
	else if (lst->letar == 'c' || lst->letar == 'C')
		return (ft_cast_char(ap, lst));
	else
		return (0);
}

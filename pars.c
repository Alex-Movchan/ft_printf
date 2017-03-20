#include "ft_printf.h"

int ft_printformat(const char *str, int *i, t_srt *lst, va_list *ap)
{
	int res;

	res = 0;
	if (str[(*i)] == '{')
		ft_color(str, i, ap, lst);
	ft_putchar(str[(*i)]);
	res++;
	return (res);
}

void ft_width_or_dolar(const char *str, int *i, t_srt *lst)
{
	int len;
	len = atoidig(str, i);
	if (str[(*i) + 1] == '$')
		lst->dolar = len;

	else
		lst->width = len;
}

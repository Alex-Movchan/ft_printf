#include "ft_printf.h"

char *ft_strcast_p(va_list ap, t_srt *lst)
{
	char *str;
	uintmax_t	nbr;

	lst->hesh = 1;
	nbr = (uintmax_t )va_arg(ap, long int);
	str = ft_itoa_base(nbr, 16);
	str = ft_accur_digits(str, lst);
	str = ft_strhesh(str, lst);
	return (str);
}


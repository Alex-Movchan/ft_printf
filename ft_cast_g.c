#include "ft_printf.h"

char *ft_nozero(char *str)
{
	int i;

	i = (int) ft_strlen(str);
	i--;
	if (str[i] == '.')

		while (str[i] == '0')
			i--;
	str[i + 1] = '\0';
	return (str);
}

char *ft_getstr_f(long double nb, t_srt *lst)
{
	char *str;
	char *src;
	int i;

	str = (itoa((intmax_t) nb));
	//if ((int)ft_strlen(str) == lst->accur || (int)ft_strlen(str) + 1 == lst->accur)
	//	return (str);
	if (lst->accur != -1)
		i = lst->accur - (int) ft_strlen(str);
	else
		i = 6 - (int) ft_strlen(str);
	nb -= (int) nb;
	src = ft_pow(nb, i);
	src = ft_nozero(src);
	str = ft_cast(str, src);
	str = ft_plus(str, lst);
	ft_strdel(&src);
	return (str);
}

char *ft_get_str_eg(long double nb, t_srt *lst)
{
	char *str;
	char *src;
	int i;

	i = 0;
	nb = rang_e(nb, &i);
	src = ft_getpow(i);
	if (lst->accur > 0 || lst->accur == -1)
		str = ft_getstr_f(nb, lst);
	else
	{
		nb = ft_r_nbr(nb);
		str = ft_itoa((int) nb);
	}
	str = ft_strjoin(str, src);
	str = ft_plus(str, lst);
	ft_strdel(&src);
	return (str);
}

char *ft_str_g(va_list ap, t_srt *lst)
{
	long double nb;
	long double nbr;
	int i;
	char *str;

	if (lst->size == 7)
		nb = (va_arg(ap, long double));
	else
		nb = va_arg(ap, double);
	if (nb < 0)
	{
		nb = -nb;
		lst->plus = '-';
	}
	nbr = nb;
	str = (itoa((intmax_t) nbr));
	i = 0;
	nbr = rang_e(nbr, &i);
	if ((ft_strlen(str) == 6 && lst->accur == -1) || (int)ft_strlen(str) == lst->accur)
		return (str);
	if ((lst->accur != -1 && i != 0 && (i <= lst->accur || -i <= lst->accur)) || ft_strlen(str) > 6)
		return (ft_get_str_eg(nb, lst));
	else
		str = ft_getstr_f(nb, lst);
	i = (int)ft_strlen(str) - 1;
	while (str[i] == '0')
		i--;
	if (str[i] == '.')
		i--;
	str[++i] = '\0';
	return (str);
}
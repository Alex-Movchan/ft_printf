#include "ft_printf.h"

char *ft_cest_str(va_list *ap, t_srt *lst)
{
	char *str;
	int res;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	else
		str = ft_strdup(str);
	str = ft_accur(str, lst);
	str = ft_width(str, lst);
	return (str);
}

int		ft_cast_chr(t_srt *lst, char *str)
{
	char a;

	a = '\0';
	str = ft_width(str, lst);
	str[ft_strlen(str) - 1] = '\0';

	if (lst->zero_or_minus != '-')
	{
		ft_putstr_fd(str, lst->fd);
		write(lst->fd, &a, 1);
		return((int)ft_strlen(str) + 1);
	}
	else if (lst->zero_or_minus == '-')
	{
		write(lst->fd, &a, 1);
		ft_putstr_fd(str, lst->fd);
		return((int)ft_strlen(str) + 1);
	}
	if (lst->width == -1)
		write(lst->fd, &a, 1);
	return(1);
}

int 	ft_cast_char(va_list *ap, t_srt *lst)
{
	char *str;

	str = ft_strnew(1);
	str[0]  = va_arg(*ap, int);
	str[1] = '\0';
	if (str[0] == '\0')
		return(ft_cast_chr(lst, str));
	str = ft_width(str, lst);
	ft_putstr_fd(str, lst->fd);
	return ((int)ft_strlen(str));
}
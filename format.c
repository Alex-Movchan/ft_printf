/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:09:05 by amovchan          #+#    #+#             */
/*   Updated: 2017/02/27 17:49:09 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_struct	inicial_struct(t_struct *lst)
{
	if ((lst = (t_struct*)malloc(sizeof(t_struct))) == NULL)
		return (NULL);
	lst->letar = '0';
	lst->zero_or_minus = '0';
	lst->space = '0';
	lst->plus_ = '0';
	lst->hesh = 0;
	lst->size = 0;
	lst->accur = 0;
	lst->wudth = -1;
	lst->rs = 0;
	lst->dot = 0;
	lst->color = "\0";
	return (lst);
}

t_struct	ft_print_format(t_struct *lst, const char *str, int *i, va_list *ap)
{
	while (str[++(*i)] && str[(*i)] != '%' && lst->letar == '\0')
	{
		if (flag_fotmat(str[(*i)], lst) == 1)
			;
		else if (str[(*i)] == '#')
			lst->hesh = 1;
		else if (atoi(str, i) != 0)
			lst->wudth = atoi(str, i);
		else if (str[(*i)] =='*')
			lst->wudth = va_arg(ap, int);
		else if (add_dot(str, i, lst) == 1)
			;
		else if (specifiers(str, i, lst))
			;
		else if (str[(*i)] == '{')
			ft_color(str, i, lst);
		else if (tayp(str[(*i)]) == 1)
			lst->letar = str[(*i)];
		if ((ft_strchr("1234567890 #+-.* LsScCdDioOuUxXbpaAfFeE{ lhjz", str[(*i)]) == NULL))
			break;
	}
	return (lst);
}

int			ft_format(const char *format, va_list *ap)
{
	t_struct	*list;
	int			i;
	int			res;

	i = -1;
	res = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			list = inicial_struct(list);
			list = ft_print_format(lst, format, &i, ap);
            res += list->rs;
		}
		else
		{
			ft_putchar(format[i]);
			res++;
		}
	}
	return (res);
}

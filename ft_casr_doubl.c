/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casr_doubl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:13:39 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/01 21:49:20 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft-printf.h"

char	*ft_cast_f(va_list *ap, t_struct *lst)
{
	double	nb;
	char	*str;

	if (lst->size == 7)
		return (ft_cast_F(ap, lst));
	nb = va_arg(*ap, double);
	str = ft_str_double((long double)nb, lst);
	if (lst->accur > lsr->width && lst_space == ' ')
		str = ft_strcpy_rev(src, str, ' ', ((int)ft_strlen(str) + 1));
	else
		str = ft_width(str, lst);
	str = ft_plus(str, lst);
	str = ft_color_print(str, lst);
	return (str);
}

char	*ft_cast_F(va_list *ap,t_struct *lst)
{
	long double nb;
	char		*str;

	nb = va_arg(*ap, long double);
	str = ft_str_double(nb, lst);
	if (lst->accur > lsr->width && lst_space == ' ')
		str = ft_strcpy_rev(src, str, ' ', ((int)ft_strlen(str) + 1));
	else
		str = ft_width(str,lst);
	str = ft_plus(str, lst);
	str = ft_color_print(str, lst);
	return (str);
}

char	*ft_cast_e(va_list *ap,t_struct *lst)
{
    long double	nb;
    char		*str;

    nb = va_arg(*ap, long double);
    str = ft_get_str_e(nb, lst);
	if (lst->accur > lsr->width && lst_space == ' ')
		str = ft_strcpy_rev(src, str, ' ', ((int)ft_strlen(str) + 1));
	else
    	str = ft_width(str,lst);
    str = ft_plus(str, lst);
    str = ft_color_print(str, lst);
	str = ft_color_print(str, lst);
    return (str);
}

char	*ft_cast_E(va_list *ap, t_struct *lst)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_cast_e(ap, lst);
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

char	*ft_cast_g(va_list *ap, t_struct *lst)
{
	char	*str;
	char	*src;
	int		len1;
	int		len2;

	str = ft_cast_f(ap, lst);
	src = ft_cast_e(ap, lst);
	len1 = ft_strlen(str);
	len2 = ft_strlen(src);
	if (len1 > len2)
	{
		ft_strdel(&src);
		return (str);
	}
	else
	{
		ft_strdel(&str);
		return (src);
	}
}

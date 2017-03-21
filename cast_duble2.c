/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_duble2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:44:21 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/01 21:54:08 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cast_G(va_list *ap, t_struct *lst)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_cast_g(ap, lst);
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

char	*ft_cast_a(va_list *ap,t_struct *lst)
{
    long double nb;
    char        *str;

    nb = va_arg(*ap, long double);
    str = ft_get_str_e(nb, lst);
	if (lst->accur > lsr->width && lst_space == ' ')
		str = ft_strcpy_rev(src, str, ' ', ((int)ft_strlen(str) + 1));
	else
    	str = ft_width(str,lst);
    str = ft_plus(str, lst);
    return (str);
}

char	*ft_cast_A(va_list *ap, t_struct *lst)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_cast_a(ap, lst);
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

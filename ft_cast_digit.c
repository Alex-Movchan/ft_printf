/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:13:00 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/01 14:21:09 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cast_di(va_list *ap, t_strucr *lst,)
{
	char		*str;
	intmax_t	nbr;

	nbr = signed_size(ap, lst);
    if (nb < 0)
        lst->plus = '-';
	str = itoa(nb);
	str = ft_accur_digitc(str, slt);
	if (lst->accur > lsr->width && lst->space == ' ' && lst->plus == '0')
		str = ft_strcpy_rev(src, str, ' ', ((int)ft_strlen(str) + 1));
	else
		str = ft_width(str, lst);
	str = ft_plus(str, lst);
	str = ft_color_print(str, lst);
	return (str);
}

char	*ft_cast_unsidned(va_list *ap, t_strucr *lst, int base)
{
	char		*str;
	uintmax_t	nbr;

	nbr = unsigned_size(ap, lst);
	str = ft_itoa_base(nb, base);
	str = ft_strhesh(str, lst);
	str = ft_accur_digitc(str, slt);
	if (lst->accur > lsr->width && lst->plus_or_space == ' ')
		str = ft_strcpy_rev(src, str, ' ', ((int)ft_strlen(str) + 1));
	else
	str = ft_width(str, lst);
	str = ft_plus(str, lst);
	str = ft_color_print(str, lst);
	return (str);
}
//?
char	*ft_cast_X(va_list *ap, t_struct *lst)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_cast_ubsigned(ap, lst, 16);
	while (s[i])
	{
		s[i] = ft_toupper(str[i]);
		i++;
	}
	return (s);
}

char	*ft_cast_D(va_list *ap, t_struct *lst)
{
	char		*str;
	intmax_t	nb;

	nb = va_arg(*ap, intmax_t);
	nb = (long int)nb;
	str = itoa(nb);
	str = ft_accur_digitc(str, slt);
	if (lst->accur > lsr->width && lst->plus_or_space == ' ')
		str = ft_strcpy_rev(src, str, ' ', ((int)ft_strlen(str) + 1));
	else
		str = ft_width(str, lst);
	str = ft_plus(str, lst);
	str = ft_color_print(str, lst);
	return (str);
}

char	*ft_cast_long(va_list *ap, t_struct *lst, int base)
{
	char		*str;
	uintmax_t	nb;

	nb = va_arg(ap, uintmax_t);
	nb = (unsigned long int)nb;
	str = ft_itoa_base(nb, base);
	str = ft_accur_digitc(str, slt);
	if (lst->accur > lsr->width && lst->plus_or_space == ' ')
		str = ft_strcpy_rev(src, str, ' ', ((int)ft_strlen(str) + 1));
	else
		str = ft_width(str, lst);
	str = ft_plus(str, lst);
	str = ft_color_print(str, lst);
	return (str);
}

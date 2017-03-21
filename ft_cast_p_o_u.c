/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_p_o_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:48:11 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/01 14:06:25 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cast_p(va_list *ap, t_struct *lst)
{
	char		*str;
	uintmax_t	nb;

	nb = va_arg(*ap, uintmax_t);
	nb = (unsigned long int)nb;
	str = ft_itoa_base(nb, 16);
	str = ft_accur_digitc(str, slt);
	if (lst->accur > lsr->width && lst_space == ' ')
		str = ft_strcpy_rev(src, str, ' ', ((int)ft_strlen(str) + 1));
	else
		str = ft_width(str, lst);
	str = ft_plus(str, lst);
	str = ft_str_hesh(str, lst);
	str = ft_color_print(str, lst);
	return (str);
}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 17:28:33 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/01 21:13:13 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_double(va_list *ap, t_struct *lst)
{
	if (lst->letar == 'f')
		return (ft_cast_f(ap, lst));
	else if (lst->letar == 'F')
		return (ft_cast_F(ap, lst));
	else if (lst->letar == 'e')
		return (ft_cast_e(ap, lst));
	else if (lst->letar == 'E')
		return (ft_cast_E(ap, lst));
	else if (lst->letar == 'g')
		return (ft_cast_g(ap, lst));
	else if (lst->letar == 'G')
		return (ft_cast_G(ap, lst));
	else if (lst->letar == 'A')
		return (ft_cast_A(ap, lst));
	else if (lst->letar == 'a')
		return (ft_cast_a(ap, lst));
	else
		return (NULL);
}

char	*get_str(va_list *ap, t_struct *lst)
{
	if (lst->letar == 's')
		return (ft_cast_str(ap, lst));
	else if (lst->letar == 'S')
		return (ft_wchar_str(ap, lst));
	else if (lst->letar == 'c' || lst->letar == 'C')
		return (ft_cast_char(ap, lst));
	else
		return (ft_get_double(ap, lst));
}

char	*ft_format_print(va_list *ap, t_strucr *lst)
{

	if (lst->letar == 'p')
		return (ft_cast_p(ap, lst));
	else if (lst->letar == 'd' || lst->letar == 'i')
		return (ft_cast_di(ap, lst));
	else if (lst->letar == 'o')
		return (ft_cast_unsigned(ap, lst, 8));
	else if (lst->letar == 'D')
		return (ft_cast_D(ap, lst));
	else if (lst->letar == 'O')
		return (ft_cast_long(ap, lst, 8));
	else if (lst->letar == 'u')
		return (ft_cast_unsigned(ap, lst, 10));
	else if (lst->letar == 'U')
		return (ft_cast_long(ap, lst, 10));
	else if (lst->letar == 'x')
		return (ft_cast_unsigned(ap, lst, 16));
	else if (lst->letar == 'b')
		return (ft_cast_unsigned(ap, lst, 2));
	else if (lst->letar == 'X')
		return (ft_cast_X(ap, lst));
	else
		return (ft_get_str(ap, lst));
}

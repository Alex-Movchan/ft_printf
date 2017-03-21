/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:54:06 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/01 14:13:50 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strndup(char *str, int len)
{
    char	*src;

	if (!(src = ft_strnew((size_t)len)))
		return (NULL);
	src = ft_strncpy(src, str, len);
	ft_strdel(&str);
	return (src);
}

char	*ft_accur(char *str, t_strucr *lst)
{
	if (lst->accur != 0)
		return (ft_strndup(str, lst->accur));
	else
		return (str);
}

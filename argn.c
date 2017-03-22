/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:56:23 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 21:18:10 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_argn(int len, va_list ap, t_srt *lst)
{
	int	*tab;

	if (lst->letar == 'n')
	{
		tab = va_arg(ap, int*);
		*tab = len;
	}
}

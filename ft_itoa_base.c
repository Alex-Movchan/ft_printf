/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:30:14 by amovchan          #+#    #+#             */
/*   Updated: 2017/02/25 16:57:50 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_base(uintmax_t nb, uintmax_t base, int *i, char *s)
{
	char *str;

	str = "0123456789abcdef";
	if (nb >= base)
		ft_base(nb / base, base, i, s);
	s[(*i)++] = str[A(nb % base)];
}

char *ft_itoa_base(uintmax_t nb, int base)
{
	char *s;
	int i;

	i = 0;
	if (base < 2 || base > 16 || !(s = (char *) malloc(sizeof(char) * 32)))
		return (NULL);
	ft_base(nb, base, &i, s);
	s[i] = '\0';
	return (s);
}

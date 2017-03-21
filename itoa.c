/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 17:03:46 by amovchan          #+#    #+#             */
/*   Updated: 2017/02/25 17:08:56 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t		ft_isnegativ(intmax_t n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static intmax_t		ft_len_int(intmax_t n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char				*itoa(intmax_t n)
{
	uintmax_t	nbr;
	int			len;
	char		*str;

	len = 0;
	len = ft_len_int(n);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	nbr = ft_isnegativ(n);
	while (len >= 0)
	{
		str[len--] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

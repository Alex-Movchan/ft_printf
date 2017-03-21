/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:54:45 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/01 18:26:54 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_dable_a(long double nb, int len)
{
	int	i;
	int	a;

	i = 0;
	s = ft_strnew(len);
	s = ft_strs(s, &i);
	nb -= 1.0;
	s[i++] = '.';
	while (i <= len && nb != 0)
	{
		nb*=16;
		a = (int)nb;
		nb = nb - (double)a;
		s[i] = ft_char(a);
		i++;
    }
	s[i] = '\0';
	return (ft_okrug_a(s));
}

char	*ft_str_zero(long double nb)
{
	int			a;
	char		*str;
	long double	b;

	b = nb;
	a = (int)b;
	b -= (long double)a;
	b *= 10;
	a = (int)b;
	str = ft_strnew(4);
	if (a > 5)
		a = 2;
	else if (a == 5 && (int)nb % 2 != 0)
		a = 2;
	else
		a = 1;
	str = ft_strs(str, 0, a);
	return (str);
}

void	ft_ppp(char *c, char *b)
{
	if ((*c) >= '0' && (*c) <= '9')
		(*c) += 1;
	else if ((*c) >= 97 && (*c) < 102)
		(*c) += 1;
	else if (c == 102)
	{
		if ((*b) >= '0' && (*b) <= '9')
			(*b) += 1;
		else if ((*b) >= 97 && (*b) < 102)
			(*b) += 1;
		(*c) = '0';
	}
}

char	*ft_okrug_a(char *str)
{
	int		i;
	char	c;
	char	a;
	char	b;

	i = ft_strlen(str);
	a = str[i--];
	c = str[i--];
	b = str[i];
	if (a >= 56)
		ft_ppp(&c, &b);
	str[i++] = b;
	str[i++] = c;
	return (str);
}

char	*ft_zero(int len)
{
	char	*str;

	str = ft_strnew((size_t)len);
	while (len >= 0)
	{
		str[len] = '0';
		len--;
	}
	return (str);
}

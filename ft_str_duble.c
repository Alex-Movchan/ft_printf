/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_duble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:22:48 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/01 21:28:14 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pow(int	nb, int pow)
{
	int	nbr;

	nbr = nb;
	while (pow > 1)
	{
		nbr *= nb;
		pow--;
	}
	return (nbr);
}

char    *ft_cast(char *s1, char *s2)
{
	char    *s;
	int		i;
	int		j;
	int		len;

    i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	s = (char*)malloc(sizeof(char) * len);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i++] = '.';
	while (i <= len)
	{
		s[i] = s2[j];
		j++;
		i++;
	}
	return (s);
}

char	*ft_okrugl(char *s)
{
	int		i;
	char	c;
	char	b;

	i = ftstrlen(s);
	b = s[--i];
	c = s[--i];
	if (b == '5' && c % 2 == 0)
		c += 1;
	else if (b > '5')
		c += 1;
	s[i] = c;
	s[++i] = '\0';
	return (s);
}

char	*ft_okrug(long double nb)
{
	int	a;

	a = (int)nb;
	nb -= (long double)a;
	nb *= 10;
	if (a % 2 == 1 && (int)nb == 5)
		a += 1;
	else if ((int) nb > 5)
		a += 1;
	return (ft_itoa(a));
}

char    *ft_str_double(long double nb, t_struct *lst)
{
    char		*s1;
    char		*s2;
    long double	a;
    long double	b;
	int			len;

	a = (int)nb;
	nb -= a;
	len = 7;
	if (lst->accur > 0)
		len = lst->accur + 1;
	else if (lst->accur == 0)
		return (ft_okrug(nb));
	b = ft_pow(10, len);
	nb *= b;
	if (nb == 0.0)
		s2 = ft_zero(len);
	s2 = ft_itoa((int)nb);
	s1 = ft_itoa((int)a);
	s1 = ft_cast(s1, s2);
	ft_strdel(&s2);
	s1 = ft_okrugl(s1);
	return (s1);
}

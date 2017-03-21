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

char *ft_str_dable_a(long double nb, int len)
{
	int i;
	int a;
	char *s;

	i = 0;
	len += 4;
	s = ft_strnew(len);
	s = ft_strs(s, &i, 1);
	nb -= 1.0;
	s[i++] = '.';

	while (i < len && nb != 0)
	{
		nb *= 16;
		a = (int) nb;
		nb = nb - (double) a;
		s[i] = ft_char(a);
		i++;
	}
	s[i] = '\0';
	//if (nb == 0 && len > i)
		return (s);
	//return (ft_okrug_a(s));
}

char *ft_str_zero(long double nb, t_srt *lst, char *s)
{
	char *str;
	char *src;
	int i;

	i = 0;
	nb = ft_r_nbr(nb);
	str = ft_strnew(4);
	str = ft_strs(str, &i, (int) nb);
	if (lst->hesh == 1)
	{
		src = ft_strnew((ft_strlen(str) + 1));
		i = 0;
		while (str[i])
		{
			src[i] = str[i];
			i++;
		}
		src[i] = '.';
		src[++i] = '\0';
		src = ft_strjoin(src, s);
		ft_strdel(&str);
		return (src);
	}
	str = ft_strjoin(str, s);
	return (str);
}

void ft_ppp(char *c, char *b)
{
	if ((*c) >= '0' && (*c) < '9')
		(*c) += 1;
	else if ((*c) == '9')
		(*c) = 'a';
	else if ((*c) >= 97 && (*c) < 102)
		(*c) += 1;
	else if ((*c) == 102)
	{
		if ((*b) >= '0' && (*b) <= '9')
			(*b) += 1;
		else if ((*b) >= 97 && (*b) < 102)
			(*b) += 1;
		(*c) = '0';
	}
}

char *ft_okrug_a(char *str)
{
	int i;
	char c;
	char a;
	char b;

	i = ft_strlen(str);
	a = str[--i];
	c = str[--i];
	b = str[i];
	if (a >= 6)
		ft_ppp(&c, &b);
	str[i] = c;
	str[++i] = '\0';
	return (str);
}

char *ft_zero(int len)
{
	char *str;

	str = ft_strnew((size_t) len);
	while (len >= 0)
	{
		str[len] = '0';
		len--;
	}
	return (str);
}

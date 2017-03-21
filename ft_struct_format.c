/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:31:12 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/01 22:17:54 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		tayp(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd')
		return (1);
	if (c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u')
		return (1);
	if (c == 'U' || c == 'x' ||c == 'X' || c == 'c' || c =='C')
		return (1);
	if (c == 'f' || c == 'F' || c == 'e' || c == 'E')
		return (1);
	if (c == 'a' || c == 'A' || c == 'g' || c == 'G')
		return (1);
	return (0);
}

int		flag_format(char c, t_struct *lst)
{
	if (c == '-')
	{
		lst->zero_or_minus = '-';
		return (1);
	}
	else if (c == '0' && lst->zero_or_minus != '-')
	{
		lst->zero_or_minus = '1';
		return (1);
	}
	else if (c == '+')
	{
		lst->plus_or_space = '+';
		return (1);
	}
	else if (c == ' ' && lst->plus_or_space != '+')
	{
		lst->plus_or_zero = ' ';
		return (1);
	}
	else
		return (0);
}
int		atoi(const char *str, int *i)
{
	int	nbr;

	nbr = 0;
	while (str[(*i)] >= '0' && str[(*i)] <= '9')
	{
		nbr *= 10;
		nbr += ((int)str[(*i)] - 48);
		i++;
	}
	return (nbr);
}

int		add_dot(const char *str, int *i, t_struct *lst, va_list *ap)
{
	if (str[(*i)] == '.')
	{
		lst->dot = 1;
		if (str[(*i) + 1] == '*')//va_arg?
		{
			lst->accur = va_arg(*ap, int);
			return (1);
		}
		else if (atoi(str, ++(*i)) != 0)
		{
			lst->accur = atoi(str, i);
			return (1);
		}
		return (1);
	}
	return (0);
}

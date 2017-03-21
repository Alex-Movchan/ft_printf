/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:22:46 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/04 16:33:42 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_color(const char *s, int *i, va_list ap, t_srt *lst)
{
	char *str;
	int j;

	j = 0;
	str = ft_strnew(8);
	str[j++] = '{';
	(*i)++;
	while (s[(*i) - 1] != '}')
	{
		str[j] = s[(*i)];
		j++;
		(*i)++;
	}
	(*i)--;
	str[j] = '\0';
	if ((ft_strcmp(str, "{red}") == 0) || (ft_strcmp(str, "{green}") == 0) || (ft_strcmp(str, "{bleu}") == 0) ||
		(ft_strcmp(str, "{eoc}") == 0))
		ft_color_print(str);
	else if (ft_strcmp(str, "{fd}") == 0)
		lst->fd = va_arg(ap, int);
	else
		(*i) -= (j - 1);
	ft_strdel(&str);
}

void ft_color_print(char *str)
{
	if (ft_strcmp(str, "{red}") == 0)
		ft_putstr("\033[0;31m");

	else if (ft_strcmp(str, "{green}") == 0)
		ft_putstr("\033[0;32m");
	else if (ft_strcmp(str, "{eoc}") == 0)
		ft_putstr("\033[0m");
	else if (ft_strcmp(str, "{bleu}") == 0)
		ft_putstr("\033[0;34m");

}
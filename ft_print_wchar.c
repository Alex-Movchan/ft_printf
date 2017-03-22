/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:17:58 by amovchan          #+#    #+#             */
/*   Updated: 2017/02/27 17:53:31 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_print_wchar_str(va_list ap, t_srt *lst)
{
	int i;
	wchar_t *str;
	char *src;
	int j;

	j = -1;
	i = 0;
	str = va_arg(ap, wchar_t *);
	if (str == NULL)
	{
		src = "(null)";
		src = ft_accur(src, lst);
		src = ft_width(src, lst);
		return (src);
	}
	else
		src = (char *) malloc(sizeof(char) * (lst->accur + 1));
		while (str[i])
		{
			ft_print_wchar(str[i], src, &j);
			i++;
		}
		src[++j] = '\0';
	src = ft_accur(src, lst);
	src = ft_width(src, lst);
	return (src);
}

void ft_print_wchar(wchar_t c, char *str, int *i)
{
	if (c <= 0x7F)
	{
		str[++(*i)] = (char) c;
	}
	else if (c <= 0x7FF)
	{
		str[++(*i)] = (char) ((c >> 6) + 0xC0);
		str[++(*i)] = (char) ((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		str[++(*i)] = (char) ((c >> 12) + 0xE0);
		str[++(*i)] = (char) (((c >> 6) & 0x3F) + 0x80);
		str[++(*i)] = (char) ((c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		str[++(*i)] = (char) ((c >> 18) + 0xF0);
		str[++(*i)] = (char) (((c >> 12) & 0x3F) + 0x80);
		str[++(*i)] = (char) (((c >> 6) & 0x3F) + 0x80);
		str[++(*i)] = (char) ((c & 0x3F) + 0x80);
	}
}

int ft_strlen_wchar(wchar_t *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_len_wchar(wchar_t *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] <= 0x7F)
			len += 1;
		else if (str[i] <= 0x7FF)
			len += 2;
		else if (str[i] <= 0xFFFF)
			len += 3;
		else if (str[i] <= 0x10FFFF)
			len += 4;
		i++;
	}
	return (len);
}
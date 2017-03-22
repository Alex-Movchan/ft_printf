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
	int len;

	j = -1;
	str = va_arg(ap, wchar_t *);
	if (str == NULL)
	{
		src = ft_strdup("(null)");
		src = ft_accur(src, lst);
		src = ft_width(src, lst);
		return (src);
	}
	len = ft_len_wchar(str);
	if (lst->accur != -1 && lst->accur < len)
		len = lst->accur;
	src = (char *) malloc(sizeof(char) * (len + 1));
	i = 0;
	while (str[i] && len != 0)
	{
		ft_print_wchar(str[i], src, &j, &len);
		i++;
	}
	src[++j] = '\0';
	src = ft_accur(src, lst);
	src = ft_width(src, lst);
	return (src);
}

void ft_print_wchar(wchar_t c, char *str, int *i, int *len)
{
	if (c <= 0x7F && (*len) >= 1)
	{
		str[++(*i)] = (char) c;
		(*len)--;
	}
	else if (c <= 0x7FF && (*len) >= 2)
	{
		str[++(*i)] = (char) ((c >> 6) + 0xC0);
		str[++(*i)] = (char) ((c & 0x3F) + 0x80);
		(*len) -= 2;
	}
	else if (c <= 0xFFFF && (*len) >= 3)
	{
		str[++(*i)] = (char) ((c >> 12) + 0xE0);
		str[++(*i)] = (char) (((c >> 6) & 0x3F) + 0x80);
		str[++(*i)] = (char) ((c & 0x3F) + 0x80);
		(*len) -= 3;
	}
	else if (c <= 0x10FFFF && (*len) >= 4)
	{
		str[++(*i)] = (char) ((c >> 18) + 0xF0);
		str[++(*i)] = (char) (((c >> 12) & 0x3F) + 0x80);
		str[++(*i)] = (char) (((c >> 6) & 0x3F) + 0x80);
		str[++(*i)] = (char) ((c & 0x3F) + 0x80);
		(*len) -= 4;
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
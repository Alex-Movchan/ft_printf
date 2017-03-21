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

void	ft_print_wchar_str(va_list *ap, t_struct *lst)
{
	in		i;
	wchar_t	*str;

	i = 0;
	str = va_arg(*ap, wchar_t*);
	while (str[i])
	{
		lst->rs += ft_print_wchar(str[i]);
		i++;
	}
}

int		ft_print_wchar(wchar_t c)
{
	if (c <= 0x7F)
	{
		ft_putchar(c);
		return (1);
	}
	else if (c <= 0x7FF)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
		return (2);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80)
		return (3);
		}
		else if (c <= 0x10FFFF)
		{
			ft_putchar((c >> 18) + 0xF0);
			ft_putchar(((c >> 12) & 0x3F) + 0x80);
			ft_putchar(((c >> 6) & 0x3F) + 0x80);
			ft_putchar((c & 0x3F) + 0x80);
			return (4);
		}
	return (0);
}

int		ft_strlen_wchar(wchar_t *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
			

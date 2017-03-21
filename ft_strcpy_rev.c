/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 21:07:21 by amovchan          #+#    #+#             */
/*   Updated: 2017/02/27 15:37:23 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy_rev(char *s1, char *s2, char c, int j)
{
	int i;

	i = ft_strlen(s2);
	while (i)
	{
		s1[j] = s2[i];
		i--;
		j--;
	}
	while (j)
	{
		s1[j] = c;
		j--;
	}
	ft_strdel(&s2);
	return (s1);
}

char	*ft_strcpychar(char *s1, char *s2, int j)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < j)
	{
		s1[i] = ' ';
		i++;
	}
	ft_strdel(&s2);
	return (s1);
}

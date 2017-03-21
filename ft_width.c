/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 20:54:56 by amovchan          #+#    #+#             */
/*   Updated: 2017/02/27 19:14:52 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy_rev(char *s1, char *s2, char c, int j)
{
	int	i;

	i = ft_strlen(s2);
	while (i >= 0)
	{
		s1[j] = s2[i];
		i--;
		j--;
	}
	while (j >= 0)
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
		s1[i] =s2[i];
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

char	*ft_width(char *str, t_struct *lst)
{
	char	*src;

	if (lst->width != 0)
	{
		if ((int)ft_strlen(str) < lst->width)
		{
			if ((src = ft_strnew((size_t)lst->width)) == NULL)
				return (NULL);
			if (lst->zero_or_minus == '1')
				return (ft_strcpy_rev(src, str, '0', lst->width));
			else if (lst->zero_or_minus == '-')
				return (ft_strcpychar(src, str, lst->width));
			else if (lst->plus != '0')
                ft_strcpy_rev(src, str, lst->plus, lst->width));
			return (ft_strcpy_rev(src, str, ' ', lst->width));
		}
		else
			return (str);
	}
	return (str);
}

char	*ft_plus(char *str, t_struct *lst)
{
	char	*src;
	int		i;

	i = 0;
	if (lst->plus_or_space == '+' || lst->plus_or_space == '-')
	{
	    src = ft_strcpy_rev(src, str, lst->plus_or_space, ((int)ft_strlen(str) + 1));
	    ft_strdel(&str);
		return (src);
	}
	else
		return (str);
}

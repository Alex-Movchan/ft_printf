/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:15:05 by amovchan          #+#    #+#             */
/*   Updated: 2017/02/25 15:09:59 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H_
#define _FT_PRINTF_H_

#include <stdarg.h>
#include "libft.h"
#define A(x) (x < 0 ? -(x) : x)

typedef struct		s_list
{
	char			letar;
	char			zero_or_minus;
	char			plus;
	char 			space;
	int				hesh;
	int				size;
	int				accur;
	int				width;
	int				rs;
	char			*color;
}					t_srtuct;

#endif
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amovchan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/17 20:47:06 by amovchan          #+#    #+#              #
#    Updated: 2017/03/22 23:02:16 by amovchan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

G = gcc

FLAG = -Wall -Wextra -Werror

SRC =	ft_cast_size.c \
		ft_cast_str.c \
		ft_casta.c \
		ft_caststr_a.c \
		ft_caststr_e.c \
		ft_color.c \
		ft_getstr.c \
		ft_itoa_base.c \
		ft_print_wchar.c \
		ft_print.c \
		ft_printf.c \
		ft_specifiers.c \
		ft_str_duble.c \
		ft_strcasr_p.c \
		ft_struct_format.c \
		ft_width.c \
		itoa.c \
		pars.c \
		argn.c \
		cast_duble2.c \
		ceil_floar.c \
		format.c \
		ft_accur_digits.c \
		ft_accur.c \
		ft_apostroph.c \
		ft_casr_doubl.c \
		ft_cast_digit.c \
		ft_cast_g.c \
		caststr_a.c \
		caststra.c \
		ft_cast_dig2.c

HDR = ft_printf.h

OBJ = $(SRC:.c=.o)

DEL = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
		make -C libft
		ar -cru $(NAME) $(OBJ) libft/*.o
		ranlib $(NAME)

%.o: %.c
		$(G) $(CFLAGS) -c -o $@ $<

clean:
		make clean -C ./libft
		$(DEL) $(OBJ)

fclean: clean
		make fclean -C ./libft
		$(DEL) $(NAME)

re: all
		make all -C ./libft
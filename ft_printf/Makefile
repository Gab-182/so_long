# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 01:38:46 by gabdoush          #+#    #+#              #
#    Updated: 2021/12/23 03:44:15 by gabdoush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES =  ft_printf.c			\
								\
		integer_argument.c		\
		hex_x_argument.c		\
		hex_upper_argument.c	\
		string_argument.c		\
		character_argument.c	\
		unsigned_int_argument.c	\
		pointer_argument.c		\
								\
		ft_putnbr_versions.c	\
		ft_putchar.c			\
		ft_putstr.c
		

OBJECTS =	$(FILES:.c=.o)

HEADERS = ft_printf.h 

FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f  $(NAME)

bonus: all

re: fclean all

.PHONY:	all clean fclean re

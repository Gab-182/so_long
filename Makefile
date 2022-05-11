# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 18:22:15 by gabdoush          #+#    #+#              #
#    Updated: 2022/02/06 17:45:09 by gabdoush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FILES = so_long.c\
		so_long_utils_1.c\
		so_long_utils_2.c\
		map_checker.c\
		at_least_checker.c\
		res_checker.c\
		map_struct.c\
		keys.c\
		handling_maps.c\
		./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c

HEADERS = ./so_long.h\
		  ./get_next_line/get_next_line.h\
		  ./ft_printf/ft_printf.h

OBJ = $(FILES:.c=.o)
#------------------------------------------------------------------------------
OPENGL_PATH = ./mlx/

MLX = $(OPENGL_PATH)libmlx.a -framework OpenGL

APPKIT = -framework AppKit
#------------------------------------------------------------------------------
MLX_FLAGS = $(MLX) $(APPKIT)

FLAGS = -Wall -Wextra -Werror

CC = gcc
#------------------------------------------------------------------------------
all: $(NAME)
$(NAME): $(OBJ)
	make -C ./mlx
	make -C ./ft_printf
	@echo "\033c"
	@echo "\033[0;32m [OK] \033[0m    \033[0;33m Compiling with the flags:\033[0m" $<
	$(CC) $(FILES) $(FLAGS) $(MLX_FLAGS) ./ft_printf/libftprintf.a -o so_long

clean:
	@echo "\033[0;32m [OK] \033[0m    \033[0;33m Cleaning so_long objects...\033[0m" $<
	rm -rf $(OBJ)
	@echo "\033[0;32m [OK] \033[0m    \033[0;33m Cleaning get_next_line objects...\033[0m" $<
	rm -rf ./get_next_line/get_next_line.o
	rm -rf ./get_next_line/get_next_line_utils.o
	@echo "\033[0;32m [OK] \033[0m    \033[0;33m Cleaning ft_printf objects...\033[0m" $<
	make -C ./ft_printf clean

fclean: clean
	@echo "\033[0;32m [OK] \033[0m    \033[0;33m fcleaning mlx excutable...\033[0m" $<
	make -C ./mlx clean
	@echo "\033[0;32m [OK] \033[0m    \033[0;33m fcleaning ft_printf archive...\033[0m" $<
	make -C ./ft_printf fclean
	@echo "\033[0;32m [OK] \033[0m    \033[0;33m fcleaning so_long excutable...\033[0m" $<
	rm -rf so_long
re: fclean all

.PHONY: all clean fclean re
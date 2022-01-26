NAME = so_long

FILES = so_long.c

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
	@printf "\033c"
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling with the flags:\033[0m" $<
	$(CC) $(FILES) $(FLAGS) $(MLX_FLAGS) -o so_long

clean:
	@echo "\033[0m       \033[0;33m Cleaning so_long objects...\033[0m" $<
	rm -rf $(OBJ)

fclean: clean
	@echo "\033[0m       \033[0;33m fcleaning mlx excutable...\033[0m" $<
	make -C ./mlx clean
	@echo "\033[0m       \033[0;33m fcleaning so_long excutable...\033[0m" $<
	rm -rf so_long
re: fclean all

.PHONY: all clean fclean re
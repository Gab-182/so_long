NAME = so_long

FILES = main.c
OBJ = $(FILES:.c=.o)
#------------------------------------------------------------------------------
OPENGL_PATH = ./opengl/

MLX_LIB = $(OPENGL_PATH)libmlx.a
OPENGL = -framework OpenGL
APPKIT = -framework AppKit
#------------------------------------------------------------------------------
MLX_FLAGS = $(MLX_LIB) $(OPENGL) $(APPKIT)
FLAGS = -Wall -Wextra -Werror
CC = gcc
#------------------------------------------------------------------------------
all: $(NAME)
$(NAME): $(OBJ)
	make -C ./opengl
	make -C ./minilibx
	@printf "\033c"
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling with the flags:\033[0m" $<
	$(CC) $(FILES) $(FLAGS) $(MLX_FLAGS) -o so_long

clean:
	@echo "\033[0m       \033[0;33m Cleaning so_long objects...\033[0m" $<
	rm -rf $(OBJ)
fclean: clean
	@echo "\033[0m       \033[0;33m fcleaning minilibx excutable...\033[0m" $<
	make -C ./minilibx clean
	@echo "\033[0m       \033[0;33m fcleaning opengl excutable...\033[0m" $<
	make -C ./opengl clean
	@echo "\033[0m       \033[0;33m fcleaning so_long excutable...\033[0m" $<
	rm -rf so_long
re: fclean all
.PHONY: all clean fclean re
# Compiler and flags
CC      = cc
CCFLAGS = -Wall -Wextra -Werror

# Project name
NAME    = cub3d

# Source files (add your .c files here)
SRCS    = src/main.c \
		  src/init.c \
		  src/error.c \
		  src/frees.c \
		  src/map_parsing.c \
		  src/map_utils.c \
		  src/file_extract_info.c \
		  src/utils.c \
		  src/extract_utils.c \
		  src/mlx_print.c \
		  src/movement1.c \
		  src/movement2.c \
		  src/game_render.c \
		  src/raycast.c \
		  src/textures.c

# Object files
OBJS    = $(SRCS:.c=.o)

# Libft path
LIBFT   = ./libft/libft.a

# Library directories and libraries
MLX_DIR = minilibx-linux/
MLX = $(MLX_DIR)libmlx.a

# Link against required libraries
OS				= $(shell uname)
ifeq ($(OS), Linux)
	DEF_OS		= -D LINUX
	MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
else
	MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -L/usr/X11/lib
endif

# Colors
GREEN   = \033[0;32m
RED     = \033[0;31m
YELLOW  = \033[1;93m
RESET   = \033[0m

# Build target
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CCFLAGS) $(OBJS) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo "\033[1;93m"
	@bash header.sh
	@echo "$(GREEN)[✔]$(RESET) Built $(NAME)"

# Build minilibx-linux library
$(MLX): $(MLX_DIR)
	@rm -rf minilibx-linux/.git
	@make -C $^ > /dev/null 2>&1

$(MLX_DIR):
	@echo "\033[1;35m[ ✔ ] Preparing minilibx...\033[0m"
	@git clone https://github.com/42Paris/minilibx-linux.git > /dev/null 2>&1

$(LIBFT):
	@echo "$(YELLOW)[*]$(RESET) Building libft..."
	@$(MAKE) -C ./libft > /dev/null 2>&1

%.o: %.c
	@$(CC) $(CCFLAGS) -c $< -o $@
	@echo "$(YELLOW)[*]$(RESET) Compiling $<"

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C ./libft clean > /dev/null 2>&1
	@echo "$(RED)[✗]$(RESET) Cleaned object files"

fclean: clean
	@rm -rf $(NAME) $(MLX_DIR)
	@$(MAKE) -C ./libft fclean > /dev/null 2>&1
	@echo "$(RED)[✗]$(RESET) Removed $(NAME)"

re: fclean all

#.PHONY: all clean fclean re

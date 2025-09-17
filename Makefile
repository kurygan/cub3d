RED = \033[0;31m
BLACK = \033[0;30m     
LIGHT_RED = \033[1;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
LIGHT_GRAY = \033[0;37m
DARK_GRAY = \033[1;30m
LIGHT_GREEN = \033[1;32m
YELLOW = \033[1;33m
LIGHT_BLUE = \033[1;34m
LIGHT_PURPLE = \033[1;35m
LIGHT_CYAN = \033[1;36m
WHITE = \033[1;37m

CC = cc
FLAGS = -Wall -Wextra -Werror

LIB_PATH = ./lib/
LIBFT_ARCH = $(LIB_PATH)libft/libft.a
MLX_ARCH = $(LIB_PATH)MLX42/build/libmlx42.a

SRCS = main.c \
	   parsing/parsing.c

OBJS = $(SRCS:.c=.o)
SRCS_DIR = ./src/
OBJS_DIR = ./.build/
MLXFOLDER = ./lib/MLX42/
MLXHEAD = $(MLXFOLDER)include/
MLXLIB = $(MLXFOLDER)build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS_PREF = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS))

NAME = cub3d

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@cc $(FLAGS) -g -c $< -o $@

$(NAME): $(OBJS_PREF) $(MLX_ARCH) $(LIBFT_ARCH)
	@make all -C lib/libft
	@cc $(FLAGS) $(OBJS_PREF) $(LIBFT_ARCH) $(MLXLIB) -g -o $(NAME)
	@echo "$(GREEN)Program compiled"

$(MLX_ARCH):
	@mkdir -p $(MLXFOLDER)build
	@cmake $(MLXFOLDER) -B $(MLXFOLDER)build
	@make -C $(MLXFOLDER)build -j4
	@echo "|🛠️|$(GREEN)MLX Compiled"

$(LIBFT_ARCH):
	@make -C lib/libft all
	@echo "|📚|$(GREEN)Libft Compiled"

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(MLXFOLDER)build
	@echo "Removing objects & MLX42"

fclean: clean 
	@rm -f $(NAME)
	@echo "Cleaning all"

re: fclean all

.PHONY: all libmlx clean fclean re
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
FLAGS = -Wall -Wextra -Werror -g3

SRCS_DIR = src/
SRCS = test.c

OBJS_DIR = .build/
OBJS = $(SRCS:.c=.o)
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS))

NAME = cub3d

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS_PREF)
	@echo "|🛠️|$(LIGHT_GREEN)Program Compiled"
	@$(CC) $(FLAGS) $(OBJS_PREF) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "|🗑️|Removing objects.."

fclean: clean
	@rm -f $(NAME)
	@echo "|🧹|Cleaning.."

test: all $(TEST)
	@cc $(FLAGS) libft.a -o $(TEST:.c=)
	@./$(TEST:.c=)
	@rm -rf ./$(TEST:.c=)

re: fclean all

.PHONY: all clean fclean re
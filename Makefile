NAME = push_swap

CC = clang
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src
OBJ_DIR = obj
HSRCS = include
LIBFT = libft/libft.a
HSRCS_BONUS = include_bonus
SRC = main.c move.c  parsing.c is_sorted.c free.c fill_stack.c \
	  algorithm/dicotomie.c algorithm/find_best_move.c algorithm/ft_youenn_algorithm.c

OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
PURPULE = \e[0;35m
NC = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) libft/libft.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling $(notdir $<)...$(NC)"
	@$(CC) $(CFLAGS) -I $(HSRCS) -I libft/ -o $@ -c $<

$(LIBFT):
	@echo "$(PURPULE)Building libraries...$(NC)"
	@$(MAKE) -C libft bonus -s

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJ_DIR)

lclean:
	@echo "$(RED)Cleaning libraries...$(NC)"
	@$(MAKE) -C libft fclean -s

fclean: clean lclean 
	@echo "$(RED)Cleaning executable $(NAME)...$(NC)"
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean lclean re bonus

NAME = push_swap
NAME_BONUS = checker

CC = clang
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src
SRC_DIR_BONUS = src_bonus

OBJ_DIR = obj

HSRCS = include
HSRCS_BONUS = include_bonus
LIBFT = libft/libft.a

SRC = main.c move1.c move2.c  parsing.c parsing_utils.c link_list.c free.c algorithm/adjust_stack.c \
	  algorithm/dicotomie.c algorithm/find_best_move.c algorithm/ft_youenn_algorithm.c is_sorted.c

SRC_BONUS = parsing.c parsing_utils.c link_list.c free.c action_bonus.c is_sorted_bonus.c \
			checker_bonus.c silent_move1_bonus.c silent_move2_bonus.c

OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)/%.o)

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
PURPULE = \e[0;35m
NC = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) libft/libft.a

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	@echo "$(GREEN)Linking $(NAME_BONUS)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) libft/libft.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling $(notdir $<)...$(NC)"
	@$(CC) $(CFLAGS) -I $(HSRCS) -I libft/ -o $@ -c $<

$(OBJ_DIR)/%.o: $(SRC_DIR_BONUS)/%.c 
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling $(notdir $<)...$(NC)"
	@$(CC) $(CFLAGS) -I $(HSRCS) -I $(HSRCS_BONUS) -I libft/ -o $@ -c $<

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
	@if [ -f $(NAME) ]; then \
		echo "$(RED)Cleaning executable $(NAME)...$(NC)"; \
		rm -f $(NAME); \
		fi
	@if [ -f $(NAME_BONUS) ]; then \
		echo "$(RED)Cleaning executable $(NAME_BONUS)...$(NC)"; \
		rm -f $(NAME_BONUS); \
		fi


re : fclean all

.PHONY: all clean fclean lclean re bonus

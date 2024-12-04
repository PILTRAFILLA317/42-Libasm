NAME = libasm_test
LIB_PATH = ./libasm
LIB = $(LIB_PATH)/libasm.a
SRC = main.c
OBJ = $(SRC:.c=.o)

CC = gcc

# Colores
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling libray ($(LIB_PATH)...)$(RESET)"
	@make -C $(LIB_PATH) --no-print-directory
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) -o $@ $^ $(LIB)
	@echo "$(GREEN)Done: $(NAME)$(RESET)"

%.o: %.c
	@echo "$(BLUE)Compiling $< ...$(RESET)"
	@sleep 0.1
	@$(CC) -o $@ -c $<
	@echo "$(GREEN) [OK]$(RESET)"

clean:
	@echo "$(RED)Cleaning objects...$(RESET)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)Cleaning library...$(RESET)"
	@make fclean -C $(LIB_PATH) --no-print-directory
	@echo "$(RED)Cleaning executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED)Done.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

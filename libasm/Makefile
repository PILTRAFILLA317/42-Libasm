AS = nasm
AR = ar
FLAGS = -f elf64
NAME = libasm.a
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS = $(SRCS:.s=.o)
OBJS_DIR = objs
OBJS_PATHS = $(addprefix $(OBJS_DIR)/, $(OBJS))

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS_PATHS)
	@echo "$(YELLOW)Creating libasm: $(NAME)...$(RESET)"
	@$(AR) rcs $@ $^
	@echo "$(GREEN)libasm created$(RESET)"

$(OBJS_DIR)/%.o: %.s
	@mkdir -p $(OBJS_DIR)
	@echo "$(BLUE)Compiling $< ...$(RESET)"
	@sleep 0.1
	@$(AS) $(FLAGS) -o $@ $<
	@echo "$(GREEN) [OK]$(RESET)"

clean:
	@rm -f $(OBJS_PATHS) @rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

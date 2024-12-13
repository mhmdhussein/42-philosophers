# Program name
NAME = philo

# Colors
GREEN = \033[39;42m
RED = \033[31m
MAGENTA = \033[35m
YELLOW = \033[33m
CYAN = \033[36m
RESET = \033[0m

# Compile flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS_DIR = srcs/
SRCS = $(SRCS_DIR)philo.c \
		$(SRCS_DIR)args.c \
		$(SRCS_DIR)error.c \
		$(SRCS_DIR)utils.c \
		$(SRCS_DIR)monitor.c \
		$(SRCS_DIR)routine.c \
		$(SRCS_DIR)simulation.c \
		$(SRCS_DIR)init.c

# Object files
OBJS_DIR = build/
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

# Include directories
INCLUDES = -I ./includes/

# Targets
all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(CYAN)Linking $@...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $(OBJS)
	@echo "$(GREEN)$@ ready!$(RESET)"

clean:
	@echo "$(MAGENTA)Cleaning object files...$(RESET)"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "$(RED)Cleaning philo...$(RESET)"
	@rm -f $(NAME)

re: fclean all

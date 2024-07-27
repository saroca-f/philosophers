NAME = philo
CC = clang
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=thread

MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY    = \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD    = \033[1m
RED     = \033[31;1m

FILES = main \
        src/parser \
        src/philo_utils \
		src/init \
		src/threads \
		src/action \
		src/write \
		src/free_philo \
        src/philo_tools/ft_atoi \
		src/philo_tools/ft_calloc \


SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo
	@echo "$(MAGENTA)philosopher compiled!$(RESET)"
	@echo

clean: 
	@rm -f $(OBJS) $(BNS_OBJS)
	@echo
	@echo "$(RED)Cleaning philosopher objects. $(RESET)"

fclean: clean
	@rm -f $(NAME) $(NAME_BNS)
	@echo "$(RED)Cleaning philosopher executables.$(RESET)"
	@echo

re: fclean all

.PHONY = all clean fclean re

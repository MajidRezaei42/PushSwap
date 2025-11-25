# ---------------------------------
# Variables
# ---------------------------------

# The name of your final executable
NAME = push_swap

# Compiler and standard flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Remove command
RM = rm -f

# ---------------------------------
# Library Directories
# ---------------------------------
LIBFT_DIR = libft

# ---------------------------------
# Library Paths
# ---------------------------------
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# ---------------------------------
# Include Paths
# ---------------------------------
# -I. (look in current dir for pipex.h)
# -Ilibft (look in libft dir for libft.h)
INCLUDES = -I. -I$(LIBFT_DIR)

# ---------------------------------
# Linker Flags (Libraries)
# ---------------------------------
# -L... specifies the path to the library
# -l... specifies the name of the library
LDFLAGS = -L$(LIBFT_DIR) -lft 

# ---------------------------------
# Source Files
# ---------------------------------

# Source files
SRCS = 		main.c				\
			oper_push.c			\
			oper_rev_rotation.c	\
			oper_rotation.c		\
			oper_swap.c			\
			parse_error.c		\
			sort_simple.c		\
			sort_utils.c		\
			sort.c				\
			stack_utils.c		\
			stack_utils2.c		\
			utils.c

# ---------------------------------
# Object Files
# ---------------------------------
OBJS = $(SRCS:.c=.o)

# ---------------------------------
# Rules
# ---------------------------------

# The 'all' rule is the default, it builds the MANDATORY program
all: $(NAME)

# Rule to build the mandatory program
$(NAME): $(LIBFT_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LDFLAGS)
	@echo "----------------------------------------------------"
	@echo "push_swap compiled! Run with:"
	@echo "./$(NAME)"
	@echo "----------------------------------------------------"

# Rule to build Libft
$(LIBFT_LIB):
	@echo "----------------------------------------------------"
	@echo "Building Libft..."
	@echo "----------------------------------------------------"
	@$(MAKE) -C $(LIBFT_DIR)

# Generic rule to compile any .c file into a .o file
%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiled $<"
	@echo "----------------------------------------------------"

# Rule to clean object files
clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "----------------------------------------------------"
	@echo "Object files cleaned."
	@echo "----------------------------------------------------"

# Rule to fully clean object files AND the executable
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "----------------------------------------------------"
	@echo "Executable cleaned."
	@echo "----------------------------------------------------"

# Rule to re-compile (fclean + all)
re: fclean all

# Declares rules that don't produce a file with the same name
.PHONY: all clean fclean re bonus

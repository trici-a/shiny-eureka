#Paths
SRCDIR = ./srcs/

INCDIR = ./include/

LIBFTDIR = ./libft/

#Files
SRC =	$(SRCDIR)main.c $(SRCDIR)create_stack.c  $(SRCDIR)free.c $(SRCDIR)args.c \
		$(SRCDIR)push.c $(SRCDIR)swap.c $(SRCDIR)rotate.c $(SRCDIR)rev_rotate.c \
		$(SRCDIR)sort_small.c $(SRCDIR)sort_large.c $(SRCDIR)parsing_utils.c \
		$(SRCDIR)sorting_utils.c

OBJ =	$(SRC:.c=.o)

#Targets
NAME = push_swap

LIBFT = $(LIBFTDIR)libft.a

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT)

$(LIBFT):
	make -C $(LIBFTDIR)

$(SRCDIR)%.o: $(SRCDIR)%.c
	$(CC) -c $(CFLAGS) $< -o $@

HDR = $(INCDIR)push_swap.h

#Compile Rules
CC = cc

CFLAGS = -Wall -Werror -Wextra -I$(INCDIR) -I$(LIBFTDIR)

RM = rm -f

#Colour Rules
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

#Phony Rules
all: $(NAME) $(HDR)

clean:
	@echo "$(GREEN)Removing object files\n$(RESET)"
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJ)

fclean: clean
	@echo "$(GREEN)Removing library and executable files\n$(RESET)"
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: fclean all
	@echo "$(GREEN)Removed object, static library and executable files\n$(RESET)"
	@echo "$(YELLOW)Rebuild COMPLETE$(RESET)"

.PHONY: all clean fclean re

#Paths

SRCDIR = ./src/

INCDIR = ./include/

#Files
SRC =	$(SRCDIR)ft_printf.c $(SRCDIR)ft_check_specifier.c $(SRCDIR)ft_puts.c\
		$(SRCDIR)ft_handle_char.c $(SRCDIR)ft_handle_str.c $(SRCDIR)ft_handle_int.c $(SRCDIR)ft_handle_unsigned.c\
		$(SRCDIR)ft_handle_hex.c $(SRCDIR)ft_handle_ptr.c $(SRCDIR)ft_handle_escape.c\

OBJ =	$(SRC:.c=.o)

#Targets
NAME =	ft_printf.a

$(NAME):	$(OBJ)
	ar rcs $@ $^

HDR = $(INCDIR)ft_printf.h

#Complie Rules
CC =	cc

CFLAGS =	-Wall -Wextra -Werror -I$(INCDIR) -I$(SRCDIR)

RM =	rm -f

#Colour Rules
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

#Phony Rules
all:	$(NAME) $(HDR)

%.o: %.c $(HDR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo "$(GREEN)Removing object files\n$(RESET)"
	$(RM) $(OBJ)

fclean: clean
	@echo "$(GREEN)Removing object and static library files\n$(RESET)"
	$(RM) $(NAME)

re: fclean all
	@echo "$(GREEN)Removed object, static library and executable files\n$(RESET)"
	@echo "$(YELLOW)Rebuild COMPLETE!\n$(RESET)"

.PHONY: all clean fclean re
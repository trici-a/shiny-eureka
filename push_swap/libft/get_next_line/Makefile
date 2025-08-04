#Files
SRC =	get_next_line.c get_next_line_utils.c\

BONUS =	get_next_line_bonus.c get_next_line_utils_bonus.c\

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

#Targets
NAME = get_next_line.a

$(NAME): $(OBJ)
	ar rcs $@ $^

HDR = get_next_line.h

#Complie Rules
CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

#Colour Rules
GREEN  = \033[0;32m
YELLOW = \033[0;33m
RESET  = \033[0m

#PHONY Rules

all: $(NAME) $(HDR) bonus

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $^

%.o: %.c $(HDR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo "$(GREEN)Removing object files\n$(RESET)"
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@echo "$(GREEN)Removing object files\n$(RESET)"
	$(RM) $(NAME) 

re: fclean all
	@echo "$(GREEN)Removed object, static library and executable files\n$(RESET)"
	@echo "$(YELLOW)Rebuild COMPLETE\n$(RESET)"
	
.PHONY: all bonus clean fclean re

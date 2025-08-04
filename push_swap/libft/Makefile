#Paths
GNLDIR = ./get_next_line/

FT_P_DIR = ./ft_printf/

#Files
SRC =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
		ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c\
		ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c\
		ft_split.c ft_itoa.c ft_putstr_fd.c ft_putendl_fd.c\
		ft_putnbr_fd.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c\
		ft_lstsize_bonus.c ft_lstlast_bonus.c\
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c ft_lstiter_bonus.c\
		ft_lstmap_bonus.c

OBJ =	$(SRC:.c=.o)

BONUS_OBJ =	$(BONUS:.c=.o)

FT_P_OBJ =	ft_printf.o ft_check_specifier.o ft_puts.o\
			ft_handle_char.o ft_handle_str.o ft_handle_int.o ft_handle_unsigned.o\
			ft_handle_hex.o ft_handle_ptr.o ft_handle_escape.o\

GNL_OBJ =	get_next_line.o get_next_line_utils.o\
			get_next_line_bonus.o get_next_line_utils_bonus.o\

#Targets
NAME =	libft.a

GNL = $(GNLDIR)get_next_line.a

FT_P = $(FT_P_DIR)ft_printf.a

$(NAME):	$(GNL) $(FT_P) $(OBJ)
	ar x $(GNL)
	ar x $(FT_P)
	ar rcs $@ $(OBJ) $(FT_P_OBJ) $(GNL_OBJ)

$(GNL):
	make -C get_next_line all bonus

$(FT_P):
	make -C ft_printf all

HDR = libft.h

#Compile Rules
CC =	cc

CFLAGS = -Wall -Wextra -Werror -I$(GNLDIR) -I$(FT_P_DIR)

RM =	rm -f

#Colour Rules
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

#Phony Rules
all:	$(NAME) $(HDR)

bonus:	$(BONUS_OBJ)
	make -C get_next_line bonus
	ar rcs $(NAME) $^

%.o: %.c $(HDR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo "$(GREEN)Removing object files\n$(RESET)"
	make -C $(GNLDIR) clean
	make -C $(FT_P_DIR) clean
	$(RM) $(OBJ) $(BONUS_OBJ) $(FT_P_OBJ) $(GNL_OBJ)

fclean: clean
	@echo "$(GREEN)Removing object and static library files\n$(RESET)"
	make -C $(GNLDIR) fclean
	make -C $(FT_P_DIR) fclean
	$(RM) $(NAME)

re: fclean all
	@echo "$(GREEN)Removed object, static library and executable files\n$(RESET)"
	@echo "$(YELLOW)Rebuild COMPLETE!\n$(RESET)"

.PHONY: all clean fclean re bonus
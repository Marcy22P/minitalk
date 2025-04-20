NAME            = libft.a
CC              = gcc
CFLAGS          = -Wall -Wextra -Werror
RM              = rm -f
AR              = ar

LIBFT_DIR       = .
PRINTF_DIR      = printf
GNL_DIR         = get_next_line

LIBFT_SRCS      = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
				  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				  ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				  ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

LIBFT_BONUS_SRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstlast.c

PRINTF_SRCS     = ft_print_char.c ft_print_hex.c ft_print_numbers.c ft_print_percent.c ft_print_ptr.c \
				  ft_print_string.c ft_printf.c ft_sort_printf.c

GNL_SRCS        = get_next_line.c get_next_line_utils.c get_next_line_bonus.c get_next_line_utils_bonus.c

LIBFT_SRCS_PATH        = $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS))
LIBFT_BONUS_SRCS_PATH  = $(addprefix $(LIBFT_DIR)/, $(LIBFT_BONUS_SRCS))
PRINTF_SRCS_PATH       = $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRCS))
GNL_SRCS_PATH          = $(addprefix $(GNL_DIR)/, $(GNL_SRCS))

SRCS            = $(LIBFT_SRCS_PATH) $(PRINTF_SRCS_PATH) $(GNL_SRCS_PATH)
BONUS_SRCS      = $(LIBFT_BONUS_SRCS_PATH)

OBJS            = $(SRCS:.c=.o)
BONUS_OBJS      = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) rcs $(NAME) $(OBJS)
	@echo "$(NAME) created!"

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -c $< -o $@

# Target bonus: compila anche i file bonus della libft
bonus: $(OBJS) $(BONUS_OBJS)
	@$(AR) rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(NAME) (with bonus) created!"


clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "Object files removed."


fclean: clean
	$(RM) $(NAME)
	@echo "Library removed."


re: fclean all
	@echo "Library recompiled."


# Target "a" che compila tutto (normale e bonus)
a: bonus
	@echo "All files (including bonus) compiled!"

.PHONY: all bonus clean fclean re a
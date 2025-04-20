# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpisani <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 19:15:23 by mpisani           #+#    #+#              #
#    Updated: 2025/02/22 19:15:34 by mpisani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_SERVER = server
NAME_CLIENT = client

CC     = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT     = $(LIBFT_DIR)/libft.a

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR) a

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(LIBFT)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

bonus: all
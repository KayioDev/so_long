# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/25 16:53:27 by klima-do          #+#    #+#              #
#    Updated: 2025/08/25 17:30:00 by klima-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
MLX_DIR     = minilibx-linux
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_DIR   = Libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_DIR     = srcs
SRC_FILES   = Map/map.c \
              Map/initialize.c \
              Render/render.c
SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) main.c
OBJS        = $(SRCS:.c=.o)

INCLUDES    = -I. -I$(LIBFT_DIR) -I$(MLX_DIR)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

run: $(NAME)
	./$(NAME) map.ber

debug: CFLAGS = -Wall -Wextra -g
debug: re

.PHONY: all clean fclean re run debug

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/04 14:00:12 by klima-do          #+#    #+#              #
#    Updated: 2025/09/04 14:08:33 by klima-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
MLX_DIR     = minilibx-linux
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_DIR   = Libft
LIBFT       = $(LIBFT_DIR)/libft.a
PRINTF_DIR  = $(LIBFT_DIR)/Ft_Printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a

SRC_DIR     = srcs
SRC_FILES   = Map/map.c \
              Map/initialize.c \
			  Map/validator.c \
              Render/render.c \
			  Render/load_sprites.c \
			  Settings/Controls.c \
			  Settings/Setting.c
SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) main.c
OBJS        = $(SRCS:.c=.o)

INCLUDES    = -I. -I$(LIBFT_DIR) -I$(MLX_DIR)

all: $(NAME)

$(LIBFT):
	@echo "📚 Compilando Libft..."
	@$(MAKE) -s -C $(LIBFT_DIR)

$(PRINTF):
	@echo "🖨️ Compilando Ft_Printf..."
	@$(MAKE) -s -C $(PRINTF_DIR)

%.o: %.c
	@echo "⚙️  Compilando $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	@echo "🔨 Linkando $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	@echo "🧹 Limpando objetos..."
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(PRINTF_DIR) clean

fclean: clean
	@echo "🧹 Limpando tudo..."
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(PRINTF_DIR) fclean

re: fclean all

run: $(NAME)
	./$(NAME) /Maps/map.ber

debug: CFLAGS = -Wall -Wextra -g
debug: re

.PHONY: all clean fclean re run debug

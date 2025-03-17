# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmohd-ed <nurhidayahtihani@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 10:33:51 by nmohd-ed          #+#    #+#              #
#    Updated: 2025/03/17 14:15:09 by nmohd-ed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fdf
CFLAGS = -Wall -Wextra -Werror -g 

INCLUDES = -I include -I./lib/libft

MLX_DIR = lib/minilibx-linux
LIBFT_DIR = lib/libft

LIBFT = -L $(LIBFT_DIR) -lft
MLX = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRC = main.c map.c free_error.c map_utils.c draw.c draw_utils.c

OBJ = $(SRC:.c=.o)

%.o:%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@echo "Building libft..."
	@make -C $(LIBFT_DIR) --silent
	@echo "Building minilibx..."
	@make -C $(MLX_DIR) --silent
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)
	@echo "✅ Build complete!"

all: $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean --silent
	@make -C $(MLX_DIR) clean --silent
	@rm -f $(OBJ)
	@echo "🗑️ Cleaned object files."

fclean: clean
	@make -C $(LIBFT_DIR) fclean --silent
	@make -C $(MLX_DIR) clean --silent
	@rm -f $(NAME)
	@echo "🗑️ Fully cleaned project."

re: fclean all

.PHONY: all clean fclean re
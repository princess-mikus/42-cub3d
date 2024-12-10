# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 12:52:31 by fcasaubo          #+#    #+#              #
#    Updated: 2024/11/27 11:12:46 by fcasaubo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3d
SRC_DIR		:=	src
SRC			:=	main.c	 	\
				movement.c	\
				rays.c		\
				image.c		\
				textures.c

MLX_DIR		:=	mlx
MLX			:=	$(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
INC			:= -I include -I $(MLX_DIR)/include

LIBFT_DIR	:= libft
LIBFT		:= libft.a

OBJ_DIR	:=	obj
OBJ		:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

CC		:=	gcc
CCFLAGS	:=	# -Wall -Wextra -Werror

all: $(MLX) $(NAME)

$(MLX):
	@clear
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CCFLAGS) $(INC) $(OBJ) $(MLX) $(LIBFT_DIR)/$(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	@$(CC) -c $(CCFLAGS) $(INC) $< $(MLX) -o $@

clean:
	@rm -fr $(OBJ_DIR)
	@make -C $(LIBFT_DIR) fclean

fclean: clean
	@rm -fr $(MLX_DIR)/build
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
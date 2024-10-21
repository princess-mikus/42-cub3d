# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 12:52:31 by fcasaubo          #+#    #+#              #
#    Updated: 2024/10/18 10:43:20 by fcasaubo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3d
SRC_DIR		:=	src
SRC			:=	main.c

MLX_DIR		:=	mlx
MLX			:=	$(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
INC			:= -I include -I $(MLX_DIR)/include

OBJ_DIR	:=	obj
OBJ		:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

CC		:=	gcc
CCFLAGS	:=	# -Wall -Wextra -Werror

all: $(MLX) $(NAME)

$(MLX):
	@clear
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(NAME): $(OBJ)
	@$(CC) $(CCFLAGS) $(INC) $(OBJ) $(MLX) -o $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	@$(CC) -c $(CCFLAGS) $(INC) $< $(MLX) -o $@

clean:
	@rm -fr $(OBJ_DIR)

fclean: clean
	@rm -fr $(MLX_DIR)/build
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
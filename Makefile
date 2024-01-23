# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 12:41:11 by cyferrei          #+#    #+#              #
#    Updated: 2024/01/18 14:00:12 by cyferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g3
XFLAGS = -Lmlx_linux -Imlx_linux -lX11 -lXext -lm -lz -Ofast
LIB_MLX = minilibx-linux/libmlx.a
LIBFT_SO_LONG = libft_so_long/libft_so_long.a

SOURCE = ./sources/

MAP = $(addprefix map/, map_utils.c map_validation.c map.c parsing_map.c valid_path.c valid_path_utils.c)
DISPLAY = $(addprefix display/, display_utils.c display.c render_map.c)
MOVE = $(addprefix movements/, movement_down.c movement_left.c movement_right.c movement_up.c movements_utils.c)
GAME = $(addprefix $(SOURCE), $(MAP) $(DISPLAY) $(MOVE) so_long.c end_game.c)

SRC = $(GAME)
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(RM) $(NAME)
	make all -C ./libft_so_long
	$(CC) $(CFLAGS) $(OBJ) $(LIB_MLX) $(XFLAGS) $(LIBFT_SO_LONG) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $(<:%.c=%.o)

clean:
	$(RM) $(OBJ)
	make clean -C ./libft_so_long

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft_so_long

re: fclean all

.PHONY: all clean fclean re
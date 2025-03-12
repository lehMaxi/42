# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 11:14:24 by mlehmann          #+#    #+#              #
#    Updated: 2025/03/10 14:06:44 by mlehmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = play_me
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft
CC = cc
INCLUDE = -I/usr/include -Imlx_linux -Ilibft -I./
MLX = ./mlx_linux/mlx_Linux.a
LIB = ./libft/libft.a
SOURCE = play.c image_handling.c utils.c rapture.c
OBJECT = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):$(MLX) $(LIB) $(OBJECT)
	$(CC) $(OBJECT) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(MLX):
	$(MAKE) -C ./mlx_linux

$(LIB):
	$(MAKE) -C ./libft

clean:
	rm -f $(OBJECT)
	clean ./libft

fclean:
	rm -f $(NAME)
	make fclean ./libft
	make clean ./mlx_linux

re: fclean all

.PHONY: clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 11:10:46 by mlehmann          #+#    #+#              #
#    Updated: 2024/11/26 13:13:57 by mlehmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Filename and compilation
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
INCLUDE = -I .
#C files
SOURCE = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
#O files
OBJECT = $(SOURCE:.c=.o)
#The real work
all: $(NAME)

$(NAME): $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#cleanup
clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re

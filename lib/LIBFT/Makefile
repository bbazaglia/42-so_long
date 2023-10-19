# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 10:32:51 by bbazagli          #+#    #+#              #
#    Updated: 2023/10/19 11:10:45 by bbazagli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC    := $(shell find ./src -iname "*.c")
OBJ := $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
HEADERS	:= -I ./include

all: $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


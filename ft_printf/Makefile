# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroldan- <jroldan-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 12:30:31 by jroldan-          #+#    #+#              #
#    Updated: 2022/12/19 17:37:16 by jroldan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAG = -Wall -Wextra -Werror

SRC =libftprintf.c 

CC = gcc
OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) -c $(SRC)
	ar rc $(NAME) $(OBJ) $(SRC)

all : $(NAME)

re : fclean all

clean :
	rm - f *.o $(NAME)

fclean :
	rm -f *.a *.o $(NAME)

.PHONY : clean fclean all re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroldan- <jroldan-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 12:30:31 by jroldan-          #+#    #+#              #
#    Updated: 2022/12/20 20:40:11 by jroldan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
CFLAG = -Wall -Wextra -Werror

SRC = ft_printf.c ft_character.c

CC = gcc
OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) -c $(SRC)
	ar rc $(NAME) $(OBJ) $(SRC)

all : $(NAME)

re : fclean all

clean :
	rm  -f $(OBJ)

fclean :
	rm  -f $(NAME)

.PHONY : clean fclean all re
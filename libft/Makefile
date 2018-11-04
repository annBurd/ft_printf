# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 19:02:29 by aburdeni          #+#    #+#              #
#    Updated: 2017/12/25 19:30:08 by aburdeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = \
    ft_atoi.c \
	ft_bzero.c \
	ft_nbrlen.c \
	ft_nbrulen.c \
	ft_strlen.c \
	ft_tolower.c
 
OBJ = $(SRC:.c=.o)

$(NAME):
	@$(CC) $(CFLAGS) -c $(NAME:.a=.h) $(SRC)
	@ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(NAME:.a=.h.gch)
	
fclean:
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft.a

.NOTPARALLEL: all clean fclean re libft.a

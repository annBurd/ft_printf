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

all: $(NAME)
	@echo "got ""\033[2;36m""$(NAME)""\033[0m"

$(NAME):
	@$(CC) $(CFLAGS) -c $(NAME:.a=.h) $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)
	
fclean: clean
	@$(RM) $(NAME)
	@echo "\033[2;36m""libft""\033[0m"" was fcleaned"

re: fclean all

.PHONY: all clean fclean re libft.a

.NOTPARALLEL: all clean fclean re libft.a

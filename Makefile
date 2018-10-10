# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/04 18:22:11 by aburdeni          #+#    #+#              #
#    Updated: 2018/10/10 00:58:09 by aburdeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/
LIBFT_DIR = ./libft/

HEADER = $(addprefix $(INC_DIR), ft_printf.h)

SRC = ft_printf.c \
	additional.c \
	define_flags.c \
    handle_char.c \
    handle_integer.c \
    handle_wc.c \
    pr_join.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)
	@echo "\nft_printf: got $(NAME)"

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@ar rc $(NAME) $(OBJ) $(LIBFT_DIR)*.o

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
	@echo -n _/\\_

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_DIR) clean
	
fclean:	clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "ft_printf: fcleaned"

re: fclean all

.PHONY: all clean fclean re libftprintf.a libft.a

# vpath %.c $(SRC_DIR)
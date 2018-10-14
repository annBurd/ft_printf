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
	handle_char.c \
	handle_nbr.c \
	handle_wchar.c \
	pr_color_me.c \
	pr_define_my_flags.c \
	pr_extract_me.c \
	pr_join_me.c \
	pr_refresh_me.c \
	pr_utoa_me.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)
	@echo "\n\033[35mft_printf\033[0m got $(NAME)"

$(NAME): 
	@make $(OBJ)
	@make -C $(LIBFT_DIR)
	@ar rc $(NAME) $(OBJ) $(LIBFT_DIR)*.o

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
	@echo -n ' <@>'

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_DIR) clean
	
fclean:	
	@make clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "\033[35mft_printf\033[0m was fcleaned"

re: fclean all

.PHONY: all clean fclean re libftprintf.a libft.a

# vpath %.c $(SRC_DIR)
	# @rm -rf $(OBJ_DIR)
	# @mkdir $(OBJ_DIR)
	# @rm -rf $(OBJ_DIR)
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/04 18:22:11 by aburdeni          #+#    #+#              #
#    Updated: 2018/11/17 15:46:09 by aburdeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/
LIBFT_DIR = ./libft/

HEADER = $(wildcard $(INC_DIR)*.h)

SRC = ft_printf.c \
	handle_cs.c \
	handle_id.c \
	handle_oubxp.c \
	pr_color.c \
	pr_define_flags.c \
	pr_join.c \
	pr_utoa.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: 
	@mkdir -p $(OBJ_DIR)
	@make -C $(LIBFT_DIR)
	@echo "start compilation""\033[2;35m"
	@make $(NAME)
	@echo "\n\033[0m""got ""\033[2;36m""$(NAME)""\033[0m"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) $(LIBFT_DIR)*.o

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n ' <@>'

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	
fclean:	
	@make clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "\033[2;36m""ft_printf""\033[0m"" was fcleaned"

re: fclean all

.PHONY: all clean fclean re libftprintf.a libft.a

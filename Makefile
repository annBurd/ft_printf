# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/04 18:22:11 by aburdeni          #+#    #+#              #
#    Updated: 2018/07/04 18:22:26 by aburdeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

HEADER = $(addprefix $(INC_DIR), ft_printf.h)

SRC = ft_printf.c \
	additional.c \
	define_specification.c \
	t_sp.c \
	handle_percentage.c \
	handle_signed.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(LIBFT)
	@mkdir $(OBJ_DIR)
	@make $(NAME)
	@echo "ft_printf: got $(NAME)"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) $(LIBFT_DIR)libft.a

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	
fclean:	clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "ft_printf: fcleaned"

re: fclean all



.PHONY: all clean fclean re libftprintf.a libft.a

.NOTPARALLEL: all clean fclean re libftprintf.a libft.a

# vpath %.c $(SRC_DIR)

# tes:
# 	@$(RM) tes
# 	@$(CC) $(CFLAGS) main.c $(NAME) $(LIBFT) -o tes
# 	@echo "ft_printf: got binary tes"
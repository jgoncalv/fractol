# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 16:00:09 by jgoncalv          #+#    #+#              #
#    Updated: 2017/03/15 16:00:15 by jgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -Ofast

LIB = libft
LIB_A = $(LIB)/libft.a

LDFLAGS = -Llibft

LDLIBS = -lft -lmlx -framework OpenGL -framework AppKit

SRC_PATH = src

SRC_NAME = main.c\
			fractal.c\
			mlx.c\
			keyhook.c\
			mandelbrot.c\
			julia.c\
			pointerhook.c\
			mousehook.c\
			burningship.c

INC = include/fractol.h

AR = ar rc

INC_LIB = -I libft/include

CPPFLAGS = -I include

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: makefile $(INC) $(LIB_A) $(NAME)

$(LIB_A):
	@make -C $(LIB)

$(NAME): $(OBJ)
	@echo $(NAME) ": Sources compiling..."
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)
	@echo "Executable "$(NAME)" made"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	@mkdir -p $(dir $(OBJ)) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_LIB) -o $@ -c $<

clean:
	@make fclean -C $(LIB)
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH) || true
	@echo $(OBJ_PATH)" supprimé !"

fclean: clean
	@rm -f $(NAME)
	@echo "Executable de "$(NAME)" supprimé !"

re: fclean all
	@echo "Make re done !"

norme:
	norminette $(SRC)
	norminette $(INC_PATH)

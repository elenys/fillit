# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 10:30:38 by bmartins          #+#    #+#              #
#    Updated: 2015/12/08 18:07:20 by bmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 

DIR_H = ./incs/

DIR_C = ./srcs/

DIR_O = ./objs/

FILE_C = main.c checks_functions.c 

FILE_O = $(FILE_C:.c=.o)

SRC_C := $(addprefix $(DIR_C), $(FILE_C))

SRC_O := $(addprefix $(DIR_O), $(FILE_O))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_O)
	@clang -o $(NAME) $(SRC_O) -L libft/ -lft

$(SRC_O): $(SRC_C)
	@make -C libft/
	@clang $(FLAGS) -c $(SRC_C) -I $(DIR_H)
	@mkdir -p $(DIR_O)
	@mv $(FILE_O) $(DIR_O)

clean:
	@/bin/rm -rf $(DIR_O)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: clean fclean cclean all re

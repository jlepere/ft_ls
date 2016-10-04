# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/01 15:03:08 by jlepere           #+#    #+#              #
#*   Updated: 2016/06/01 15:07:31 by jlepere          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean norme re

CXX = gcc
NAME = ft_ls
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -lft

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
LIB_PATH = ./libft/

SRC_NAME = main.c ft_ls_argv.c ft_ls_path.c ft_ls_data.c ft_ls_view.c \
	ft_ls_flag.c ft_ls_sort.c ft_ls_stat.c ft_ls_util.c
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB = $(addprefix -L, $(LIB_PATH))
INC = $(addprefix -I, $(INC_PATH))
INC += $(addprefix -I, $(LIB_PATH)includes/)

all: $(NAME)

$(NAME): $(OBJ)
	@$(foreach DIR, $(LIB_PATH), $(MAKE) -sC $(DIR) ;)
	@$(CXX) $^ $(LIB) $(LFLAGS) -o $@
	@printf "%-72s\033[32;01m[FINISH]\033[0m\n" "[BIN] Built target $@ ..."

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CXX) $(CFLAGS) $(INC) -c $< -o $@
	@printf "%-73s\033[33;01m[BUILD]\033[0m\n" "[GCC] Building object $@ ..."

clean:
	@$(foreach DIR, $(LIB_PATH), $(MAKE) -sC $(DIR) clean;)
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@printf "%-73s\033[31;01m[CLEAN]\033[0m\n" "[BIN] Clear target $(NAME) ..."

fclean: clean
	@rm -f $(NAME)

norme:
	norminette $(SRC_PATH)
	norminette $(INC_PATH)

re: fclean all

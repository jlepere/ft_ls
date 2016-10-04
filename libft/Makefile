# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:36:04 by jlepere           #+#    #+#              #
#    Updated: 2016/04/06 15:58:20 by jlepere          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CXX = gcc
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

SRC_NAME = ft_memcmp.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
		   ft_memset.c ft_memalloc.c ft_memdel.c ft_bzero.c ft_strnew.c \
		   ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
		   ft_strchr.c ft_strnchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
		   ft_strmap.c ft_strmapi.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		   ft_strsplit.c ft_strclr.c ft_strdel.c ft_strdel_tab.c ft_striter.c \
		   ft_striteri.c ft_strlen.c ft_strlcat.c ft_strcmp.c ft_strncmp.c \
		   ft_strequ.c ft_strnequ.c \
		   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		   ft_toupper.c ft_tolower.c ft_intlen.c ft_atoi.c ft_itoa.c \
		   ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
		   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
		   ft_lstmap.c ft_lstdel.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c \
		   ft_cbuff_new.c ft_cbuff_add.c ft_cbuff_free.c
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@ranlib $@
	@printf "%-72s\033[32;01m[FINISH]\033[0m\n" "[LIB] Built target $@ ..."

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CXX) $(CFLAGS) $(INC) -c $< -o $@
	@printf "%-73s\033[33;01m[BUILD]\033[0m\n" "[GCC] Building object $@ ..."

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@printf "%-73s\033[31;01m[CLEAN]\033[0m\n" "[LIB] Clear target $(NAME) ..."

fclean: clean
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC_PATH)
	norminette $(INC_PATH)

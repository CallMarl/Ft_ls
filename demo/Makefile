# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/06 12:01:52 by pprikazs          #+#    #+#              #
#    Updated: 2018/03/06 12:02:02 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB_DIR = ../libs
export LIB_NEED = ./libft

DEBUG = no
ifeq ($(DEBUG), yes)
	FLAGS = -g -w
endif
	
INCLUDES = -I./includes/
LIBS = ./libs/libft.a

SRCS = ./main.c\

OBJ = $(SRCS:./%.c=./%.o)

.PHONY: all clean fclean re

all : $(NAME)

%.o : %.c
	@$(CC) $(INCLUDES) -c $< -o $@ $(FLAGS)

$(NAME) : $(OBJ)
	@echo "Compilation ft_ls..."
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $^ -o $@ $(LIBS)

clean :
	@$(MAKE) clean "LIB_NEED = $(LIB_NEED)" -C $(LIB_DIR)
	@rm -f $(OBJ)

fclean :
	@$(MAKE) fclean "LIB_NEED = $(LIB_NEED)" -C $(LIB_DIR)
	@rm -f $(OBJ) $(NAME)

re : fclean $(NAME)

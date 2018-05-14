# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/03 17:06:17 by pprikazs          #+#    #+#              #
#    Updated: 2018/05/14 17:15:22 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc

DEBUG = no
FLAGS = -Wall -Wextra -Werror

ifeq ($(DEBUG), yes)
	FLAGS = $(FLAGS) -g -fsanitize=adress
endif

NOFLAGS = no
ifeq ($(DEBUG), yes)
	FLAGS = -g -w
endif
	
DEPS = includes/*.h Makefile
INCLUDES = -I./includes/

SRCS = ./main.c \
	   ./srcs/ft_debug.c \
	   ./srcs/ft_error.c \
	   ./srcs/ft_global.c \
	   ./srcs/ft_ls.c \
	   ./srcs/ft_ls_args.c \
	   ./srcs/ft_ls_noargs.c \
	   ./srcs/buff/ft_buff_get.c \
	   ./srcs/buff/ft_buff_getfile.c \
	   ./srcs/buff/ft_buff_insert.c \
	   ./srcs/buff/ft_buff_new.c \
	   ./srcs/buff/ft_buff_rm.c \
	   ./srcs/display/ft_display_column.c \
	   ./srcs/display/ft_display_file.c \
	   ./srcs/display/ft_display_long.c \
	   ./srcs/display/ft_display_ls.c \
	   ./srcs/display/ft_display_path.c \
	   ./srcs/display/ft_display_prepare.c \
	   ./srcs/display/ft_display_preparestr.c \
	   ./srcs/display/ft_display_short.c \
	   ./srcs/display/ft_display_utils.c \
	   ./srcs/error/ft_err_opendir.c \
	   ./srcs/error/ft_err_openstat.c \
	   ./srcs/param/ft_param_get.c \
	   ./srcs/param/ft_param_parse.c \
	   ./srcs/sort/ft_sort_file.c \
	   ./srcs/sort/ft_sort_filecmp_c.c \
	   ./srcs/sort/ft_sort_filecmp_d.c

OBJ = $(SRCS:./%.c=./%.o)
	
LIB_DIR = ../libs
LIBS = ./libs/libft.a
export LIB_NEED = ./libft

.PHONY: all clean fclean re
.SUFFIXES:

all : $(NAME)

%.o : %.c
	$(CC) $(INCLUDES) -c $< -o $@ $(FLAGS)

$(NAME) : $(OBJ) $(DEPS)
	@echo "Compilation ft_ls1..."
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $(OBJ) -o $@ $(LIBS)

clean :
	@$(MAKE) clean -C $(LIB_DIR)
	@rm -f $(OBJ)

fclean :
	@$(MAKE) fclean -C $(LIB_DIR)
	@rm -f $(OBJ) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

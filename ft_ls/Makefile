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

SRCS = ./main.c \
	   ./srcs/buffer/ft_buffer_initarr.c \
	   ./srcs/buffer/ft_buffer_setinfo.c \
	   ./srcs/ft_display.c \
	   ./srcs/ft_ls.c \
	   ./srcs/node/ft_node_getinfo.c \
	   ./srcs/node/ft_node_setinfo.c \
	   ./srcs/params/ft_param_arrsize.c \
	   ./srcs/params/ft_param_delarr.c \
	   ./srcs/params/ft_param_display.c \
	   ./srcs/params/ft_param_get.c \
	   ./srcs/params/ft_param_initarr.c \
	   ./srcs/params/ft_param_parse.c \
	   ./srcs/params/ft_param_set.c \
	   ./srcs/path/ft_path_init.c

OBJ = $(SRCS:./%.c=./%.o)

DEPS = includes/*.h Makefile
DEPS += $(shell find -E . -regex ".*\.[ch]")

.PHONY: all clean fclean re
.SUFFIXES:

all : $(NAME)

%.o : %.c
	@$(CC) $(INCLUDES) -c $< -o $@ $(FLAGS)

$(NAME) : $(OBJ)
	@echo "Compilation ft_ls..."
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $^ -o $@ $(LIBS)

clean :
	@$(MAKE) clean -C $(LIB_DIR)
	@rm -f $(OBJ)

fclean :
	@$(MAKE) fclean -C $(LIB_DIR)
	@rm -f $(OBJ) $(NAME)

re :
	$(MAKE) -C fclean
	$(MAKE) -C all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:26:31 by blefeuvr          #+#    #+#              #
#    Updated: 2018/03/04 14:09:14 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT = $(shell pwd)/

PRGS = $(ROOT)/ft_ls/

.PHONY: all clean fclean re

all :
	@sh init.sh
	@for dir in $(PRGS) ; \
		do \
			$(MAKE) -C $$dir; \
		done

clean : 
	@for dir in $(PRGS) ; \
		do \
			$(MAKE) $@ -C $$dir; \
		done

fclean :
	@for dir in $(PRGS) ; \
		do \
			$(MAKE) $@ -C $$dir; \
		done
	@sh uninit.sh

re : fclean all

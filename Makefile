# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 13:03:19 by pprikazs          #+#    #+#              #
#    Updated: 2018/05/18 13:04:48 by pprikazs         ###   ########.fr        #
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

re :
	$(MAKE) fclean
	$(MAKE) all

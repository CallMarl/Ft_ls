# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:26:31 by blefeuvr          #+#    #+#              #
#    Updated: 2018/05/03 14:00:27 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT = $(shell pwd)/

PRGS = $(ROOT)/ft_ls/ \
	   $(ROOT)/demo/

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

ROOT = $(shell pwd)/

.PHONY: all clean fclean re

all :
	@for dir in $(LIB_NEED) ; \
		do \
			$(MAKE) -C $(ROOT)$$dir; \
		done

clean : 
	@for dir in $(LIB_NEED) ; \
		do \
			$(MAKE) $@ -C $(ROOT)$$dir; \
		done

fclean :
	@for dir in $(LIB_NEED) ; \
		do \
			$(MAKE) $@ -C $(ROOT)$$dir; \
		done

re :
	$(MAKE) fclean
	$(MAKE) all

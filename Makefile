##
## 		R O O T  M A K E F I L E
##
## Corentin COUTRET-ROZET
## https://github.com/sheiiva/DuckHunt
##
##

NAME 		= 	root_makefile

SRC_PATH	=	./sources/
LIB_PATH	=	./lib/

CLEAN		=	clean
FCLEAN		=	fclean

all:
	@$(MAKE) -C $(LIB_PATH)
	@$(MAKE) -C $(SRC_PATH)

clean:
	@$(MAKE) $(CLEAN) -C $(LIB_PATH)
	@$(MAKE) $(CLEAN) -C $(SRC_PATH)

fclean:
	@$(MAKE) $(FCLEAN) -C $(LIB_PATH)
	@$(MAKE) $(FCLEAN) -C $(SRC_PATH)

re: fclean all

.PHONY: all clean fclean re

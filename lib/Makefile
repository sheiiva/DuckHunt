##
## 		L I B  M A K E F I L E
##
## Corentin COUTRET-ROZET
## https://github.com/sheiiva/DuckHunt
##
##

AR			=	ar rc

PRINT		=	@echo -e
RM          =   @rm -f

ROOT_PATH			=	../
INCLUDE_PATH		=	$(ROOT_PATH)include/
LIB_INCLUDE_PATH	=	my/include/

INCLUDES			=	-I$(LIB_INCLUDE_PATH)

override CFLAGS 	+=	-W -Wall -Werror -Wextra $(INCLUDES)
override LDFLAGS 	+=
override LDLIBS 	+=


SRC			=	my/my_putchar.c

OBJ 		= 	$(SRC:.c=.o)


NAME 		= 	libmy.a

$(NAME): $(OBJ)
	$(PRINT) "\n------->\tPRECOMPILED SRC DEPENDENCIES.\n\nLET'S LINK IT ALL:\n"
	$(AR) $@ $^ 
	$(PRINT) "\n------->\tCONGRATS !\n"
	@cp $(LIB_INCLUDE_PATH)/my.h $(INCLUDE_PATH)

all: $(NAME)

clean:
	$(PRINT) "\n------->\tREMOVE TMP FILES\n"
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)
	$(RM) $(INCLUDE_PATH)/my.h

fclean: clean
	$(PRINT) "------->\tREMOVE BINARY\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
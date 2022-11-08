##
## 		L I B  M A K E F I L E
##
## Corentin COUTRET-ROZET
## https://github.com/sheiiva/DuckHunt
##
##

CC			=	gcc
AR			=	ar rc
PRINT		=	@echo -e
RM          =   @rm -f

INCLUDES	=	$(shell find . -name '*.h' | grep -oP ".*/")

SOURCES		=	$(shell find . -name '*.c')

OBJ 		= 	$(SOURCES:.c=.o)

override CFLAGS 	+=	-W -Wall -Werror -Wextra -I$(INCLUDES)

NAME 		= 	libmy.a

$(NAME): $(OBJ)
	$(PRINT) "\n------->\tPRECOMPILED SRC DEPENDENCIES.\n\nLET'S LINK IT ALL:\n"
	$(AR) $@ $^ 
	$(PRINT) "\n------->\tCONGRATS !\n"

all: $(NAME)

clean:
	$(PRINT) "\n------->\tREMOVE TMP FILES\n"
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	$(PRINT) "------->\tREMOVE BINARY\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
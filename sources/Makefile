##
## 		S O U R C E S  M A K E F I L E
##
## Corentin COUTRET-ROZET
## https://github.com/sheiiva/DuckHunt
##
##

CC			=	gcc
LD			=	$(CC)

PRINT		=	@echo -e
RM          =   @rm -f

ROOT_PATH			=	../
INCLUDE_PATH		=	$(ROOT_PATH)include/

LIB_PATH			=	$(ROOT_PATH)lib/

override CFLAGS 	+=	-W -Wall -Werror -Wextra -I$(INCLUDE_PATH)
override LDFLAGS 	+=	-L$(LIB_PATH)
override LDLIBS 	+=	-lmy -lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window


SRC			=	main.c				\
				manager/duckManager.c		\
				manager/eventManager.c		\
				manager/sceneManager.c		\
				manager/systemManager.c		\
				manager/windowManager.c		\
				manager/objects/imageManager.c		\
				manager/objects/soundManager.c		\
				manager/objects/textManager.c		\
				scenes/gameScene.c		\

OBJ 		= 	$(SRC:.c=.o)


NAME 		= 	$(ROOT_PATH)DuckHunt

$(NAME): $(OBJ)
	$(PRINT) "\n------->\tPRECOMPILED SRC DEPENDENCIES.\n\nLET'S LINK IT ALL:\n"
	$(LD) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
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
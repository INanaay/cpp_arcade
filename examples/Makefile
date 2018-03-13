##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

NAMEBIN	=	./arcade

NAMELIB1	= ./lib/lib_arcade_ncurses.so

NAMELIB2	=	./lib/lib_arcade_SFML.so



SRCBIN	= ./src/main.cpp	\
					./src/Core.cpp

SRCLIB1	= ./src/Glib/NcursesWrapper.cpp

SRCLIB2	=	./src/Glib/SFMLWrapper.cpp

OBJBIN	=	$(SRCBIN:.cpp=.o)



CC	=	g++

CFLAGS	=	-W -Wall -Wextra -Werror -std=c++17

RM	=	rm -rf


all:		bin libs

bin:	$(OBJBIN)
	$(CC) -o $(NAMEBIN) $(OBJBIN) $(CFLAGS) -ldl

libs:
	$(CC) -fPIC -shared -lncurses -o $(NAMELIB1) $(SRCLIB1) $(CFLAGS)
	$(CC) -fPIC -shared -lsfml-graphics -lsfml-window -lsfml-system -o $(NAMELIB2) $(SRCLIB2) $(CFLAGS)

clean:
		$(RM) $(OBJBIN)

fclean:		clean
		$(RM) $(NAMEBIN)
		$(RM) $(NAMELIB1)

re:		fclean all

.PHONY:		all clean fclean re bin libs

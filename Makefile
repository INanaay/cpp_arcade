##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

NAMEBIN	=	arcade

NAMELIB1	= ./lib/lib_arcade_ncurses.so



SRCBIN	= ./src/main.cpp

SRCLIB1	= ./src/Glib/ncurses/NcursesWrapper.cpp


OBJBIN	=	$(SRCBIN:.cpp=.o)

OBJLIB1	=	$(SRCLIB1:.cpp=.o)



CC	=	g++

CFLAGS	=	-W -Wall -Wextra -std=c++17

RM	=	rm -rf


all:		bin libs

bin:	$(OBJBIN)
	$(CC) -o $(NAMEBIN) $(OBJBIN) $(CFLAGS) -ldl

libs:
	$(CC) -fPIC -shared -o $(NAMELIB1) $(SRCLIB1) $(CFLAGS)


clean:
		$(RM) $(OBJBIN)
		$(RM) $(OBJLIB1)

fclean:		clean
		$(RM) $(NAMEBIN)
		$(RM) $(NAMELIB1)

re:		fclean all

.PHONY:		all clean fclean re bin libs

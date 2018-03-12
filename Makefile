##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

NAMEBIN	=	arcade

NAMELIB1	= ./lib/lib_arcade_ncurses.so



SRCBIN	= src/main.cpp

SRCLIB1	= src/ncurses/NcursesWrapper.cpp



OBJBIN	=	$(SRCBIN:.cpp=.o)

OBJLIB1	=	$(SRCLIB1:.cpp=.o)



CC	=	g++

CFLAGS	=	-W -Wall -Wextra -std=c++17

LIBFLAGS	+= -fpic -shared

RM	=	rm -rf


all:		bin libs

bin:	$(OBJBIN)
	$(CC) -o $(NAMEBIN) $(OBJBIN) $(CFLAGS)

libs:	$(OBJLIB1)
	$(CC) -o $(NAMELIB1) $(OBJLIB1) $(CFLAG) $(LIBFLAGS) -lncurses


clean:
		$(RM) $(OBJBIN)
		$(RM) $(OBJLIB1)

fclean:		clean
		$(RM) $(NAMEBIN)
		$(RM) $(NAMELIB1)

re:		fclean all

.PHONY:		all clean fclean re bin libs

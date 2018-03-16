##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

NAMEBIN		= arcade
SFMLNAME	= ./lib/lib_arcade_SFML.so
NCURSESNAME	= ./lib/lib_arcade_ncurses.so



SRCBIN		= 	./src/main.cpp		\
			./src/Common/Core.cpp
SRCNCURSES	=	./src/Wrappers/NcursesWrapper.cpp
SRCSFML		=	./src/Wrappers/SFMLWrapper.cpp

CXX		= g++
CXXFLAGS 	= -W -Wall -Wextra -Werror -std=c++17

OBJBIN	= $(SRCBIN:.cpp=.o)
OBJSFML = $(SRCSFML:.cpp=.o)
OBJNCURSES = $(SRCNCURSES:.cpp=.o)

RM	= rm -rf

all:	graphicals core

core:	$(OBJBIN)
	$(CXX) -o $(NAMEBIN) $(OBJBIN) $(CXXFLAGS) -ldl -lstdc++fs

graphicals: $(OBJNCURSES) $(OBJSFML)
	$(CXX) $(OBJNCURSES) -shared -lncurses -o $(NCURSESNAME)
	$(CXX) $(OBJSFML) -shared -lsfml-graphics -lsfml-window -lsfml-system -o $(SFMLNAME)


clean:
		$(RM) $(OBJBIN)
		$(RM) $(OBJSFML)
		$(RM) $(OBJNCURSES)

fclean:		clean
		$(RM) $(NAMEBIN)
		$(RM) $(SFMLNAME)
		$(RM) $(NCURSESNAME)

re:		fclean all

.PHONY:		all clean fclean re core graphicals

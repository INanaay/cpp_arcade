##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

CXX	=	g++ -shared
RM	=	rm -f

CXXFLAGS	+=	-std=c++17 -fPIC

CXXFLAGS	+=	-W -Wextra -Wall -Werror

NAME		=	../../../games/game_arcade_nibbler.so

SRCS		=	./NibblerGame.cpp	\
			../../core/Entity.cpp

OBJS		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

re: 		fclean all

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

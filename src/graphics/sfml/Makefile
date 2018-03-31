##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

CXX	=	g++
RM	=	rm -f

CXXFLAGS	+=	-std=c++17 -fPIC
CXXFLAGS	+=	-W -Wextra -Wall -Werror

NAME		=	../../../lib/lib_arcade_SFML.so

SRCS		=	./SFMLWrapper.cpp	\
			../../core/Entity.cpp

OBJS		=	$(SRCS:.cpp=.o)

LDFLAGS		+=	-lsfml-graphics -lsfml-window -lsfml-system

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CXX) -shared $(OBJS) -o $(NAME) $(LDFLAGS)

re: 		fclean all

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

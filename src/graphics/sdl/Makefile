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

NAME		=	../../../lib/lib_arcade_SDL.so

SRCS		=	./SDLWrapper.cpp	\
			../../core/Entity.cpp

OBJS		=	$(SRCS:.cpp=.o)

LDFLAGS		+=	-lSDL2 -lSDL2_image -lSDL2_ttf

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CXX) -shared $(OBJS) -o $(NAME) $(LDFLAGS)

re: 		fclean all

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

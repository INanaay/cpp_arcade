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

NAME		=	../../../lib/lib_arcade_Allegro.so

SRCS		=	./AllegroWrapper.cpp

OBJS		=	$(SRCS:.cpp=.o)

LDFLAGS		+=	-lallegro -lallegro_color -lallegro_image -lallegro_physfs -lallegro_acodec -lallegro_dialog -lallegro_main -lallegro_primitives -lallegro_audio -lallegro_font -lallegro_memfile -lallegro_ttf

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CXX) -shared $(OBJS) -o $(NAME) $(LDFLAGS)

re: 		fclean all

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

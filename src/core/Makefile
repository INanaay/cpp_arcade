##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

CXX		=	g++
NAME		=	../../arcade
RM		=	rm -f

CXXFLAGS	+=	-std=c++17 -fPIC
CXXFLAGS	+=	-W -Wextra -Wall -Werror

LDFLAGS		+=	-ldl -lstdc++fs

SRCS		+=	main.cpp
SRCS		+=	Core.cpp

OBJS		+=	$(SRCS:.cpp=.o)

all: 			$(NAME)

$(NAME):		$(OBJS)
			$(CXX) $(OBJS) $(LDFLAGS) -o $(NAME)

re: 			fclean all

clean:
			$(RM) $(OBJS)

fclean: 		clean
			$(RM) $(NAME)

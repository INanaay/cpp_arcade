CXX		=	g++
RM		=	rm -f

CXXFLAGS	+=	-std=c++17 -fPIC
CXXFLAGS	+=	-W -Wextra -Wall -Werror

NAME		=	../../../lib/lib_arcade_ncurses.so
SRCS		+=	NcursesWrapper.cpp
OBJS		=	$(SRCS:.cpp=.o)

LDFLAGS		+=	-lncurses

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) -shared $(OBJS) -o $(NAME) $(LDFLAGS)

re: 		fclean all

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

##
## EPITECH PROJECT, 2021
## Arcade - Nibbler
## File description:
## Makefile
##

CXX			=	g++

CXXFLAGS	+=	-std=c++11 -fPIC

CXXFLAGS	+=	-I ./include/ -I ../../core/include/

NAME		=	../../../lib/arcade_nibbler.so

SRC			=	./src/nibbler.cpp	\
				./src/loop.cpp	\
				./src/pos.cpp	\
				./src/tail.cpp	\

OBJ			=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) -shared $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) *~

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: fclean all re
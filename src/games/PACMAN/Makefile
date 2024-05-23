##
## EPITECH PROJECT, 2021
## Arcade - Pacman
## File description:
## Makefile
##

CXX			=	g++

CXXFLAGS	+=	-std=c++11 -fPIC

CXXFLAGS	+=	-I ./include/ -I ../../core/include/

NAME		=	../../../lib/arcade_pacman.so

SRC			=	./src/pacman.cpp	\
				./src/loop.cpp	\
				./src/pos.cpp \
				./src/enemy.cpp	\
				./src/freeWay.cpp	\
				./src/moveEnemy.cpp	\
				./src/eatEnemy.cpp

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
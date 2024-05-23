##
## EPITECH PROJECT, 2021
## Arcade - SFML
## File description:
## Makefile
##

CXX			=	g++

CXXFLAGS	+=	-std=c++11 -fPIC

CXXFLAGS	+=	-I ./include/ -I ../../core/include/

LDFLAGS		+=	-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

NAME		=	../../../lib/arcade_sfml.so

SRC			=	./src/libSFML.cpp	\
				./src/elemSFML.cpp

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
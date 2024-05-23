##
## EPITECH PROJECT, 2021
## Arcade - SDL
## File description:
## Makefile
##

CXX			=	g++

CXXFLAGS	+=	-std=c++11 -fPIC

CXXFLAGS	+=	-I ./include/ -I ../../core/include/

LDFLAGS		+=	-lSDL2 -lSDL2_image -lSDL2_ttf

NAME		=	../../../lib/arcade_sdl2.so

SRC			=	./src/sdl.cpp	\
				./src/elemSDL.cpp

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
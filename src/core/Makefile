##
## EPITECH PROJECT, 2021
## Arcade - core
## File description:
## Makefile
##

CXX			=	g++

CXXFLAGS	+=	-std=c++11 -fPIC

CXXFLAGS	+=	-I ./include/

LDFLAGS		+=	-ldl

NAME		=	../../arcade

SRC			=	./src/main.cpp \
				./src/arcade.cpp \
				./src/parseFile.cpp \
				./src/argumentHandler.cpp	\
				./src/highscore.cpp		\
				./src/CEncapsulation.cpp	\
				./src/highscoreConf.cpp		\
				./src/displayCommand.cpp	\
				./src/getLib.cpp	\
				./src/getGame.cpp	\
				./src/gameLoop.cpp

OBJ			=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) *~

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: fclean all re
##
## EPITECH PROJECT, 2021
## Arcade
## File description:
## Makefile
##

all:	core games graphicals

core:
	@make --no-print-directory -C ./src/core/

games:
	@make --no-print-directory -C ./src/games/PACMAN/
	@make --no-print-directory -C ./src/games/NIBBLER/

graphicals:
	@make --no-print-directory -C ./src/graphicals/NCURSES/
	@make --no-print-directory -C ./src/graphicals/SDL/
	@make --no-print-directory -C ./src/graphicals/SFML/

clean:
	@make --no-print-directory -C ./src/core/ clean
	@make --no-print-directory -C ./src/games/PACMAN/ clean
	@make --no-print-directory -C ./src/games/NIBBLER/ clean
	@make --no-print-directory -C ./src/graphicals/NCURSES/ clean
	@make --no-print-directory -C ./src/graphicals/SDL/ clean
	@make --no-print-directory -C ./src/graphicals/SFML/ clean

fclean:
	@make --no-print-directory -C ./src/core/ fclean
	@make --no-print-directory -C ./src/games/PACMAN/ fclean
	@make --no-print-directory -C ./src/games/NIBBLER/ fclean
	@make --no-print-directory -C ./src/graphicals/NCURSES/ fclean
	@make --no-print-directory -C ./src/graphicals/SDL/ fclean
	@make --no-print-directory -C ./src/graphicals/SFML/ fclean

re:	fclean all

.PHONY:	all clean fclean re
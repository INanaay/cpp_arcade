all:
	make -C ./src/core/
##	make -C ./src/games/nibbler/
##	make -C ./src/games/pacman/
	make -C ./src/graphics/sfml/
	make -C ./src/graphics/ncurses/

re:	fclean all

clean:
	make clean -C ./src/core/
##	make clean -C ./src/games/nibbler/
##	make clean -C ./src/games/pacman/
	make clean -C ./src/graphics/sfml/
	make clean -C ./src/graphics/ncurses/

fclean:
	make fclean -C ./src/core/
##	make fclean -C ./src/games/nibbler/
##	make fclean -C ./src/games/pacman/
	make fclean -C ./src/graphics/sfml/
	make fclean -C ./src/graphics/ncurses/

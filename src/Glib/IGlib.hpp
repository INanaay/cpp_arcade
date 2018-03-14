/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by JOJO
*/

#ifndef CPP_ARCADE_IGLIB_HPP
# define CPP_ARCADE_IGLIB_HPP

# include <string>
# include <vector>
# include <map>

enum UserEvent {
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	LIB_NEXT,
	LIB_PREV,
	ACTION1,
	ACTION2,
	ESCAPE,
	ENTER
};

class IGlib {
public:
	virtual ~IGlib() = default;

	virtual void Clear() = 0;
	virtual void Display() = 0;
	virtual void DrawMenu() = 0;
	virtual void InitWindow() = 0;
	virtual void DestroyWindow() = 0;

	virtual char getCharacter() = 0;
	virtual UserEvent getLastEvent() = 0;
};

#endif //CPP_ARCADE_IGLIB_HPP

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

class IGlib {
public:
	virtual ~IGlib() = default;
	virtual void drawMenu() = 0;
    	virtual void initWindow() = 0;
    	virtual void destroyWindow() = 0;
};

#endif //CPP_ARCADE_IGLIB_HPP

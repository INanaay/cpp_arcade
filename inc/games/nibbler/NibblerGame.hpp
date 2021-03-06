/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_NIBBLER_HPP
#define CPP_ARCADE_NIBBLER_HPP


#include "../../core/IGame.hpp"
#include "../../core/EntityType.hpp"
#include "../../games/common/Map.hpp"

struct SnakeEntity : public Entity
{
	Direction	nextDirection;
};

class NibblerGame : public IGame
{
public:
	NibblerGame();
	UserEvent run();
	void stop();
	void init(std::unique_ptr<IGlib> library);
	std::unique_ptr<IGlib> getLib();
	void setLib(std::unique_ptr<IGlib>);
	size_t getScore();
private:
	bool eventHandler(std::pair<UserEvent, char>);
	bool moveSnake();
	void popApple();
	bool checkCol();
	void checkApple();
private:
	std::unique_ptr<IGlib> m_library;
	Map	m_map;
	std::map<EntityType, Entity> m_assets;
	std::vector<SnakeEntity> m_snake;
	Entity m_apple;
	SnakeEntity m_prevSnake;
	size_t m_score;
};


#endif //CPP_ARCADE_NIBBLER_HPP

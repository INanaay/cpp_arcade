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
	UserEvent Run();
	void Stop();
	void Init(std::unique_ptr<IGlib> library);
	std::unique_ptr<IGlib> getLib();
	void setLib(std::unique_ptr<IGlib>);
private:
	bool eventHandler(std::pair<UserEvent, char>);
	void moveSnake();
	void popApple();
	void checkCol();
	void checkApple();
	void popSnake(std::pair<std::size_t, std::size_t>);
private:
	std::unique_ptr<IGlib> m_library;
	Map	m_map;
	std::map<EntityType, Entity> m_assets;
	std::vector<SnakeEntity> m_snake;
	Entity m_apple;
	/*
private:
	int m_appleState;
	int m_appleIndex;
	std::vector<Entity> m_map;
	std::vector<Entity> m_snake;

	void loadMap(const std::string &path);
	bool isGameFinished();
	void chooseNextDir(Entity &, std::size_t);
	*/
};


#endif //CPP_ARCADE_NIBBLER_HPP

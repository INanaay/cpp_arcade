/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_ENTITY_HPP
#define CPP_ARCADE_ENTITY_HPP

#include <string>
#include <utility>
#include "Direction.hpp"
#include "EntityType.hpp"

typedef unsigned char uchar;

class Entity
{
public:
	Entity() = default;
	~Entity() = default;

	float getSize() const;
	void setSize(float size);
	float getSpeed() const;
	void setSpeed(float speed);
	uchar getAscii() const;
	void setAscii(uchar ascii);
	const std::string &getSprite() const;
	void setSprite(const std::string &sprite);
	Direction getDirection() const;
	void setDirection(Direction direction);
	Direction getNextDirection() const;
	void setNextDirection(Direction direction);
	const std::pair<float, float> &getPosition() const;
	void setPosition(const std::pair<float, float> &position);
	const std::pair<uint, uint> &getCase() const;
	void setCase(const std::pair<uint, uint> &pos);
private:
	float m_size;
	float m_speed;
	uchar m_ascii;
	EntityType m_type;
public:
	EntityType getType() const;
	void setType(EntityType type);
private:
	std::string m_sprite;
	Direction m_direction;
	Direction m_nextDirection;
	std::pair<float, float> m_position;
	std::pair<uint, uint> m_case;
};


#endif //CPP_ARCADE_ENTITY_HPP

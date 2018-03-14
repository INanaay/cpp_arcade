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

typedef unsigned char uchar;

class Entity
{
public:
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
	const std::pair<float, float> &getPosition() const;
	void setPosition(const std::pair<float, float> &position);
private:
	float m_size;
	float m_speed;
	uchar ascii;
	std::string m_sprite;
	Direction m_direction;
	std::pair<float, float> m_position;

};


#endif //CPP_ARCADE_ENTITY_HPP

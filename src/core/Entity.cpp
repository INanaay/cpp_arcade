#include "../../inc/core/Entity.hpp"

/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/


float Entity::getSize() const
{
	return m_size;
}
void Entity::setSize(float size)
{
	m_size = size;
}
float Entity::getSpeed() const
{
	return m_speed;
}
void Entity::setSpeed(float speed)
{
	m_speed = speed;
}
uchar Entity::getAscii() const
{
	return m_ascii;
}
EntityType Entity::getType() const
{
	return m_type;
}
void Entity::setType(EntityType type)
{
	m_type = type;
}
void Entity::setAscii(uchar ascii)
{
	m_ascii = ascii;
}
const std::string &Entity::getSprite() const
{
	return m_sprite;
}
void Entity::setSprite(const std::string &sprite)
{
	m_sprite = sprite;
}
Direction Entity::getDirection() const
{
	return m_direction;
}
void Entity::setDirection(Direction direction)
{
	m_direction = direction;
}
Direction Entity::getNextDirection() const
{
	return m_nextDirection;
}
void Entity::setNextDirection(Direction nextDirection)
{
	m_nextDirection = nextDirection;
}
const std::pair<float, float> &Entity::getPosition() const
{
	return m_position;
}
void Entity::setPosition(const std::pair<float, float> &position)
{
	m_position = position;
}
const std::pair<uint, uint> &Entity::getCase() const
{
	return m_case;
}
void Entity::setCase(const std::pair<uint, uint> &pos)
{
	m_case = pos;
}

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
	return ascii;
}
void Entity::setAscii(uchar ascii)
{
	Entity::ascii = ascii;
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
const std::pair<float, float> &Entity::getPosition() const
{
	return m_position;
}
void Entity::setPosition(const std::pair<float, float> &position)
{
	m_position = position;
}

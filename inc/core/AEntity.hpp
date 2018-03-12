/*
 ** EPITECH PROJECT, 2018
 ** Epitech scolarship project (4 years remaining)
 ** File description:
 **      Made on 2018/03 by ebernard
 */

#ifndef CPP_ARCADE_AEENTITY_HPP
#define CPP_ARCADE_AEENTITY_HPP

#include "arcade.hpp"

namespace arcade {
	class AEntity {
	public:
		virtual arcade::Point <float> getPos() const = 0;
		virtual float getAngle() const = 0;
		virtual unsigned char getKeyTraductor() const = 0;
	protected:
		arcade::Point <float>pos;
		float angle;
		unsigned char key_traductor;
	};
}

#endif //CPP_ARCADE_AEENTITY_HPP

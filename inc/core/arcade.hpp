/*
** EPITECH PROJECT, 2018
**
** File description:
** description
*/

#ifndef ARCADE_HPP
# define ARCADE_HPP

#include <string>
#include <vector>

namespace arcade {
	template <typename T>
	class Point {
	public:
		Point(T _x, T _y) {
			x = _x;
			y = _y;
		}
		T x;
		T y;
	};

	struct Color {
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	};

	struct Traductor {
		enum class Types {
			SQUARE, LINE, CIRCLE, TRIANGLE, SPRITE, TEXT
		};
		arcade::Traductor::Types type;
		std::string text;
		std::string spritePath;
		std::string asciiSprite;
		arcade::Color couleur;
	};
}

#endif

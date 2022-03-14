#ifndef DTB_UTIL_H
#define DTB_UTIL_H

#include <SFML/Graphics.hpp>

#include <cmath>

namespace nadpher
{
	static sf::Vector2f normalizeVector(const sf::Vector2f& vector)
	{
		if (vector.x == 0 && vector.y == 0)
		{
			return {};
		}

		float length = std::sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2));

		return { vector.x / length, vector.y / length };
	}
}

#endif

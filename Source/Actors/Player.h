#ifndef DTB_PLAYER_H
#define DTB_PLAYER_H

#include "Actor.h"

namespace nadpher
{
	class Player : public Actor
	{
	public:
		Player();

		void update(float deltaTime);

		static const char* playerSpriteFilePath;

	private:
		const float m_speed = 500.0f;

		sf::Vector2f m_size;
	};
}

#endif


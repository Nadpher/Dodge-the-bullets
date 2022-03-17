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

		const sf::Vector2f& getPosition() const { return m_position; }

		static const char* playerSpriteFilePath;
		static const sf::Vector2f size;

	private:
		const float m_speed = 500.0f;

	};
}

#endif


#ifndef DTB_BULLET_H
#define DTB_BULLET_H

#include "Actor.h"

namespace nadpher
{
	class Bullet : public Actor
	{
	public:
		Bullet() = delete;
		Bullet(const sf::Vector2f& startPos, float speed = 500.0f);

		void update(float deltaTime);

		static sf::Vector2f& getSize() { return m_size; }
		sf::Vector2f& getPosition() { return m_position; }

		static const char* bulletSpritePath;

	private:
		float m_speed;

		static sf::Vector2f m_size;
		sf::Vector2f m_scale;
	};
}

#endif

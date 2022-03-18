#ifndef DTB_BULLET_H
#define DTB_BULLET_H

#include "Actor.h"

namespace nadpher
{
	class Bullet : public Actor
	{
	public:
		Bullet();

		void init();

		void update(float deltaTime);

		static constexpr float minSpeed = 500.0f;
		static constexpr float maxSpeed = 800.0f;

		static const sf::Vector2f size;
		const sf::Vector2f& getPosition() const { return m_position; }

		const bool isAlive() const { return m_isAlive; }

		static const char* bulletSpritePath;

	private:

		bool m_isAlive;
		float m_speed;

		sf::Vector2f m_scale;
	};
}

#endif

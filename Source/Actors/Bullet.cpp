#include "Bullet.h"

namespace nadpher
{
	const char* Bullet::bulletSpritePath = "Resource/Textures/bullet.png";
	const sf::Vector2f Bullet::size = { 50, 50 };

	Bullet::Bullet(const sf::Vector2f& startPos, float speed)
		: Actor(bulletSpritePath), m_speed(speed)
	{
		m_position = startPos;

		sf::IntRect rect = m_sprite.getTextureRect();

		// negative scale to flip sprite
		m_scale = { -(size.x / rect.width), size.y / rect.height };

	}

	void Bullet::update(float deltaTime)
	{
		m_position.x -= m_speed * deltaTime;

		// makes sprite follow player
		m_sprite.setPosition(m_position);
		m_sprite.setScale(m_scale);
	}
}
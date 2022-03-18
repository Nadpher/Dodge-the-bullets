#include "Bullet.h"

#include "../Game.h"

#include <random>

namespace nadpher
{
	const char* Bullet::bulletSpritePath = "Resource/Textures/bullet.png";
	const sf::Vector2f Bullet::size = { 50, 50 };

	Bullet::Bullet()
		: Actor(bulletSpritePath), 
		m_isAlive(false),
		m_speed(0.0f),
		m_scale({})
	{
		sf::IntRect rect = m_sprite.getTextureRect();

		// negative scale to flip sprite
		m_scale = { -(size.x / rect.width), size.y / rect.height };
	}

	void Bullet::init()
	{
		std::random_device dev;
		std::mt19937 rng(dev());

		std::uniform_int_distribution<unsigned int> posGen(0, Game::get_bounds().y - size.y);
		std::uniform_real_distribution<float> speedGen(minSpeed, maxSpeed);

		m_speed = speedGen(rng);
		m_position = { (float)Game::get_bounds().x, (float)posGen(rng) };

		m_isAlive = true;
	}

	void Bullet::update(float deltaTime)
	{
		m_position.x -= m_speed * deltaTime;

		if (m_position.x + size.x < 0)
		{
			m_isAlive = false;
		}

		// makes sprite follow player
		m_sprite.setPosition(m_position);
		m_sprite.setScale(m_scale);
	}
}
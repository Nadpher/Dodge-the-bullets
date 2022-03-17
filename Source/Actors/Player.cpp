#include <spdlog/spdlog.h>

#include "../Game.h"

#include "../Input.h"
#include "../Util.h"
#include "../TextureManager.h"

#include "Player.h"


namespace nadpher
{
	const char* Player::playerSpriteFilePath = "Resource/Textures/player.png";
	const sf::Vector2f Player::size = { 150, 100 };

	Player::Player() : Actor(playerSpriteFilePath)
	{
		m_position = { 0, 400 };

		m_sprite.setColor(sf::Color(255, 255, 255, 255));
	}

	void Player::update(float deltaTime)
	{
		sf::Vector2f direction = {};

		if (Input::get_key_pressed(sf::Keyboard::Key::D))
		{
			direction.x += 1;
		}

		if (Input::get_key_pressed(sf::Keyboard::Key::A))
		{
			direction.x -= 1;
		}

		if (Input::get_key_pressed(sf::Keyboard::Key::W))
		{
			direction.y -= 1;
		}
		
		if (Input::get_key_pressed(sf::Keyboard::Key::S))
		{
			direction.y += 1;
		}

		// normalize direction vector
		direction = normalizeVector(direction);

		m_position.x += direction.x * m_speed * deltaTime;
		m_position.y += direction.y * m_speed * deltaTime;

		sf::Vector2u bounds = Game::get_bounds();

		// clamp position values
		if (m_position.x < 0)
		{
			m_position.x = 0;
		}
		else if (m_position.x > bounds.x - size.x)
		{
			m_position.x = bounds.x - size.x;
		}

		if (m_position.y < 0)
		{
			m_position.y = 0;
		}
		else if (m_position.y > bounds.y - size.y)
		{
			m_position.y = bounds.y - size.y;
		}

		// makes sprite follow player
		m_sprite.setPosition(m_position);

		sf::IntRect rect = m_sprite.getTextureRect();
		m_sprite.setScale(size.x / rect.width, size.y / rect.height);
	}
}
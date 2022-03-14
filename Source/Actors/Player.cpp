#include <spdlog/spdlog.h>

#include "../Input.h"
#include "../Util.h"
#include "../TextureManager.h"

#include "Player.h"

namespace nadpher
{
	const char* Player::playerSpriteFilePath = "Resource/Textures/player.png";

	Player::Player()
	{
		m_sprite.setTexture(TextureManager::get_texture(playerSpriteFilePath));
		m_sprite.setPosition(m_position);
		m_sprite.setColor(sf::Color(255, 255, 255, 255));
	}

	void Player::update(float deltaTime)
	{
		sf::Vector2f direction = {};

		if (Input::get_instance()->get_key_pressed(sf::Keyboard::Key::D))
		{
			direction.x += 1;
		}

		if (Input::get_instance()->get_key_pressed(sf::Keyboard::Key::A))
		{
			direction.x -= 1;
		}

		if (Input::get_instance()->get_key_pressed(sf::Keyboard::Key::W))
		{
			direction.y -= 1;
		}
		
		if (Input::get_instance()->get_key_pressed(sf::Keyboard::Key::S))
		{
			direction.y += 1;
		}

		// normalize direction vector
		direction = normalizeVector(direction);

		m_position.x += direction.x * speed * deltaTime;
		m_position.y += direction.y * speed * deltaTime;

		m_sprite.setPosition(m_position);
	}

	void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_sprite, states);
	}
}
#ifndef DTB_ACTOR_H
#define DTB_ACTOR_H

#include <SFML/Graphics.hpp>

#include "../TextureManager.h"

namespace nadpher
{
	class Actor : public sf::Drawable
	{
	public:
		Actor(const char* texturePath) { m_sprite.setTexture(TextureManager::get_texture(texturePath)); }
		~Actor() = default;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override
		{
			target.draw(m_sprite, states);
		}

	protected:
		sf::Vector2f m_position;
		sf::Sprite m_sprite;
	};
}

#endif


#ifndef DTB_PLAYER_H
#define DTB_PLAYER_H

#include <SFML/Graphics.hpp>


namespace nadpher
{
	class Player : public sf::Drawable
	{
	public:
		Player();

		void update(float deltaTime);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		static const char* playerSpriteFilePath;

	private:
		const float speed = 200.0f;

		sf::Vector2f m_position;
		sf::Sprite m_sprite;
	};
}

#endif


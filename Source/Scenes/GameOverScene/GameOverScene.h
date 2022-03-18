#ifndef DTB_GAME_OVER_SCENE_H
#define DTB_GAME_OVER_SCENE_H

#include "../Scene.h"
#include <SFML/Graphics.hpp>

namespace nadpher
{
	class GameOverScene : public Scene
	{
	public:
		GameOverScene();

		bool iterate(float deltaTime) override;
		bool end() override;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


	private:
		sf::Font m_font;

		sf::Text m_gameOverLabel;
		sf::Text m_scoreLabel;
	};
}

#endif


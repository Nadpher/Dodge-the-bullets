#include <spdlog/spdlog.h>

#include "GameOverScene.h"

#include "../MainScene/GUI.h"

namespace nadpher
{
	GameOverScene::GameOverScene()
	{
		if (m_font.loadFromFile(GUI::fontFilePath))
		{
			spdlog::error("Couldn't load font {}", GUI::fontFilePath);
		}

		m_scoreLabel.setFont(m_font);
		m_gameOverLabel.setFont(m_font);

		m_gameOverLabel.setString("GAME OVER!");
		m_gameOverLabel.setCharacterSize(64);

		m_scoreLabel.setPosition(500, 300);
	}

	bool GameOverScene::iterate(float deltaTime)
	{

		return true;
	}

	bool GameOverScene::end()
	{
		return true;
	}

	void GameOverScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_gameOverLabel);
		target.draw(m_scoreLabel);
	}
}
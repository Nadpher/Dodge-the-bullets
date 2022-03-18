#include <spdlog/spdlog.h>
#include <iomanip>
#include <sstream>

#include "GameOverScene.h"

#include "../MainScene/GUI.h"
#include "../MainScene/MainScene.h"

#include "../../Input.h"
#include "../../SceneManager.h"

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

		m_gameOverLabel.setString("GAME OVER! Press 'r' to restart or 'ESC' to quit");
		m_gameOverLabel.setCharacterSize(50);
		m_gameOverLabel.setPosition(GUI::padding, GUI::padding);

		m_scoreLabel.setPosition(GUI::padding, 100 + GUI::padding);
		m_scoreLabel.setCharacterSize(30);

		std::stringstream stream;
		stream << std::fixed << std::setprecision(2) << MainScene::getEndScore();
		m_scoreLabel.setString("Score: " + stream.str());
	}

	bool GameOverScene::iterate(float deltaTime)
	{
		if (Input::get_key_down(sf::Keyboard::Key::R))
		{
			SceneManager::getInstance()->switchScene(0);
		}
		else if (Input::get_key_down(sf::Keyboard::Key::Escape))
		{
			return false;
		}

		return true;
	}

	bool GameOverScene::end()
	{
		return false;
	}

	void GameOverScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_gameOverLabel);
		target.draw(m_scoreLabel);
	}
}
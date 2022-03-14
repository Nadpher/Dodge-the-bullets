#include <spdlog/spdlog.h>

#include "Game.h"

#include "Scenes/MainScene.h"

namespace nadpher
{
	sf::RenderWindow Game::m_window;
	std::vector<std::unique_ptr<Scene>> Game::m_scenes;
	size_t Game::m_currentScene = 0;

	bool Game::init(unsigned int width, unsigned int height, const char* title)
	{
		m_window.create(sf::VideoMode(width, height), title);

		m_scenes.push_back(std::make_unique<MainScene>());

		spdlog::set_level(spdlog::level::info);

		return true;
	}

	void Game::run()
	{
		sf::Clock clock;

		while (m_window.isOpen())
		{
			sf::Time elapsed = clock.restart();
			float deltaTime = elapsed.asSeconds();

			spdlog::info("Delta time: {}", deltaTime);

			sf::Event event;
			while (m_window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					m_window.close();
					break;

				default:
					m_scenes[m_currentScene]->handle_events(event);
					break;
				}
			}

			m_scenes[m_currentScene]->iterate(deltaTime);

			m_window.clear();
			// ????????
			m_window.draw(*(m_scenes[m_currentScene].get()));
			m_window.display();
		}
	}

	void Game::end()
	{

	}
}
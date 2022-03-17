#include <spdlog/spdlog.h>

#include "Game.h"
#include "Input.h"

#include "Scenes/MainScene/MainScene.h"

namespace nadpher
{
	sf::RenderWindow			        Game::m_window;
	sf::Vector2u				        Game::m_bounds;
	std::vector<std::unique_ptr<Scene>> Game::m_scenes;
	size_t							    Game::m_currentScene = 0;

	bool Game::init(unsigned int width, unsigned int height, const char* title)
	{
		spdlog::set_level(spdlog::level::debug);
		m_window.create(sf::VideoMode(width, height), title);

		m_scenes.push_back(std::make_unique<MainScene>());

		m_bounds.x = width;
		m_bounds.y = height;

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

			handle_events();

			if (!m_scenes[m_currentScene]->iterate(deltaTime))
			{
				m_scenes[m_currentScene]->end();
				break;
			}

			m_window.clear();
			m_window.draw(*m_scenes[m_currentScene]);
			m_window.display();
		}
	}

	void Game::end()
	{
		if (m_window.isOpen()) m_window.close();
	}

	void Game::handle_events()
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;

			case sf::Event::KeyPressed:
				Input::set_key_up(event.key.code, true);
				Input::set_key_down(event.key.code, true);
				Input::set_key_pressed(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				Input::set_key_down(event.key.code, false);
				Input::set_key_pressed(event.key.code, false);
				Input::set_key_up(event.key.code, true);
				break;

			default:
				break;
			}
		}
	}
}
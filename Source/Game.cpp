#include <spdlog/spdlog.h>

#include "Game.h"
#include "Input.h"

#include "Scenes/MainScene.h"

namespace nadpher
{
	sf::RenderWindow			        Game::m_window;
	sf::Vector2u				        Game::m_bounds;
	std::vector<std::unique_ptr<Scene>> Game::m_scenes;
	size_t							    Game::m_currentScene = 0;

	bool Game::init(unsigned int width, unsigned int height, const char* title)
	{
		m_window.create(sf::VideoMode(width, height), title);

		m_scenes.push_back(std::make_unique<MainScene>());

		spdlog::set_level(spdlog::level::info);

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

			m_scenes[m_currentScene]->iterate(deltaTime);

			m_window.clear();
			m_window.draw(*m_scenes[m_currentScene]);
			m_window.display();
		}
	}

	void Game::end()
	{

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
				Input::get_instance()->set_key_up(event.key.code, true);
				Input::get_instance()->set_key_down(event.key.code, true);
				Input::get_instance()->set_key_pressed(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				// released keys buffer?
				Input::get_instance()->set_key_down(event.key.code, false);
				Input::get_instance()->set_key_pressed(event.key.code, false);
				Input::get_instance()->set_key_up(event.key.code, true);
				break;

			default:
				break;
			}
		}
	}
}
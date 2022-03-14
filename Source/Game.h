#ifndef DTB_GAME_H
#define DTB_GAME_H

#include "Scenes/Scene.h"
#include <memory>

namespace nadpher
{
	class Game
	{
	public:
		Game() = delete;

		static bool init(unsigned int width = 800, unsigned int height = 600, const char* title = "Window");
		static void run();
		static void end();

	private:

		static void handle_events();

		static std::vector<std::unique_ptr<Scene>> m_scenes;
		static size_t m_currentScene;
		static sf::RenderWindow m_window;

	};
}

#endif


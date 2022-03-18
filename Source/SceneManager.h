#ifndef DTB_SCENE_MANAGER_H
#define DTB_SCENE_MANAGER_H

#include <vector>
#include <memory>

#include <spdlog/spdlog.h>

#include "Scenes/MainScene/MainScene.h"
#include "Scenes/GameOverScene/GameOverScene.h"

namespace nadpher
{
	class SceneManager
	{
	public:
		static SceneManager* getInstance()
		{
			static SceneManager* instance = new SceneManager;
			return instance;
		}

		const std::unique_ptr<Scene>& getScene() const { return m_scenes[m_currentScene]; }

		void switchScene(size_t index) 
		{ 
			if (index > m_scenes.size() - 1)
			{
				spdlog::error("{} isn't a valid scene index", index);
				return;
			}

			m_currentScene = index; 
		}

	private:
		SceneManager()
		{
			m_scenes.push_back(std::make_unique<MainScene>());
			m_scenes.push_back(std::make_unique<GameOverScene>());
		}

		size_t m_currentScene = 0;

		std::vector<std::unique_ptr<Scene>> m_scenes;

	};
}

#endif


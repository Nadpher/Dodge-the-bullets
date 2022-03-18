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

		const std::unique_ptr<Scene>& getScene() const { return m_scenes[0]; }

		void switchScene(size_t index) 
		{ 
			switch (index)
			{
			case 0:
				m_scenes.pop_back();
				m_scenes.push_back(std::make_unique<MainScene>());
				break;

			case 1:
				m_scenes.pop_back();
				m_scenes.push_back(std::make_unique<GameOverScene>());
				break;

			default:
				spdlog::error("{} isn't a valid scene index", index);
				break;
			}
		}

	private:
		SceneManager()
		{
			m_scenes.push_back(std::make_unique<MainScene>());
		}

		std::vector<std::unique_ptr<Scene>> m_scenes;

	};
}

#endif


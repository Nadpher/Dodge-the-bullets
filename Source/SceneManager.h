#ifndef DTB_SCENE_MANAGER_H
#define DTB_SCENE_MANAGER_H

#include <vector>
#include <memory>

#include "Scenes/Scene.h"

namespace nadpher
{
	class SceneManager
	{
	public:


	private:
		SceneManager() {}

		std::vector<std::unique_ptr<Scene>> m_scenes;

	};
}

#endif


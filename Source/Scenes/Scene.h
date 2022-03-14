#ifndef DTB_SCENE_H
#define DTB_SCENE_H

#include <SFML/Graphics.hpp>

namespace nadpher
{
	class Scene : public sf::Drawable
	{
	public:
		virtual ~Scene() = default;

		virtual void iterate(float deltaTime) = 0;
	};
}

#endif

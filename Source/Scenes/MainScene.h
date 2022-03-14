#ifndef DTB_MAINSCENE_H
#define DTB_MAINSCENE_H

#include "Scene.h"

#include "../Actors/Player.h"

namespace nadpher
{
	class MainScene : public Scene
	{
	public:
		MainScene() = default;
		~MainScene() = default;

		void iterate(float deltaTime) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		Player m_player;

	};
}


#endif


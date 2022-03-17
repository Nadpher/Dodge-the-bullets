#ifndef DTB_MAINSCENE_H
#define DTB_MAINSCENE_H

#include "Scene.h"

#include "../BulletSpawner.h"
#include "../Actors/Player.h"

namespace nadpher
{
	class MainScene : public Scene
	{
	public:
		MainScene();
		~MainScene() = default;

		bool iterate(float deltaTime) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:

		bool isPlayerAlive(const std::vector<Bullet>& bullets);

		Player m_player;
		BulletSpawner m_bulletSpawner;
	};
}


#endif


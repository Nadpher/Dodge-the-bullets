#ifndef DTB_MAINSCENE_H
#define DTB_MAINSCENE_H

#include "../Scene.h"

#include "../../Actors/Player.h"
#include "BulletSpawner.h"
#include "GUI.h"

namespace nadpher
{
	class MainScene : public Scene
	{
	public:
		MainScene();
		~MainScene() = default;

		bool iterate(float deltaTime) override;
		bool end() override;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		static float getEndScore() { return m_endScore; }

	private:

		bool isPlayerAlive(const std::array<Bullet, BulletPool::maxBullets>& bullets);

		Player m_player;
		BulletSpawner m_bulletSpawner;
		GUI m_gui;

		float m_score = 0;
		static float m_endScore;
	};
}


#endif


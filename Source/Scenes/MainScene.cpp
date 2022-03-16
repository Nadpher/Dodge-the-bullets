#include "MainScene.h"

namespace nadpher
{
	MainScene::MainScene()
		: m_bulletSpawner(300.0f, 500.0f, 1.0f)
	{
		
	}

	bool MainScene::iterate(float deltaTime)
	{
		m_player.update(deltaTime);
		m_bulletSpawner.update(deltaTime);

		return true;
	}

	void MainScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_player, states);
		target.draw(m_bulletSpawner, states);
	}
}
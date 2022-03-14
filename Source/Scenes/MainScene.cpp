#include "MainScene.h"

namespace nadpher
{
	void MainScene::iterate(float deltaTime)
	{
		m_player.update(deltaTime);
	}

	void MainScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_player, states);
	}
}
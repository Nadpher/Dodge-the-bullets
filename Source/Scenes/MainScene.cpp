#include "MainScene.h"

namespace nadpher
{
	MainScene::MainScene()
		: m_bulletSpawner(0.3f)
	{
		
	}

	bool MainScene::iterate(float deltaTime)
	{
		m_player.update(deltaTime);
		m_bulletSpawner.update(deltaTime);

		return isPlayerAlive(m_bulletSpawner.getBullets());
	}

	bool MainScene::isPlayerAlive(const std::vector<Bullet>& bullets)
	{
		sf::Vector2f playerPosition = m_player.getPosition();

		for (const Bullet& bullet : bullets)
		{
			//aabb collision detection
			sf::Vector2f bulletPosition = bullet.getPosition();

			if (playerPosition.x < bulletPosition.x + Bullet::size.x &&
				playerPosition.x + Player::size.x > bulletPosition.x &&
				playerPosition.y < bulletPosition.y + Bullet::size.y &&
				playerPosition.y + Player::size.y > bulletPosition.y)
			{
				return false;
			}
		}

		return true;
	}

	void MainScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_player, states);
		target.draw(m_bulletSpawner, states);
	}
}
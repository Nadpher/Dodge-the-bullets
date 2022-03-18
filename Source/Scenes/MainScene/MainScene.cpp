#include "MainScene.h"

#include "../../SceneManager.h"

namespace nadpher
{
	float MainScene::m_endScore = 0.0f;

	MainScene::MainScene()
		: m_bulletSpawner(0.3f)
	{
		
	}

	bool MainScene::iterate(float deltaTime)
	{
		m_score += deltaTime;

		m_player.update(deltaTime);
		m_bulletSpawner.update(deltaTime);

		m_gui.update(m_score);

		return isPlayerAlive(m_bulletSpawner.getBullets());
	}

	bool MainScene::isPlayerAlive(const std::vector<Bullet>& bullets)
	{
		sf::Vector2f playerPosition = m_player.getPosition();

		for (const Bullet& bullet : bullets)
		{
			//aabb collision detection
			sf::Vector2f bulletPosition = bullet.getPosition();

			if (playerPosition.x + Player::hitboxEaser < bulletPosition.x + Bullet::size.x &&
				playerPosition.x + Player::size.x - Player::hitboxEaser > bulletPosition.x &&
				playerPosition.y + Player::hitboxEaser < bulletPosition.y + Bullet::size.y &&
				playerPosition.y + Player::size.y  - Player::hitboxEaser > bulletPosition.y)
			{
				return false;
			}
		}

		return true;
	}

	bool MainScene::end()
	{
		m_endScore = m_score;

		SceneManager::getInstance()->switchScene(1);
		return true;
	}

	void MainScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_player, states);
		target.draw(m_bulletSpawner, states);

		target.draw(m_gui);
	}
}
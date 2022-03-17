#include "BulletSpawner.h"

#include "Game.h"

#include <random>


namespace nadpher
{
	BulletSpawner::BulletSpawner(float frequency)
		: m_spawnFrequency(frequency)
	{
		m_timer = 0.0f;
	}

	void BulletSpawner::update(float deltaTime)
	{
		m_timer += deltaTime;
		if (m_timer >= m_spawnFrequency)
		{
			m_timer = 0.0f;
			generateBullet();
		}

		size_t len = m_bullets.size();
		for (int i = 0; i < len; ++i)
		{
			m_bullets[i].update(deltaTime);
		}

		checkOutOfBounds();
	}

	void BulletSpawner::generateBullet()
	{
		spdlog::debug("Generated bullet!");

		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<unsigned int> position(0, Game::get_bounds().y - Bullet::size.y);
		std::uniform_real_distribution<float> speed(minBulletSpeed, maxBulletSpeed);

		float generatedSpeed = speed(rng);
		spdlog::debug("Bullet speed: {}", generatedSpeed);

		Bullet instance({(float)Game::get_bounds().x, (float)position(rng)}, generatedSpeed);
		m_bullets.push_back(instance);
	}

	void BulletSpawner::checkOutOfBounds()
	{
		size_t len = m_bullets.size();
		for (int i = 0; i < len; ++i)
		{
			if (m_bullets[i].getPosition().x + Bullet::size.x < 0)
			{
				m_bullets.erase(m_bullets.begin() + i);
				break;
			}
		}
	}

	void BulletSpawner::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (const Bullet& bullet : m_bullets)
		{
			target.draw(bullet);
		}
	}
}
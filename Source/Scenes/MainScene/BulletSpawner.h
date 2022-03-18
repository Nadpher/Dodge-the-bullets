#ifndef DTB_BULLET_SPAWNER_H
#define DTB_BULLET_SPAWNER_H

#include "BulletPool.h"

namespace nadpher
{
	class BulletSpawner : public sf::Drawable
	{
	public:
		BulletSpawner(float frequency = 1.0f)
			: m_frequency(frequency),
			m_timer(0.0f)
		{}

		void update(float deltaTime)
		{
			m_timer += deltaTime;
			if (m_timer >= m_frequency)
			{
				m_timer = 0.0f;
				m_pool.create();
			}

			m_pool.update(deltaTime);
		}

		const std::array<Bullet, BulletPool::maxBullets>& getBullets() { return m_pool.getBullets(); }

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override
		{
			for (const Bullet& bullet : m_pool.getBullets())
			{
				target.draw(bullet);
			}
		}

	private:
		BulletPool m_pool;
		float m_timer;
		const float m_frequency;
	};
}

#endif


#include "BulletPool.h"

namespace nadpher
{
	void BulletPool::create()
	{
		for (int i = 0; i < maxBullets; ++i)
		{
			if (!m_bullets[i].isAlive())
			{
				m_bullets[i].init();
				return;
			}
		}
	}

	void BulletPool::update(float deltaTime)
	{
		for (int i = 0; i < maxBullets; ++i)
		{
			m_bullets[i].update(deltaTime);
		}
	}
}
#ifndef DTB_BULLET_POOL_H
#define DTB_BULLET_POOL_H

#include <array>

#include "../../Actors/Bullet.h"

namespace nadpher
{
	class BulletPool
	{
	public:

		void create();
		void update(float deltaTime);

		static constexpr size_t maxBullets = 10;

		const std::array<Bullet, maxBullets>& getBullets() const { return m_bullets; }

	private:
		std::array<Bullet, maxBullets> m_bullets;
	};
}

#endif 


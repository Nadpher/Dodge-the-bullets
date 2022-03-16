#ifndef DTB_BULLET_SPAWNER_H
#define DTB_BULLET_SPAWNER_H

#include "Actors/Bullet.h"

namespace nadpher
{
	class BulletSpawner : public sf::Drawable
	{
	public:
		BulletSpawner() = delete;
		BulletSpawner(float minBulletSpeed, float maxBulletSpeed, float frequency = 1000.0f);

		void update(float deltaTime);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:

		void generateBullet();
		void checkOutOfBounds();

		const float m_minBulletSpeed;
		const float m_maxBulletSpeed;

		float m_spawnFrequency;
		float m_timer;

		std::vector<Bullet> m_bullets;
	};
}

#endif


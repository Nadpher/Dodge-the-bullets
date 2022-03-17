#ifndef DTB_BULLET_SPAWNER_H
#define DTB_BULLET_SPAWNER_H

#include "Actors/Bullet.h"

namespace nadpher
{
	class BulletSpawner : public sf::Drawable
	{
	public:
		BulletSpawner() = delete;
		BulletSpawner(float frequency = 1.0f);

		void update(float deltaTime);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		const std::vector<Bullet>& getBullets() const{ return m_bullets; }

		static constexpr float minBulletSpeed = 300.0f;
		static constexpr float maxBulletSpeed = 800.0f;
	private:

		void generateBullet();
		void checkOutOfBounds();


		float m_spawnFrequency;
		float m_timer;

		std::vector<Bullet> m_bullets;
	};
}

#endif


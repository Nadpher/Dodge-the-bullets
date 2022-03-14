#ifndef DTB_MAINSCENE_H
#define DTB_MAINSCENE_H

#include "Scene.h"

namespace nadpher
{
	class MainScene : public Scene
	{
	public:
		MainScene() = default;
		~MainScene() = default;

		void iterate(float deltaTime) override;
		void handle_events(sf::Event& event) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:

	};
}


#endif


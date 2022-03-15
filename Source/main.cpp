#include "Game.h"

int main()
{
	if (!nadpher::Game::init(1024, 768, "Dodge The Bullets"))
	{
		return 1;
	}

	nadpher::Game::run();
	nadpher::Game::end();

	return 0;
}
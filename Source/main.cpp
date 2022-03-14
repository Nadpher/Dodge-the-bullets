#include "Game.h"

int main()
{
	if (!nadpher::Game::init())
	{
		return 1;
	}

	nadpher::Game::run();
	nadpher::Game::end();

	return 0;
}
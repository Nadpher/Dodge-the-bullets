#include "Input.h"

namespace nadpher
{
	std::map<sf::Keyboard::Key, bool> Input::m_keysPressed;
	std::map<sf::Keyboard::Key, bool> Input::m_keysUp;
	std::map<sf::Keyboard::Key, bool> Input::m_keysDown;
}
#ifndef DTB_INPUT_H
#define DTB_INPUT_H

#include <SFML/Window.hpp>
#include <map>

namespace nadpher
{
	class Input
	{
	public:
		Input() = delete;

		static void set_key_up(const sf::Keyboard::Key& key, bool val)		{ m_keysUp[key] = val;      }
		static void set_key_down(const sf::Keyboard::Key& key, bool val)	{ m_keysDown[key] = val;    }
		static void set_key_pressed(const sf::Keyboard::Key& key, bool val) { m_keysPressed[key] = val; }

		static bool get_key_down(const sf::Keyboard::Key& key)    { return m_keysDown[key];    }
		static bool get_key_up(const sf::Keyboard::Key& key)      { return m_keysUp[key];      }
		static bool get_key_pressed(const sf::Keyboard::Key& key) { return m_keysPressed[key]; }

	private:
		static std::map<sf::Keyboard::Key, bool> m_keysPressed;
		static std::map<sf::Keyboard::Key, bool> m_keysUp;
		static std::map<sf::Keyboard::Key, bool> m_keysDown;
	};

}

#endif 


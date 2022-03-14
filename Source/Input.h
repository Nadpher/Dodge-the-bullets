#ifndef DTB_INPUT_H
#define DTB_INPUT_H

#include <map>
#include <SFML/Graphics.hpp>

namespace nadpher
{
	class Input
	{
	public:

		static Input* get_instance()
		{
			static Input* instance = new Input;
			return instance;
		}

		void set_key_up(const sf::Keyboard::Key& key, bool val)		 { m_keysUp[key] = val;      }
		void set_key_down(const sf::Keyboard::Key& key, bool val)	 { m_keysDown[key] = val;    }
		void set_key_pressed(const sf::Keyboard::Key& key, bool val) { m_keysPressed[key] = val; }

		bool get_key_down(const sf::Keyboard::Key& key)    { return m_keysDown[key];    }
		bool get_key_up(const sf::Keyboard::Key& key)	   { return m_keysUp[key];      }
		bool get_key_pressed(const sf::Keyboard::Key& key) { return m_keysPressed[key]; }

	private:
		Input() {}

		std::map<sf::Keyboard::Key, bool> m_keysPressed;
		std::map<sf::Keyboard::Key, bool> m_keysUp;
		std::map<sf::Keyboard::Key, bool> m_keysDown;
	};

}

#endif 


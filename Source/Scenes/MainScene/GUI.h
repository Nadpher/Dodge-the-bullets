#ifndef DTB_GUI_H
#define DTB_GUI_H

#include <SFML/Graphics.hpp>

namespace nadpher
{
	class GUI : public sf::Drawable
	{
	public:
		GUI();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void update(float score);

		static const char* fontFilePath;
		static constexpr unsigned int scoreLabelSize = 50;
		static constexpr float padding = 20;

	private:
	
		sf::Font m_font;
		sf::Text m_scoreLabel;
	};
}

#endif


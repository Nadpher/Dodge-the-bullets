#include <spdlog/spdlog.h>

#include "GUI.h"

#include <iomanip>
#include <sstream>

namespace nadpher
{
	const char* GUI::fontFilePath = "Resource/Fonts/font.otf";

	GUI::GUI()
	{
		// loads necessary font
		if (!m_font.loadFromFile(fontFilePath))
		{
			spdlog::error("Couldn't load font {}", fontFilePath);
		}

		m_scoreLabel.setFont(m_font);
		m_scoreLabel.setCharacterSize(scoreLabelSize);
	}

	void GUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_scoreLabel);
	}

	void GUI::update(float score)
	{
		std::stringstream stream;
		stream << std::fixed << std::setprecision(2) << score;
		
		m_scoreLabel.setString(stream.str());
	}
}
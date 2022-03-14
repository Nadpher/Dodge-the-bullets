#ifndef DTB_TEXTURE_MANAGER_H
#define DTB_TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

#include <map>
#include <string>


namespace nadpher
{
	class TextureManager
	{
	public:

		static sf::Texture& get_texture(const std::string& filePath)
		{
			if (m_textures.find(filePath) == m_textures.end())
			{
				sf::Texture texture;
				if (!texture.loadFromFile(filePath))
				{
					spdlog::error("Couldn't load texture {}", filePath);
				}
				m_textures.insert({ filePath, texture });
			}

			return m_textures[filePath];
		}

	private:
		static std::map<std::string, sf::Texture> m_textures;
	};

}

#endif


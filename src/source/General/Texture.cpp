#include "Texture.h"

YEngine::Texture::Texture(std::string filename) : Resource(RESOURCE::TEXTURE), m_Filename(filename)
{
}

YEngine::Texture::~Texture()
{
	this->unload();
}

bool YEngine::Texture::load()
{
	if (!m_Loaded)
	{
		m_Texture = new sf::Texture();
		m_Loaded = m_Texture->loadFromFile(m_Filename);

		if (!m_Loaded)
		{
			delete m_Texture;
		}
	}

	return m_Loaded;
}

void YEngine::Texture::unload()
{
	if (m_Loaded)
	{
		delete m_Texture;
		m_Loaded = false;
	}
}

sf::Texture* YEngine::Texture::getData() const
{
	return m_Texture;
}

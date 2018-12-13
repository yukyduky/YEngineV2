#include "Shader.h"


YEngine::Shader::Shader(std::string fileVertex, std::string fileFragment) : 
	Resource(RESOURCE::SHADER), m_FileVertex(fileVertex), m_FileFragment(fileFragment), m_LoadGeometry(false)
{

}

YEngine::Shader::Shader(std::string fileVertex, std::string fileGeometry, std::string fileFragment) : 
	Resource(RESOURCE::SHADER), m_FileVertex(fileVertex), m_FileGeometry(fileGeometry), m_FileFragment(fileFragment), m_LoadGeometry(true)
{

}

YEngine::Shader::~Shader()
{
	this->unload();
}

bool YEngine::Shader::load()
{
	if (!m_Loaded && m_LoadGeometry)
	{
		m_Shader = new sf::Shader;
		m_Loaded = m_Shader->loadFromFile(m_FileVertex, m_FileGeometry, m_FileFragment);

		if (!m_Loaded)
		{
			delete m_Shader;
		}
	}
	else if (!m_Loaded)
	{
		m_Shader = new sf::Shader;
		m_Loaded = m_Shader->loadFromFile(m_FileVertex, m_FileFragment);

		if (!m_Loaded)
		{
			delete m_Shader;
		}
	}

	return m_Loaded;
}

void YEngine::Shader::unload()
{
	if (m_Loaded)
	{
		m_Loaded = false;
		delete m_Shader;
	}
}

sf::Shader* YEngine::Shader::getData() const
{
	return m_Shader;
}

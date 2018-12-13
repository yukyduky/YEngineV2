#include "ResourceManager.h"
#include "Texture.h"
#include "General/Shader.h"


namespace YEngine
{
	bool ResourceManager::createShader(std::string fileVertex, std::string fileFragment, size_t id)
	{
		bool created = false;

		if (m_ResourceMap.find(id) == m_ResourceMap.end())
		{
			created = true;
			m_ResourceMap.insert(m_ResourceMap.end(), std::pair<size_t, Resource*>(id, new Shader(fileVertex, fileFragment)));
		}

		return created;
	}

	bool ResourceManager::createShader(std::string fileVertex, std::string fileGeometry, std::string fileFragment, size_t id)
	{
		bool created = false;

		if (m_ResourceMap.find(id) == m_ResourceMap.end())
		{
			created = true;
			m_ResourceMap.insert(m_ResourceMap.end(), std::pair<size_t, Resource*>(id, new Shader(fileVertex, fileGeometry, fileFragment)));
		}

		return created;
	}

	ResourceManager::ResourceManager()
	{
	}

	ResourceManager::~ResourceManager()
	{
		std::unordered_map<size_t, Resource*>::iterator it = m_ResourceMap.begin();

		for (; it != m_ResourceMap.end(); it++)
		{
			delete (*it).second;
		}
	}

	bool ResourceManager::createTexture(std::string filename, const size_t id)
	{
		bool created = false;

		if (m_ResourceMap.find(id) == m_ResourceMap.end())
		{
			created = true;
			m_ResourceMap.insert(m_ResourceMap.end(), std::pair<size_t, Resource*>(id, new Texture(filename)));
		}

		return created;
	}
	
	void ResourceManager::unloadResource(size_t id)
	{
		m_ResourceMap.at(id)->unload();
	}
	
	void ResourceManager::removeResource(size_t id)
	{
		if (m_ResourceIDs.remove(id))
		{
			m_ResourceMap[id]->unload();
			delete m_ResourceMap[id];
			m_ResourceMap.erase(id);
		}
	}
	
	bool ResourceManager::isResourceLoaded(size_t id)
	{
		return m_ResourceMap[id]->isLoaded();
	}
	
	void ResourceManager::cleanup()
	{
		for (auto &i : m_ResourceMap) 
		{
			i.second->unload();
			delete i.second;
		}
		m_ResourceIDs.clear();
	}

	bool ResourceManager::getResourceData(sf::Texture*& data, size_t id) const
	{
		bool success = false;

		if (m_ResourceMap.find(id) == m_ResourceMap.end() && m_ResourceMap.at(id)->getType() == RESOURCE::TEXTURE)
		{
			success = true;
			data = static_cast<Texture*>(m_ResourceMap.at(id))->getData();
		}

		return success;
	}

	bool ResourceManager::getResourceData(sf::Shader*& data, const size_t id) const
	{
		bool success = false;

		if (m_ResourceMap.find(id) == m_ResourceMap.end() && m_ResourceMap.at(id)->getType() == RESOURCE::SHADER)
		{
			success = true;
			data = static_cast<Shader*>(m_ResourceMap.at(id))->getData();
		}

		return success;
	}
}

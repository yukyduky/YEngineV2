#pragma once

#include "General/IResourceManager.h"
#include <unordered_map>
#include "General/YUtilityTypes.h"
#include "General/IDHandler.h"
#include <sfml/Graphics.hpp>
#include "Resource.h"

namespace YEngine
{
	class ResourceManager : public IResourceManager
	{
	private:
		IDHandler m_ResourceIDs;
		std::unordered_map<size_t, Resource*> m_ResourceMap;
	
	public:
		ResourceManager();
		virtual ~ResourceManager();

		//************************************
		// Method:    createTexture
		// FullName:  YEngine::ResourceManager::createTexture
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: std::string filename
		// Parameter: size_t id
		// Description: Creates a Texture resource and gives it the filename so that it is ready to load at any time
		//************************************
		bool createTexture(std::string filename, size_t id);
		//************************************
		// Method:    createShader
		// FullName:  YEngine::ResourceManager::createShader
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: std::string fileVertex
		// Parameter: std::string fileFragment
		// Parameter: size_t id
		// Description: Creates a Shader resource and gives it the filenames so that it is ready to load at any time
		//************************************
		bool createShader(std::string fileVertex, std::string fileFragment, size_t id);
		//************************************
		// Method:    createShader
		// FullName:  YEngine::ResourceManager::createShader
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: std::string fileVertex
		// Parameter: std::string fileGeometry
		// Parameter: std::string fileFragment
		// Parameter: size_t id
		// Description: Creates a Shader resource and gives it the filenames so that it is ready to load at any time
		//************************************
		bool createShader(std::string fileVertex, std::string fileGeometry, std::string fileFragment, size_t id);
		//***********************************************************
		// Method:    unloadResource
		// FullName:  ResourceManager::unloadResource
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: size_t id
		// Description: Unloads the resource with the given id. Unloading releases the memory used back to the system.
		//***********************************************************
		void unloadResource(size_t id);
		//***********************************************************
		// Method:    removeResource
		// FullName:  IResourceManager::removeResource
		// Access:    virtual public 
		// Returns:   void
		// Qualifier:
		// Parameter: size_t id
		// Description: Removes the resource completely and frees up the id
		//***********************************************************
		void removeResource(size_t id);
		bool isResourceLoaded(size_t id);
		void cleanup();

		bool getResourceData(sf::Texture*& data, const size_t id) const;
		bool getResourceData(sf::Shader*& data, const size_t id) const;
	};
}

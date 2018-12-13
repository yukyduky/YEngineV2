#pragma once

#include <sfml/Graphics.hpp>
#include "General/YUtilityTypes.h"

namespace YEngine
{
	class IResourceManager
	{
	public:
		virtual ~IResourceManager() {}
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
		virtual bool createTexture(std::string filename, size_t id) = 0;
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
		virtual bool createShader(std::string fileVertex, std::string fileFragment, size_t id) = 0;
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
		virtual bool createShader(std::string fileVertex, std::string fileGeometry, std::string fileFragment, size_t id) = 0;
		//***********************************************************
		// Method:    unloadResource
		// FullName:  ResourceManager::unloadResource
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: size_t id
		// Description: Unloads the resource with the given id. Unloading releases the memory used back to the system.
		//***********************************************************
		virtual void unloadResource(size_t id) = 0;
		//***********************************************************
		// Method:    removeResource
		// FullName:  IResourceManager::removeResource
		// Access:    virtual public 
		// Returns:   void
		// Qualifier:
		// Parameter: size_t id
		// Description: Removes the resource completely and frees up the id
		//***********************************************************
		virtual void removeResource(size_t id) = 0;
		virtual bool isResourceLoaded(size_t id) = 0;

		virtual bool getResourceData(sf::Texture*& data, const size_t id) const = 0;
		virtual bool getResourceData(sf::Shader*& data, const size_t id) const = 0;
	};
}
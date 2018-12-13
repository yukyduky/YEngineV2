#include "ComponentManager.h"
#include <intrin.h>
#include <cassert>
#include "Components/Component.h"


namespace YEngine
{

	idlist<YEngine::ComponentManager::Entity> ComponentManager::m_Entities;
	std::unordered_map<std::bitset<BITMASK_SIZE>, ComponentManager::ComponentData> ComponentManager::m_Components;
	IDHandler ComponentManager::m_BitmaskIDs;

	
	ComponentManager::ComponentManager()
	{
		m_BitmaskIDs.resize(BITMASK_SIZE, 0);
	}
	
	size_t ComponentManager::addEntity(std::bitset<BITMASK_SIZE> componentBitmask)
	{
		size_t id = m_Entities.push(Entity());
	
		this->addComponentsToEntity(id, componentBitmask);
	
		return id;
	}
	
	void ComponentManager::removeEntity(const size_t entityID)
	{
		this->removeComponentsFromEntity(entityID, m_Entities[entityID].componentBitmask);
	
		m_Entities.remove(entityID);
	}
	
	void ComponentManager::addComponentsToEntity(const size_t entityID, const std::bitset<BITMASK_SIZE> componentBitmask)
	{
		size_t componentsAdded = 0;
		std::unordered_map<std::bitset<BITMASK_SIZE>, ComponentData>::iterator it = m_Components.begin();
	
		while (it != m_Components.end() && componentsAdded < componentBitmask.count())
		{
			if (((*it).first & componentBitmask) == (*it).first)
			{
				componentsAdded++;
	
				Component* component = nullptr;
				(*it).second.mm.requestMemory(component, (*it).second.templateInstance, (*it).second.byteSize);
				m_Entities[entityID].componentIDs[(*it).first] = (*it).second.components.push(component);

				component->setEntityID(entityID);
	
				m_Entities[entityID].componentBitmask |= (*it).first;
			}
	
			it++;
		}
	}
	
	void ComponentManager::removeComponentsFromEntity(const size_t entityID, const std::bitset<BITMASK_SIZE> componentBitmask)
	{
		size_t componentsRemoved = 0;
		std::unordered_map<std::bitset<BITMASK_SIZE>, ComponentData>::iterator it = m_Components.begin();
	
		while (it != m_Components.end() && componentsRemoved < componentBitmask.count())
		{
			if (((*it).first & componentBitmask) == (*it).first)
			{
				componentsRemoved++;
	
				try
				{
					ComponentData& data = m_Components.at((*it).first);
					size_t componentID = m_Entities[entityID].componentIDs.at((*it).first);
		
					data.mm.releaseMemory(data.components[componentID]);
					data.components.remove(entityID);
				}
				catch (std::out_of_range)
				{
					throw std::out_of_range("ComponentManager - One of the chosen component types is not registered (4)");
				}

				// 00001 -> 11110
				std::bitset<BITMASK_SIZE> notBitmask = ~(*it).first;
				// 01101 & 11110 -> 01100
				m_Entities[entityID].componentBitmask &= notBitmask;
				m_Entities[entityID].componentIDs.erase((*it).first);
			}
	
			it++;
		}
	}
	
	std::bitset<BITMASK_SIZE> ComponentManager::registerComponentType(Component* templateInstance, size_t byteSize, const char* name, size_t maxCapacity)
	{
		size_t id = m_BitmaskIDs.getNewID();

		std::bitset<BITMASK_SIZE> componentBitmask(1ULL << id);

		m_Components.insert(m_Components.end(), std::pair<std::bitset<BITMASK_SIZE>, ComponentData>(componentBitmask, ComponentData(templateInstance, name, byteSize, maxCapacity)));
	
		return componentBitmask;
	}
	
	void ComponentManager::unregisterComponentType(std::bitset<BITMASK_SIZE> componentBitmask)
	{
		try
		{
			ComponentData& data = m_Components.at(componentBitmask);
			data.mm.cleanup();
			delete data.templateInstance;
			m_Components.erase(componentBitmask);

			for (size_t i = 0; i < m_Entities.size(); i++)
			{
				if ((m_Entities[i].componentBitmask & componentBitmask) == componentBitmask)
				{
					std::bitset<BITMASK_SIZE> notBitmask = ~componentBitmask;
					m_Entities[i].componentBitmask &= notBitmask;
					m_Entities[i].componentIDs.erase(componentBitmask);
				}
			}

			unsigned long id;
			_BitScanForward(&id, componentBitmask.to_ulong()); // TODO::YE: Make compatible with other compilers)
			m_BitmaskIDs.remove(id);
		}
		catch (std::out_of_range)
		{
			throw std::out_of_range("ComponentManager - The chosen component type is not registered (3)");
		}
	}
	
	void ComponentManager::cleanup()
	{
		for (auto &i : m_Components)
		{
			i.second.mm.cleanup();
			delete i.second.templateInstance;
		}
		m_Components.clear();
	}
	
	bool ComponentManager::getComponentFromEntity(const size_t entityID, const std::bitset<BITMASK_SIZE> componentBitmask, Component*& component)
	{
		bool componentFound = false;

		if (componentBitmask.count() == 1 && (m_Entities[entityID].componentBitmask & componentBitmask) == componentBitmask)
		{
			componentFound = true;
			size_t componentID = m_Entities[entityID].componentIDs.at(componentBitmask);
			component = m_Components.at(componentBitmask).components[componentID];
		}

		return componentFound;
	}

	bool ComponentManager::getAllComponentsOfType(const std::bitset<BITMASK_SIZE> componentBitmask, idlist<Component*>*& components)
	{
		bool success = false;

		if (componentBitmask.count() == 1 && m_Components.find(componentBitmask) != m_Components.end())
		{
			success = true;
			components = &m_Components.at(componentBitmask).components;
		}

		return success;
	}
}

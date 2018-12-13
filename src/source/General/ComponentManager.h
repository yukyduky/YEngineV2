#pragma once

#include <map>
#include <unordered_map>
#include <bitset>
#include "General/YUtilityTypes.h"
#include "MemoryManager.h"
#include "General/idlist.h"
#include "General/IDHandler.h"
#include "IComponentManager.h"


namespace YEngine
{
	class Component;

	class ComponentManager : public IComponentManager
	{
	private:
		struct Entity
		{
			std::bitset<BITMASK_SIZE> componentBitmask;
			std::unordered_map<std::bitset<BITMASK_SIZE>, size_t> componentIDs;

			Entity()
			{
				componentBitmask.reset();
			}
			Entity(std::bitset<BITMASK_SIZE> componentBitmask) : componentBitmask(componentBitmask)
			{
				componentIDs.reserve(componentBitmask.count());
			}
		};

		struct ComponentData
		{
			MemoryManager mm;
			idlist<Component*> components;
			size_t byteSize;
	
			Component* templateInstance;
			const char* name;
	
			ComponentData(Component* templateInstance, const char* name, size_t byteSize, size_t maxCapacity) :
				templateInstance(templateInstance), name(name), byteSize(byteSize), mm(byteSize, maxCapacity), components(maxCapacity) {}
		};
	
		static idlist<Entity> m_Entities;
		static std::unordered_map<std::bitset<BITMASK_SIZE>, ComponentData> m_Components;
		static IDHandler m_BitmaskIDs;
	public:
		ComponentManager();
		virtual ~ComponentManager() {}

		size_t addEntity(std::bitset<BITMASK_SIZE> componentBitmask) override;
		void removeEntity(const size_t entityID) override;
		void addComponentsToEntity(const size_t entityID, const std::bitset<BITMASK_SIZE> componentBitmask) override;
		void removeComponentsFromEntity(const size_t entityID, const std::bitset<BITMASK_SIZE> componentBitmask) override;
	
		static std::bitset<BITMASK_SIZE> registerComponentType(Component* templateInstance, size_t byteSize, const char* name, size_t maxCapacity);
		static void unregisterComponentType(std::bitset<BITMASK_SIZE> componentBitmask);
		void cleanup();
	
		bool getComponentFromEntity(const size_t entityID, const std::bitset<BITMASK_SIZE> componentBitmask, Component*& component) override;
		bool getAllComponentsOfType(const std::bitset<BITMASK_SIZE> componentBitmask, idlist<Component*>*& components) override;
	};
}

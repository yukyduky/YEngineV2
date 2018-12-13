#pragma once

#include <bitset>
#include "General/YUtilityTypes.h"
#include "General/idlist.h"

namespace YEngine
{
	class Component;

	class IComponentManager
	{
	public:
		virtual size_t addEntity(std::bitset<BITMASK_SIZE> componentBitmask) = 0;
		virtual void removeEntity(const size_t entityID) = 0;
		virtual void addComponentsToEntity(const size_t entityID, const std::bitset<BITMASK_SIZE> componentBitmask) = 0;
		virtual void removeComponentsFromEntity(const size_t entityID, const std::bitset<BITMASK_SIZE> componentBitmask) = 0;

		virtual bool getComponentFromEntity(const size_t entityID, const std::bitset<BITMASK_SIZE> componentBitmask, Component*& component) = 0;
		virtual bool getAllComponentsOfType(const std::bitset<BITMASK_SIZE> componentBitmask, idlist<Component*>*& components) = 0;
	};
}
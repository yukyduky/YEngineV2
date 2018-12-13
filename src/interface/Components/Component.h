#pragma once

#include <glm/glm.hpp>
#include <bitset>
#include "General/YUtilityTypes.h"
#include "General/ComponentManager.h"
#include "sfml/Graphics.hpp"

namespace YEngine
{
	using glm::mat4;
	using glm::mat3;

	class Component
	{
	private:
		size_t m_EntityID;
	public:
		virtual ~Component() {}

		virtual void init() = 0;
		virtual void update(float dt) = 0;
		virtual void cleanup() = 0;

		size_t getEntityID() const
		{
			return m_EntityID;
		}
		void setEntityID(size_t val)
		{
			m_EntityID = val;
		}
	};

	template<class Derived>
	class DerivedComponent : public Component
	{
	private:
		static bool m_IsRegistered;
		static std::bitset<BITMASK_SIZE> m_ComponentBitmask;
		static size_t m_ByteSize;
	public:
		virtual ~DerivedComponent() {}

		virtual void init() = 0;
		virtual void update(float dt) = 0;
		virtual void cleanup() = 0;

		static bool getIsRegistered();
		static std::bitset<BITMASK_SIZE> getComponentBitmask();
		static size_t getByteSize();

		static void registerComponent(DerivedComponent<Derived>* derivedInstance, size_t byteSize, const char* componentName, size_t maxCapacity);
		static void unregisterComponent();
	};

	template<class Derived>
	inline bool DerivedComponent<Derived>::getIsRegistered()
	{
		return m_IsRegistered;
	}

	template<class Derived>
	inline std::bitset<BITMASK_SIZE> DerivedComponent<Derived>::getComponentBitmask()
	{
		return m_ComponentBitmask;
	}

	template<class Derived>
	inline size_t DerivedComponent<Derived>::getByteSize()
	{
		return m_ByteSize;
	}

	template<class Derived>
	inline void DerivedComponent<Derived>::registerComponent(DerivedComponent<Derived>* derivedInstance, size_t byteSize, const char* componentName, size_t maxCapacity)
	{
		if (!m_IsRegistered)
		{
			m_IsRegistered = true;
			m_ByteSize = byteSize;
			m_ComponentBitmask = ComponentManager::registerComponentType(derivedInstance, byteSize, componentName, maxCapacity);
		}
	}

	template<class Derived>
	inline void DerivedComponent<Derived>::unregisterComponent()
	{
		if (m_IsRegistered)
		{
			m_IsRegistered = false;
			ComponentManager::unregisterComponentType(m_ComponentBitmask);
			m_ComponentBitmask.reset();
		}
	}

	template <class Derived> bool DerivedComponent<Derived>::m_IsRegistered = false;
	template <class Derived> std::bitset<BITMASK_SIZE> DerivedComponent<Derived>::m_ComponentBitmask = m_ComponentBitmask.reset();
	template <class Derived> size_t DerivedComponent<Derived>::m_ByteSize = 0;
}

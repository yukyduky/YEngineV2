#pragma once

#include "Components/Component.h"
#include <unordered_map>

namespace YEngine
{
	class SuperEntityComponent : public DerivedComponent<SuperEntityComponent>
	{
	private:
		size_t m_SuperEntityID;
	public:
		SuperEntityComponent();
		virtual ~SuperEntityComponent() {};

		void setSuperEntityID(size_t entityID);
		size_t getSuperEntityID() const;
	};
}

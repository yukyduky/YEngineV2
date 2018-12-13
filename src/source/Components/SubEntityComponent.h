#pragma once

#include "Components/Component.h"

namespace YEngine
{
	class SubEntityComponent : public DerivedComponent<SubEntityComponent>
	{
	private:
		std::list<size_t> m_SubEntityIDs;
	public:
		SubEntityComponent();
		virtual ~SubEntityComponent() {};

		void addSubEntityID(size_t entityID);
		void removeSubEntityID(size_t entityID);
		const std::list<size_t>& getSubEntityIDs() const;
	};
}


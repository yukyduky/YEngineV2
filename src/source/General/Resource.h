#pragma once

#include "General/YUtilityTypes.h"
#include <sfml/Graphics.hpp>

namespace YEngine
{
	class Resource
	{
	private:
		RESOURCE::TYPE m_Type;
		size_t m_Scope;
	protected:
		bool m_Loaded;

	public:
		Resource(RESOURCE::TYPE type);
		virtual ~Resource() {}
		virtual bool load() = 0;
		virtual void unload() = 0;
		bool isLoaded() const;
	
		RESOURCE::TYPE getType() const;
		size_t getScope() const;
		void setScope(size_t val);
	};
}

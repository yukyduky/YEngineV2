#include "Resource.h"

namespace YEngine
{

	Resource::Resource(RESOURCE::TYPE type) : m_Loaded(false), m_Scope(-1), m_Type(type)
	{
	}

	bool Resource::isLoaded() const
	{
		return m_Loaded;
	}

	RESOURCE::TYPE Resource::getType() const
	{
		return m_Type;
	}

	size_t Resource::getScope() const
	{
		return m_Scope;
	}

	void Resource::setScope(size_t val)
	{
		m_Scope = val;
	}
}

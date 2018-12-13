#include "SubEntityComponent.h"


YEngine::SubEntityComponent::SubEntityComponent()
{

}

void YEngine::SubEntityComponent::addSubEntityID(size_t entityID)
{
	m_SubEntityIDs.push_back(entityID);
}

void YEngine::SubEntityComponent::removeSubEntityID(size_t entityID)
{
	bool idFound = false;
	std::list<size_t>::iterator it = m_SubEntityIDs.begin();

	while (it != m_SubEntityIDs.end() && !idFound)
	{
		if ((*it) == entityID)
		{
			idFound = true;
			m_SubEntityIDs.erase(it);
		}

		it++;
	}
}

const std::list<glm::size_t>& YEngine::SubEntityComponent::getSubEntityIDs() const
{
	return m_SubEntityIDs;
}

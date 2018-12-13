#include "SuperEntityComponent.h"



YEngine::SuperEntityComponent::SuperEntityComponent() : m_SuperEntityID(-1)
{
}

void YEngine::SuperEntityComponent::setSuperEntityID(size_t entityID)
{
	m_SuperEntityID = entityID;
}

size_t YEngine::SuperEntityComponent::getSuperEntityID() const
{
	return m_SuperEntityID;
}

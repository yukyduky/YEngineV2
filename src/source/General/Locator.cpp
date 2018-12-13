#include "Locator.h"


YEngine::IComponentManager* YEngine::Locator::m_CM = nullptr;
YEngine::IResourceManager* YEngine::Locator::m_RM = nullptr;

YEngine::IComponentManager* YEngine::Locator::getComponentManager()
{
	return m_CM;
}

void YEngine::Locator::supply(IComponentManager* cm)
{
	m_CM = cm;
}

YEngine::IResourceManager* YEngine::Locator::getResourceManager()
{
	return m_RM;
}

void YEngine::Locator::supply(YEngine::IResourceManager* rm)
{
	m_RM = rm;
}

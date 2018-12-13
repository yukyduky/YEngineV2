#pragma once
#include "IComponentManager.h"
#include "IResourceManager.h"

namespace YEngine
{
	class Locator
	{
	private:
		static IComponentManager* m_CM;
		static IResourceManager* m_RM;
	public:
		static IComponentManager* getComponentManager();
		static void supply(IComponentManager* cm);
		static IResourceManager* getResourceManager();
		static void supply(YEngine::IResourceManager* rm);
	};
}

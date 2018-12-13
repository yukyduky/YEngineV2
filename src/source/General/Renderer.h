#pragma once

#include <sfml/Graphics.hpp>
#include "General/idlist.h"

namespace YEngine
{
	class IComponentManager;
	class IResourceManager;
	class Component;

	class Renderer
	{
	private:
		sf::RenderWindow m_Window;
		IComponentManager* m_CM;
		IResourceManager* m_RM;

		void sort(idlist<Component*>& components);
	public:
		~Renderer();

		void init(sf::Vector2u windowSize, bool fullscreen, std::string title);
		bool pollEvent(sf::Event& event);
		void draw();
	};
}

